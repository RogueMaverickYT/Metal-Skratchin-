#include "BlockMap.h"



BlockMap::BlockMap() {

	mAudio = AudioManager::Instance();

	Rows = 12;
	Columns = 18;
	int xOffset = -375;
	int yOffset = -300;




	for (int i = 0; i < Rows; i++) {

		for (int j = 0; j < Columns; j++) {
			
			int colour = 0;

			if (j == 0 || j == 1) {
				colour = 3;
			}

			else if (j == 2 || j == 3) {
				colour = 2;
			}

			else if (j == 4 || j == 5) {
				colour = 1;
			}

			else {
				colour = 0;
			}




			mMap.push_back(new Block(colour));
			mMap.back()->Parent(this);
			mMap.back()->Position(xOffset+ 45*(i%Rows), yOffset+ 15*(j%Columns));
		}
	}
}


BlockMap::~BlockMap() {




}

void BlockMap::Render() {



	for (Block* b : mMap) {

		b->Render();
	}
}

void BlockMap::Update() {

	for (int i = mMap.size() - 1; i >= 0; --i) {

		if (mMap[i]->IsDead()) {

			delete mMap[i];
			mMap[i] = nullptr;

			mMap.erase(mMap.begin() + i);
			mAudio->PlaySFX("SFX/Break.wav", 0, -1);
		}
	}
}