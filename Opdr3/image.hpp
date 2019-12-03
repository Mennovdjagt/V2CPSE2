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
	virtual void move( sf::Vector2f delta ) override;
	virtual bool contains( const sf::Vector2f& object ) const override;
	virtual void newPosition( const sf::Vector2f newPos ) override;
	sf::Vector2f getPosition() const;
	std::string getPicture() const;
};

#endif