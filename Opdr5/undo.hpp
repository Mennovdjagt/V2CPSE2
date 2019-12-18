#ifndef _UNDO_HPP
#define _UNDO_HPP

#include <string>
#include "picture.hpp"

class undo{
private:
	picture* pic;
	std::string image;
	bool currentPic;
	std::string imageBefore = "";

public:
	undo(picture* pic);

	bool execute( bool currentPic );

	void back();

};

#endif