//
// Created by melle on 25/11/2022.
//
#include "six.h"

void y2021::six::solve() {
	std::ifstream f = fs::read("2021/inputs/6");
	std::string line;
	std::getline(f, line);
	std::vector<lanternfish> fishies;
	for (size_t pos = line.find(','); pos != std::string::npos; pos = line.find(',')) {
		fishies.push_back(lanternfish{std::stoi(line.substr(0, pos))});
		line.erase(0, pos + 1);
	}
	fishies.push_back(lanternfish{std::stoi(line)});
	std::vector<lanternfish> queue;
	for (int8_t i = 0; i < 80; ++i) {
		queue.clear();
		for (auto& fish : fishies) {
			lanternfish lf = fish.tick();
			if (lf.timer != -2) queue.push_back(lf); // don't want to push back while iterating
		}
		fishies.insert(fishies.end(), queue.begin(), queue.end());
	}
	std::cout << fishies.size() << std::endl;

	// part 2
	fishies.clear();
	f.clear();
	f.seekg(0, std::ios::beg);
	std::getline(f, line);
	std::vector<uint64_t> fish;
	fish.resize(9);
	for (size_t pos = line.find(','); pos != std::string::npos; pos = line.find(',')) {
		fish[std::stoul(line.substr(0, pos))]++ ;
		line.erase(0, pos + 1);
	}
	fish[std::stoul(line)]++;
	// very fast lmao
	for (int16_t i = 0; i != 256; ++i) {
		std::vector<uint64_t> fish2(9,0);
		for(unsigned e=8;e;e--) // load fish into fish2, shifted one back (stops at e ==0)
			fish2[e-1]=fish[e];
		fish2[6]+=fish[0];
		fish2[8]=fish[0];
		fish=fish2;
	}
	std::cout << std::accumulate(fish.begin(), fish.end(), 0llu) << std::endl;
}