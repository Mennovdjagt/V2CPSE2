#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
//#include "ball.hpp"
#include "rectangle.hpp"
#include <array>
#include "drawable.hpp"
#include "factory.hpp"

class action {
private:
	std::function< bool() > condition;
	std::function< void() > work;
public:
	action(
	   std::function< bool() > condition, 
	   std::function< void() > work
	) : condition( condition ), 
		work( work ) 
	{}

	action(
		sf::Keyboard::Key key,
		std::function< void() > work
	) :
		condition(
			[ key ]()->bool { return sf::Keyboard::isKeyPressed( key ); }
		),
		work(work)
	{}

	action(
		sf::Mouse::Button button,
		std::function< void() > work
	) :
		condition(
			[ button ]()->bool { return sf::Mouse::isButtonPressed( button ); }
		),
		work(work)
	{}

	action(
		std::function< void() > work
	) :
		condition(
			[]()->bool { return 1; }
		),
		work(work)
	{}

	void operator()(){
		if( condition() ){
			work();
		}
	}
};

int main( int argc, char *argv[] ){
	std::cout << "Starting application 01-05 array of actions\n";

	sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };

	rectangle my_block{ 	sf::Vector2f{ 310.0, 230.0 }, 		sf::Vector2f{ 20.0, 20.0 }, sf::Color{255, 0, 0} };

	std::array< drawable *, 1 > objects = { &my_block };

	action actions[] = {
		action( sf::Keyboard::Left,  	[&](){ my_block.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, 	[&](){ my_block.move( sf::Vector2f( +3.0,  0.0 )); }),
		action( sf::Keyboard::Up,    	[&](){ my_block.move( sf::Vector2f(  0.0, -3.0 )); }),
		action( sf::Keyboard::Down,  	[&](){ my_block.move( sf::Vector2f(  0.0, +3.0 )); }),
	};

	factory no_name("tekst.txt");
	no_name.read();


	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();

		for( auto & p : objects ){
         p->draw( window );
      }

		window.display();

		sf::sleep( sf::milliseconds( 10 ));

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}	
	}

	std::cout << "Terminating application\n";
	return 0;

}