#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *top;
};

void buatStack(Stack *s)
{
    s->top = nullptr;
}

bool isEmpty(Stack *s)
{
    return s->top == nullptr;
}

void push(Stack *s, int nilai)
{
    Node *newNode = new Node;
    newNode->data = nilai;
    newNode->next = s->top;
    s->top = newNode;
}

bool peek(Stack *s)
{
    if (isEmpty(s))
        return false;
    cout << s->top->data << endl;
    return true;
}

bool pop(Stack *s)
{
    if (isEmpty(s))
        return false;

    Node *del = s->top;
    s->top = s->top->next; // miindah posisi top ke node bawahnya
    delete del;
    return true;
}

bool show(Stack *s)
{
    Node *curr = s->top;

    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next; // geser temp ke node di bawahnya
    }
   
    return true;
}

bool clear(Stack *s)
{
    while (s->top != nullptr)
    {
        Node *del = s->top;
        s->top = s->top->next;
        delete del;
    }
    return true;
}

int main()
{
    Stack stack;
    buatStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    show(&stack);
    peek(&stack);

    push(&stack, 5);
    peek(&stack);

    pop(&stack);
    peek(&stack);

    show(&stack);
}