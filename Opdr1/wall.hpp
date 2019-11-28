#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class wall : public drawable {
private:
	sf::Vector2f size;
	float thick;
	sf::Color color;

public:

	wall( sf::Vector2f position, sf::Vector2f size, float thick, sf::Color color = {255, 0, 0} );

	virtual void draw( sf::RenderWindow & window ) override;

};

#endif
