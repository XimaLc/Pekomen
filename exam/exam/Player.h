#pragma once
#include "Entity.h"
#include "Team.h"

enum DIRECTIONS { down, left, right, up };

class Player : public Entity
{
	sf::Vector2i position;

	Team* m_playerTeam;

	int animState;
	int dir;

public:
	inline sf::Vector2i getPosition() { return position; }
	inline void setPosition(sf::Vector2i _position) { position = _position; }

	virtual void Draw(sf::RenderWindow& window);
	virtual void Update();

	void move(int x, int y);
	void anim(int x, int y);

	inline Team* getTeam() { return m_playerTeam; }
	inline void loadTeam() { m_playerTeam->load(); }
	//void savePos(std::string _name);
	//void loadPos(std::string _name);

	Player(std::string _name, sf::Texture& _texture);
	Player();

	~Player();
};

