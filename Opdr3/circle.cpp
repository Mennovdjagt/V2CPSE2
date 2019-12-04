#include <SFML/Graphics.hpp>
#include "circle.hpp"
#include "drawable.hpp"
#include <iostream>

circle::circle( sf::Vector2f position, float size, sf::Color color ) :
	position{ position },
	size{ size },
	color{ color }
{}

void circle::draw( sf::RenderWindow & window ) {
	ball.setRadius(size);
	ball.setPosition(position);
	ball.setFillColor(color);
	window.draw(ball);
}

void circle::move( sf::Vector2f delta ){
	position += delta;
}

bool circle::contains( const sf::Vector2f& object ) const {
	return ball.getGlobalBounds().contains( object );
}

void circle::newPosition( const sf::Vector2f newPos ){
	position = (newPos - sf::Vector2f{size, size});
}

std::string circle::getType() const{
	return "CIRCLE";
}

sf::Vector2f circle::getPosition() const {
	return position;
}

float circle::getSize() const {
	return size;
}

sf::Color circle::getColor() const{
	return color;
}