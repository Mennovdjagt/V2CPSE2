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

   	/*bool x_overlap1 = within( 
      	object.left - 2, 
      	position.x, 
      	position.x + size
   	);
     
   	bool y_overlap = within( 
      	position.y + 2, 
      	object.top, 
      	object.top + object.height
   	);
	bool y_overlap1 = within( 
      	object.top, 
      	position.y - 2, 
      	position.y + size
   	);*/

   	//std::cout << "do this shit: " << x_overlap << ", " << y_overlap << " " << x_overlap1 << ", " << y_overlap1 << std::endl;

   	/*if( within( position.x, object.left - 2, object.left + object.width + 2 ) ){
   		std::cout << "left" << std::endl;
   		//position.x += 2;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}else if( within( position.y, object.top - 2, object.top + object.height + 2)){
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}else if(){

   	}else if(){

   	}*/

   	if( position.x + 2 == object.left + object.width ){
   		std::cout << "left" << std::endl;
   		position.x += 2;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( position.x + size + 2 == object.left ){
   		std::cout << "right" << std::endl;
   		position.x -= 2;
   		return sf::Vector2f{ speed.x * -1, speed.y };
   	}
   	if( position.y - 2 == object.top ){
   		std::cout << "up" << std::endl;
   		position.y += 2;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}
   	if( position.y + size + 2 == object.top ){
   		std::cout << "bottom" << std::endl;
   		position.y -= 2;
   		return sf::Vector2f{ speed.x, speed.y * -1 };
   	}

   	return sf::Vector2f{ speed.x, speed.y };

}