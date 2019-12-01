#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <SFML/Graphics.hpp>
#include "drawable.hpp"
#include <iostream>

class image : public drawable {
private:
	std::string picture;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

public:

	image( std::string pic, sf::Vector2f position );

	virtual void draw( sf::RenderWindow & window ) override;
};

#endif