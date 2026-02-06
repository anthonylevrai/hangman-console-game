#pragma once
#include <vector>
#include <string>


void reset(const std::vector<std::string>& words, std::vector<char>& key, std::vector<char>& revealed, int& attempts, std::vector<char>& guesses);
bool checkGuess(char guess, const std::vector<char>& key, std::vector<char>& revealed, int& attempts, std::vector<char>& guesses);
bool isWin(const std::vector<char>& key,const std::vector<char>& revealed);
bool isLoss(int attempts, const std::vector<char>& key, const std::vector<char>& revealed);


