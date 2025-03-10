#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

std::vector<int> color_sort(std::vector<int> &arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        if(arr[mid] == 0) {
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else if (arr[mid] == 2) {
            std::swap(arr[mid], arr[high]);
            high--;
        }
    }

    return arr;
}

TEST(color_sort, test) { 
    std::vector<int> array = {2, 0, 2, 1, 1, 0};
    std::vector<int> expected = {0, 0, 1, 1, 2, 2};
    std::vector<int> result = color_sort(array);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}