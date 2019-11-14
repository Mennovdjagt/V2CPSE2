#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "drawable.hpp"

ball::ball( sf::Vector2f position, float size, sf::Color color ) :
	drawable{ position },
	size{ size },
	color{ color }
{}

void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ){
	position += delta;
}

void ball::jump( sf::Vector2f target ){
	position = target;
}

void ball::jump( sf::Vector2i target ){
	jump( sf::Vector2f( 
		static_cast< float >( target.x ), 
		static_cast< float >( target.y )
	));
}
