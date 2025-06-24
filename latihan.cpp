#include<iostream>
#include<string>
using namespace std;

class makanan{
    public:
    int noPesanan;
    string nama;
    float harga;

    void printdata(){
        cout << "noPesanan \n" << noPesanan << endl;
        cout << "nama \n" << nama << endl;
        cout << "harga \n" << harga << endl;
    }
};

int main(){
    makanan mkn;
    mkn.noPesanan = 123;
    mkn.nama = "soto";
    mkn.harga = 50000;

  
}