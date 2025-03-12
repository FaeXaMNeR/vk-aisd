#include <gtest/gtest.h>

struct list {
    int data;
    list *next;
    list(int value) : data(value), next(nullptr) {}
};

list *reverse(list **head) {
    list *prev = nullptr;
    list *current = *head;

    while (current != nullptr) {
        list *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
    return *head;
}

TEST(reverse, test) {
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);

    reverse(&head);

    EXPECT_EQ(head->data, 3);
    EXPECT_EQ(head->next->data, 2);
    EXPECT_EQ(head->next->next->data, 1);

    delete head->next->next;
    delete head->next;
    delete head;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}