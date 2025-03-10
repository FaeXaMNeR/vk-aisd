#include <gtest/gtest.h>
#include <vector>

std::vector<int> zero_to_end(std::vector<int> &marks) {
	int normal = 0;
    
	for(int i = 0; i < marks.size(); i++) {
		if (marks[i] != 0) {
            marks[normal] = marks[i];
			normal++;
		}
	}

	for(int i = normal; i < marks.size(); i++) {
		marks[i] = 0;
	}

    return marks;
}

TEST(zero_to_end, test) { 
    std::vector<int> array1 = {0, 0, 1, 0, 3, 12};
    std::vector<int> expected1 = {1, 3, 12, 0, 0, 0};
    std::vector<int> result1 = zero_to_end(array1);
    EXPECT_EQ(result1, expected1);

    std::vector<int> array2 = {0, 33, 57, 88, 60, 0, 0, 80, 99};
    std::vector<int> expected2 = {33, 57, 88, 60, 80, 99, 0, 0, 0};
    std::vector<int> result2 = zero_to_end(array2);
    EXPECT_EQ(result2, expected2);

    std::vector<int> array3 = {0, 0, 0, 18, 16, 0, 0, 77, 99};
    std::vector<int> expected3 = {18, 16, 77, 99, 0, 0, 0, 0, 0};
    std::vector<int> result3 = zero_to_end(array3);
    EXPECT_EQ(result3, expected3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}