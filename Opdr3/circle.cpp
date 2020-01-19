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

void circle::writeToFile( std::ofstream &output ){
	output << getColor() << " " << getSize() << "\n"; 
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

std::string circle::getPosition() const {
	return "(" + std::to_string(position.x) + "," + std::to_string(position.y) + ") ";
}

std::string circle::getSize() {
	return std::to_string(size);
}

std::string circle::getColor(){
	const struct { const char * name; sf::Color color; } colors[]{
        	{ "yellow", sf::Color::Yellow },
        	{ "red",    sf::Color::Red },
        	{ "blue", sf::Color::Blue }
    
    };
    for( auto const & colour : colors ){
        if( colour.color == color ){ 
            return std::string{colour.name};
        }
    }
    return "red";
}

std::string circle::getPicture() const {
	return "";
}

float circle::getRotation() const {
	return ball.getRotation();
}