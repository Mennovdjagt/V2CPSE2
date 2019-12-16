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
  picture undo{   "undo.png", sf::Vector2f{ 510, 30 } };
  bool mousePressed = 0;      //is used to solve the multiple click problem
  bool crossOrCircle = 0;

  std::array< picture *, 2 > object = { &image, &undo };
  std::array< picture *, 9 > objects = {};

  //a loop with values declared here, because I am to lazy to make 9 invisible objects to press on
  uint k = 0;
  float x = 30;
  float y = 30;

  for(uint i = 0; i < 3; i++){
      for(uint j = 0; j < 3; j++){
          objects[k] = new picture{"black.jpg", sf::Vector2f{ x, y }};
          k++;
          x+=151;
      }
      x = 30;
      y+=154;
  }

  action actions[] = {
      action( sf::Mouse::Left,          [&](){ for(auto & p : objects){ if(p->contains( p->castToF( sf::Mouse::getPosition(window))) && mousePressed ){ p->setSprite(crossOrCircle); crossOrCircle ? crossOrCircle = 0 : crossOrCircle = 1; mousePressed = 0;} } }),
  };

  while (window.isOpen()) {
      for( auto & action : actions ){
          action();
      }

      window.clear();

      for( auto & p : objects ){
          p->draw(window);
      }

      for( auto & p : object ){
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
              std::cout << "hello there" << std::endl;
          }
      }
  }

}