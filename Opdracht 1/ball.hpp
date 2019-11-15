#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable {
private:
	sf::Vector2f position;
	float size;
	sf::Color color;
	sf::CircleShape circle;

public:

	ball( sf::Vector2f position, float size = 30.0, sf::Color color = {50, 50, 150} );

	virtual void draw( sf::RenderWindow & window ) override;



	void move( sf::Vector2f delta );

	bool intersects( sf::FloatRect& object) const{
		return circle.getGlobalBounds().intersects(object);
	}
};

#endif
