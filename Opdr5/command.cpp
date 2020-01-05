#include <string>
#include "command.hpp"
#include "picture.hpp"

command::command(picture* pic, std::string image):
	pic{ pic },
	image{ image }
{}

void command::execute(){
	imageBefore = pic->getSprite();

	pic->setSprite( image );
}

void command::undo(){
	pic->setSprite( imageBefore );
}