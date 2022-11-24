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
        gamma |= 2 * ones < lines ? 0 : i;
        epsilon |= 2 * ones > lines ? 0 : i;
    }
    std::cout << gamma * epsilon << std::endl;

    // part 2
    std::ifstream f = fs::read("2021/inputs/3");
    std::vector<int16_t> nums;
    if (f.is_open()) {
        std::string line;
        while (std::getline(f, line))
            nums.push_back(std::stoi(line, nullptr, 2));
        f.close();
    }
    std::vector<int16_t> nums2 = nums;

    // oxygen
    for (int16_t i = 0b100000000000; i > 0 && nums.size() != 1; i >>= 1) {
        int ones = 0;
        for (const auto& l : nums)
            ones += l & i ? 1 : 0;


        nums.erase(std::remove_if(nums.begin(), nums.end(), [&i, &ones, &nums](int16_t num) {
            return ones == 0 || 2 * ones >= nums.size() ? !(num & i) : num & i;
        }), nums.end());
    }
    int oxygen = nums[0]; // should only be one left

    // carbon
    for (int16_t i = 0b100000000000; i > 0 && nums2.size() != 1; i >>= 1) {
        int ones = 0;
        for (const auto& l : nums2)
            ones += l & i ? 1 : 0;


        nums2.erase(std::remove_if(nums2.begin(), nums2.end(), [&i, &ones, &nums2](int16_t num) {
            return 2 * ones < nums2.size() ? !(num & i) : num & i;
        }), nums2.end());
    }
    int carbon = nums2[0]; // should only be one left


    std::cout << oxygen * carbon << std::endl;
}