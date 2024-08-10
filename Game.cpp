#include "Game.h"

#include <iostream>
#include <fstream>

Game::Game()
{
	init();
}

void Game::init()
{
	int width = 1280, height = 720, frameLimit = 0;
	bool fullScreen = false;

	m_window.create(sf::VideoMode(width, height), "SFML Template", (fullScreen) ? sf::Style::Fullscreen : sf::Style::Default);
	m_window.setFramerateLimit(frameLimit);

	std::srand(std::time(nullptr));

	spawnPlayer();
	spawnEnemy();
}

void Game::run()
{
	while (m_running)
	{
		m_entities.update();

		if (!m_paused)
		{
			sEnemySpawner();
			sMovement();
			sCollision();
		}

		sUserInput();
		sRender();

		m_currentFrame++;
	}
}

void Game::setPaused()
{
	m_paused = !m_paused;
}

void Game::spawnPlayer()
{

}

void Game::spawnEnemy()
{

}


void Game::sMovement()
{

}


void Game::sCollision()
{

}

void Game::sEnemySpawner()
{
	//if (m_currentFrame - m_lastEnemySpawnTime > m_enemyConfig.SI)
	//{
		spawnEnemy();
	//}

}

void Game::sRender()
{

	m_window.clear();

	//m_text = sf::Text("Score: " + std::to_string(m_score), m_font, m_fontConfig.S);
	//m_text.setPosition(10, 10);
	//m_window.draw(m_text);

	for (auto e : m_entities.getEntities())
	{
		//m_window.draw();
	}

	m_window.display();
}

void Game::sUserInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		// this event triggers when the window is closed
		if (event.type == sf::Event::Closed)
		{
			m_running = false;
		}

		// this event is triggered when a key is pressed
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				m_running = false;
				break;
			case sf::Keyboard::W:
				break;
			case sf::Keyboard::S:
				break;
			case sf::Keyboard::A:
				break;
			case sf::Keyboard::D:
				break;
			case sf::Keyboard::P:
				setPaused();
			default: break;
			}
		}

		// this event is triggered when a key is released
		if (event.type == sf::Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::W:
				break;
			case sf::Keyboard::S:
				break;
			case sf::Keyboard::A:
				break;
			case sf::Keyboard::D:
				break;
			default: break;
			}
		}

		// this event is triggered when a key is released


		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				std::cout << "Right Mouse Button Clicked at (" << event.mouseButton.x << " " << event.mouseButton.y << ")\n";
			}

			if (event.mouseButton.button == sf::Mouse::Right)
			{
				std::cout << "Right Mouse Button Clicked at (" << event.mouseButton.x << " " << event.mouseButton.y << ")\n";
			}
		}

	}
}


