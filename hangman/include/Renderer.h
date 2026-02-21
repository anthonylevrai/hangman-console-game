#pragma once
#include <string>
#include <vector>

class Renderer {
public:
	void draw(const std::vector<char>& revealed, int attempts, const std::vector<char>& guesses) const;
	void showMessage(const std::string& msg) const;
	void showEndScreen(bool won, const std::string& word) const;

private:
	void drawHangman(int attempts) const;
};