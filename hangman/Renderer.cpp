#include "Renderer.h"
#include "GameLogic.h"
#include <fstream>
#include <iostream>

void printGame(int attempts) {
	std::string filename = "files/assets/hangman" + std::to_string(attempts) + ".txt";
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open ASCII art file. \n";
		return;
	}
	system("cls");
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << "\n";
	}
}
void printRevealed(const std::vector<char>& revealed) {
	for (char e : revealed) {
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
void printKey(const std::vector<char>& key) {
	for (char e : key ) {
		std::cout << e;
	}
	std::cout << std::endl;
}
void printUI(const int& attempts,const std::vector<char>& revealed,const std::vector<char>& guesses) {
	printGame(attempts);
	centerText();
	std::cout << "Welcome to Hangman!! \n";
	centerText();
	std::cout << "you know the rules... \n";
	centerText();
	printRevealed(revealed);
	if (!guesses.empty()) {
		std::cout << "You have guessed: ";
		for (char e : guesses) {
			std::cout << e << ", ";
		}
	}
	std::cout << "\nEnter your guess here: \t";
}
bool printEndGame(int attempts,const std::vector<char>& key,const std::vector<char>& revealed) {
	system("cls");
	if (isLoss(attempts, key, revealed)) {
		std::cout << "You have failed to guess the word \n"
			<< "Hangman is dead XXX \n";
	}
	else {
		std::cout << "You have guessed the word. \n";
	}
	std::cout << "The word was: \t";
	printKey(key);
	std::cout << "Would you like to play again ? \n Y or N: \t";
	char in;
	std::cin >> in;
	if (in == 'n' || in == 'N') {
		std::cout << "Thank you for playing!!";
		return 0;
	}
	return 1;
}
void centerText() {
	for (int i = 0; i < 6;i++) {
		std::cout << "  \t  ";
	}
}