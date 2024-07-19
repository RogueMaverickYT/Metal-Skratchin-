#ifndef __BLOCK_H
#define __BLOCK_H
#include"PhysEntity.h"
#include"Texture.h"

using namespace SDLFramework;

class Block :public PhysEntity
{
	enum BlockType{RED=0, YELLOW, BLUE, GREEN};

protected:
	bool mIsDead;
	GLTexture *RedBox;
	GLTexture *YellowBox;
	GLTexture *BlueBox;
	GLTexture *GreenBox;
	GLTexture *CurrentTexture;
	int mPoints;
	int RedPoints;
	int YellowPoints;
	int BluePoints;
	int GreenPoints;
	BlockType mBox;

public:
	Block();
	Block(int colour);
	~Block();

	void IsDead(bool isdead);

	bool IsDead();

	bool IgnoreCollisions() override;

	void Hit(PhysEntity* other) override;

	void Render() override;

	void Update() override;



};

#endif // !__ BLOCK_H