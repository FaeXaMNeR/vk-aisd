#include <gtest/gtest.h>

struct list {
    char data;
    list *next;
    list(char value) : data(value), next(nullptr) {}
};

bool issubsequence(list *str1, list *str2) {
    list *current1 = str1;

    if (current1 == nullptr) return true;

    list *current2 = str2;

    while (current1 != nullptr && current2 != nullptr) {
        if (current2->data == current1->data) {
            current1 = current1->next;
        }
        current2 = current2->next;
    }

    return current1 == nullptr;
}

TEST(issubq, test) {
    list* str1 = new list('a');
    str1->next = new list('b');
    str1->next->next = new list('d');

    list* str2 = new list('u');
    str2->next = new list('a');
    str2->next->next = new list('b');
    str2->next->next->next = new list('q');
    str2->next->next->next->next = new list('d');

    bool res = issubsequence(str1, str2);

    EXPECT_TRUE(res);
    
    delete str2->next->next->next->next;
    delete str2->next->next->next;
    delete str2->next->next;
    delete str2->next;
    delete str2;

    delete str1->next->next;
    delete str1->next;
    delete str1;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}