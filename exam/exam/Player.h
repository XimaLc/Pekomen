#pragma once
#include "Entity.h"
#include "Team.h"


enum STARTER_TYPE { PLANTE = 1, FEU = 4, EAU = 7 };

class Player : public Entity
{
	Team* m_playerTeam;

public:
	inline sf::Vector2i getPosition() { return position; }
	inline void setPosition(sf::Vector2i _position) { position = _position; }

	virtual void Draw(sf::RenderWindow& window);
	virtual void Update();

	void addStarter(int _type);

	inline Team* getTeam() { return m_playerTeam; }
	inline void loadTeam() { m_playerTeam->load(); }
	//void savePos(std::string _name);
	//void loadPos(std::string _name);

	Player(std::string _name, sf::Texture& _texture);
	Player();

	~Player();
};

