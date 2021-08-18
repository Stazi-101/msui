#include "VirtualPiano.h"

#include <iostream>



VirtualPiano::VirtualPiano(sf::Time given_start_time) {
	lowest_note = LOWEST_NOTE;
	highest_note = HIGHEST_NOTE;
	start_time = given_start_time.asSeconds();

	sample_board = new SampleBoard();
	

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
		
}

void VirtualPiano::giveEvent(sf::Event new_event) {


	int i = 0;
	for (int k : keys) {
		if (new_event.key.code == k) {
			sample_board->playSound(i);
			break;
		}

		i++;
	}
	
}



