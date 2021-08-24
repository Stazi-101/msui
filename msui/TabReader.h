#pragma once

#include "MusicStructs.h"

class TabReader
{
public:
	TabReader();

	void readFile();
	void readConsoleInput(); 

	Track* getTrack();
};

