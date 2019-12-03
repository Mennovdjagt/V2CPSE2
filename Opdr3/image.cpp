#include <SFML/Graphics.hpp>
#include <iostream>
#include "image.hpp"
#include "drawable.hpp"

image::image( std::string picture, sf::Vector2f position ):
	picture{ picture },
	position{ position }
{}

void image::draw( sf::RenderWindow & window ) {
	texture.loadFromFile(picture);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	window.draw(sprite);
}

void image::move( sf::Vector2f delta ){
	position += delta;
}

bool image::contains( const sf::Vector2f& object ) const {
	return sprite.getGlobalBounds().contains( object );
}

void image::newPosition( const sf::Vector2f newPos ){
	sf::Vector2f size = castToF(texture.getSize());
	position = (newPos - sf::Vector2f(size.x/2, size.y/2));
}

sf::Vector2f image::getPosition() const {
	return position;
}

std::string image::getPicture() const {
	return picture;
}
