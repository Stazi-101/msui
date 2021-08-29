#pragma once

#include <array>
#include <string>

#include <SFML/Audio.hpp>

//includes both highest and lowest notes, so number of notes = highest_note-lowest_note+1
const int LOWEST_NOTE = 30;
const int HIGHEST_NOTE = 76;


class SampleBoard
{
public:
	SampleBoard();
	void playSound(int);

private:
	void loadSounds();
	
	std::array<sf::Sound*, (HIGHEST_NOTE - LOWEST_NOTE + 1)> sounds;
	std::array<std::string, 12> notes;
	
	int lowest_note;
	int highest_note;
};

