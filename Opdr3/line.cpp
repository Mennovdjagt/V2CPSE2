#include <SFML/Graphics.hpp>
#include "line.hpp"

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

void line::writeToFile( std::ofstream &output ){
	output << getColor() << " " << getSize() << getRotation() << "\n";
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

std::string line::getPosition() const {
	return "(" + std::to_string(position.x) + "," + std::to_string(position.y) + ") ";
}

std::string line::getSize() {
	return "(" + std::to_string(size.x) + "," + std::to_string(size.y) + ") " ;
}

std::string line::getColor(){
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

std::string line::getPicture() const {
	return "";
}

float line::getRotation() const {
	return lineShape.getRotation();
}