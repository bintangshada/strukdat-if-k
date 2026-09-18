#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *buatNode(int nilai)
{
    return new Node{nilai, nullptr};
}

void tambahAwal(Node *&head, Node *&tail, int data)
{
    Node *baru = buatNode(data);

    if (data < head->data)
    {
        if (head == nullptr)
        {
            head = baru;
            tail = baru;
            return;
        }
        baru->next = head;
        head = baru;
    }
    else
    {
        cout << "Data terlalu besar daripada head" << endl;
    }
}

void tambahAkhir(Node *&head, Node *&tail, int data)
{
    Node *baru = buatNode(data);

    if (data > tail->data)
    {
        if (head == nullptr)
        {
            head = baru;
            tail = baru;
            return;
        }
        tail->next = baru;
        tail = baru;
    }
    else
    {
        cout << "Data terlalu kecil daripada tail" << endl;
    }
}

void tambahTengah(Node *&head, Node *&tail, int data)
{
    Node *baru = buatNode(data);
    baru->next = nullptr;

    if (head->data > data)
    {
        cout << "data terlalu kecil daripada head" << endl;
    }
    else if (tail->data < data)
    {
        cout << "data terlalu besar daripada tail" << endl;
    }
    else
    {
        if (head == nullptr)
        {
            head = baru;
            tail = baru;
            return;
        }

        Node *temp = head;

        while (temp != NULL && baru->data > temp->next->data)
        {
            temp = temp->next;
        }

        baru->next = temp->next;
        temp->next = baru;
    }
}

bool hapusData(Node *&head, int nilai)
{
    if (head == nullptr)
        return false;

    Node *target = head;
    Node *sebelum = nullptr;

    while (target != nullptr && target->data != nilai)
    {
        sebelum = target;
        target = target->next;
    }

    if (target == nullptr)
        return false;

    if (sebelum == nullptr)
        head = target->next;
    else
        sebelum->next = target->next;

    delete target;
    return true;
}

void bacaMaju(Node *head)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void bacaMundur(Node *head)
{
    if (head == nullptr)
    {
        return;
    }

    bacaMundur(head->next);

    cout << head->data << " ";
}

int main()
{
    Node *pertama = buatNode(10);

    Node *head = pertama;
    Node *tail = pertama;
    // head -> pertama
    // tail -> pertama

    tambahAwal(head, tail, 5);
    // head -> [5] -> [10] -> nullptr
    tambahAkhir(head, tail, 20);
    // head -> [5] -> [10] -> [20] -> nullptr
    cout << tail->data << endl;

    tambahTengah(head, tail, 7);
    bacaMaju(head);
    hapusData(head, 10);
    bacaMaju(head);
    tambahTengah(head, tail, 1);
    bacaMaju(head);
    bacaMundur(head);
}