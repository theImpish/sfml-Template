#pragma once
#pragma once

#include "Entity.h"
#include "EntityManager.h"

#include <SFML/Graphics.hpp>

class Game
{
	sf::RenderWindow m_window;
	bool m_paused = false;
	bool m_running = true;
	EntityManager m_entities;

	sf::Font m_font;
	sf::Text m_text;

	//int m_score = 0;
	int m_currentFrame = 0;
	//int m_lastEnemySpawnTime = 0;

	//int m_bulletFadeOutRatio;
	//int m_smallEnemyFadeOutRatio;
	//int m_specialSpread;

	std::shared_ptr<Entity> m_player;

	void init();
	void setPaused();

	void sMovement();
	void sUserInput();
	void sRender();
	void sEnemySpawner();
	void sCollision();

	void spawnPlayer();
	void spawnEnemy();


public:

	Game();

	void run();
};
