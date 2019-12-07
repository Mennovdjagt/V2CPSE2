#include <SFML/Graphics.hpp>
#include "line.hpp"
#include "drawable.hpp"

line::line( sf::Vector2f position, sf::Vector2f size, sf::Color color ) :
	position{ position },
	size{ size },
	color{ color }
{}

void line::draw( sf::RenderWindow & window ) {
	sf::Vertex line[] =
	{
    	sf::Vertex(sf::Vector2f(10, 10), color),
    	sf::Vertex(sf::Vector2f(150, 150), color)
	};
	window.draw(line, 2, sf::Lines);
}

void line::move( sf::Vector2f delta ){
	position += delta;
}

bool line::contains( const sf::Vector2f& object ) const {
	//return line.getGlobalBounds().contains( object );
	return 0;
}

void line::newPosition( const sf::Vector2f newPos ){
	position = (newPos - sf::Vector2f{size.x / 2, size.y / 2});
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