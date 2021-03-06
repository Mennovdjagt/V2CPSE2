#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include <SFML/Graphics.hpp>
#include <string>

class picture{
private:
	std::string image;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	picture( std::string image, sf::Vector2f position );

	void draw( sf::RenderWindow & window );
	bool contains( const sf::Vector2f& object ) const;

	void setSprite( std::string newSprite );

	std::string getSprite();

	sf::Vector2f castToF( sf::Vector2i target ){
	return sf::Vector2f(
			static_cast<float>( target.x ),
			static_cast<float>( target.y )
		);
	}

};

#endif