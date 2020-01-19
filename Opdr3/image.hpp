#ifndef _IMAGE_HPP
#define _IMAGE_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "drawable.hpp"

class image : public drawable {
private:
	std::string picture;
	sf::Vector2f position;
	sf::Texture texture;
	sf::Sprite sprite;

public:

	image( std::string pic, sf::Vector2f position );

	virtual void draw( sf::RenderWindow & window ) override;
	virtual void writeToFile( std::ofstream &output ) override;
	virtual void move( sf::Vector2f delta ) override;
	virtual bool contains( const sf::Vector2f& object ) const override;
	virtual void newPosition( const sf::Vector2f newPos ) override;
	virtual std::string getType() const override;
	virtual std::string getPosition() const override;
	virtual std::string getSize() override;
	virtual std::string getColor() override;

	virtual std::string getPicture() const override;
	virtual float getRotation() const override;

};

#endif