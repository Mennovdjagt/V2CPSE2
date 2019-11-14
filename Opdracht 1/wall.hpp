#ifndef _WALL_HPP
#define _WALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class wall : public drawable {
public:

	wall( sf::Vector2f position, sf::Vector2f size, float thick, sf::Color color = {255, 0, 0} );

	void draw( sf::RenderWindow & window ) const;

private:
	sf::Vector2f size;
	float thick;
	sf::Color color;
};

#endif
