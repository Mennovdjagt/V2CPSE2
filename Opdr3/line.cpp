#include <SFML/Graphics.hpp>
#include "line.hpp"
#include "drawable.hpp"

line::line( sf::Vector2f position, sf::Vector2f size, sf::Color color, float rotation ) :
	position{ position },
	size{ size },
	color{ color },
	rotation{ rotation }
{}

void line::draw( sf::RenderWindow & window ) {
	lineShape.setSize(size);
	lineShape.setPosition(position);
	lineShape.setFillColor(color);
	lineShape.setRotation(rotation);
	window.draw(lineShape);
}

void line::move( sf::Vector2f delta ){
	position += delta;
}

bool line::contains( const sf::Vector2f& object ) const {
	return lineShape.getGlobalBounds().contains( object );
}

void line::newPosition( const sf::Vector2f newPos ){
	position = newPos;
}

std::string line::getType() const{
	return "LINE";
}

sf::Vector2f line::getPosition() const {
	return position;
}

sf::Vector2f line::getSize() {
	return size;
}

sf::Color line::getColor() const{
	return color;
}

std::string line::getPicture() const {
	return "";
}

float line::getRotation() const {
	return lineShape.getRotation();
}