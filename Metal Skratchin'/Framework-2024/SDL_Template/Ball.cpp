#include "Ball.h"
#include "Player.h"




Ball::Ball() {
	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mLives = 3;
	mBallServe = false;


	mBallAnimated = new AnimatedGLTexture("HellBall.png", 0, 0, 15, 15, 1, 1, Animation::Layouts::Horizontal);
	mBall = new GLTexture("HellBall.png",0 ,0 ,15, 15);

	mBallAnimated->Parent(this);
	mBall->Parent(this);
	mBall->Position(0,0);

	mBallSpeed = 300.0f;
	mBallBoundsX = Vector2(0, Graphics::SCREEN_WIDTH * 0.765f);
	mBallBoundsY = Vector2(0, Graphics::SCREEN_HEIGHT);
	mBallDir = Vector2(1, -1);
	mBallCollisionEventCooldown = 0;

	AddCollider(new BoxCollider(Vector2(10.0f, 10.0f)));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Ball);
}



Ball:: ~Ball() {
	delete mBall;
	mBall = nullptr;

	delete mBallAnimated;
	mBallAnimated = nullptr;

	mTimer = nullptr;
}

void Ball::Render() {
	mBall->Render();
	//PhysEntity::Render();


}

void Ball::Update() {
	mBall->Update();
	
	if (mBallServe) { 
		
		HandleMovement(); 
	
	}

}

void Ball::Hit(PhysEntity* other) {
	
	mBallDir.y *= -1;
	

	if (other->Tag() == "Block") {



	}

	else {

		mAudio->PlaySFX("SFX/Bounce.wav", 0, -1);

	}

	if (mBallCollisionEventCooldown <= 0)
	{



		mBallCollisionEventCooldown = 20;
	}
	else
	{

	}
}
bool Ball::IgnoreCollisions()
{
	return false;
}

void Ball::HandleMovement() {

	/*Vector2 target = Vec2_One;
	Translate(target * mBallSpeed * mTimer -> DeltaTime(), World);*/
	Vector2 Pos = Position(Local);
	
	
	if (Pos.x < mBallBoundsX.x)
	{
		mBallDir.x = -mBallDir.x;


	}

	else if (Pos.x > mBallBoundsX.y)
	{
		mBallDir.x = -mBallDir.x;

	}

	if (Pos.y < mBallBoundsY.x)
	{
		mBallDir.y = -mBallDir.y;

	}

	else if (Pos.y > mBallBoundsY.y)
	{
		//mBallDir.y = -mBallDir.y;

		mLives = mLives -1;
		mBallServe = false;


	}
	Translate(mBallDir * mBallSpeed * mTimer->DeltaTime(), World);
}
