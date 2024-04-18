#include "InGameMenu.h"
#include "StateManager.h"

InGameMenu::InGameMenu()
{
	isMenuOpen = false;

	m_inGameProfilBouton = Bouton({ 1620, 190 }, { 300, 100 }, "Dresseur");
	m_inGamePokemonBouton = Bouton({ 1620, 290 }, { 300, 100 }, "Pekomon");
	m_inGameBagBouton = Bouton({ 1620, 390 }, { 300, 100 }, "Sac");
	m_inGamePokedexBouton = Bouton({ 1620,  490}, { 300, 100 }, "Bestiaire");
	m_inGameSaveBouton = Bouton({ 1620, 590 }, { 300, 100 }, "Sauvegarde");
	m_inGameOptionsBouton = Bouton({1620, 690 }, { 300, 100 }, "Options");
	m_inGameLeaveBouton = Bouton({ 1620, 790 }, { 300, 100 }, "Quitter");

	auto inGameProfilBoutonAction = [this]() { if (m_inGameProfilBouton.timer > 0.5f) { /*ouvrir le profil*/ }};
	m_inGameProfilBouton.setOnClick(inGameProfilBoutonAction);

	auto inGamePokemonBoutonAction = [this]() { if (m_inGamePokemonBouton.timer > 0.5f) { /*ouvrir les pokemons*/  }};
	m_inGamePokemonBouton.setOnClick(inGamePokemonBoutonAction);

	auto inGameBagBoutonAction = [this]() { if (m_inGameBagBouton.timer > 0.5f) { /*ouvrir le sac*/  }};
	m_inGameBagBouton.setOnClick(inGamePokemonBoutonAction);

	auto inGamePokedexBoutonAction = [this]() { if (m_inGamePokedexBouton.timer > 0.5f) { /*ouvrir le pokedex*/  }};
	m_inGamePokedexBouton.setOnClick(inGamePokedexBoutonAction);

	auto inGameSaveBoutonAction = [this]() { if (m_inGameSaveBouton.timer > 0.5f) { OpenClose(isSaveMenuOpen); }};
	m_inGameSaveBouton.setOnClick(inGameSaveBoutonAction);

	auto inGameOptionsBoutonAction = [this]() { if (m_inGameOptionsBouton.timer > 0.5f) { /*ouvrir les options*/  }};
	m_inGameOptionsBouton.setOnClick(inGameOptionsBoutonAction);

	auto inGameLeaveBoutonAction = [this]() { if (m_inGameLeaveBouton.timer > 0.5f) { StateManager::ChangeState(MENU); }};
	m_inGameLeaveBouton.setOnClick(inGameLeaveBoutonAction);
}

void InGameMenu::OpenClose(bool& _toSwitch)
{
	if (_toSwitch)
		_toSwitch = false;
	else
		_toSwitch = true;
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
	
	if (m_inGameSaveBouton.isClicked())
	{
		m_inGameSaveBouton.useClickAction();
	}

	if (m_inGameLeaveBouton.isClicked())
	{
		m_inGameLeaveBouton.useClickAction();
	}
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
		if (isSaveMenuOpen)
		{
			m_saveMenu.Draw(_window);
		}
	}
}
