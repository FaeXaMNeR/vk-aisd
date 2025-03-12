#include <gtest/gtest.h>

struct list {
    int data;
    list *next;
    list(int value) : data(value), next(nullptr) {}
};

list *middle(list *head) {
    list *slow = head;
    list *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // в случае списка четной длины 2n вернется n + 1 элемент
    return slow;
}

TEST(middle, odd) {
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);

    list *res = middle(head);

    EXPECT_EQ(res->data, 2);

    delete head->next->next;
    delete head->next;
    delete head;
}

TEST(middle, even) {
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);
    head->next->next->next = new list(4);

    list *res = middle(head);

    EXPECT_EQ(res->data, 3);

    delete head->next->next->next;
    delete head->next->next;
    delete head->next;
    delete head;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}