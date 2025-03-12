#include <gtest/gtest.h>
#include <deque>

bool ispalindrome(std::deque<char> &list) {
    int left = 0;
    int right = list.size() - 1;

    while (left < right) {
        if (list[left] != list[right]) return false;
        left++;
        right--;
    }

    return true;
}

TEST(remove, test) {
    std::deque<char> str1 = {'a', 'b', 'c', 'b', 'a'};
    std::deque<char> str2 = {'a', 'b'};

    EXPECT_TRUE(ispalindrome(str1));
    EXPECT_FALSE(ispalindrome(str2));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}