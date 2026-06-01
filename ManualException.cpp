#include <iostream>
using namespace std;

int main()
{
    //membuat isi dari try untuk pengujian error
    try
    {
        cout << "Selamat belajar di prodi TI UMY" << endl;

        //throw 0.5; //melemparkan sebuah integer maka
        throw 5;

        cout << "Pernyataan tidak akan ditampilkan" << endl;
    }

    return 0;
}