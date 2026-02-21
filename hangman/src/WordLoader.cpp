#include "WordLoader.h"
#include <fstream>
#include <random>
#include <stdexcept>

std::vector<std::string> WordLoader::loadWords(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) throw std::runtime_error("Could not open word list: " + filename);

	std::vector<std::string> words;
	std::string line;

	while (std::getline(file, line)) {
		if (!line.empty()) words.push_back(line);
	}

	file.close();
	return words;
}

std::string WordLoader::pickRandomWord(const std::vector<std::string>& words) {
	if (words.empty()) throw std::runtime_error("No words loaded.");

	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<size_t> dist(0, words.size() - 1);

	return words[dist(gen)];
}