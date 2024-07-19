#include "Block.h"
#include "PhysicsManager.h"
#include "BoxCollider.h"

Block::Block() {

}

Block::Block(int colour):
mBox(static_cast <BlockType> (colour))

{

	RedBox = new GLTexture("RedBox.png", 0, 0, 45, 15);
	YellowBox = new GLTexture("YellowBox.png", 0, 0, 45, 15);
	BlueBox = new GLTexture("BlueBox.png", 0, 0, 45, 15);
	GreenBox = new GLTexture("GreenBox.png", 0, 0, 45, 15);

	RedPoints = 1;
	YellowPoints = 2;
	BluePoints = 3;
	GreenPoints = 4;
	
	mIsDead = false;

	switch (mBox) {
	case RED:
		CurrentTexture = RedBox;
		mPoints = RedPoints;
		break;

	case YELLOW:
		CurrentTexture = YellowBox;
		mPoints = YellowPoints;
		break;

	case BLUE:
		CurrentTexture = BlueBox;
		mPoints = BluePoints;
		break;

	case GREEN:
		CurrentTexture = GreenBox;
		mPoints = GreenPoints;
		break;

	}

	CurrentTexture->Parent(this);

	CurrentTexture->Position(0, 0);

	AddCollider(new BoxCollider(CurrentTexture->ScaledDimensions()));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Block);
	Tag("Block");
}

Block::~Block(){

	delete RedBox;
	RedBox = nullptr;
	delete YellowBox;
	YellowBox = nullptr;
	delete BlueBox;
	BlueBox = nullptr;
	delete GreenBox;
	GreenBox = nullptr;

	PhysicsManager::Instance()->UnregisterEntity(mId);

}

void Block::Hit(PhysEntity* other){

	mIsDead = true;

}

void Block::Render(){

	CurrentTexture->Render();
	//PhysEntity::Render();

}


void Block::Update(){}

bool Block::IgnoreCollisions() {

	return false;

}

void Block::IsDead(bool isdead) {

	mIsDead = isdead;

}

bool Block::IsDead() {

	return mIsDead;

}