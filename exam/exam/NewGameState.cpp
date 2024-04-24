#include "NewGameState.h"
#include "DB.h"
#include "StateManager.h"
NewGameState::NewGameState()
{
	m_player = new Player;
}

NewGameState::NewGameState(Player& _player)
{
	m_player = &_player;
	m_backgroundTexture.loadFromFile("../Files/Textures/fond.png");
	m_background.setTexture(m_backgroundTexture);

	font.loadFromFile("../Files/Fonts/Pokemon.ttf"); 

	m_starterPlanteBouton = Bouton({ 180, 500 }, { 400, 400 }, DB::getPathByID(1),POKEMON_PATH);
	m_starterFeuBouton = Bouton({ 760, 500 }, { 400, 400 }, DB::getPathByID(4), POKEMON_PATH);
	m_starterEauBouton = Bouton({ 1320, 500 }, { 400, 400 }, DB::getPathByID(7),POKEMON_PATH);

	m_starterEauBouton.setOnClick([this]()
		{
			if (m_starterEauBouton.timer > 0.5f)
			{
				m_player->addStarter(EAU);
				StateManager::ChangeState(GAME_STATE);
			}
		});
	
	m_starterFeuBouton.setOnClick([this]()
		{
			if (m_starterEauBouton.timer > 0.5f)
			{
				m_player->addStarter(FEU);
				StateManager::ChangeState(GAME_STATE);
			}
		});
	
	m_starterPlanteBouton.setOnClick([this]()
		{
			if (m_starterEauBouton.timer > 0.5f)
			{
				m_player->addStarter(PLANTE);
				StateManager::ChangeState(GAME_STATE);
			}
		});

	text.setString("Choisis ton premier pokemon");
	text.setCharacterSize(70);
	text.setFillColor(sf::Color::Black);
	text.setPosition({400, 200});
}

void NewGameState::Update(sf::Vector2f _mousePos) 
{
	m_starterPlanteBouton.Update(_mousePos);
	m_starterFeuBouton.Update(_mousePos); 
	m_starterEauBouton.Update(_mousePos); 

	if (m_starterEauBouton.isClicked())
		m_starterEauBouton.useClickAction();
	else if (m_starterFeuBouton.isClicked())
		m_starterFeuBouton.useClickAction();
	else if (m_starterPlanteBouton.isClicked())
		m_starterPlanteBouton.useClickAction();
}

void NewGameState::Draw(sf::RenderWindow& _window)
{
	_window.draw(m_background);
	text.setFont(font);
	_window.draw(text);
	m_starterPlanteBouton.Draw(_window);
	m_starterFeuBouton.Draw(_window);
	m_starterEauBouton.Draw(_window);
}

void NewGameState::HandleKeyboard(sf::Event _event)
{
}
