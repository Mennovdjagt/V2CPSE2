#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "picture.hpp"
#include "action.hpp"
#include "undo.hpp"

//a loop with values declared here, because I am to lazy to make 9 invisible objects to press on
void makeBoardImages(std::array< picture *, 9 > & objects){
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
}

int main( int argc, char *argv[] ){
  std::cout << "Starting application 01-05 array of actions\n";

  sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

  picture board{        "board.png", sf::Vector2f{ 0, 0 } };
  picture undoPicture{  "undo.png", sf::Vector2f{ 510, 30 } };

  bool mousePressed = 0;      //a flag to check whether the mousebutton is released
  bool crossOrCircle = 0;     //a flag that decides if the object will be a cross or a circle

  std::array< picture *, 9 > objects = {};
  std::vector< undo * > undoList;

  makeBoardImages(objects);

  action actions[] = {
      action( sf::Mouse::Left,  [&](){ if(undoPicture.contains(undoPicture.castToF( sf::Mouse::getPosition(window))) && mousePressed && undoList.size() > 0){ undoList.back()->back(); undoList.pop_back(); mousePressed = 0; crossOrCircle = !crossOrCircle; } }),
      action( sf::Mouse::Left,  [&](){ for(auto & p : objects){ if(p->contains( p->castToF( sf::Mouse::getPosition(window))) && mousePressed && p->getSprite() == "black.jpg"){ undoList.push_back(new undo(p)); crossOrCircle = undoList.back()->execute(crossOrCircle); mousePressed = 0; } } }),
  };

  while (window.isOpen()) {
      for( auto & action : actions ){
          action();
      }

      window.clear();

      for( auto & p : objects ){
          p->draw(window);
      }

      undoPicture.draw(window);
      board.draw(window);

      window.display();

      sf::sleep( sf::milliseconds( 10 ));

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