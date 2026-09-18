#include <iostream>
using namespace std;

struct Sensor
{
    int suhuTerakhir;
    int suhuTertinggi;
};


void updateSuhu(Sensor* sensor, int suhuBaru){
    sensor->suhuTerakhir = suhuBaru;
    if(suhuBaru > sensor->suhuTertinggi){
        sensor->suhuTertinggi = suhuBaru;
    }
}

int main(){
    Sensor snr;
    snr.suhuTerakhir = 30;
    snr.suhuTertinggi = 35;

    cout << snr.suhuTerakhir << endl;

    updateSuhu(&snr, 36);

    cout << snr.suhuTerakhir << endl;
    cout << snr.suhuTertinggi << endl;
       
}