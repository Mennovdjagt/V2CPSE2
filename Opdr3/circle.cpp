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