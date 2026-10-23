#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *front;
    Node *rear;
};

Queue init()
{
    return Queue{nullptr, nullptr};
};

bool isEmpty(Queue &q)
{
    return q.front == nullptr;
}

bool enqueue(Queue &q, int nilai)
{
    Node *baru = new Node{nilai, nullptr};

    if (isEmpty(q))
    {
        q.front = baru;
        q.rear = baru;
    }
    else
    {
        q.rear->next = baru;
        q.rear = baru;
    }

    return true;
}

bool dequeue(Queue &q)
{
    if (isEmpty(q))
    {
        return false;
    }
    Node *hapus = q.front;

    q.front = q.front->next;

    if (q.front == nullptr)
    {
        q.rear = nullptr;
    }
    delete hapus;
    return true;
}

bool peek(Queue &q)
{
    if (isEmpty(q))
    {
        return false;
    }

    int nilaiDepan = q.front->data;
    cout << "Nilai depan : " << nilaiDepan << endl;

    int nilaiBlkg = q.rear->data;
    cout << "Nilai Belakang : " << nilaiBlkg << endl;
    return true;
};

void tampilkan(Queue &q)
{
    if (isEmpty(q)){
        cout <<"Queue kosong."<<endl;
        return;
    }

    Node *bantu = q.front;

    cout << "Isi Queue: ";

    while (bantu != nullptr)
    {
        cout << bantu->data << " ";
        bantu = bantu->next;
    }

    cout << "\n";
}

void clear(Queue &q){
    while(!isEmpty(q)){
        dequeue(q);
    }

    // q.front = nullptr;
    // q.rear = nullptr;
}

int main()
{
    Queue urutan = init();

    enqueue(urutan, 59);
    enqueue(urutan, 10);
    enqueue(urutan, 9);
    tampilkan(urutan);
    peek(urutan);
    dequeue(urutan);

    tampilkan(urutan);
    peek(urutan);

    clear(urutan);
    tampilkan(urutan);
}