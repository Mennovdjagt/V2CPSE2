#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class circle : public drawable {
private:
	sf::Vector2f position;
	float size;
	sf::Color color;
	sf::CircleShape ball;

public:

	circle( sf::Vector2f position, float size = 30.0, sf::Color color = {50, 50, 150} );

	virtual void draw( sf::RenderWindow & window ) override;
};

#endif
