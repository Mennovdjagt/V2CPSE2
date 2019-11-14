#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable {
public:

	ball( sf::Vector2f position, float size = 30.0, sf::Color color = {50, 50, 150} );

	void draw( sf::RenderWindow & window ) const;

	void move( sf::Vector2f delta );

	void jump( sf::Vector2f target );
	void jump( sf::Vector2i target );

private:
	float size;
	sf::Color color;
};

#endif
