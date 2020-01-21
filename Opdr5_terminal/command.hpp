#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include <string>
#include "circleCrossObject.hpp"

class command{
private:
	circleCrossObject* object;
	char charObject;
	char charObjectBefore = ' ';

public:
	command( circleCrossObject* object, char charObject );

	void execute();

	void undo();

};

#endif