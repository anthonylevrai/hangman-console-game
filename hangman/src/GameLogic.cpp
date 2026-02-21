#include "GameLogic.h"
#include <algorithm>
#include <cctype>

GameLogic::GameLogic() : attempts(0) {};

void GameLogic::reset(const std::string& newWord ) {
	key.assign(newWord.begin(), newWord.end());

	revealed.assign(key.size(), '_');
	guesses.clear();
	attempts = 0;
}

bool GameLogic::hasGuessed(char c) const {
	return std::find(guesses.begin(), guesses.end(), c) != guesses.end();
}

GuessResult GameLogic::processGuess(char guess) {
	guess = static_cast<char>(std::tolower(static_cast<unsigned char>(guess)));

	if (!std::isalpha(static_cast<unsigned char>(guess))) return GuessResult::INVALID;
	if (hasGuessed(guess)) return GuessResult::REPEAT;
	
	guesses.push_back(guess);

	bool updated = false;
	for (size_t i = 0; i < key.size(); ++i) {
		if (key[i] == guess) {
			revealed[i] = guess;
			updated = true;
		}
	}

	if (!updated) {
		++attempts;
		return GuessResult::INCORRECT;
	}
	if (updated) return GuessResult::CORRECT;
}
bool GameLogic::isWin() const{
	return revealed == key;
}
bool GameLogic::isLoss() const {
	return attempts >= MAX_ATTEMPTS && !isWin();
}
int GameLogic::getAttempts() const {
	return attempts;
}
const std::vector<char>& GameLogic::getRevealed() const {
	return revealed;
}
const std::vector<char>& GameLogic::getGuesses() const {
	return guesses;
}