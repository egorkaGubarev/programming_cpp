#include <iostream>
#include <string>

struct Node{
    int value;
    struct Node *next;
};

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

int pop(Node** head)
{
    Node* memory = *head;
    int pop_value = (**head).value;
    *head = (**head).next;
    delete memory;
    return pop_value;
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

int main()
{
    int current_code, n1, n2, r;
    int digit_counter = 0, number = 0, i = 0;
    bool negative = false;
    char current_symbol, next_symbol;
    std::string polish;
    Node* stack = NULL;
    std::getline(std::cin, polish);
    do{
        current_symbol = polish[i];
        next_symbol = polish[i + 1];
        i ++;
        current_code = current_symbol - '0';
        if (current_code > -1 && current_code < 10){
            number = number * 10 + current_code;
            digit_counter ++;
        }
        if (current_symbol == ' ' && digit_counter > 0){
            if (negative){
                number = -number;
                negative = false;
            }
            push(&stack, number);
            number = 0;
            digit_counter = 0;
        }
        if (current_symbol == '+'){
            n1 = pop(&stack);
            n2 = pop(&stack);
            r = n2 + n1;
            push(&stack, r);
        }
        if (current_symbol == '*'){
            n1 = pop(&stack);
            n2 = pop(&stack);
            r = n2 * n1;
            push(&stack, r);
        }
        if (current_symbol == '/'){
            n1 = pop(&stack);
            n2 = pop(&stack);
            r = n2 / n1;
            push(&stack, r);
        }
        if (current_symbol == '-' && (next_symbol == ' ' || next_symbol == '\0')){
            n1 = pop(&stack);
            n2 = pop(&stack);
            r = n2 - n1;
            push(&stack, r);
        }
        if (current_symbol == '-' && next_symbol != ' '){
            negative = true;
        }
    } while (current_symbol != '\0');
    r = pop(&stack);
    std::cout << r;
    return 0;
}
