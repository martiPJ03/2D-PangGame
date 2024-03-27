#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include "Bubble.h"
#include "Game.h"

#define JUMP_ANGLE_STEP 2
#define JUMP_HEIGHT 150
#define FALL_STEP 2

enum BubbleAnims
{
	GRAN48, MITJA32, PETITA16, ENANA8
};

void Bubble::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram, int anim, float vel)
{
	spritesheet.loadFromFile("images/Bubble.png", TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(64, 64), glm::vec2(0.5f, 0.5f), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(4);

	sprite->setAnimationSpeed(GRAN48, 1);
	sprite->addKeyframe(GRAN48, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(MITJA32, 1);
	sprite->addKeyframe(MITJA32, glm::vec2(0.5f, 0.f));

	sprite->setAnimationSpeed(PETITA16, 1);
	sprite->addKeyframe(PETITA16, glm::vec2(0.f, 0.5f));

	sprite->setAnimationSpeed(ENANA8, 1);
	sprite->addKeyframe(ENANA8, glm::vec2(0.5f, 0.5f));

	sprite->changeAnimation(anim);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posBubble.x), float(tileMapDispl.y + posBubble.y)));
	velocity = vel;
	canJump = true;
	startY = 130;
	direccio = 2;
	jumpAngle = 50;
	freeze = false;

}

void Bubble::update(int deltaTime)
{

	if (!freeze) {
		if (sprite->animation() == GRAN48)
		{

			direccio = map->circleCollisionWithMap(posBubble.x + 32, posBubble.y + 32, 24);

			if (direccio == 0) {
				velocity = -(velocity);
				posBubble.x -= 4;
				//cout << "right" << endl;
			}
			else if (direccio == 1) {
				velocity = -(velocity);
				posBubble.x += 4;
				//cout << "left" << endl;
			}
			else if (direccio == 2)
			{
				canJump = true;

				startY = posBubble.y;
				posBubble.y -= 4;
				jumpAngle = 0;
				//cout << "bot" << endl;
			}
			else if (direccio == 3) {
				canJump = false;
				posBubble.y += 4;
				//cout << "top" << endl;

			}


			posBubble.x += velocity;

			if (canJump) {
				jumpAngle += 1.5;
				if (jumpAngle == 180)
				{
					posBubble.y = startY;
				}
				else
				{
					posBubble.y = int(startY - 130 * sin(3.14159f * jumpAngle / 180.f));
				}
			}

			else
			{

				posBubble.y += 4;
			}
		}

		if (sprite->animation() == MITJA32)
		{
			//cout << jumpAngle  << " " << startY << endl;
			direccio = map->circleCollisionWithMap(posBubble.x + 32, posBubble.y + 32, 16);

			if (direccio == 0) {
				velocity = -(velocity);
				posBubble.x -= 2;
				//cout << "right" << endl;
			}
			else if (direccio == 1) {
				velocity = -(velocity);
				posBubble.x += 2;
				//cout << "left" << endl;
			}
			else if (direccio == 2)
			{
				canJump = true;
				startY = posBubble.y;
				posBubble.y -= 2;
				jumpAngle = 0;
				//cout << "bot" << endl;



			}
			else if (direccio == 3) {
				canJump = false;
				posBubble.y += 2;
				//cout << "top" << endl;

			}
			posBubble.x += velocity;

			if (canJump) {
				jumpAngle += 2;
				if (jumpAngle >= 90 && startY < 130) canJump = false;
				if (jumpAngle == 180)
				{
					posBubble.y = startY;
				}
				else
				{
					posBubble.y = int(startY - (100 * startY / 150) * sin(3.14159f * jumpAngle * 150 / startY / 180.f));
				}
			}

			else
			{

				posBubble.y += 3;

			}
		}

		if (sprite->animation() == PETITA16)
		{

			direccio = map->circleCollisionWithMap(posBubble.x + 32, posBubble.y + 32, 9);

			if (direccio == 0) {
				velocity = -(velocity);
				posBubble.x -= 2;
				//cout << "right" << endl;
			}
			else if (direccio == 1) {
				velocity = -(velocity);
				posBubble.x += 2;
				//cout << "left" << endl;
			}
			else if (direccio == 2)
			{
				canJump = true;

				startY = posBubble.y;
				posBubble.y -= 2;
				jumpAngle = 0;
				//cout << "bot" << endl;
			}
			else if (direccio == 3) {
				canJump = false;
				posBubble.y += 2;
				//cout << "top" << endl;

			}


			posBubble.x += velocity;

			if (canJump) {
				jumpAngle += 2.5;
				if (jumpAngle == 180)
				{
					posBubble.y = startY;
				}
				else
				{
					posBubble.y = int(startY - 70 * sin(3.14159f * jumpAngle / 180.f));
				}
			}

			else
			{

				posBubble.y += 2;
			}
		}

		if (sprite->animation() == ENANA8)
		{



			direccio = map->circleCollisionWithMap(posBubble.x + 32, posBubble.y + 32, 5);

			if (direccio == 0) {
				velocity = -(velocity);
				posBubble.x -= 2;
				//cout << "right" << endl;
			}
			else if (direccio == 1) {
				velocity = -(velocity);
				posBubble.x += 2;
				//cout << "left" << endl;
			}
			else if (direccio == 2)
			{
				canJump = true;

				startY = posBubble.y;
				posBubble.y -= 2;
				jumpAngle = 0;
				//cout << "bot" << endl;
			}
			else if (direccio == 3) {
				canJump = false;
				posBubble.y += 2;
				//cout << "top" << endl;

			}

			posBubble.x += velocity;

			if (canJump) {
				jumpAngle += 3.f;
				if (jumpAngle == 180)
				{
					posBubble.y = startY;
				}
				else
				{
					posBubble.y = int(startY - 50 * sin(3.14159f * jumpAngle / 180.f));
				}
			}
			else
			{
				posBubble.y += 2;
			}
		}
	}
	
	sprite->update(deltaTime);
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posBubble.x), float(tileMapDispl.y + posBubble.y)));

}

void Bubble::render()
{
	sprite->render();
}

void Bubble::setTileMap(TileMap* tileMap)
{
	map = tileMap;
}

void Bubble::setPosition(const glm::vec2& pos)
{
	posBubble = pos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posBubble.x), float(tileMapDispl.y + posBubble.y)));
}

glm::ivec2 Bubble::getPosition() 
{
	return posBubble;
}

int Bubble::getSize() 
{
	if (sprite->animation() == GRAN48) return 0;
	if (sprite->animation() == MITJA32) return 1;
	if (sprite->animation() == PETITA16) return 2;
	if (sprite->animation() == ENANA8) return 3;
}

float Bubble::getVelocity() {
	return velocity;
}

bool Bubble::collisionWithBullet(const glm::ivec2& posBullet, int heightBullet, int widthBullet) 
{
	int x0 = posBullet.x + 24 - widthBullet;
	int x1 = posBullet.x + 24 + widthBullet;
	int r;
	switch (getSize())
	{
	case 0:  r = 26; break;
	case 1:  r = 18; break;
	case 3:  r = 10; break;
	default: r =  6; break;
	}

	glm::ivec2 bCenter = glm::ivec2(posBubble.x + 32, posBubble.y + 32);

	//cout << "->" << posBullet.y - heightBullet << " (" << bCenter.x << " " << bCenter.y << ") " << r << endl;
	for (int i = 0; i < heightBullet + 32; ++i) 
	{
		float distX0 = abs(x0 - bCenter.x);
		float distX1 = abs(x0 - bCenter.x);
		float distY  = abs((posBullet.y - i + 32) - bCenter.y);

		float dist2center0 = sqrt((distX0 * distX0) + (distY * distY));
		float dist2center1 = sqrt((distX1 * distX1) + (distY * distY));

		if (dist2center0 < r) return true;
		if (dist2center1 < r) return true;
	}
	for (int i = x0; i < x1+1; ++i)
	{
		float distX = abs((x0 + i) - bCenter.x);
		float distY = abs((posBullet.y + heightBullet) - bCenter.y);
		float dist2center = sqrt((distX * distX) + (distY * distY));
		if (dist2center < r) return true;
	}
	return false;


}

bool Bubble::collisionWithPlayer(const glm::ivec2& posPlayer, int heightPlayer, int widthPlayer)
{
	int r;
	switch (getSize())
	{
	case 0:  r = 22; break;
	case 1:  r = 14; break;
	case 3:  r = 6; break;
	default: r = 2; break;
	}

	for (int i = 0; i < heightPlayer; ++i)
	{
		// temporary variables to set edges for testing
		float testX = posBubble.x+32;
		float testY = posBubble.y+32;

		// which edge is closest?
		if (posBubble.x + 32 < posPlayer.x)         testX = posPlayer.x;      // test left edge
		else if (posBubble.x + 32 > posPlayer.x + widthPlayer) testX = posPlayer.x + widthPlayer;   // right edge
		if (posBubble.y + 32 < posPlayer.y)         testY = posPlayer.y;      // top edge
		else if (posBubble.y + 32 > posPlayer.y + heightPlayer) testY = posPlayer.y + heightPlayer;   // bottom edge

		// get distance from closest edges
		float distX = posBubble.x + 32 - testX;
		float distY = posBubble.y + 32 - testY;
		float distance = sqrt((distX * distX) + (distY * distY));

		// if the distance is less than the radius, collision!
		if (distance <= r) {
			return true;
		}
		return false;
	}
	return false;

}