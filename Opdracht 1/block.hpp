#ifndef _BLOCK_HPP
#define _BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"

class block : public drawable {
public:

	block( sf::Vector2f position, sf::Vector2f size, sf::Color color = {50, 150, 50} );

	void draw( sf::RenderWindow & window ) const;

	void move( sf::Vector2f delta );

private:
	sf::Vector2f size;
	sf::Color color;
};

#endif
