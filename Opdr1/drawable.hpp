#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
public:

	virtual void draw( sf::RenderWindow & window ) = 0;

	virtual void update(){};
	
};

#endif
