#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

void reversearray(std::vector<int> &numbers, int left, int right) {    
    while (left < right) {
        std::swap(numbers[left], numbers[right]);
        left++;
        right--;
    }
}

std::vector<int> solution(std::vector<int> &array, int k) {
    int n = array.size();

    reversearray(array, 0, n - 1);
    reversearray(array, 0, k % n - 1);
    reversearray(array, k % n, n - 1);

    return array;
}

TEST(solution, test) { 
    std::vector<int> numbers1 = {3, 8, 9, 11, 16, 18, 19, 21};
    std::vector<int> expected1 = {11, 16, 18, 19, 21, 3, 8, 9};
    std::vector<int> result1 = solution(numbers1, 5);
    EXPECT_EQ(result1, expected1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}