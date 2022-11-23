//
// Created by melle on 23/11/2022.
//

#ifndef AOC_FILESYSTEM_H
#define AOC_FILESYSTEM_H
#include <fstream>
namespace fs {
	void init();
	std::ifstream read(const std::string&);
}
#endif //AOC_FILESYSTEM_H
