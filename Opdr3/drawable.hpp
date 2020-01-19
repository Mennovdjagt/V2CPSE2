#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

class drawable {
public:

	virtual void draw( sf::RenderWindow & window ) = 0;
	virtual void writeToFile( std::ofstream &output ) = 0;
	virtual void move ( sf::Vector2f delta );
	virtual void update(){}
	virtual bool contains( const sf::Vector2f& object ) const;
	virtual void newPosition( const sf::Vector2f newPos );
	virtual std::string getType() const;
	virtual std::string getPosition() const;
	virtual std::string getSize();
	virtual std::string getColor();
	virtual std::string getPicture() const;
	virtual float getRotation() const;

	sf::Vector2f castToF( sf::Vector2i target ){
	return sf::Vector2f(
			static_cast<float>( target.x ),
			static_cast<float>( target.y )
		);
	}

	sf::Vector2f castToF( sf::Vector2u target ){
	return sf::Vector2f(
			static_cast<float>( target.x ),
			static_cast<float>( target.y )
		);
	}
	
};

#endif