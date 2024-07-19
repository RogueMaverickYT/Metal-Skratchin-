#ifndef __PLAYSCREEN_H 
#define __PLAYSCREEN_H 

#include "AudioManager.h" 
#include "PlaySideBar.h"
#include "Player.h"
#include "Ball.h"
#include "BlockMap.h"
#include "GLTexture.h"
#include "InputManager.h"

class PlayScreen : public GameEntity { 
private: 

	Timer * mTimer; 
	AudioManager * mAudio; 
	InputManager* mInput;

	PlaySideBar* mSideBar;

	GLTexture* mBackTexture;
	Ball* mBall;
	Player* mPlayer;
	BlockMap* mBlockMap;

public: 
	PlayScreen(); 
	~PlayScreen(); 

	void ServeBall();

	void ResetBall();

	void StartNewGame();
	
	void Update() override; 
	void Render() override; 

	int GetLives() {

		return mBall->GetLives();

	}

private:
	void StartNextLevel();
}; 

#endif
