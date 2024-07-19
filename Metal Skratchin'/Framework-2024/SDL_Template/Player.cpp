#include "Player.h"

void Player::HandleMovement() {
	//if (mInput->KeyDown(SDL_SCANCODE_RIGHT)) {
	//	Translate(Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
	//}
	//else if (mInput->KeyDown(SDL_SCANCODE_LEFT)) {
	//	Translate(-Vec2_Right * mMoveSpeed * mTimer->DeltaTime(), World);
	//}

    Position(Vector2(mInput->MousePosition().x, Position(Local).y));
	

	Vector2 pos = Position(Local);
	if (pos.x < mMoveBounds.x) {
		pos.x = mMoveBounds.x;
	}
	else if (pos.x > mMoveBounds.y) {
		pos.x = mMoveBounds.y;
	}

	if (mInput->MousePosition().x > (Graphics::SCREEN_WIDTH * 0.765f) - 60)
	{
		pos.x = (Graphics::SCREEN_WIDTH * 0.765f) - 60;
	}
	else if (mInput->MousePosition().x < 60)
	{
		pos.x = 60;
	}

	Position(pos);
}

Player::Player() {
	mTimer = Timer::Instance();
	mInput = InputManager::Instance();
	mAudio = AudioManager::Instance();

	mVisible = true;
	mAnimating = false;
	mWasHit = false;

	mScore = 0;
	mLives = 2;
	mShip = new GLTexture("HellPaddle.png", 0, 0, 125, 25);
	mShip->Parent(this);
	mShip->Position(Vec2_Zero);

	mMoveSpeed = 300.0f;
	mMoveBounds = Vector2(0.0f, Graphics::SCREEN_WIDTH * 0.765f);  

	mDeathAnimation = new AnimatedGLTexture("PlayerExplosion.png", 0, 0, 128, 128, 4, 1.0f, Animation::Layouts::Horizontal);
	mDeathAnimation->Parent(this);
	mDeathAnimation->Position(Vec2_Zero);
	mDeathAnimation->SetWrapMode(Animation::WrapModes::Once);

	AddCollider(new BoxCollider(Vector2(120.0f, 25.0f)));

	mId = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Paddle);
}

Player::~Player() {
	mTimer = nullptr;
	mInput = nullptr;
	mAudio = nullptr;

	delete mShip;
	mShip = nullptr;

	delete mDeathAnimation;
	mDeathAnimation = nullptr;

}

void Player::Visible(bool visible) {
	mVisible = visible;
}

bool Player::IsAnimating() {
	return mAnimating;
}

int Player::Score() {
	return mScore;
}

int Player::Lives() {
	return mLives;
}

void Player::AddScore(int change) {
	mScore += change;
}

bool Player::IgnoreCollisions()
{
	return !mVisible || mAnimating;
}

void Player::Hit(PhysEntity* other) {
	
}

bool Player::WasHit() {
	return mWasHit;
}

void Player::Update() {

	mAudio = AudioManager::Instance();

	if (mAnimating) {

		if (mWasHit) {
			mWasHit = false;

			

		}

		mDeathAnimation->Update();
		mAnimating = mDeathAnimation->IsAnimating();
		mAudio->PlaySFX("SFX/Rebound.wav", 0, -1);

		

	}
	else {
		if (Active()) {
			HandleMovement();

		}
	}
}

void Player::Render() {
	if (mVisible) {
		if (mAnimating) {
			mDeathAnimation->Render();
		}
		else {
			mShip->Render();
		}
	}

	//PhysEntity::Render();
}