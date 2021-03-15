#include <iostream>

struct Node{
    int value;
    struct Node *next;
};

bool is_empty(Node* head)
{
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}

int pop(Node** head)
{
    Node* memory = *head;
    *head = (**head).next;
    delete memory;
    return (*memory).value;
}

void print_stack(Node* head)
{
    Node* p_node = head;
    while ((*p_node).next != NULL) {
        std::cout << (*p_node).value << ' ';
        p_node = (*p_node).next;
    }
    std::cout << (*p_node).value << ' ';
    std::cout << '\n';
}

void push(Node** head, int value)
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

int top(Node* head)
{
    return (*head).value;
}

int main()
{
    Node* stack = NULL;
    int depth = 0;
    int number;
    do{
        std::cin >> number;
        if (number != 0){
            if (number > 0){
                push(&stack, number);
                depth ++;
            }
            else{
                if (!is_empty(stack)){
                    if (-number < top(stack)){
                        (*stack).value = (*stack).value + number;
                    }
                    else{
                        pop(&stack);
                        depth --;
                    }
                }
            }
        }
    } while (number != 0);
    std::cout << depth << ' ';
    if(!is_empty(stack)){
        std::cout << top(stack);
    }
    else{
        std::cout << -1;
    }
}
