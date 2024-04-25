#include "InGameMenu.h"
#include "StateManager.h"

InGameMenu::InGameMenu()
{
	isMenuOpen = false;
	isPokemonMenuOpen = false;

	m_inGameProfilBouton = Bouton({ 1620, 190 }, { 300, 100 }, "Dresseur");
	m_inGamePokemonBouton = Bouton({ 1620, 290 }, { 300, 100 }, "Pekomon");
	m_inGameBagBouton = Bouton({ 1620, 390 }, { 300, 100 }, "Sac");
	m_inGamePokedexBouton = Bouton({ 1620,  490 }, { 300, 100 }, "Bestiaire");
	m_inGameSaveBouton = Bouton({ 1620, 590 }, { 300, 100 }, "Sauvegarde");
	m_inGameOptionsBouton = Bouton({ 1620, 690 }, { 300, 100 }, "Options");
	m_inGameLeaveBouton = Bouton({ 1620, 790 }, { 300, 100 }, "Quitter");

	m_inGameProfilBouton.setOnClick([this]() 
		{ 
			if (m_inGameProfilBouton.timer > 0.5f) 
			{ 
				/*ouvrir le profil*/ 
			}
		});

	m_inGamePokemonBouton.setOnClick([this]()
		{
			if (m_inGamePokemonBouton.timer > 0.5f)
			{
				if (!m_pokemonMenu.m_isPokemonMenuOpen)
					closeAllMenu();
				m_pokemonMenu.OpenClose();
				m_inGamePokemonBouton.timer = 0;
			}
		});
		
	m_inGameBagBouton.setOnClick([this]() 
		{ 
			if (m_inGameBagBouton.timer > 0.5f) 
			{ 
				/*ouvrir le sac*/ 
			}
		});

	m_inGamePokedexBouton.setOnClick([this]() 
		{ 
			if (m_inGamePokedexBouton.timer > 0.5f) 
			{ 
				/*ouvrir le pokedex*/ 
			}
		});

	m_inGameSaveBouton.setOnClick([this]() 
		{ 
			if (m_inGameSaveBouton.timer > 0.5f)
			{
				if (!m_saveMenu.isSaveMenuOpen) 
					closeAllMenu();
				m_saveMenu.OpenClose();
				m_inGameSaveBouton.timer = 0;
			}
		});

	m_inGameOptionsBouton.setOnClick([this]() 
		{ 
			if (m_inGameOptionsBouton.timer > 0.5f) 
			{ 
				/*ouvrir les options*/ 
			}
		});

	m_inGameLeaveBouton.setOnClick([this]() 
		{ 
			if (m_inGameLeaveBouton.timer > 0.5f) 
			{
				closeAllMenu();
				m_inGameSaveBouton.timer = 0; 
				StateManager::ChangeState(MENU_STATE); 
			}
	});
}

InGameMenu::~InGameMenu()
{
}

void InGameMenu::closeAllMenu()
{
	if(m_saveMenu.isSaveMenuOpen)
		m_saveMenu.OpenClose();
	if(m_pokemonMenu.m_isPokemonMenuOpen)
		m_pokemonMenu.OpenClose();
}

void InGameMenu::OpenCloseMenu(bool& _toSwitch)
{
	if (!_toSwitch)
		closeAllMenu();

	_toSwitch = !_toSwitch;
}

void InGameMenu::OpenCloseOtherMenu(bool& _toSwitch)
{
	_toSwitch = !_toSwitch;
}


void InGameMenu::Update(const sf::Vector2f _mousePos)
{
	if (isMenuOpen)
	{
		m_inGameOptionsBouton.Update(_mousePos);
		m_inGameBagBouton.Update(_mousePos);
		m_inGamePokemonBouton.Update(_mousePos);
		m_inGameProfilBouton.Update(_mousePos);
		m_inGameSaveBouton.Update(_mousePos);
		m_inGamePokedexBouton.Update(_mousePos);
		m_inGameLeaveBouton.Update(_mousePos);
	}
	if (m_saveMenu.isSaveMenuOpen)
		m_saveMenu.Update(_mousePos);

	if (m_pokemonMenu.m_isPokemonMenuOpen)
		m_pokemonMenu.Update(_mousePos);

	if (m_inGameSaveBouton.isClicked())
		m_inGameSaveBouton.useClickAction();
	
	if (m_inGamePokemonBouton.isClicked())
	{
		m_pokemonMenu.loadPlayer();
		m_inGamePokemonBouton.useClickAction();
	}
	
	if (m_inGameLeaveBouton.isClicked())
		m_inGameLeaveBouton.useClickAction();
	
}

void InGameMenu::Draw(sf::RenderWindow& _window)
{
	if (isMenuOpen)
	{
		m_inGameOptionsBouton.Draw(_window);
		m_inGameBagBouton.Draw(_window);
		m_inGamePokemonBouton.Draw(_window);
		m_inGameProfilBouton.Draw(_window);
		m_inGameSaveBouton.Draw(_window);
		m_inGamePokedexBouton.Draw(_window);
		m_inGameLeaveBouton.Draw(_window);
		if (m_saveMenu.isSaveMenuOpen)
			m_saveMenu.Draw(_window);

		if (m_pokemonMenu.m_isPokemonMenuOpen)
			m_pokemonMenu.Draw(_window);

	}
}
