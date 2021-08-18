#include "VirtualPiano.h"

#include <iostream>



VirtualPiano::VirtualPiano(sf::Time given_start_time) {
	lowest_note = LOWEST_NOTE;
	highest_note = HIGHEST_NOTE;
	start_time = given_start_time.asSeconds();

	//note names
	notes = { "A","A#","B","C","C#","D","D#","E","F","F#","G","G#" };

	//keys corresponding to notes, written lowest to highest separated by semitones
	keys = {
		sf::Keyboard::Z,
		sf::Keyboard::S,
		sf::Keyboard::X,
		sf::Keyboard::D,
		sf::Keyboard::C,
		sf::Keyboard::V,
		sf::Keyboard::G,
		sf::Keyboard::B,
		sf::Keyboard::H,
		sf::Keyboard::N,
		sf::Keyboard::J,
		sf::Keyboard::M,
		sf::Keyboard::Comma,
		sf::Keyboard::L,
		sf::Keyboard::Period,
		sf::Keyboard::SemiColon,
		sf::Keyboard::Slash,
		sf::Keyboard::Q,
		sf::Keyboard::Num2,
		sf::Keyboard::W,
		sf::Keyboard::Num3,
		sf::Keyboard::E,
		sf::Keyboard::Num4,
		sf::Keyboard::R,
		sf::Keyboard::T,
		sf::Keyboard::Num6,
		sf::Keyboard::Y,
		sf::Keyboard::Num7,
		sf::Keyboard::U,
		sf::Keyboard::I,
		sf::Keyboard::Num9,
		sf::Keyboard::O,
		sf::Keyboard::Num0,
		sf::Keyboard::P,
		sf::Keyboard::Dash,
		sf::Keyboard::LBracket,
		sf::Keyboard::RBracket, };
		

	loadSounds();
}

void VirtualPiano::giveEvent(sf::Event new_event) {


	int i = 0;
	for (int k : keys) {
		if (new_event.key.code == k) {
			playSound(i);
		}

		i++;
	}
	
}

void VirtualPiano::loadSounds() {

	//this assumes you have samples in minor thirds (a, c, d#, f#) and fills in notes accordingly
	for (int i = lowest_note; i <= highest_note; i++) {

		int octave = i / 12;
		//In my sample data, A has octave notation weirdly, this corrects for that
		if (i % 12 - i % 3 == 0) { octave -= 1; }
		std::string octave_string = std::to_string(octave);

		std::string pitch = notes[i%12 - i%3];//i%12 - i%3 gets the pitch of the nearest sampled note
		std::string path = "C:\\Users\\anast\\Music\\piano_samples\\"+pitch+octave_string+"v2.wav";

		//load sound
		sf::Sound* sound = new sf::Sound();
		sf::SoundBuffer* buffer = new sf::SoundBuffer();
		if (!buffer->loadFromFile(path)) {
			return;
		}
		sound->setBuffer(*buffer);

		//pitch shift the nearest sampled note to get the real note
		switch (i%3) {
		case 1:
			sound->setPitch( float(1.0595));
			break;
		case 2:
			sound->setPitch( float(1.1225));
			break;
		}

		sounds[i - lowest_note] = sound;
	}
}

void VirtualPiano::playSound(int n) {

	sounds[n]->play();
}

