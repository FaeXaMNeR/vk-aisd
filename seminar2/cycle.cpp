#include <gtest/gtest.h>

struct list {
    int data;
    list *next;
    list(int value) : data(value), next(nullptr) {}
};

bool has_cycle(list *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }

    list *slow = head;
    list *fast = head->next;

    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

TEST(has_cycle, HasCycle) {
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);
    head->next->next->next = head;  // цикл

    EXPECT_TRUE(has_cycle(head));

    head->next->next->next = nullptr; 
    delete head->next->next;
    delete head->next;
    delete head;
}

TEST(has_cycle, HasCycleInMiddle) {
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);
    head->next->next->next = head->next;  // цикл

    EXPECT_TRUE(has_cycle(head));

    head->next->next->next = nullptr; 
    delete head->next->next;
    delete head->next;
    delete head;
}

TEST(has_cycle, NoCycle) {
    list* head = new list(1);
    head->next = new list(2);
    head->next->next = new list(3);

    EXPECT_FALSE(has_cycle(head));

    delete head->next->next;
    delete head->next;
    delete head;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}