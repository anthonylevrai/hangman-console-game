#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int generateRandomIndex(const std::vector<std::string>& words) {
	if (words.empty()) {
		std::cerr << "Error: no words loaded.";
	}
	return rand() % words.size();
}
void loadWords(std::vector<std::string>& words) {
	std::ifstream file("files/assets/words.txt");
	if (!file.is_open()) {
		std::cerr << "Error: could not open word list. \n";
		return;
	}
	std::string line;
	while (std::getline(file, line)) {
		if (!line.empty()) {
			words.push_back(line);
		}
	}
	file.close();
}
void reset(const std::vector<std::string>& words,std::vector<char>& key,std::vector<char>& revealed,int& attempts,std::vector<char>& guesses) {
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
bool checkGuess(char guess,const std::vector<char>& key,std::vector<char>& revealed,int& attempts,std::vector<char>& guesses) {
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
void printGame(int attempts) {
	std::string filename = "files/assets/hangman" + std::to_string(attempts) + ".txt";
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: could not open word list. \n";
		return;
	}
	system("cls");
	std::string line;
	while (std::getline(file, line)) {
		std::cout << line << "\n";
	}
}
bool isComplete(std::vector<char> key, std::vector<char> revealed) {
	return revealed == key;
}


int main() {
	srand(time(nullptr));
	std::vector<std::string> words;
	loadWords(words);

	while (true) {
		//initialize game here
		std::vector<char> key;
		std::vector<char> revealed;
		std::vector<char> guesses;
		int attempts;

		reset(words,key, revealed, attempts, guesses);

		while (true) {
			char guess;
			//round logic here
			printGame(attempts);
			std::cout << "Welcome to Hangman!! \n";
			std::cout << "you know the rules... \n";
			for (char e : revealed) {
				std::cout << e << " ";
			}
			std::cout << "\n";
			if (!guesses.empty()) {
				std::cout << "You have guessed: ";
				for (char e : guesses) {
					std::cout << e << ", ";
				}
			}
			std::cout << "\nEnter your guess here: \t";
			std::cin >> guess;
			checkGuess(guess, key, revealed, attempts, guesses);




			if (attempts == 6) {
				system("cls");
				std::cout << "You have failed to guess the word \n"
					<< "Hangman is dead XXX \n"
					<< "The word was: \t";
				for (char e : key) {
					std::cout << e;
				}
				std::cout << std::endl;
				break;
			}

			if (isComplete(key,revealed)) {
				system("cls");
				std::cout << "You have guessed the word. \n"
					<< "The word was: \t";
				for (char e : key) {
					std::cout << e;
				}
				std::cout << std::endl;
				break;
			}
			
		}
		std::cout << "Would you like to play again ? \n Y or N: \t";
		char in;
		std::cin >> in;
		if (in == 'n' || in == 'N') {
			std::cout << "Thank you for playing!!";
			break;
		}
	}

	return 0;
}