#include <string>
#include "undo.hpp"
#include "picture.hpp"

undo::undo(picture* pic):
	pic{ pic }
{
	image = pic->getSprite();
}

bool undo::execute( bool currentPic ){
	imageBefore = pic->getSprite();

	return pic->setSprite( currentPic );
}

void undo::back(){
	pic->setSprite( imageBefore );
}