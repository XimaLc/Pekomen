#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Team.h"
#include "State.h"
#include "Bouton.h"
#include "PokemonMenu.h"
#include "pokemonInGameInfoBar.h"
#include "DB.h"

class CombatState : public State
{
protected:
	Bouton m_move1Bouton;
	Bouton m_move2Bouton;
	Bouton m_move3Bouton;
	Bouton m_move4Bouton;
	Bouton m_retourAttaqueBouton;

	Move nextMove;

	bool lastUpdate;
	bool m_isAttaqueMenuOpen;
	bool m_isSacMenuOpen;
	bool m_isPokemonMenuOpen;
	bool m_isMainMenuOpen;

	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;

	PokemonMenu m_pokemonMenu;

	Bouton m_attaqueBouton;
	Bouton m_pokemonBouton;
	Bouton m_sacBouton;
	Bouton m_fuiteBouton;
	
	Bouton m_ballBouton;
	Bouton m_soinBouton;

	sf::Sprite m_opponentPkmSprite;
	sf::Texture* m_opponentPkmTexture;
	Pokemon actualOpponentPkm;
	pokemonInGameInfoBar m_opponentInfoBar;

	sf::Sprite m_playerPkmSprite;
	sf::Texture* m_playerPkmTexture;
	int actualPlayerPkm;
	pokemonInGameInfoBar m_playerInfoBar;

	Player* m_player;

	bool inCombat;

	float timer;
public:
	CombatState();
	CombatState(Player& _player);
	~CombatState();

	void setOpponentPkmTexture(std::string _path);
	void setPlayerPkmTexture(std::string _path);

	void Attaque(int _damages, Pokemon& _target);
	void TurnAction();

	virtual void CommonUpdate(sf::Vector2f _mousePos);
	virtual void CommonDraw(sf::RenderWindow& _window);
	virtual void HandleKeyboard(sf::Event _event);
};

