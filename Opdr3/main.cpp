#include <iostream>
#include <functional>
#include <array>
#include <fstream>
#include <string>
#include <exception>

#include <SFML/Graphics.hpp>
//#include "ball.hpp"
#include "rectangle.hpp"
#include "drawable.hpp"
#include "action.hpp"


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
   		/*if( s == "" ){
      		throw end_of_file();
   		}
   		throw unknown_color( s );*/
   		
   	rhs = sf::Color::Yellow;
   	return input;
}


void read(){
	std::string position;
	std::string name;
	sf::Color color;
	std::string size;
	
	std::ifstream myfile("tekst.txt");
	if(myfile.is_open()){
		while(myfile >> position >> name >> color >> size){
			std::cout << position << ", " << name << ", " << size << std::endl;
			std::cout << "hello" << std::endl;
		}
		myfile.close();
	}

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

	//std::string location = "tekst.txt";
	read();


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