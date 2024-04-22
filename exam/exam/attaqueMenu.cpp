#include "AttaqueMenu.h"

AttaqueMenu::AttaqueMenu()
{
}

AttaqueMenu::AttaqueMenu(Pokemon _pokemon, int type)
{
	m_isOpen = false;

	m_pokemon = _pokemon;

	m_move1Bouton = Bouton({ 1500, 830 }, { 200, 100 }, m_pokemon.getMoves()[0].getName());
	m_move2Bouton = Bouton({ 1500, 930 }, { 200, 100 }, m_pokemon.getMoves()[1].getName());
	m_move3Bouton = Bouton({ 1700, 830 }, { 200, 100 }, m_pokemon.getMoves()[2].getName());
	m_move4Bouton = Bouton({ 1700, 930 }, { 200, 100 }, m_pokemon.getMoves()[3].getName());
	m_retourBouton = Bouton({ 1400, 930 }, { 100, 100 }, "Back");

	auto retourBoutonAction = [this]() {if (m_retourBouton.timer > 0.5) { m_retourBouton.timer = 0; m_isOpen = false; }};
	m_retourBouton.setOnClick(retourBoutonAction);

	auto attaqueActionBouton1 = [this]() {if (m_move1Bouton.timer > 0.5) { m_move1Bouton.timer = 0;}};
	auto attaqueActionBouton2 = [this]() {if (m_move2Bouton.timer > 0.5) { m_move2Bouton.timer = 0;}};
	auto attaqueActionBouton3 = [this]() {if (m_move3Bouton.timer > 0.5) { m_move3Bouton.timer = 0;}};
	auto attaqueActionBouton4 = [this]() {if (m_move4Bouton.timer > 0.5) { m_move4Bouton.timer = 0;}};
}																												

void AttaqueMenu::Update(sf::Vector2f _mousePos)
{
	m_move1Bouton.Update(_mousePos);
	m_move2Bouton.Update(_mousePos);
	m_move3Bouton.Update(_mousePos);
	m_move4Bouton.Update(_mousePos);
	m_retourBouton.Update(_mousePos);

	if (m_retourBouton.isClicked())
		m_retourBouton.useClickAction();
}

void AttaqueMenu::Draw(sf::RenderWindow& _window)
{
	m_move1Bouton.Draw(_window);
	m_move2Bouton.Draw(_window);
	m_move3Bouton.Draw(_window);
	m_move4Bouton.Draw(_window);
	m_retourBouton.Draw(_window);
}
