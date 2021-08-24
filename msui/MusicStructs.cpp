#include "MusicStructs.h"

#include <iostream>
//struct Track {
//	Track();
//	float duration;
//
//	std::vector<int>* notes;
//	std::vector<float>* times;
//
//	void addHit(int note, float time);
//};
//
//
//class TrackPlayer {
//public:
//	TrackPlayer(SampleBoard*);
//	void addTrack(Track*);
//	void tick(float time);
//private:
//	std::vector<Track*>* tracks;
//	std::vector<float>* start_times;
//	SampleBoard* sample_board;
//	float time_last_updated;
//};



Track::Track() {
	duration = 0;
	notes = new std::vector<int>;
	times = new std::vector<float>; //These times are relative to 'start_time'
}


void Track::addHit(int note, float time) {

	float last_end_time = 0;
	if (times->size() > 0) { last_end_time = times->back(); }
	
	notes->push_back(note);
	times->push_back(time);
	if (time > duration) { duration = time; }
}


TrackPlayer::TrackPlayer(SampleBoard* given_sample_board) {
	sample_board = given_sample_board;
	tracks = new std::vector<Track*>;
	start_times = new std::vector<float>;
	time_last_updated = 0;
}

void TrackPlayer::addTrack(Track* new_track) {
	//Added track will have a start time at the end of the last track in the queue. If there is no last track, or if it has already finished,
	//new start time will be 1 ms after the trackplayer was last updated (so immediately)
	float last_end_time;
	if (tracks->size() > 0) {
		last_end_time = start_times->back() + tracks->back()->duration;
	}
	else {
		last_end_time = 0;
	}
	tracks->push_back(new_track);

	if (last_end_time > time_last_updated) {
		start_times->push_back(last_end_time);
	}
	else {
		start_times->push_back(time_last_updated+0.001);
	}
}

void TrackPlayer::tick(float time) {
	std::vector<Track*>::iterator track_it = tracks->begin();
	std::vector<float>::iterator time_it = start_times->begin();

	for (int i = 0; i < tracks->size(); i++) {
		Track* track = *track_it;
		float start_time = *time_it;

		//If current time is within track time
		if (start_time < time < start_time + track->duration) {

			//Find a hit that should have been played but hasn't been
			std::vector<int>::iterator note_it = track->notes->begin();
			for (float hit_time : *track->times) {

				//std::cout << time_last_updated << ' ' << hit_time << ' ' << time << '\n';

				if (time_last_updated <= hit_time && hit_time < time) {
					
					sample_board->playSound(*note_it);
					std::cout << *note_it << " played\n";

					
				}
				++note_it;
			}
		}
		
		++track_it;
		++time_it;
	}

	time_last_updated = time;
	
}


Track* make_example_track() {
	Track* new_track = new Track();

	for (int i = 0; i < 10; i++) {
		new_track->addHit(50+i, i);
	}
	return new_track;
}