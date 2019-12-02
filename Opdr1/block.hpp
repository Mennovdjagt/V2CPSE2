#ifndef _BLOCK_HPP
#define _BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class block : public drawable {
private:
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Color color;
	sf::RectangleShape rectangle;

public:

	block( sf::Vector2f position, sf::Vector2f size = sf::Vector2f{ 30.0, 50.0 }, sf::Color color = { 50, 150, 50 } );

	virtual void draw( sf::RenderWindow & window ) override;

	void move( sf::Vector2f delta );

	sf::FloatRect getGlobalBounds() const;
};

#endif
