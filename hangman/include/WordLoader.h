#pragma once
#include <vector>
#include <string>

class WordLoader {
public:
	static std::vector<std::string> loadWords(const std::string& filename);

	static std::string pickRandomWord(const std::vector<std::string>& words);
};
