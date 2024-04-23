#pragma once
#include "State.h"
#include "Bouton.h"
#include "Player.h"
#include <iostream>

class MenuState : public State
{
	Bouton m_playBouton;
	Bouton m_optBouton;
	Bouton m_leaveBouton;

	sf::Texture m_backgroundTexture;
	sf::Sprite m_background;

	Player* m_player;
public:

	MenuState();
	MenuState(Player& _player);

	virtual void Update(sf::Vector2f _mousePos) override;
	virtual void Draw(sf::RenderWindow& _window) override; 
	virtual void HandleKeyboard(sf::Event _event);
};

