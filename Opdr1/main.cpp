#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "block.hpp"
//#include "wall.hpp"
#include <array>
#include "drawable.hpp"

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
	ball  my_ball{ 	sf::Vector2f{ 500.0, 50.0 } };
	block my_block{ sf::Vector2f{ 100.0, 200.0 }, 	sf::Vector2f{ 50.0, 150.0 } };
	block left{ 	sf::Vector2f{ 0.0, 0.0 }, 		sf::Vector2f{ 10.0, 480.0 }, sf::Color{255, 0, 0} };
	block right{ 	sf::Vector2f{ 630.0, 0.0 }, 	sf::Vector2f{ 10.0, 480.0 }, sf::Color{255, 0, 0} };
	block up{ 		sf::Vector2f{ 0.0, 0.0 }, 		sf::Vector2f{ 640.0, 10.0 }, sf::Color{255, 0, 0} };
	block down{ 	sf::Vector2f{ 0.0, 470.0 }, 	sf::Vector2f{ 640.0, 10.0 }, sf::Color{255, 0, 0} };
	//wall my_wall{ sf::Vector2f{ 0.0, 0.0 }, sf::Vector2f{ 640.0, 480.0 }, 10 };

	std::array< drawable *, 6 > objects = { &my_ball, &my_block, &left, &right, &up, &down };

	action actions[] = {
		action( sf::Keyboard::Left,  	[&](){ my_block.move( sf::Vector2f( -3.0,  0.0 )); }),
		action( sf::Keyboard::Right, 	[&](){ my_block.move( sf::Vector2f( +3.0,  0.0 )); }),
		action( sf::Keyboard::Up,    	[&](){ my_block.move( sf::Vector2f(  0.0, -3.0 )); }),
		action( sf::Keyboard::Down,  	[&](){ my_block.move( sf::Vector2f(  0.0, +3.0 )); }),

		action( [&](){ my_ball.update(); }),
		action( [&](){ return my_ball.intersects( left.getGlobalBounds() 	 ); }, [&](){ my_ball.newDirection( my_ball.overlaps( left.getGlobalBounds() 	 ) 	); }),
		action( [&](){ return my_ball.intersects( right.getGlobalBounds() 	 ); }, [&](){ my_ball.newDirection( my_ball.overlaps( right.getGlobalBounds() 	 ) 	); }),
		action( [&](){ return my_ball.intersects( up.getGlobalBounds() 		 ); }, [&](){ my_ball.newDirection( my_ball.overlaps( up.getGlobalBounds() 		 )  ); }),
		action( [&](){ return my_ball.intersects( down.getGlobalBounds() 	 ); }, [&](){ my_ball.newDirection( my_ball.overlaps( down.getGlobalBounds() 	 ) 	); }),
		action( [&](){ return my_ball.intersects( my_block.getGlobalBounds() ); }, [&](){ my_ball.newDirection( my_ball.overlaps( my_block.getGlobalBounds() )  ); })
		//, [&](){ my_ball.move( sf::Vector2f(  +1.0, 0.0 ));
	};

	while (window.isOpen()) {
		for( auto & action : actions ){
			action();
		}

		window.clear();

		for( auto & p : objects ){
         p->draw( window );
      }

		window.display();

		//std::cout << my_block.getGlobalBounds().intersects(right.getGlobalBounds()) << std::endl;
		//std::cout << my_block.getGlobalBounds() << std::endl;

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

