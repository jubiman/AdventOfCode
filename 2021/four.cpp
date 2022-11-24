//
// Created by Melle on 24/11/2022.
//
#include "four.h"

void y2021::four::solve() {
	std::ifstream f = fs::read("2021/inputs/4");
	if (f.is_open()) {
		std::vector<uint8_t> draws;
		std::string line;
		std::getline(f, line);
		for (size_t pos = line.find(','); pos != std::string::npos; pos = line.find(',')) {
			draws.push_back(std::stoi(line.substr(0, pos)));
			line.erase(0, pos + 1);
		}
		draws.push_back(std::stoi(line));

		std::vector<std::vector<std::vector<uint8_t>>> boards;
		while (std::getline(f, line)) { // ignore whiteline
			std::vector<std::vector<uint8_t>> board(5);
			for (auto& x : board) {
				std::getline(f, line); // 5 lines per board
				std::vector<uint8_t> curr;
				for (uint8_t i = 0, j = 0; i < 14; i += 3, ++j) // every number is 2 characters
					curr.push_back(std::stoi(line.substr(i, 2)));
				x = curr;
			}
			boards.push_back(board);
		}
		f.close();

		// play the actual game (kinda cursed nested loops lmao)
		std::vector<uint8_t> counter;
		std::vector<int> scores(boards.size(), 0);
		int j = 0;
		for (auto &board: boards) {
			uint8_t c = 0;
			for (const auto& draw : draws) {
				for (auto &row: board) {
					for (auto &num: row) {
						if (num == draw) {
							num = 255;
							break;
						}
					}
				}
				// check if board has bingo
				if (bingo(board)) {
					int score = 0;
					for (const auto &row: board)
						for (const auto& num : row)
							if (num != 255)
								score += num;
					scores[j] = score * draw;
					goto b; // kinda forbidden but fuck nested loops tbf
				}
				else c++; // hihi
			}
			b:;
			counter.push_back(c);
			++j;
		}

		uint8_t pos = 0;
		for (uint8_t i = 1, min = counter[0]; i < counter.size(); ++i) {
			if (counter[i] < min) {
				min = counter[i];
				pos = i;
			}
		}

		std::cout << scores[pos] << std::endl;

		// damn that was only part 1
		// part 2 (all work is actually already done lmao)
		pos = 0;
		for (uint8_t i = 1, max = counter[0]; i < counter.size(); ++i) {
			if (counter[i] > max) {
				max = counter[i];
				pos = i;
			}
		}
		std::cout << scores[pos] << std::endl;
	}
}

bool y2021::four::bingo(const std::vector<std::vector<uint8_t>>& board) {
	// check every row
	for (const auto& row : board)
		if (row[0] == 255 && row[1] == 255 && row[2] == 255 && row[3] == 255 && row[4] == 255)
			return true;

	// check columns
	for (uint8_t i = 0; i < 5; ++i)
		if (board[0][i] == 255 && board[1][i] == 255 && board[2][i] == 255 && board[3][i] == 255 && board[4][i] == 255)
			return true;

	return false;
}