#include <iostream>
#include <functional>
#include <array>
#include <fstream>
#include <string>
#include <exception>
#include <memory>

#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include "drawable.hpp"
#include "action.hpp"


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
	std::string size;
	
	input >> position >> name >> color >> size;
	std::cout << "(" << position.x << "," << position.y << "), " << name << ", " << size << std::endl;
	/*if( name == "CIRCLE" ){
     	return new circle( );
	}*/
   	if( name == "RECTANGLE" ){
      	return new rectangle(position, sf::Vector2f(10, 10), color);
   	/*} else if( name == "PICTURE" ){
      	return new picture(  );*/

   	} else if( name == "" ){
      	throw end_of_file();
    }

   throw unknown_shape( name );
}


int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	rectangle my_block{ 	sf::Vector2f{ 310.0, 230.0 }, 		sf::Vector2f{ 20.0, 20.0 }, sf::Color{255, 0, 0} };

	std::array< drawable *, 1 > objects = { &my_block };

	action actions[] = {
		action( sf::Keyboard::Left,  	[&](){ my_block.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, 	[&](){ my_block.move( sf::Vector2f( +3.0,  0.0 )); }),
		action( sf::Keyboard::Up,    	[&](){ my_block.move( sf::Vector2f(  0.0, -3.0 )); }),
		action( sf::Keyboard::Down,  	[&](){ my_block.move( sf::Vector2f(  0.0, +3.0 )); }),
	};

	{
		std::ifstream input( "tekst.txt" );
		try{
			for(;;){
				read( input );
			}
		}catch( std::exception & e ){
			std::cout << e.what();
		}
	}


	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();

		for( auto & p : objects ){
         p->draw( window );
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