#include "TabReader.h"

const float TAB_STEP = 0.1;



TabReader::TabReader() {
	tracks = {};
}

void TabReader::readFile() {}

void TabReader::readConsoleInput() {
	//std::string tab_string;
	std::cout << "Copy in tab: \n";
	//getline(std::cin, tab_string);

	std::vector<std::string> tab_lines;

	while (!std::cin.eof())	{
		std::string line;
		getline(std::cin, line);

		if (std::cin.fail())
		{
			//error
			break;
		}

		if (line == "") { break; }

		//std::cout << line << std::endl;
		tab_lines.push_back(line);
	}

	//for (std::string line : tab_lines) {
	//	std::cout << line << '\n';
	//}

	string_to_track(tab_lines);




	//std::cout << tab_string;

}

void TabReader::string_to_track(std::vector<std::string> tab_lines) {

	float current_time = 0;
	int last_line_length = 0;
	Track* new_track = new Track();

	for (std::string line : tab_lines) {

		if (line == " ") {
			current_time += last_line_length * TAB_STEP;
		}
		else {
			last_line_length = read_line(line, current_time, new_track);
		}
	}

	tracks.push_back(new_track);
}

int TabReader::read_line(std::string line, float line_start_time, Track* dest_track) {

	std::string::iterator line_it = line.begin();

	std::string note = std::string(1,*line_it);
	++line_it;
	if (*line_it != '|') {
		note.push_back(*line_it);
		++line_it;
	}
	++line_it;
	int starting_note = note_to_int(note);

	int i = 0;
	while (*line_it != line.back()) {

		if (isdigit(*line_it)) {
			int n = *line_it - '0'; //implicit casting to int
			dest_track->addHit(n+starting_note, line_start_time + i*TAB_STEP);

			std::cout << "Read note, time " <<n <<' '<< starting_note << ' ' << line_start_time + i * TAB_STEP << '\n';
		}

		i++;
		++line_it;
	}
	return i - 1;
}

int TabReader::note_to_int(std::string note_str) {
	//std::vector<std::string> notes = { "A","A#","B","C","C#","D","D#","E","F","F#","G","G#" };
	int note_int=0;
	std::cout << note_str.front() << '\n';
	//std::cout << char(note_str[0])=='e';
	switch (note_str.front()){
		case 'E':
			note_int = 31;
			break;
		case 'A':
			note_int = 36;
			break;
		case 'D':
			note_int = 41;
			break;
		case 'G':
			note_int = 46;
			break;
		case 'B':
			note_int = 50;
			break;
		case 'e':
			note_int = 55;
			break;
	}
	std::cout << note_int << '\n';
	return note_int;
}


Track* TabReader::getTrack() {
	return tracks.back();
}
Track* TabReader::getTrack(int n) {
	return tracks.at(n);
}

