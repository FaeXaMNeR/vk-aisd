#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

std::vector<int> even_first(std::vector<int> &arr) {
    int evenIndex = 0;

    for(int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            std::swap(arr[i], arr[evenIndex]);
            evenIndex++;
        }
    }

    return arr;
}

TEST(even_first, test) { 
    std::vector<int> array = {3, 2, 4, 1, 11, 8, 9};
    std::vector<int> expected = {2, 4, 8, 1, 11, 3, 9};
    std::vector<int> result = even_first(array);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}