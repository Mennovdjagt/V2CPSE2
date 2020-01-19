#include <SFML/Graphics.hpp>
#include "rectangle.hpp"
#include "drawable.hpp"

rectangle::rectangle( sf::Vector2f position, sf::Vector2f size, sf::Color color ) :
	position{ position },
	size{ size },
	color{ color }
{}

void rectangle::draw( sf::RenderWindow & window ) {
	block.setSize(size);
	block.setPosition(position);
	block.setFillColor(color);
	window.draw(block);
}

void rectangle::writeToFile( std::ofstream &output ){
	output << getColor() << " " << getSize() << "\n";  
}

void rectangle::move( sf::Vector2f delta ){
	position += delta;
}

bool rectangle::contains( const sf::Vector2f& object ) const {
	return block.getGlobalBounds().contains( object );
}

void rectangle::newPosition( const sf::Vector2f newPos ){
	position = (newPos - sf::Vector2f{size.x / 2, size.y / 2});
}

std::string rectangle::getType() const{
	return "RECTANGLE";
}

std::string rectangle::getPosition() const {
	return "(" + std::to_string(position.x) + "," + std::to_string(position.y) + ") ";
}

std::string rectangle::getSize() {
	return "(" + std::to_string(size.x) + "," + std::to_string(size.y) + ") " ;
}

std::string rectangle::getColor() {
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

std::string rectangle::getPicture() const {
	return "";
}

float rectangle::getRotation() const {
	return block.getRotation();
}