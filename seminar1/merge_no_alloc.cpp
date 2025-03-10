#include <gtest/gtest.h>
#include <vector>

std::vector<int> merge_array(std::vector<int> &arr1, std::vector<int> &arr2) {
    arr1.resize(arr1.size() + arr2.size());

    int pointer1 = arr1.size() - arr2.size() - 1;
    int pointer2 = arr2.size() - 1;
    int pointer3 = arr1.size() - 1;

    while (pointer2 >= 0) {
        if (pointer1 >= 0 && arr1[pointer1] > arr2[pointer2]) {
            arr1[pointer3] = arr1[pointer1];
            pointer1--;
        }
        else {
            arr1[pointer3] = arr2[pointer2];
            pointer2--;
        }
        pointer3--;
    }
    
    return arr1;
}

TEST(merge_array, test) { 
    std::vector<int> array1 = {3, 8, 10, 11};
    std::vector<int> array2 = {1, 7, 9};
    std::vector<int> expected = {1, 3, 7, 8, 9, 10, 11};
    std::vector<int> result = merge_array(array1, array2);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}