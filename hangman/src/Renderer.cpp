#include "Renderer.h"
#include <iostream>
#include <fstream>

void Renderer::draw(const std::vector<char>& revealed, int attempts, const std::vector<char>& guesses) const {
	drawHangman(attempts);

	std::cout << "\nWord:";
	for (char c : revealed) std::cout << c;
	std::cout << std::endl;

	for (char c : guesses) std::cout << c <<' ';
	std::cout << std::endl;

	std::cout << "Attempts used: " << attempts << "/6" << "\n\n";
}
void Renderer::showMessage(const std::string& msg) const {
	std::cout << msg << "\n";
}
void Renderer::showEndScreen(bool won, const std::string& word) const {
	if (won) std::cout << "You won!\n";
	else
		std::cout << "You lost!\n";
}
void Renderer::drawHangman(int attempts) const {
	std::string filename = "assets/ASCII/hangman" + std::to_string(attempts) + ".txt";
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