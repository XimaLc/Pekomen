#pragma once
#include "Bouton.h"
#include "Pokemon.h"

enum TYPE {ATTAQUE_INFIGHT, ATTAQUE_MENU};

class AttaqueMenu
{
	Pokemon m_pokemon;

	
	Bouton m_move1Bouton;
	Bouton m_move2Bouton;
	Bouton m_move3Bouton;
	Bouton m_move4Bouton;
	Bouton m_retourBouton;
public:
	bool m_isOpen;
	
	AttaqueMenu();
	AttaqueMenu(Pokemon _pokemon, int type);

	inline void OpenClose() { m_isOpen = !m_isOpen; }

	void Update(sf::Vector2f _mousePos);
	void Draw(sf::RenderWindow& _window);
};

