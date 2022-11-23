//
// Created by melle on 23/11/2022.
//

#include "two.h"

void y2021::two::solve() {
	std::ifstream f = fs::read("2021/inputs/2");
	if (f.is_open()) {
		std::string line;

		int hor = 0, vert = 0;
		while (std::getline(f, line)) {
			std::string direction = line.substr(0, line.find(' '));
			if (direction == "up") {
				vert -= std::stoi(line.substr(line.find(' ') + 1));
			} else if (direction == "down") {
				vert += std::stoi(line.substr(line.find(' ') + 1));
			} else {
				hor += std::stoi(line.substr(line.find(' ') + 1));
			}
		}
		f.close();
		std::cout << hor * vert << std::endl;
	} else std::cout << "failed to open file" << std::endl;

	// part 2
	f = fs::read("2021/inputs/2");
	if (f.is_open()) {
		std::string line;

		int hor = 0, depth = 0, aim = 0;
		while (std::getline(f, line)) {
			std::string direction = line.substr(0, line.find(' '));
			if (direction == "up") {
				aim -= std::stoi(line.substr(line.find(' ') + 1));
			} else if (direction == "down") {
				aim += std::stoi(line.substr(line.find(' ') + 1));
			} else {
				int i = std::stoi(line.substr(line.find(' ') + 1));
				hor += i;
				depth += i * aim;
			}
		}
		f.close();
		std::cout << hor * depth << std::endl;
	} else std::cout << "failed to open file" << std::endl;
}