// Octave1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

#include "Circle.h"
#include "Ball.h"
#include "Game.h"
#include "Table.h"


using namespace std;

//
//int main()
//{
//	Ball ball1(15, 25);
//	Table table(3, 3, 100, 60);
//
//	ball1.shoot(1, 2);
//	while (true)
//	{
//		ball1.advance();
//
//		auto collission = table.checkCollision(ball1);
//		switch (collission)
//		{
//		case Left:
//			ball1.bounceX();
//			break;
//		case Right:
//			ball1.bounceX();
//			break;
//		case Up:
//			ball1.bounceY();
//			break;
//		case Down:
//			ball1.bounceY();
//			break;
//		}
//
//
//		if(collission != None)
//			cout<<endl<<"BOUNCE" <<endl;
//
//		ball1.display();
//		std::chrono::milliseconds dura(100);
//		this_thread::sleep_for(dura);
//	}
//}

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 400), "SFML works!");
	sf::Clock clockDisplay;
	sf::Clock clockCompute;

	Game theGame;

	clockDisplay.restart();
	clockCompute.restart();

	while (window.isOpen())
	{
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if(event.key.code == sf::Keyboard::Key::Enter )
					theGame.start();

				if(event.key.code == sf::Keyboard::Key::Right)
					theGame.rotateDown();

				if(event.key.code == sf::Keyboard::Key::Left)
					theGame.rotateUp();

				if(event.key.code == sf::Keyboard::Key::Up)
					theGame.stronger();

				if(event.key.code == sf::Keyboard::Key::Down)
					theGame.weaker();
			}
				
		}


		if (clockCompute.getElapsedTime().asMilliseconds() > 1) {
			theGame.advance();
			clockCompute.restart();
		}

		
		
		if (clockDisplay.getElapsedTime().asMilliseconds() > 10) {
			window.clear();

			auto shapes = theGame.GetShapes();

			for (auto shape : shapes)
			{
				window.draw(*shape);
			}


			window.display();

			clockDisplay.restart();
		}
		

		/*std::chrono::microseconds dura(1000);
		this_thread::sleep_for(dura);*/
	}//main loop

	return 0;
}
