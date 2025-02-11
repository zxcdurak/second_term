#include <iostream>
#include <array>

#define length_array 10

typedef struct el { int value; struct el* next; } list_elem;

list_elem* generate_list(int n) {

    list_elem* head = nullptr;
    list_elem* curr = nullptr;
    list_elem* prev = nullptr;

    for (int i = 0; i < length_array; i++) {
        curr = new list_elem;
        curr->value = i;
        curr->next = nullptr;
        if (i == 0) {
            head = curr;
        }
        else {
            prev->next = curr;
        }
        prev = curr;
    }
    return head;
}

void print_list(list_elem* head) {
    list_elem* curr = head;
    while (curr != nullptr) {
        std::cout << curr->value << "\n";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void delete_list(list_elem* head) {
    list_elem* curr = head;
    while (curr != nullptr) {
        list_elem* next = curr->next;
        delete curr;
        curr = next;
    }
}

void index(int* arr) {

    for (int i = 0; i < length_array; i++) {
        arr[i] = i * i;
        std::cout << arr[i] << "\n";
    }
    std::cout << "\n";
}

void pointer(int* arr) {
    int* p = arr;

    for (int i = 0; i < length_array; i++) {
        *p = i * i;
        std::cout << *p << "\n";
        p++;
    }
    std::cout << "\n";
}

void exercise_1() {
    int static_array[length_array];
    int* dynamic_array = new int[length_array];
    index(static_array);
    pointer(static_array);
    index(dynamic_array);
    pointer(dynamic_array);
    delete[] dynamic_array;
}

void exercise_2() {
    list_elem* head;
    head = generate_list(length_array);
    print_list(head);
    delete_list(head);
}

int main()
{
    //exercise_1();
    exercise_2();
    return 0;
}


