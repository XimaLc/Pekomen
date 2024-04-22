#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Team.h"
#include "State.h"
#include "Bouton.h"
#include "PokemonMenu.h"
#include "pokemonInGameInfoBar.h"
#include "AttaqueMenu.h"
#include "DB.h"

class CombatState : public State
{
protected:
	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;

	PokemonMenu m_pokemonMenu;
	AttaqueMenu m_attaqueMenu;

	Bouton m_attaqueBouton;
	Bouton m_pokemonBouton;
	Bouton m_sacBouton;
	Bouton m_fuiteBouton;
	
	sf::Sprite m_opponentPkmSprite;
	sf::Texture* m_opponentPkmTexture;
	Pokemon actualOpponentPkm;
	pokemonInGameInfoBar m_opponentInfoBar;

	sf::Sprite m_playerPkmSprite;
	sf::Texture* m_playerPkmTexture;
	Pokemon actualPlayerPkm;
	pokemonInGameInfoBar m_playerInfoBar;

	Player m_player;

	bool inCombat;
	bool isAttaqueMenuOpen;


	float timer;
public:
	CombatState();
	~CombatState();

	void setOpponentPkmTexture(std::string _path);
	void setPlayerPkmTexture(std::string _path);

	virtual void CommonUpdate(sf::Vector2f _mousePos);
	virtual void CommonDraw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
};

