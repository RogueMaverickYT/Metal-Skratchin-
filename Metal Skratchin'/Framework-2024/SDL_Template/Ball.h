#ifndef __BALL_h
#define __BALL_h



#include "PhysEntity.h"
#include "AnimatedGLTexture.h"
#include "Player.h"
#include "BoxCollider.h"
#include "PhysicsManager.h"
#include <iostream>
#include "AudioManager.h"
using std::cout;


using namespace SDLFramework;
class Ball :public PhysEntity {

private:
	Timer* mTimer;
	AudioManager* mAudio;
	AnimatedGLTexture* mBallAnimated;
	GLTexture* mBall;
	float mBallSpeed;
	Vector2 mBallBoundsX;
	Vector2 mBallBoundsY;
	Vector2 mBallDir;
	float mBallCollisionEventCooldown;
	int mLives;
	bool mBallServe;

	
public:
	Ball();
	~Ball();
	void Hit(PhysEntity * other)override;
	bool IgnoreCollisions() override;

	int GetLives() {return mLives;}

	void SetLives() { mLives = 3; }

	bool GetBallServe() {return mBallServe;}

	void SetBallServe(bool change) {mBallServe = change;}

	void Update();
		


	void Render();

private:
	void HandleMovement();


};





#endif // !__BALL_h