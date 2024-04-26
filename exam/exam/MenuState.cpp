#include "MenuState.h"
#include "StateManager.h"

MenuState::MenuState()
{
	m_player = new Player();
}

MenuState::MenuState(Player& _player)
{
	m_backgroundTexture.loadFromFile("../Files/Textures/fond.png");
	m_background.setTexture(m_backgroundTexture);
	m_background.setPosition(0, 0);

	m_player = &_player;

	m_playBouton = Bouton({ 860, 230 }, { 200, 80 }, "Jouer");
	m_optBouton = Bouton({ 860, 450 }, { 200, 80 }, "Options");
	m_leaveBouton = Bouton({ 860, 670 }, { 200, 80 }, "Quitter");

	auto loadBoutonAction = [this]() 
		{
			if (m_playBouton.timer > 1.f) 
			{ 
				m_playBouton.timer = 0;
				m_player->loadTeam();  
				StateManager::ChangeState(GAME_STATE); 
			}
		};
	auto newGameBoutonAction = [this]() 
		{
			if (m_optBouton.timer > 1.f) 
			{ 
				m_optBouton.timer = 0; 
				/*
					DOIT CHOISIR UN STARTER ICI
				*/
				StateManager::ChangeState(NEW_GAME_STATE); 
			}
		};
	
	
	m_playBouton.setOnClick([this, loadBoutonAction, newGameBoutonAction]()
		{
			if (m_playBouton.timer > 1.f)
			{
				m_playBouton.timer = 0;
				m_playBouton.setString("Reprendre");
				m_playBouton.setOnClick(loadBoutonAction);
				m_optBouton.setString("Nouveau");
				m_optBouton.setOnClick(newGameBoutonAction);
			}
		});

	m_optBouton.setOnClick([this]() 
		{ 
			if (m_optBouton.timer > 1.f) 
			{ 
				std::cout << "Options" << std::endl; 
				m_optBouton.timer = 0;
			}
		});
}

void MenuState::Update(const sf::Vector2f _mousePos)
{
	m_playBouton.Update(_mousePos);
	m_optBouton.Update(_mousePos);
	m_leaveBouton.Update(_mousePos);

	if(m_playBouton.checkClick()) {}
	else if (m_optBouton.checkClick()) {}
	else if (m_leaveBouton.checkClick()) {}



	//if (m_playBouton.isClicked())
	//{
	//	m_playBouton.useClickAction();
	//}
	//
	//if (m_optBouton.isClicked())
	//{
	//	m_optBouton.useClickAction();
	//}
	//
	//if (m_leaveBouton.isClicked())
	//{
	//	exit(0);
	//}
}

void MenuState::Draw(sf::RenderWindow& _window)
{
	_window.draw(m_background);

	m_playBouton.Draw(_window);
	m_optBouton.Draw(_window);
	m_leaveBouton.Draw(_window);
}

void MenuState::HandleKeyboard(sf::Event _event)
{
}