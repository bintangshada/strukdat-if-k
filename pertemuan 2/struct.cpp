#include <iostream>

using namespace std;

int main()
{
    struct Mahasiswa
    {
        string nim;
        string nama;
        int ipk;
    };

    Mahasiswa mhs;
    Mahasiswa *ptr = &mhs;

    ptr->nim = "1232456";
    ptr->nama = "Bintang";
    ptr->ipk = 4;

    cout << ptr << endl;
    cout << &mhs.nim << endl;
    cout << mhs.nama << endl;
    cout << mhs.ipk << endl;
}