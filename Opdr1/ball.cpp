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
   std::cout << object.left << ", " << object.width << ", " << object.height << ", " << position.x << ", " << position.y << ", " << (object.top - position.x) << std::endl;

   	if( (object.left - position.x) <= 60 && (object.left - position.x) >= 50){
   		std::cout << "right" << std::endl;
   		position.x -= 10;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( (object.left - position.x) >= -100 && (object.left - position.x) <= 0){
   		std::cout << "left" << std::endl;
   		position.x += 10;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( (object.top - position.y) <=60 && (object.top - position.y) >= 50 ){
   		std::cout << "bottom" << std::endl;
   		position.y -= 10;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}
   	if( (object.top - position.y) <= 0 ){
   		std::cout << "up" << std::endl;
   		position.y += 10;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}

   	return sf::Vector2f{ speed.x, speed.y };
   }


