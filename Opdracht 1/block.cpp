#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "drawable.hpp"

block::block( sf::Vector2f position, sf::Vector2f size, sf::Color color ) :
	drawable{ position },
	size{ size },
	color{ color }
{}

void block::draw( sf::RenderWindow & window ) const {
	sf::RectangleShape rectangle;
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
	window.draw(rectangle);
}

void block::move( sf::Vector2f delta ){
	position += delta;
}
