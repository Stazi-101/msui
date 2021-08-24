#include "SampleBoard.h"

#include <iostream>


SampleBoard::SampleBoard() {

	//note names
	notes = { "A","A#","B","C","C#","D","D#","E","F","F#","G","G#" };
	lowest_note = LOWEST_NOTE;
	highest_note = HIGHEST_NOTE;

	loadSounds();

}

void SampleBoard::loadSounds() {

	//this assumes you have samples in minor thirds (a, c, d#, f#) and fills in notes accordingly
	for (int i = lowest_note; i <= highest_note; i++) {

		int octave = i / 12;
		//In my sample data, A has octave notation weirdly, this corrects for that
		if (i % 12 - i % 3 == 0) { octave -= 1; }
		std::string octave_string = std::to_string(octave);


		std::string pitch = notes[i % 12 - i % 3];//i%12 - i%3 gets the pitch of the nearest sampled note
		std::string path = "C:\\Users\\anast\\Music\\piano_samples\\" + pitch + octave_string + "v2.wav";

		//load sound
		sf::Sound* sound = new sf::Sound();
		sf::SoundBuffer* buffer = new sf::SoundBuffer();
		//Exit if sound not loaded properly
		if (!buffer->loadFromFile(path)) { continue; }
		sound->setBuffer(*buffer);

		//pitch shift the nearest sampled note to get the real note
		switch (i % 3) {
		case 1:
			sound->setPitch(float(1.0595));
			break;
		case 2:
			sound->setPitch(float(1.1225));
			break;
		}

		sounds[i - lowest_note] = sound;
	}
}

void SampleBoard::playSound(int n) {
	
	sounds[n - lowest_note]->play();
}