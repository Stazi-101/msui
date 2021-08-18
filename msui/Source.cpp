#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <thread>
#include <iostream>

#include "VirtualPiano.h"





void loop();



int main(int argc, char* args[]){


	loop();

	return 0;
}



void loop() {

	sf::Window* window = new sf::Window(sf::VideoMode(800, 600), "awooga");

	sf::Sound sound;
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("C:\\Users\\anast\\Music\\piano_samples\\a5v1.wav")) {
		std::cout << "File not able to load\n";
		return;
	}
	sound.setBuffer(buffer);

	double pitch = 1;

	sf::Clock clock;

	VirtualPiano vpiano = VirtualPiano(clock.getElapsedTime());

	// run the program as long as the window is open
	while (window->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			else if (event.type == sf::Event::KeyPressed) {
				vpiano.giveEvent(event);
			}

		}
	}

}

void example_sounds() {
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("C:\\Users\\anast\\Music\\piano_samples\\a5v1.wav")) {
		return;
	}
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	sound.setPitch(1.059);
	sound.play();
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}