//
// Created by melle on 23/11/2022.
//
#include "three.h"

void y2021::three::solve() {
	int16_t gamma = 0, epsilon = 0;
	for (int16_t i = 0b100000000000; i > 0; i >>= 1) {
		std::ifstream f = fs::read("2021/inputs/3");
		int ones = 0;
		int lines = 0;
		if (f.is_open()) {
			std::string line;
			while (std::getline(f, line)) {
				// 12 bits
				int16_t l = std::stoi(line, nullptr, 2);
				ones += l & i ? 1 : 0;
				++lines;
			}
			f.close();
		}
		gamma |=  lines / ones > lines / 2 ? i : 0;
		epsilon |= lines / ones > lines / 2 ? 0 : i;
	}
	std::cout << gamma * epsilon << std::endl;
}