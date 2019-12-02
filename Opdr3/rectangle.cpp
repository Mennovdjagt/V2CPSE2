#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include "drawable.hpp"

rectangle::rectangle( sf::Vector2f position, sf::Vector2f size, sf::Color color ) :
	position{ position },
	size{ size },
	color{ color }
{}

void rectangle::draw( sf::RenderWindow & window ) {
	block.setSize(size);
	block.setPosition(position);
	block.setFillColor(color);
	window.draw(block);
}

void rectangle::move( sf::Vector2f delta ){
	position += delta;
}

bool rectangle::contains( const sf::Vector2f& object ) const {
	return block.getGlobalBounds().contains( object );
}

sf::Vector2f rectangle::getPosition() const {
	return position;
}

sf::Vector2f rectangle::getSize() const {
	return size;
}

sf::Color rectangle::getColor() const{
	return color;
}