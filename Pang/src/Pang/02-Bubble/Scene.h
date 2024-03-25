#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"
#include "Bullet.h"
#include "Bubble.h"
#include "Background.h"
#include "Interface.h"


// Scene contains all the entities of our game.
// It is responsible for updating and render them.


class Scene
{

public:
	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();

private:
	void initShaders();

private:
	Background* bg;
	TileMap *map;
	Player *player;
	Bullet *bullet;
	Bubble *bubble;
	vector<Bubble*> bubbles;
	ShaderProgram texProgram;
	Interface *timeDisp;
	float currentTime;
	glm::mat4 projection;
	int f;
	int t;
	int idLevel;
};


#endif // _SCENE_INCLUDE

