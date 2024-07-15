#include "Game.h"

#include <iostream>

using namespace std;

Game::Game(): _ball(65, 75), _table(50, 50, 500, 300), _hole(150, 170), _status(NotStarted), _cue(65, 75)
{
	if (!_ballHitBuffer.loadFromFile("ball01.wav"))
		std::cout << "Can not load sound" << std::endl;

	_ballHitSound.setBuffer(_ballHitBuffer);

	if (!_ballFallBuffer.loadFromFile("hole01.wav"))
		std::cout << "Can not load sound" << std::endl;

	_ballFall.setBuffer(_ballFallBuffer);

	

}

void Game::advance()
{
	if (_status != Running)
	{
		return;
	}

	auto collission = _table.checkCollision(_ball);

	switch (collission)
	{
	case Left:
		_ball.bounceX();
		break;
	case Right:
		_ball.bounceX();
		break;
	case Up:
		_ball.bounceY();
		break;
	case Down:
		_ball.bounceY();
		break;
	}

	_ball.advance();

	if (collission != None)
	{
		//std::cout << std::endl << "BOUNCE" << std::endl;

		_ballHitSound.play();
	}

	if (_hole.ballInHole(_ball))
	{
		_status = Finished;

		//std::cout << std::endl << "Ball in hole!" << std::endl;

		_ballFall.play();
	}
}

vector<shared_ptr<sf::Shape>> Game::GetShapes() const
{
	std::vector<shared_ptr<sf::Shape>> result;

	result.push_back(_table.getShape());

	result.push_back(_hole.getShape());

	


	if(_status != Finished)
	{
		result.push_back(_ball.getShape());
	}

	if(_status == NotStarted)
	{
		result.push_back(_cue.getShape());
	}

	return result;
}

void Game::start()
{
	if (_status == NotStarted)
	{
		/*float vx = (rand() % 30) / (float)10 +1;
		float vy = (rand() % 30) / (float)10 +1;*/

		_ball = Ball(65, 75);

		
		_ball.shoot(_cue.get_vX(), _cue.get_vY());

		_status = Running;

		_ballHitSound.play();


	}
	else
	{
		_status = NotStarted;
		_cue = Cue(65, 75);
		_ball = Ball(65, 75);
	}
}
void Game::rotateUp()
{
	_cue.rotateUp();
}

void Game::rotateDown()
{
	_cue.rotateDown();
}

void Game::stronger()
{
	_cue.stronger();
}
void Game::weaker()
{
	_cue.weaker();
}

