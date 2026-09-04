#include <iostream>
using namespace std;

void reversalArray(int data[], int n)
{
    cout << "Alamat dalam fungsi : " << data << endl;
    cout << "Alamat Kapasitas dalam fungsi : " << &n << endl;
    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n / 2; i++)
    {
        int tmp = data[i];
        data[i] = data[n - 1 - i];
        data[n - 1 - i] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << data[i] << " ";
    }
};

int main()
{

    struct  Mahasiswa
    {
        string nama;
        float nilai;
    };

    Mahasiswa m[2];
    //assign value struct
    m[0].nama = "Rizky";
    m[0].nilai = 98.0;

    m[1].nama = "Dewi";
    m[1].nilai = 80;
    
    int nilaiTertinggi = 0;
    for (int i = 0; i < 2; i++)
    {
        if(nilaiTertinggi < m[i].nilai){
            nilaiTertinggi = m[i].nilai;
        }
    }
    cout << "Nilai mahasiwa tertinggi : " << nilaiTertinggi << endl;
    

    // mengumpulkan
    const int KAPASITAS = 4;
    int data[KAPASITAS] = {10, 20, 30, 40};

    int total;
    for (int i = 0; i < KAPASITAS; i++)
    {
        total = total + data[i];
    }
    cout << "Total nilai : " << total << endl;

    // mencari nilai maksimal
    int maks = 0;
    for (int i = 0; i < KAPASITAS; i++)
    {
        if (data[i] > maks)
        {
            maks = data[i];
        }
    }
    cout << "Nilai maksimal : " << maks << endl;
    cout << &data << endl;
    cout << "alamat kapasitas : " << &KAPASITAS << endl;
    reversalArray(data, KAPASITAS);
}
