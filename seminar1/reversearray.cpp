#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

std::vector<int> reversearray(std::vector<int> &numbers) {
    int left = 0;
    int right = numbers.size() - 1;
    
    while (left < right) {
        std::swap(numbers[left], numbers[right]);
        left++;
        right--;
    }

    return numbers;
}

TEST(reversearray, test) {
    // Массив с четным количеством элементов
    std::vector<int> numbers1 = {3, 8, 9, 11, 16, 18, 19, 21};
    std::vector<int> expected1 = {21, 19, 18, 16, 11, 9, 8, 3};
    std::vector<int> result1 = reversearray(numbers1);
    EXPECT_EQ(result1, expected1);

    // Массив с нечетным количеством элементов
    std::vector<int> numbers2 = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {5, 4, 3, 2, 1};
    std::vector<int> result2 = reversearray(numbers2);
    EXPECT_EQ(result2, expected2);

    // Пустой массив
    std::vector<int> numbers3 = {};
    std::vector<int> expected3 = {};
    std::vector<int> result3 = reversearray(numbers3);
    EXPECT_EQ(result3, expected3);

    // Массив с одним элементом
    std::vector<int> numbers4 = {42};
    std::vector<int> expected4 = {42};
    std::vector<int> result4 = reversearray(numbers4);
    EXPECT_EQ(result4, expected4);

    // Массив с повторяющимися элементами
    std::vector<int> numbers5 = {1, 2, 2, 3, 3, 3};
    std::vector<int> expected5 = {3, 3, 3, 2, 2, 1};
    std::vector<int> result5 = reversearray(numbers5);
    EXPECT_EQ(result5, expected5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}