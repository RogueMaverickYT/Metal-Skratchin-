#include "PlayScreen.h"
#include "AssetManager.h"
#include "StartScreen.h"
#include "Texture.h"

PlayScreen::PlayScreen() {

	mTimer = Timer::Instance();
	mAudio = AudioManager::Instance();
	mInput = InputManager::Instance();

	mSideBar = new PlaySideBar();
	mSideBar->Parent(this);
	mSideBar->Position(Graphics::SCREEN_WIDTH * 0.87f, Graphics::SCREEN_HEIGHT * 0.05f);
	mBackTexture = new GLTexture("firebrim.jpg", 0, 0, 4961, 3508);
	mBackTexture->Parent(this);
	mBackTexture->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mPlayer = nullptr;
	mBall = nullptr;

	mBlockMap = nullptr;
	
}


PlayScreen::~PlayScreen() { 
	delete mSideBar;
	mSideBar = nullptr;

	mTimer = nullptr; 
	mAudio = nullptr; 
	mInput = nullptr;
	
	delete mBackTexture;
	mBackTexture = nullptr;

	delete mPlayer;

	mPlayer = nullptr;

	delete mBall;
	mBall = nullptr;
} 

void PlayScreen::Update() { 
	
	mSideBar->Update(); 
	mPlayer->Update();
	mBall->Update();
	mBlockMap->Update();

	if (mInput->KeyPressed(SDL_SCANCODE_SPACE) && mBall->GetBallServe()==false) {

		ServeBall();

	}

	if (mBall->GetBallServe() == false && mBall->GetLives() >= 0) {

		ResetBall();

	}

	std::cout << mBall->Position().x << ", " << mBall->Position().y << std::endl;

} 

void PlayScreen::Render() {
	mBackTexture->Render();
	mSideBar->Render(); 
	mBall->Render();
	mPlayer->Render();
	mBlockMap->Render();

}

void PlayScreen::StartNewGame() { 
	StartNextLevel();

	delete mPlayer;
	mPlayer = new Player();
	mPlayer->Parent(this);
	mPlayer->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.9f);

	delete mBall;
	mBall = new Ball();
	mBall->Parent(mPlayer);
	mBall->Position(0.0f, -25.0f);
	mBall->SetLives();

	delete mBlockMap;
	mBlockMap = new BlockMap();
	mBlockMap->Parent(this);
	mBlockMap->Position(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.5f);

	mSideBar->SetHighScore(30000);
	mSideBar->SetShips(mBall->GetLives());

}

void PlayScreen::StartNextLevel() { 
	
	mSideBar->SetLevel(1); 

}

void PlayScreen::ServeBall() {

	mBall->Parent(NULL);
	mBall->SetBallServe(true);

}

void PlayScreen::ResetBall() {

	mBall->Parent(mPlayer);
	mBall->Position(0.0f, -25.0f);
	mSideBar->SetShips(mBall->GetLives());

}