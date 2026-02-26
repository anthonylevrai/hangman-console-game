#include <iostream>
#include <ctime>
#include "WordLoader.h"
#include "GameLogic.h"
#include "Renderer.h"

static void runGame(GameLogic& logic, Renderer& renderer, const std::vector<std::string>& words) {
	while (!logic.isWin() && !logic.isLoss()) {
		renderer.draw(logic.getRevealed(), logic.getAttempts(), logic.getGuesses());

		char guess;

		std::cout << "\nEnter guess here: ";

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
}

int main() {
	bool run = true;
	Renderer renderer;
	int menuChoice;

	renderer.showMainMenu();
	std::cout << "Choice: ";
	std::cin >> menuChoice;

	switch (menuChoice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		run = false;
		break;
	default:
		break;
	}

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
	

	while (run) {
		word = WordLoader::pickRandomWord(words);
		logic.reset(word);

		runGame(logic, renderer, words);
		
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
