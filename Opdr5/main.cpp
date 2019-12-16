#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include "picture.hpp"
#include "action.hpp"

sf::Vector2f castToF( sf::Vector2i target ){
  return sf::Vector2f(
      static_cast<float>( target.x ),
      static_cast<float>( target.y )
    );
  }

int main( int argc, char *argv[] ){
  std::cout << "Starting application 01-05 array of actions\n";

  sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

  picture image{  "board.png", sf::Vector2f{ 0, 0 } };
  picture circle{ "circle.png", sf::Vector2f{ 0, 0 } };
  picture circle1{ "circle.png", sf::Vector2f{ 180, 180 } };
  bool mousePressed = 0;      //is used to solve the multiple click problem

  std::array< picture *, 3 > objects = { &image, &circle, &circle1 };

  action actions[] = {
      //action( sf::Mouse::Left,      [&](){ for(auto & p : objects){ if(p->contains( p->castToF( sf::Mouse::getPosition(window)))){ std::cout << "klik" << std::endl; } } }),
    action( sf::Mouse::Left,          [&](){ if(mousePressed){ sf::Vector2f x = castToF(sf::Mouse::getPosition(window)); std::cout << "x: " << x.x << ", y: " << x.y << std::endl; mousePressed = 0; } })
  };

  while (window.isOpen()) {
      for( auto & action : actions ){
          action();
      }

      window.clear();

      for( auto & p : objects ){
          p->draw(window);
      }

      window.display();

      sf::sleep( sf::milliseconds( 0.001 ));

      sf::Event event;    
      while( window.pollEvent(event) ){
          if( event.type == sf::Event::Closed ){
              window.close();
          }else if( event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left ){ 
              mousePressed = 1;
          }
      }
  }

}