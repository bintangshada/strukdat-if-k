#include <iostream>

using namespace std;

void tambahNilai(int* nilai){
    *nilai = 100;
    cout << "Nilai di fungsi : " << *nilai << endl; // 100
    cout << "Alamat Nilai di fungsi : " << nilai << endl;
}

int main(){
    int nilai = 90;
    
    cout << "Alamat Nilai di main : " << &nilai << endl;
    cout << "Nilai di main : " << nilai << endl; // 90

    tambahNilai(&nilai);
    
    cout << "Nilai di setelah fungsi : " << nilai << endl; // 90
    

}