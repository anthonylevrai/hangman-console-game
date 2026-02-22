#include <iostream>
#include <ctime>
#include "WordLoader.h"
#include "GameLogic.h"
#include "Renderer.h"

int main() {
	std::string filename = "assets/ASCII/words.txt";
	std::vector<std::string> words;

	try {
		words = WordLoader::loadWords(filename);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::string word;
	GameLogic logic;
	Renderer renderer;

	while (true) {
		word = WordLoader::pickRandomWord(words);
		logic.reset(word);

		while (!logic.isWin() && !logic.isLoss()) {
			renderer.draw(logic.getRevealed(), logic.getAttempts(), logic.getGuesses());

			char guess;

			std::cout << "\nEnter guess here: \t";

			std::cin >> guess;
			GuessResult result = logic.processGuess(guess);

			switch (result) {
			case GuessResult::REPEAT:
				renderer.showMessage(std::string("You have already entered: " + guess));
				break;
			case GuessResult::INVALID:
				renderer.showMessage(std::string(guess + " is an invalid guess."));
				break;
			case GuessResult::INCORRECT:
				renderer.showMessage("Wrong guess.");
				break;
			default:
				break;
			};
		}
		renderer.draw(logic.getRevealed(), logic.getAttempts(), logic.getGuesses());
		renderer.showEndScreen(logic.isWin(), word);

		//play again logic
		char in;
		std::cout << "Would you like to play again? (Y/N): ";
		std::cin >> in;
		in = static_cast<char>(std::tolower(static_cast<unsigned char>(in)));
		if ((in == 'y' || in == 'n'))
			if (in == 'n') break;
	}
}