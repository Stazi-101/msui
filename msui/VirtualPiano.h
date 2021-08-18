#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <array>
#include <string>

//includes both highest and lowest notes, so number of notes = highest_note-lowest_note+1
const int LOWEST_NOTE = 39;
const int HIGHEST_NOTE = 76;
const double SEMITONE_MULTIPLIER = 1.059;

class VirtualPiano
{
public:
	VirtualPiano(sf::Time);
	void giveEvent(sf::Event);

private:
	void loadSounds();
	void playSound(int);

	std::array<sf::Sound*, (HIGHEST_NOTE - LOWEST_NOTE +1)> sounds;
	std::array<std::string, 12> notes;
	std::array<int, 37> keys;

	int lowest_note;
	int highest_note;
	int start_time;
};

