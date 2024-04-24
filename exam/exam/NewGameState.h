#pragma once
#include "State.h"
#include "Player.h"
#include "Bouton.h"

class NewGameState : public State
{
	Player* m_player;

	Bouton m_starterFeuBouton;
	Bouton m_starterEauBouton;
	Bouton m_starterPlanteBouton;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;

	sf::Font font;
	sf::Text text;
public:
	NewGameState();
	NewGameState(Player& _player);

	virtual void Update(sf::Vector2f _mousePos);
	virtual void Draw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
};

