#include <iostream>
#include <bits/stdc++.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void clear_list(Node** head)
{
    while (*head != NULL){
        Node* next_node = (**head).next;
        delete (*head);
        *head = next_node;
     }
     std::cout << "Cleared" << '\n';
}

int pop(Node** head, int index)
{
    if (*head == NULL){
        return INT_MIN;
    }
    Node* pop_node = *head;
    if (index == 0){
        Node* memory = *head;
        *head = (**head).next;
        delete memory;
    }
    else{
        for (int i = 1; i < index; i ++){
            pop_node = (*pop_node).next;
            if ((*pop_node).next == NULL){
                std::cout << "No index" << '\n';
                return INT_MIN;
            }
        }
        Node* memory = (*pop_node).next;
        (*pop_node).next = (*memory).next;
        delete memory;
    }
    std::cout << "Index " << index << " popped" << '\n';
    return (*pop_node).value;
}

void print_list(Node* head)
{
    if (head == NULL){
        std::cout << "Empty" << '\n';
    }
    else{
        Node* p_node = head;
        while ((*p_node).next != NULL) {
            std::cout << (*p_node).value << ' ';
            p_node = (*p_node).next;
        }
        std::cout << (*p_node).value << ' ';
        std::cout << '\n';
    }
}

void push_left(Node** head, int value)
{
    if (*head == NULL){
        *head = new Node;
        (**head).value = value;
        (**head).next = NULL;
        return;
    }
    Node* new_node = new Node;
    (*new_node).value = value;
    (*new_node).next = *head;
    *head = new_node;
}

void remove(Node** head, int value)
{
    if (*head == NULL){
        return;
    }
    Node* remove_node = *head;
    if ((**head).value == value){
        Node* memory = *head;
        *head = (**head).next;
        delete memory;
        return;
    }
    while ((*remove_node).next != NULL){
        if ((*(*remove_node).next).value == value){
            Node* memory = (*remove_node).next;
            (*remove_node).next = (*memory).next;
            delete memory;
            std::cout << "Removed" << '\n';
            return;
        }
        remove_node = (*remove_node).next;
    }
    std::cout << "No value" << '\n';
    return;
}

void remove_all(Node** head, int value)
{
    if (*head == NULL){
        return;
    }
    int amount = 0;
    while((**head).value == value){
        if ((**head).next != NULL){
            Node* memory = *head;
            *head = (**head).next;
            delete memory;
            amount ++;
        }
        else{
            delete *head;
            amount ++;
            *head = NULL;
            std::cout << amount << " indexes removed" << '\n';
            return;
        }
    }
    Node* remove_node = *head;
    while ((*remove_node).next != NULL){
        if ((*(*remove_node).next).value == value){
            Node* memory = (*remove_node).next;
            (*remove_node).next = (*memory).next;
            delete memory;
            amount ++;
        }
        else{
            remove_node = (*remove_node).next;
        }
    }
    std::cout << amount << " indexes removed" << '\n';
    return;
}

void replace_all(Node* head, int old_int, int new_int)
{
    if (head != NULL){
        Node* node = head;
        while ((*node).next != NULL){
            if ((*node).value == old_int){
                (*node).value = new_int;
            }
            node = (*node).next;
            if ((*node).value == old_int){
                (*node).value = new_int;
            }
        }
    }
    return;
}

void reverse(Node** head)
{
    if (*head != NULL){
        int amount = 1;
        Node* node = *head;
        while((*node).next != NULL){
            node = (*node).next;
            amount ++;
        }
        int* matrix = new int[amount];
        node = *head;
        int itt = 0;
        while((*node).next != NULL){
            matrix[itt] = (*node).value;
            itt ++;
            node = (*node).next;
        }
        matrix[itt] = (*node).value;
        *head = NULL;
        for (int i = 0; i < itt + 1; i++){
            push_left(head, matrix[i]);
        }
    delete[] matrix;
    }
    return;
}

int unique(Node* head)
{
    int itt = 0;
    if (head != NULL){
        int amount = 1;
        Node* node = head;
        while((*node).next != NULL){
            node = (*node).next;
            amount ++;
        }
        int* matrix = new int[amount];
        int err = 0;
        node = head;
        while((*node).next != NULL){
            for(int i = 0; i < itt; i++){
                err = 0;
                if (matrix[i] == (*node).value){
                    err ++;
                }
            }
            if (err == 0){
                matrix[itt] = (*node).value;
                itt ++;
            }
            node = (*node).next;
        }
        for(int i = 0; i < itt; i++){
            err = 0;
            if (matrix[i] == (*node).value){
                err ++;
            }
        }
        if (err == 0){
            matrix[itt] = (*node).value;
            itt ++;
        }
        delete[] matrix;
    }
    return itt;
}

int main()
{
    Node* list = NULL;
    std::cout << "Enter nodes amount -> ";
    size_t amount;
    std::cin >> amount;
    int number, value;
    for (int i = 0; i < amount; ++i){
        number = i + 1;
        std::cout << "Enter " << number << " node value -> ";
        std::cin >> value;
        push_left(&list, value);
    }
    std::cout << "Created" << '\n';
    print_list(list);
    std::cout << "Enter index to pop -> ";
    int pop_index;
    std::cin >> pop_index;
    pop(&list, pop_index) << '\n';
    print_list(list);
    std::cout << "Enter value to remove -> ";
    int remove_value;
    std::cin >> remove_value;
    remove(&list, remove_value);
    print_list(list);
    std::cout << "Enter value to remove all -> ";
    int remove_all_value;
    std::cin >> remove_all_value;
    remove_all(&list, remove_all_value);
    print_list(list);
    std::cout << "Enter old int and new int to replace -> ";
    int old_int, new_int;
    std::cin >> old_int >> new_int;
    replace_all(list, old_int, new_int);
    print_list(list);
    std::cout << "Unique -> " << unique(list) << '\n';
    reverse(&list);
    std::cout << "Reversed" << '\n';
    print_list(list);
    clear_list(&list);
    print_list(list);
    return 0;
}
