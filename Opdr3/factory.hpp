#ifndef _FACTORY_HPP
#define _FACTORY_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <exception>

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
		std::string color;
		std::string size;
	

		//std::string line;
		std::ifstream myfile(location);
		if(myfile.is_open()){
			while(myfile >> position >> name >> color >> size){
				std::cout << position << ", " << name << ", " << size << std::endl;
				std::cout << "hello" << std::endl;
			}
			myfile.close();
		}
	}

	friend std::ifstream & operator>>( std::ifstream & input, sf::Color & rhs );
	friend std::ifstream & operator>>( std::ifstream & input, sf::Vector2f & rhs );
	
};

std::ifstream & operator>>( std::ifstream & input, sf::Color& rhs ){
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
   		throw unknown_color( s );
   		*/
   	return input;
}

std::ifstream & operator>>( std::ifstream & input, sf::Vector2f & rhs ){
   	char c;
   	//if( ! ( input >> c )){ throw end_of_file(); }
   	//if( c != '(' ){ throw invalid_position( c ); }

   	if( ! ( input >> rhs.x )){ }

   	if( ! ( input >> c )){ }
   	if( ! ( input >> rhs.y )){ }

   	if( ! ( input >> c )){ }
   	//if( c != ')' ){ throw invalid_position( c ); }

   	return input;
}

/*class unknown_color : public std::exception {
public:
   unknown_color( const std::string & name  ):
       s{ std::string{ "unknown colcor [" } + name + "]" }
   {}
   const char * what() const override {
      return s.c_str();
   }
private:
   std::string s;
};*/


#endif