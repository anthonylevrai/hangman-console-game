#pragma once
#include <string>
#include <vector>

void printGame(int attempts);
void printRevealed(const std::vector<char>& revealed);
void printUI(const int& attempts, const std::vector<char>& revealed,const std::vector<char>& guesses);
bool printEndGame(int attempts, const std::vector<char>& key, const std::vector<char>& revealed);
void centerText();
