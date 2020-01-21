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
	virtual std::string getType() const override;
	virtual sf::Vector2f getPosition() const override;
	virtual sf::Vector2f getSize() override;
	virtual sf::Color getColor() const override;

	virtual std::string getPicture() const override;
	virtual float getRotation() const override;

};

#endif