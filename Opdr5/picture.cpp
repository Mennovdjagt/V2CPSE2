#include <SFML/Graphics.hpp>
#include <string>
#include "picture.hpp"

picture::picture( std::string image, sf::Vector2f position ):
	image{ image },
	position{ position }
{}

void picture::draw( sf::RenderWindow & window ) {
	texture.loadFromFile(image);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	window.draw(sprite);
}

bool picture::contains( const sf::Vector2f& object ) const {
	return sprite.getGlobalBounds().contains( object );
}