#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
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

void tambahNode(int nilai)
{
    nodeBaru = new Node();
    nodeBaru->data = nilai;
    nodeBaru->next = nullptr;

    if (listkosong())
    {
        head = tail = nodeBaru;
        nodeBaru->next = head; // agar node terakhir nunjuk ke head
    }
    else if (nilai < head->data)
    {
        nodeBaru->next = head;
        head = nodeBaru;
        tail->next = head;
    }
    else if (nilai > tail->data)
    {
        tail->next = nodeBaru;
        tail = nodeBaru;
        tail->next = head;
    }
    else
    {
        tmp = head;
        while (tmp->next != head && tmp->next->data <= nilai)
        {
            tmp = tmp->next;
        }
        nodeBaru->next = tmp->next;
        tmp->next = nodeBaru;
    }
}

void print()
{
    if (listkosong())
    {
        cout << "List Ksoong" << endl;
        return;
    }

    tmp = head;

    do
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    } while (tmp != head);
    cout << endl;
}

void hapusNode(int infoHapus)
{
    if (listkosong())
    {
        cout << "List masih kosong" << endl;
        return;
    }

    tmp = tail, del = head;

    do
    {
        if (del->data == infoHapus)
        {

            // ketika hanya ada 1 node
            if (head == tail)
            {
                head = tail = nullptr;
            }
            else
            {
                tmp->next = del->next;

                // jika head yang dihapus
                if (del == head)
                {
                    head = del->next; // posisi head akan digeser ke node selanjutnya
                }

                // jika yang dihapus di tail
                if (del == tail)
                {
                    tail = tmp; // posisi tail akan di geser ke node sebelumnya (posisi temp sekarang)
                }
            }

            delete del;
            return;
        }
        tmp = del;       // posisi temp = del
        del = del->next; // posiis hapus digeser ke nextnya
    } while (del != head); // akan berulang terus sampai del kembali ke head

    cout << "Data tidak ditemukan" << endl;
}

int main()
{

    tambahNode(10);
    tambahNode(5);
    tambahNode(20);
    tambahNode(19);
    tambahNode(30);
    print();

    hapusNode(20);
    print();
}