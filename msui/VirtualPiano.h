#pragma once
#include <array>
#include <SFML/Window.hpp>

#include "SampleBoard.h"



class VirtualPiano
{
public:
	VirtualPiano(sf::Time);
	void giveEvent(sf::Event);

private:

	SampleBoard* sample_board;

	std::array<int, (HIGHEST_NOTE - LOWEST_NOTE + 1)> keys;

	int lowest_note;
	int highest_note;
	
	float start_time;
};

