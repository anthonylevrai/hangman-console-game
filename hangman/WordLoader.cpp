#include "WordLoader.h"
#include <fstream>
#include <iostream>
#include <cstdlib>

int generateRandomIndex(const std::vector<std::string>& words) {
	if (words.empty()) {
		std::cerr << "Error: no words loaded.";
	}
	return rand() % words.size();
}
void loadWords(std::vector<std::string>& words) {
	std::ifstream file("files/assets/words.txt");
	if (!file.is_open()) {
		std::cerr << "Error: could not open word list. \n";
		return;
	}
	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty()) {
			words.push_back(line);
		}
	}
	file.close();
}