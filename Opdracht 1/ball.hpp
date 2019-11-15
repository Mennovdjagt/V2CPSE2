#ifndef _BALL_HPP
#define _BALL_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class ball : public drawable {
private:
	sf::Vector2f position;
	float size;
	sf::Color color;

	sf::Vector2f speed = { -1, 1};
	sf::CircleShape circle;

public:

	ball( sf::Vector2f position, float size = 30.0, sf::Color color = {50, 50, 150} );

	virtual void draw( sf::RenderWindow & window ) override;

	virtual void update() override;

	void move( sf::Vector2f delta );

	bool intersects( const sf::FloatRect& object) const;

	void newDirection( sf::Vector2f delta );

	bool within( int x, int a, int b );

	sf::Vector2f overlaps( const sf::FloatRect other );
};

#endif
