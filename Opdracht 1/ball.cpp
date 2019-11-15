#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "drawable.hpp"

ball::ball( sf::Vector2f position, float size, sf::Color color ) :
	position{ position },
	size{ size },
	color{ color }
{}

void ball::draw( sf::RenderWindow & window ) {
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ){
	position += delta;
}

