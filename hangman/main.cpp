#include <iostream>
#include <ctime>
#include "WordLoader.h"
#include "GameLogic.h"
#include "Renderer.h"

int main() {
	//init game state here
	bool run = true;												
	srand(time(nullptr));											
	std::vector<std::string> words;
	loadWords(words);
	while (run) {
		//initialize round here
		std::vector<char> key;
		std::vector<char> revealed;
		std::vector<char> guesses;
		int attempts;

		reset(words,key, revealed, attempts, guesses);

		while (true) {
			char guess;
			//round logic here
			printUI(attempts, revealed, guesses);
			std::cin >> guess;
			checkGuess(guess, key, revealed, attempts, guesses);
			if (isLoss(attempts,key,revealed) || isWin(key, revealed)) {
				run = printEndGame(attempts, key, revealed);
				break;
			}
		}	
	}
	return 0;
}