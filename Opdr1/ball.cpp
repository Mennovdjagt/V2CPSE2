#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "drawable.hpp"
#include <iostream>

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

void ball::update(){
	position += speed;
}

void ball::move( sf::Vector2f delta ){
	position += delta;
}

bool ball::intersects(const sf::FloatRect& object) const{
	return circle.getGlobalBounds().intersects(object);
}

void ball::newDirection( sf::Vector2f delta ){
    speed = delta;
}

bool ball::within( int x, int a, int b ){
   	return ( x >= a ) && ( x <= b );
}

sf::Vector2f ball::overlaps( const sf::FloatRect object ){

   	if( position.x + 2 == object.left + object.width ){
   		std::cout << "left" << std::endl;
   		position.x += 2;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( position.x + size + 2 == object.left + object.width - size){
   		std::cout << "right" << std::endl;
   		position.x -= 2;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( position.y - 2 == object.top ){
   		std::cout << "up" << std::endl;
   		position.y += 2;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}
   	if( position.y + size - 2 == object.top - size){
   		std::cout << "bottom" << std::endl;
   		position.y -= 2;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}

   	return sf::Vector2f{ speed.x, speed.y };
   }


