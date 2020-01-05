#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "picture.hpp"
#include "action.hpp"
#include "command.hpp"

//a very lazy win or draw checker
uint winOrDraw(std::array< picture *, 9 > & objects){
  uint buf = 0;
  std::string cross = "cross.png";
  std::string circle = "circle.png";

      for (uint i = 0; i < 3; ++i){
          if(objects[i]->getSprite() == circle && objects[i+3]->getSprite() == circle && objects[i+6]->getSprite() == circle){
              std::cout << "winner: circle" << std::endl;
              return 2;
          }else if(objects[buf]->getSprite() == circle && objects[buf+1]->getSprite() == circle && objects[buf+2]->getSprite() == circle){
              std::cout << "winner: circle" << std::endl;
              return 2;
          }else if(objects[i]->getSprite() == cross && objects[i+3]->getSprite() == cross && objects[i+6]->getSprite() == cross){
              std::cout << "winner: cross" << std::endl;
              return 1;
          }else if(objects[buf]->getSprite() == cross && objects[buf+1]->getSprite() == cross && objects[buf+2]->getSprite() == cross){
              std::cout << "winner: cross" << std::endl;
              return 1;
          }
          buf+=3;
      }

  if(objects[0]->getSprite() == circle && objects[4]->getSprite() == circle && objects[8]->getSprite() == circle){
      std::cout << "winner: circle" << std::endl;
      return 2;
  }else if(objects[0]->getSprite() == cross && objects[4]->getSprite() == cross && objects[8]->getSprite() == cross){
      std::cout << "winner: cross" << std::endl;
      return 1;
  }else if(objects[2]->getSprite() == circle && objects[4]->getSprite() == circle && objects[6]->getSprite() == circle){
      std::cout << "winner: circle" << std::endl;
      return 2;
  }else if(objects[2]->getSprite() == cross && objects[4]->getSprite() == cross && objects[6]->getSprite() == cross){
      std::cout << "winner: cross" << std::endl;
      return 1;
  }

  uint count = 0;
  for (int i = 0; i < 9; ++i){
      if(objects[i]->getSprite() != "black.jpg"){
          count++;
      }
  }

  if(count == 9){
      std::cout << "draw" << std::endl;
      return 3;
  }
  return 0;
}

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
  bool crossOrCircle = 0;     //holds if the next will be a cross or a circle

  std::array< picture *, 9 > objects = {};      //holds all the 9 places on the board
  std::vector< command * > undoList;               //holds a list with al the undo's

  makeBoardImages(objects);

  action actions[] = {
      action( sf::Mouse::Left,  [&](){ if(undoPicture.contains(undoPicture.castToF( sf::Mouse::getPosition(window))) && mousePressed && undoList.size() > 0){ 
          undoList.back()->undo(); undoList.pop_back(); mousePressed = 0; if(crossOrCircle){crossOrCircle = 0;}else{crossOrCircle = 1;}} }),
      action( sf::Mouse::Left,  [&](){ for(auto & p : objects){ if(p->contains( p->castToF( sf::Mouse::getPosition(window))) && mousePressed && p->getSprite() == "black.jpg"){ 
          if(crossOrCircle){ undoList.push_back(new command(p, "circle.png")); crossOrCircle = 0; }else{ undoList.push_back(new command(p, "cross.png")); crossOrCircle = 1; } undoList.back()->execute(); mousePressed = 0; } } }),
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
              
      if(winOrDraw(objects) != 0){                 //checks if there is a winner or if there is a draw
        makeBoardImages(objects);                 //makes the board blank again
        crossOrCircle = 0;
        undoList.clear();                         //makes sure there is nothing in the list anymore
      }

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