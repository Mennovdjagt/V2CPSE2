#ifndef _PICTURE_HPP
#define _PICTURE_HPP

#include <SFML/Graphics.hpp>
#include <string>

class picture{
private:
	std::string image;
	sf::Vector2f position;
	uint sortObject;
	sf::Texture texture;
	sf::Sprite sprite;

public:
	picture( std::string image, sf::Vector2f position, uint sortObject );

	void draw( sf::RenderWindow & window );
	bool contains( const sf::Vector2f& object ) const;

	bool setSprite( bool x );

	void setSprite( std::string newSprite );

	std::string getSprite();

	uint getSpriteInt();

	sf::Vector2f castToF( sf::Vector2i target ){
	return sf::Vector2f(
			static_cast<float>( target.x ),
			static_cast<float>( target.y )
		);
	}

};

#endif