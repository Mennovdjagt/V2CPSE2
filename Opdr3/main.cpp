#include <iostream>
#include <functional>
#include <array>
#include <fstream>
#include <string>
#include <exception>
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "drawable.hpp"
#include "action.hpp"
#include "image.hpp"


class unknown_color : public std::exception {
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown colcor [" } + name + "]" }
   {}
   const char * what() const noexcept {
      return s.c_str();
   }
private:
   std::string s;
};


class end_of_file : public std::exception {
public:
	end_of_file( ){}

	const char * what() const noexcept {
      return "end of file";
   }

private:
};


class invalid_position : public std::exception {
public:
	invalid_position( const char & c):
		s{ std::string{ "invalid_position [" } + c + "]" }
	{}

	const char * what() const noexcept {
      return s.c_str();
   }

private:
	std::string s;
};


class unknown_shape : public std::exception {
public:
	unknown_shape( const std::string & s ):
		s{ std::string{ "unknown shape [" } + s + "]" }
	{}

	const char * what() const noexcept {
      return s.c_str();
   }

private:
	std::string s;
};


std::istream & operator>>( std::istream & input, sf::Color & rhs ){
	std::string s;
   	input >> s;
   	const struct { const char * name; sf::Color color; } colors[]{
       	{ "yellow", sf::Color::Yellow },
       	{ "red",    sf::Color::Red },
       	{ "blue",	sf::Color::Blue }
    
   	};
   	for( auto const & color : colors ){
       	if( color.name == s ){ 
          	rhs = color.color;
          	return input;
       	}
   	}
   		if( s == "" ){
      		throw end_of_file();
   		}
   		throw unknown_color( s );
}


std::istream & operator>>( std::istream & input, sf::Vector2f & rhs ){
   	char c;
   	if( ! ( input >> c )){ throw end_of_file(); }
   	if( c != '(' ){ throw invalid_position( c ); }

   	if( ! ( input >> rhs.x )){ }

   	if( ! ( input >> c )){ }
   	if( ! ( input >> rhs.y )){ }

   	if( ! ( input >> c )){ }
   	if( c != ')' ){ throw invalid_position( c ); }

   	return input;
}

drawable* read( std::ifstream & input ){
	sf::Vector2f position;
	std::string name;
	sf::Color color;					
	sf::Vector2f size;
	std::string sizef;					//sizef is a string that will be converted to a float in circle
	std::string pic;					//the location of the picture
	
	input >> position >> name;			//only the first 2 are the same with circle's, rectangle's, picture's and line's

	if( name == "CIRCLE" ){
		input >> color >> sizef;
     	return new circle( position, std::stof(sizef), color );		//std::stof(sizef) is a build in function from std::string to convert to a float
	}
   	if( name == "RECTANGLE" ){
   		input >> color >> size;
      	return new rectangle( position, size, color );
   	} else if( name == "PICTURE" ){
   		input >> pic;
      	return new image( pic, position );

   	} else if( name == "" ){
      	throw end_of_file();
    }

   throw unknown_shape( name );
}

void write( std::ofstream &, drawable* objects ){

}


int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	std::vector<drawable *> object;

	{
		std::ifstream input( "tekst.txt" );
		try{
			for(;;){
				object.push_back(read( input ));
			}
		}catch( std::exception & e ){
			std::cout << e.what();
		}
	}

	int block = -1;
	bool selected = 0;

	action actions[] = {
		action( sf::Keyboard::Left,  	[&](){ if(block >= 0){ object.at(block)->move( sf::Vector2f( -1.0,  0.0 )); } }),
		action( sf::Keyboard::Right, 	[&](){ if(block >= 0){ object.at(block)->move( sf::Vector2f( +1.0,  0.0 )); } }),
		action( sf::Keyboard::Up,    	[&](){ if(block >= 0){ object.at(block)->move( sf::Vector2f(  0.0, -1.0 )); } }),
		action( sf::Keyboard::Down,  	[&](){ if(block >= 0){ object.at(block)->move( sf::Vector2f(  0.0, +1.0 )); } }),
	};


	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();

        int a = 0;

        for( auto & p : object ){
         	p->draw(window);
         	if(sf::Mouse::isButtonPressed( sf::Mouse::Left )){
         		bool isPressed = p->contains( p->castToF( sf::Mouse::getPosition(window)));
         		if(isPressed && !selected){
         			selected = true;
         			std::cout << isPressed << std::endl;
         			block = a;
         		}else if( !isPressed ){
         			selected = false;
         			std::cout << "missed" << std::endl;
         			//block = -1;
         		}
         	}
         	a++;
     	}

		window.display();

		sf::sleep( sf::milliseconds( 10 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;

}