#include <SFML/Graphics.hpp>
#include <string>
#include "picture.hpp"

picture::picture( std::string image, sf::Vector2f position, uint sortObject ):
	image{ image },
	position{ position },
	sortObject{ sortObject }
{}

void picture::draw( sf::RenderWindow & window ) {
	texture.loadFromFile(image);
	sprite.setTexture(texture);
	sprite.setPosition(position);
	window.draw(sprite);
}

bool picture::contains( const sf::Vector2f& object ) const {
	return sprite.getGlobalBounds().contains( object );
}

bool picture::setSprite( bool x ){
	if(x && image != "circle.png" && image != "cross.png"){
		image = "circle.png";
		sortObject = 2;
		return false;
	}else if(!x && image != "circle.png" && image != "cross.png"){
		image = "cross.png";
		sortObject = 3;
		return true;
	}else{
		return x;
	}
}

void picture::setSprite( std::string newSprite ){
	image = newSprite;
	if(image == "circle.png"){
		sortObject = 2;
	}else if(image == "cross.png"){
		sortObject = 3;
	}else{
		sortObject = 1;
	}
}

std::string picture::getSprite(){
	return image;
}

uint picture::getSpriteInt(){
	return sortObject;
}