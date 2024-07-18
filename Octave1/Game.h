#pragma once
#include "Ball.h"
#include "Table.h"

#include <SFML/Audio.hpp>

#include "Cue.h"
#include "Hole.h"
#include "Panel.h"

enum GameStatus
{
	Before, NotStarted, Running, Finished
};

class Game
{
private:

	Ball _ball;
	Table _table;
	Hole _hole;
	Panel _panel;
	GameStatus _status;
	Cue _cue;

	sf::SoundBuffer _ballHitBuffer;
	sf::Sound _ballHitSound;
	sf::SoundBuffer _ballFallBuffer;
	sf::Sound _ballFall;
	


public:

	Game();

	void advance();

	std::vector<std::shared_ptr<sf::Shape>> GetShapes() const;

	void start();

	void rotateUp();
	void rotateDown();
	void stronger();
	void weaker();

};

