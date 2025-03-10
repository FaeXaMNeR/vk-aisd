#include <gtest/gtest.h>
#include <vector>

std::vector<int> merge_array(std::vector<int> &arr1, std::vector<int> &arr2) {
    std::vector<int> merge;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merge.push_back(arr1[i]);
            i++;
        }
        else {
            merge.push_back(arr2[j]);
            j++;
        }
    }
    
    for(int k = i; k < arr1.size(); k++) {
        merge.push_back(arr1[k]);
    }
    for(int k = j; k < arr2.size(); k++) {
        merge.push_back(arr2[k]);
    }

    return merge;
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