#ifndef _RECTANGLE_HPP
#define _RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class rectangle : public drawable {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	sf::RectangleShape block;

public:

	rectangle( sf::Vector2f position, sf::Vector2f size, sf::Color color = {50, 150, 50} );

	virtual void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );
};

#endif