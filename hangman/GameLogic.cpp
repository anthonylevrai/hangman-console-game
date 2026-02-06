#include "GameLogic.h"
#include "WordLoader.h"
#include <iostream>

void reset(const std::vector<std::string>& words, std::vector<char>& key, std::vector<char>& revealed, int& attempts, std::vector<char>& guesses) {
	//reset the gamestate and reinitialize
	//initialize the key vector
	std::string keyString = words[generateRandomIndex(words)];
	key.clear();
	key.resize(keyString.length());
	for (int i = 0; i < keyString.length(); i++) {
		key[i] = keyString.at(i);
	}
	//reset the revealed vector
	revealed.clear();
	revealed.resize(key.size(), '_');
	//reset the attempt counter
	attempts = 0;
	//reset guesses
	guesses.clear();
}
bool checkGuess(char guess, const std::vector<char>& key, std::vector<char>& revealed, int& attempts, std::vector<char>& guesses) {
	bool update = false;
	//check if char has alrady been guessed
	for (char e : guesses) {
		if (guess == e) {
			std::cout << "You have already guessed " << guess << ". \n Please enter another letter: \t";
			std::cin >> guess;
			return checkGuess(guess, key, revealed, attempts, guesses);
		}
	}
	//update guessed characters
	guesses.push_back(guess);
	//iterate over the key vector and update the revealed vector
	for (int i = 0; i < key.size(); i++) {
		if (key[i] == guess) {
			revealed[i] = guess;
			update = true;
		}
	}
	//increment attempts if not in key and return false
	if (!update) {
		attempts++;
	}
	//return true if any updates were made
	return update;
}
bool isWin(const std::vector<char>& key,const std::vector<char>& revealed) {
	return revealed == key;
}
bool isLoss(int attempts,const std::vector<char>& key,const std::vector<char>& revealed) {
	return (attempts == 6 && !isWin(key, revealed));
}
