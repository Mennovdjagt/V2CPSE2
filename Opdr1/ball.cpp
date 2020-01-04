#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "drawable.hpp"
#include <iostream>

ball::ball( sf::Vector2f position, float size, sf::Color color ) :
	position{ position },
	size{ size },
	color{ color }
{
   location = sf::Vector2f{ position.x - size, position.y - size };
}

void ball::draw( sf::RenderWindow & window ) {
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(color);
   circle.setOrigin(size, size);
	window.draw(circle);
}

void ball::update(){
	position += speed;
   location += speed;
}

bool ball::intersects(const sf::FloatRect& object) const{
	return circle.getGlobalBounds().intersects(object);
}

void ball::newDirection( sf::Vector2f delta ){
    speed = delta;
}

void ball::overlaps( const sf::FloatRect object ){

      std::cout << "location: x: " << location.x << " y: " << location.y << std::endl;
      std::cout << "object: x: " << object.left << " y: " << object.top << std::endl;


      if(object.left + object.width == location.x + 2){
         position += sf::Vector2f{2, 0};
         std::cout << "left" << std::endl;
         speed = sf::Vector2f{ speed.x * -1, speed.y };
      }else if(object.left == (position.x + size) - 2){
         position += sf::Vector2f{-2, 0};
         std::cout << "right" << std::endl;
         speed = sf::Vector2f{ speed.x * -1, speed.y };
      }else if(object.top == (position.y + size) - 2){
         position += sf::Vector2f{0, -2};
         std::cout << "down" << std::endl;
         speed = sf::Vector2f{ speed.x, speed.y * -1 };
      }else if(object.top + object.height == location.y){
         position += sf::Vector2f{0, 2};
         std::cout << "down" << std::endl;
         speed = sf::Vector2f{ speed.x, speed.y * -1 };
      }else{
         std::cout << "something went wrong" << std::endl;
         speed = sf::Vector2f{ speed.x = 0, speed.y = 0 };
      }

}


