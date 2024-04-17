#pragma once
#include "State.h"
#include "Bouton.h"
#include <iostream>

class MenuState : public State
{
	Bouton m_playBouton;
	Bouton m_optBouton;
	Bouton m_leaveBouton;

public:
	MenuState();

	virtual void Update(sf::Vector2f _mousePos) override;
	virtual void Draw(sf::RenderWindow& _window) override; 
	virtual void HandleEvent(sf::Event _event, sf::RenderWindow& _window) override;
};

