#include <SFML/Graphics.hpp>
#include <array>
#include <vector>
#include <iostream>
#include "circleCrossObject.hpp"
#include "action.hpp"
#include "command.hpp"

//a very lazy win or draw checker
uint winOrDraw(std::array< circleCrossObject *, 9 > & objects){
  uint buf = 0;
  char cross = 'X';
  char circle = 'O';

      for (uint i = 0; i < 3; ++i){
          if(objects[i]->getObject() == circle && objects[i+3]->getObject() == circle && objects[i+6]->getObject() == circle){
              std::cout << "winner: circle" << std::endl;
              return 2;
          }else if(objects[buf]->getObject() == circle && objects[buf+1]->getObject() == circle && objects[buf+2]->getObject() == circle){
              std::cout << "winner: circle" << std::endl;
              return 2;
          }else if(objects[i]->getObject() == cross && objects[i+3]->getObject() == cross && objects[i+6]->getObject() == cross){
              std::cout << "winner: cross" << std::endl;
              return 1;
          }else if(objects[buf]->getObject() == cross && objects[buf+1]->getObject() == cross && objects[buf+2]->getObject() == cross){
              std::cout << "winner: cross" << std::endl;
              return 1;
          }
          buf+=3;
      }

  if(objects[0]->getObject() == circle && objects[4]->getObject() == circle && objects[8]->getObject() == circle){
      std::cout << "winner: circle" << std::endl;
      return 2;
  }else if(objects[0]->getObject() == cross && objects[4]->getObject() == cross && objects[8]->getObject() == cross){
      std::cout << "winner: cross" << std::endl;
      return 1;
  }else if(objects[2]->getObject() == circle && objects[4]->getObject() == circle && objects[6]->getObject() == circle){
      std::cout << "winner: circle" << std::endl;
      return 2;
  }else if(objects[2]->getObject() == cross && objects[4]->getObject() == cross && objects[6]->getObject() == cross){
      std::cout << "winner: cross" << std::endl;
      return 1;
  }

  uint count = 0;
  for (int i = 0; i < 9; ++i){
      if(objects[i]->getObject() != ' '){
          count++;
      }
  }

  if(count == 9){
      std::cout << "draw" << std::endl;
      return 3;
  }
  return 0;
}

void draw(std::array< circleCrossObject *, 9 > & objects){
	std::cout << objects[0]->getObject() << '|' << objects[1]->getObject() << '|' << objects[2]->getObject() << '\n';  
	std::cout << "-----\n";
	std::cout << objects[3]->getObject() << '|' << objects[4]->getObject() << '|' << objects[5]->getObject() << '\n';
	std::cout << "-----\n";  
	std::cout << objects[6]->getObject() << '|' << objects[7]->getObject() << '|' << objects[8]->getObject() << '\n';  
}

//a loop with values declared here, because I am to lazy to make 9 invisible objects to press on
void makeBoardImages(std::array< circleCrossObject *, 9 > & objects){
  uint k = 0;

  for(uint i = 0; i < 3; i++){
      for(uint j = 0; j < 3; j++){
          objects[k] = new circleCrossObject(' ');
          k++;
      }
  }
}

int main( int argc, char *argv[] ){
  std::cout << "Starting application 01-05 array of actions\n";

  std::array< circleCrossObject *, 9 > objects = {};      //holds all the 9 places on the board
  std::vector< command * > undoList;               //holds a list with al the undo's

  int x_as;
  int y_as;
  bool crossOrCircle = 0;

  makeBoardImages(objects);

  while( true ){
  	std::cout << "\nEnter location: ";
  	std::cin >> x_as >> y_as;

  	if(x_as <= 3 && y_as <= 3 && x_as > 0 && y_as > 0){
  		uint location = (x_as - 1) + ((y_as - 1) * 3);
  		if(objects[location]->getObject() == ' '){
  			if(crossOrCircle){
  				undoList.push_back(new command(objects[location], 'O'));
  				crossOrCircle = 0;
  			}else{
  				undoList.push_back(new command(objects[location], 'X'));
  				crossOrCircle = 1;
  			}
  		}else{
  			std::cout << "location already in use!\n";
  		}
  	}
  	else if(x_as > 3 || y_as > 3){
  		if(undoList.size() > 0){
  			undoList.back()->undo();
  			undoList.pop_back();
  			crossOrCircle ? crossOrCircle = 0 : crossOrCircle = 1;
  		}
  	}
  	else if(x_as == 0 || y_as == 0){
  		break;
  	}

  	if(undoList.size() > 0){
  		undoList.back()->execute();
  	}

  	draw(objects);


  	if(winOrDraw(objects) != 0){                 //checks if there is a winner or if there is a draw
        makeBoardImages(objects);                 //makes the board blank again
        crossOrCircle = 0;
        undoList.clear();                         //makes sure there is nothing in the list anymore
      }
  }

}