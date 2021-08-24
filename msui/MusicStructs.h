#pragma once

#include <vector>
#include "SampleBoard.h"

struct Track {
	Track();
	float duration;

	std::vector<int>* notes;
	std::vector<float>* times;

	void addHit(int note, float time);
};


class TrackPlayer {
public:
	TrackPlayer(SampleBoard*);
	void addTrack(Track*);
	void tick(float time);
private:
	std::vector<Track*>* tracks;
	std::vector<float>* start_times;
	SampleBoard* sample_board;
	float time_last_updated;
};


Track* make_example_track();