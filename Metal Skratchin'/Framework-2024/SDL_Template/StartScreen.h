#ifndef __STARTSCREEN_H 
#define __STARTSCREEN_H 

#include "AnimatedGLTexture.h" 
#include "InputManager.h" 
#include "Scoreboard.h"
#include "AudioManager.h"

using namespace SDLFramework; 

class StartScreen : public GameEntity { 
private: 
	Timer * mTimer; 
	InputManager * mInputManager;
	AudioManager* mAudio;

	// Top Bar Entities 
	GameEntity * mTopBar; 
	GLTexture * mPlayerOne; 
	GLTexture * mPlayerTwo; 
	GLTexture * mHiScore;

	Scoreboard* mPlayerOneScore; 
	Scoreboard* mPlayerTwoScore; 
	Scoreboard* mTopScore;

	// Logo Entities 
	GLTexture * mLogo;
	AnimatedGLTexture* mAnimatedLogo;

	// Play Mode Entities 
	GameEntity * mPlayModes; 
	GLTexture * mOnePlayerMode; 
	GLTexture * mTwoPlayerMode; 
	GLTexture * mCursor;

	Vector2 mCursorStartPos; 
	Vector2 mCursorOffset; 
	int mSelectedMode;

	// Bottom Bar Entities 
	GameEntity * mBottomBar; 
	GLTexture * mNamco; 
	GLTexture * mDates; 
	GLTexture * mRights;

	// Screen Animation Variables 
	Vector2 mAnimationStartPos; 
	Vector2 mAnimationEndPos; 
	float mAnimationTotalTime; 
	float mAnimationTimer; 
	bool mAnimationDone;

public: 
	StartScreen(); 
	~StartScreen(); 

	void ResetAnimation(); 
	int SelectedMode();

	void ChangeSelectedMode(int change);

	void Update() override; 
	void Render() override;
};

#endif