#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "MusicStructs.h"

class TabReader
{
public:
	TabReader();

	void readFile();
	void readConsoleInput(); 

	Track* getTrack(); //get track most recently loaded
	Track* getTrack(int); //get track at position

private:
	void string_to_track(std::vector<std::string>);
	int read_line(std::string, float, Track*);
	int note_to_int(std::string);

	std::vector<Track*> tracks;
};

