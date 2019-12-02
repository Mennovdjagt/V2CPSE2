#ifndef _DRAWABLE_HPP
#define _DRAWABLE_HPP

#include <SFML/Graphics.hpp>

class drawable {
public:

	virtual void draw( sf::RenderWindow & window ) = 0;
	virtual void move ( sf::Vector2f delta );
	virtual void update(){}
	virtual bool contains( const sf::Vector2f& object ) const;
	//virtual sf::Vector2f castToF( sf::Vector2i target );

	sf::Vector2f castToF( sf::Vector2i target ){
	return sf::Vector2f(
			static_cast<float>( target.x ),
			static_cast<float>( target.y )
		);
	}
	
};

#endif