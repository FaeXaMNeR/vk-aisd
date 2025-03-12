#include <iostream>

struct list {
    int data;
    list *next;
    list(int value) : data(value), next(nullptr) {}
};

list *merge(list *list1, list *list2) {
    list temp(0);
    list *tail = &temp;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data < list2->data) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    if (list1 != nullptr) tail->next = list1;
    else tail->next = list2;

    return temp.next;
}

void print(list *list) {
    while (list != nullptr) {
        std::cout << list->data << " ";
        list = list->next;
    }
    std::cout << "\n";
}

int main() {
    list* arr1 = new list(1);
    arr1->next = new list(4);
    arr1->next->next = new list(7);

    list* arr2 = new list(2);
    arr2->next = new list(3);
    arr2->next->next = new list(6);

    print(merge(arr1, arr2));

    return 0;
}