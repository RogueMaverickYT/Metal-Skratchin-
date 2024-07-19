#ifndef __BLOCKMAP_H
#define __BLOCKMAP_H

#include "Block.h"
#include <vector>
#include "AudioManager.h"
using namespace SDLFramework;

class BlockMap :public GameEntity
{
protected:

	AudioManager* mAudio;

	std::vector <Block*> mMap;

	int Rows;
	int Columns;

public:
	BlockMap();
	~BlockMap();

	void Render() override;

	void Update() override;



};

#endif