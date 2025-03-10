#include <iostream>
#include <gtest/gtest.h>
#include <vector>

std::pair<int, int> twoSum(std::vector<int> &numbers, int target) {
    int left = 0;
    int right = numbers.size() - 1;
    
    while (left < right) {
        int sum = numbers[left] + numbers[right];

        if (sum == target) {
            return {left, right};
        }

        else if (sum < target) {
            left++;
        }

        else {
            right--;
        }
        
    }

    return {0, 0};
}

TEST(twoSum, test) {
    std::vector<int> numbers = {3, 8, 9, 11, 16, 18, 19, 21};

    int target = 27; // 8 + 21

    std::pair<int, int> result = twoSum(numbers, target);
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, 6);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}