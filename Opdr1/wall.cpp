#include <SFML/Graphics.hpp>
#include "block.hpp"
#include "wall.hpp"
#include "drawable.hpp"

wall::wall( sf::Vector2f position, sf::Vector2f size, float thick, sf::Color color ) :
	drawable{ position },
	size{ size },
	thick{ thick },
	color{ color }
{}

void wall::draw( sf::RenderWindow & window ) const {

	block left{sf::Vector2f{position.x, position.y}, sf::Vector2f{thick, size.y - position.y}, color};
	block right{sf::Vector2f{size.x - thick, position.y}, sf::Vector2f{thick, size.y - position.y}, color};
	block up{sf::Vector2f{position.x, position.y}, sf::Vector2f{size.x - position.x, thick}, color};
	block down{sf::Vector2f{position.x, size.y - thick}, sf::Vector2f{size.x - position.x, thick}, color};

	left.draw(window);
	right.draw(window);
	up.draw(window);
	down.draw(window);
}