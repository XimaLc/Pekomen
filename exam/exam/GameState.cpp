#include "GameState.h"

GameState::GameState()
{
	shape.setFillColor(sf::Color::Red);
	shape.setSize({ 200, 200 });
	shape.setPosition({ 200, 200 });

	std::cout << "Dans le game state" << std::endl;
}

void GameState::Update(sf::Vector2f _mousePos)
{

}

void GameState::Draw(sf::RenderWindow& _window)
{
	_window.draw(shape);
}

void GameState::HandleEvent(sf::Event _event, sf::RenderWindow& _window)
{
}
