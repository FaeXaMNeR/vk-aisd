#include <gtest/gtest.h>

struct list {
    int data;
    list *next;
    list(int value) : data(value), next(nullptr) {}
};

void remove(list **head, int value) {
    list *temp = *head;
    list *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        *head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;
}

TEST(remove, test) {
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);

    remove(&head, 1);

    EXPECT_EQ(head->data, 2);
    EXPECT_EQ(head->next->data, 3);

    delete head->next;
    delete head;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}