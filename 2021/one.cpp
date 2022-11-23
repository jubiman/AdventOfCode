//
// Created by melle on 23/11/2022.
//
#include "one.h"

void y2021::one::solve() {
	std::ifstream f = fs::read("2021/inputs/1");
	if (f.is_open()) {
		std::string line;
		int last = 0x7fffffff, counter = 0;
		while (std::getline(f, line)) {
			int curr = std::stoi(line);
			if (last < curr) ++counter;
			last = curr;
		}
		f.close();
		std::cout << counter << std::endl;
	} else std::cout << "failed to open file" << std::endl;

	// part 2
	f = fs::read("2021/inputs/1");
	if (f.is_open()) {
		int lines[3];
		std::string line;
		std::getline(f, line);
		lines[1] = std::stoi(line);
		std::getline(f, line);
		lines[2] = std::stoi(line);

		int last = 0x7fffffff, counter = 0;
		while (std::getline(f, line)) {
			lines[0] = lines[1];
			lines[1] = lines[2];
			lines[2] = std::stoi(line);
			int curr = lines[0] + lines[1] + lines[2];
			if (last < curr) ++counter;
			last = curr;
		}
		f.close();
		std::cout << counter << std::endl;
	} else std::cout << "failed to open file" << std::endl;
}