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
	virtual void move( sf::Vector2f delta ) override;
	virtual bool contains( const sf::Vector2f& object ) const override;
	virtual void newPosition( const sf::Vector2f newPos ) override;
	virtual std::string getType() const override;
	sf::Vector2f getPosition() const;
	float getSize() const;
	sf::Color getColor() const;
};

#endif
