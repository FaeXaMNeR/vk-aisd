#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

std::vector<int> binary_sort(std::vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        if(arr[left] == 1) {
            std::swap(arr[left], arr[right]);
            right--;
        }
        else {
            left++;
        }
    }

    return arr;
}

TEST(binary_sort, test) { 
    std::vector<int> array = {0, 1, 1, 0, 1, 0, 1, 0};
    std::vector<int> expected = {0, 0, 0, 0, 1, 1, 1, 1};
    std::vector<int> result = binary_sort(array);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}