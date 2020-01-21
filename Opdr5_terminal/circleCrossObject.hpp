#ifndef _CIRCLECROSSOBJECT_HPP
#define _CIRCLECROSSOBJECT_HPP

#include <iostream>

class circleCrossObject{
private:
	char object;

public:
	circleCrossObject( char object ):
		object( object )
	{}

	void setObject( char newObject ){
		object = newObject;
	}

	char getObject(){
		return object;
	}

};

#endif