#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <string>
#include "picture.hpp"

class command{
private:
	picture* pic;
	std::string image;
	std::string imageBefore = "";

public:
	command( picture* pic, std::string image );

	void execute();

	void undo();

};

#endif