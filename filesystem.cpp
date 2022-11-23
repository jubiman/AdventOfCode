//
// Created by melle on 23/11/2022.
//
#include "filesystem.h"

std::string dir;
void fs::init() {
	std::string path = __FILE__;
	dir = path.substr(0, path.rfind('/'));
}

std::ifstream fs::read(const std::string& fn) {
	return std::ifstream{(dir + '/' + fn)};
}