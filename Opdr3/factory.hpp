#ifndef _FACTORY_HPP
#define _FACTORY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <fstream>
#include <string>

class factory {
private:
	std::string location;

public:
	factory( std::string location ):
		location{ location }
	{}

	void read(){
		std::string position;
		std::string name;
		sf::Color color;

		//std::string line;
		std::ifstream myfile(location);
		if(myfile.is_open()){
			while(myfile >> position >> name >> color){
				std::cout << position << ", " << name << std::endl;
			}
			myfile.close();
		}
	}

	std::ifstream & operator>>(std::ifstream & input, sf::Color & rhs){
		std::string s;
   		input >> s;
   		const struct { const char * name; sf::Color color; } colors[]{
       		{ "yellow", sf::Color::Yellow },
       		{ "red",    sf::Color::Red },
       		{ "blue",	sf::Color::Blue}
    
   		};
   		for( auto const & color : colors ){
       		if( color.name == s ){ 
          		rhs = color.color;
          		return input;
       		}
   		}
   		//if( s == "" ){
      	//	throw end_of_file();
   		//}
   		//throw unknown_color( s );
	}

	/*std::ifstream & operator>>( std::ifstream & input, sf::Vector2f & rhs ){
   		char c;
   		if( ! ( input >> c )){ throw end_of_file(); }
   		if( c != '(' ){ throw invalid_position( c ); }

   		if( ! ( input >> rhs.x )){ . . . }

   		if( ! ( input >> c )){ . . . }
   		if( ! ( input >> rhs.y )){ . . . }

   		if( ! ( input >> c )){ . . . }
   		if( c != ')' ){ throw invalid_position( c ); }

   		return input;
	}*/
	
};

#endif