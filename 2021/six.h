//
// Created by melle on 25/11/2022.
//

#ifndef AOC_SIX_H
#define AOC_SIX_H
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include "../filesystem.h"
namespace y2021 {
	namespace six {
		void solve();
		struct lanternfish {
			int timer;

			lanternfish tick() {
				if(--timer < 0)
					return birth();
				return lanternfish{-2};
			}
			lanternfish birth() {
				timer = 6;
				return lanternfish{8};
			}
		};
	}
}
#endif //AOC_SIX_H
