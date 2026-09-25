#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;
Node *tail = nullptr;
Node *del = nullptr;
Node *tmp = nullptr;
Node *nodeBaru = nullptr;

bool listkosong()
{
    return (head == nullptr);
}

void cetakMaju()
{
    if (listkosong())
    {
        cout << "List kosong" << endl;
    }
    else
    {
        tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
    cout << endl;
}

void sisipDepan(int data)
{
    nodeBaru = new Node();
    nodeBaru->data = data;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (listkosong())
    {
        head = tail = nodeBaru;
    }
    else
    {
        nodeBaru->next = head;
        head->prev = nodeBaru;
        head = nodeBaru;
    }
}

void sisipBelakang(int data)
{
    nodeBaru = new Node();
    nodeBaru->data = data;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (listkosong())
    {
        head = tail = nodeBaru;
    }
    else
    {
        nodeBaru->prev = tail;
        tail->next = nodeBaru;
        tail = nodeBaru;
    }
}

void sisipTengah(int data)
{
    nodeBaru = new Node();
    nodeBaru->data = data;
    nodeBaru->next = nullptr;
    nodeBaru->prev = nullptr;

    if (listkosong())
    {
        cout << "List kosong" << endl;
    }
    else
    {
        tmp = head;
        while (tmp->next != nullptr && tmp->next->data < data)
        {
            tmp = tmp->next;
        }

        nodeBaru->next = tmp->next;

        if (tmp->next != nullptr)
        {
            tmp->next->prev = nodeBaru;
        }

        tmp->next = nodeBaru;
        nodeBaru->prev = tmp;
    }
}

void cetakMundur()
{
    if (listkosong())
    {
        cout << "List kosong" << endl;
    }
    else
    {
        tmp = tail;
        while (tmp != nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->prev;
        }
    }
    cout << endl;
}

void hapusNode(int infoHapus)
{
    if (listkosong())
    {
        cout << "List kosong" << endl;
    }
    else if (infoHapus == head->data)// jika node yang dihapus ada di head
    { 
        del = head;

        if (head == tail)
        { // jika di list hanya ada 1 node
            head = nullptr;
            tail = nullptr;
        }
        else
        { // jika list lebih dari 1 node
            head = head->next;
            head->prev = nullptr;
        }
        delete del;
    }
    else  // jika yang dihapus bukan di head
    { 
        tmp = head->next;
        while (tmp != nullptr && tmp->data != infoHapus)
        {
            tmp = tmp->next;
        }
        del = tmp;
        
        if (del != nullptr)
        {
            if (del->prev != nullptr)
            {
                del->prev->next = del->next;
            }
            if (del->next != nullptr)
            {
                del->next->prev = del->prev;
            }
            if (del == tail)
            {
                tail = del->prev;
            }
            delete del;
        }
    }
}

int main()
{
    sisipDepan(10);
    sisipBelakang(30);
    sisipTengah(20);
    cetakMaju();
    cetakMundur();
}