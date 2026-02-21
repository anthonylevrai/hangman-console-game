#pragma once
#include <vector>
#include <string>

enum class GuessResult {
	CORRECT,
	INCORRECT,
	REPEAT,
	INVALID
};
class GameLogic {
public:
	GameLogic();

	//start new round with new word
	void reset(const std::string& newWord);
	//process one guess and return what happened
	GuessResult processGuess(char guess);

	bool isWin() const;
	bool isLoss() const;

	int getAttempts() const;
	const std::vector<char>& getRevealed() const;
	const std::vector<char>& getGuesses() const;

private:
	static constexpr int MAX_ATTEMPTS = 6;

	std::vector<char> key;
	std::vector<char> revealed;
	std::vector<char> guesses;
	int attempts;

	bool hasGuessed(char c) const;

};



