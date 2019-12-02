#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "drawable.hpp"

block::block( sf::Vector2f position, sf::Vector2f size, sf::Color color ) :
	position{ position },
	size{ size },
	color{ color }
{}

void block::draw( sf::RenderWindow & window ) {
	rectangle.setSize(size);
	rectangle.setPosition(position);
	rectangle.setFillColor(color);
	window.draw(rectangle);
}

void block::move( sf::Vector2f delta ){
	position += delta;
}

sf::FloatRect block::getGlobalBounds() const {
	return rectangle.getGlobalBounds();
}
