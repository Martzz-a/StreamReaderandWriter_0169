#include <iostream>
#include <fstream>
#include <array>
#include <string>

using namespace std;

class TokoElektronik {
private:
    array<string, 3> etalase;

public:
    TokoElektronik() {
        etalase[0] = "Laptop";
        etalase[1] = "Mouse";
        etalase[2] = "Keyboard";
    }

    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        }
        catch (out_of_range&) {
            throw string(
                "Gagal Mengambil Barang : Rak nomor "
                + to_string(nomorRak)
                + " kosong atau tidak tersedia!"
            );
        }
    }
};

void readBarang() {
    string baris;
    ifstream file("gudang.txt");

    cout << "\n=== DAFTAR BARANG GUDANG ===" << endl;

    if (file.is_open()) {
        while (getline(file, baris)) {
            cout << "- " << baris << endl;
        }
        file.close();
    } else {
        cout << "Belum ada data barang." << endl;
    }
}

void createBarang() {
    string barang;

    cout << "Nama barang : ";
    cin.ignore();
    getline(cin, barang);

    ofstream file("gudang.txt", ios::app);
    file << barang << endl;
    file.close();

    cout << "Barang berhasil ditambahkan." << endl;
}

void updateBarang() {
    string data[100];
    string baris, barangBaru;
    int jumlah = 0, nomor;

    ifstream file("gudang.txt");

    while (getline(file, baris)) {
        data[jumlah] = baris;
        jumlah++;
    }

    file.close();

    cout << "Nomor barang yang diubah : ";
    cin >> nomor;

    if (nomor < 1 || nomor > jumlah) {
        cout << "Nomor barang tidak tersedia." << endl;
        return;
    }

    cout << "Nama barang baru : ";
    cin.ignore();
    getline(cin, barangBaru);

    data[nomor - 1] = barangBaru;

    ofstream out("gudang.txt");

    for (int i = 0; i < jumlah; i++) {
        out << data[i] << endl;
    }

    out.close();

    cout << "Barang berhasil diubah." << endl;
}

void deleteBarang() {
    string data[100];
    string baris;
    int jumlah = 0, nomor;

    ifstream file("gudang.txt");

    while (getline(file, baris)) {
        data[jumlah] = baris;
        jumlah++;
    }

    file.close();

    cout << "Nomor barang yang dihapus : ";
    cin >> nomor;

    if (nomor < 1 || nomor > jumlah) {
        cout << "Nomor barang tidak tersedia." << endl;
        return;
    }

    ofstream out("gudang.txt");

    for (int i = 0; i < jumlah; i++) {
        if (i != nomor - 1) {
            out << data[i] << endl;
        }
    }

    out.close();

    cout << "Barang berhasil dihapus." << endl;
}

void simulasiEtalase() {
    TokoElektronik toko;

    cout << "\n=== SIMULASI ETALASE ===" << endl;

    try {
        cout << "Skenario 1: Rak index ke-1" << endl;
        cout << "Barang: " << toko.ambilProduk(1) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }

    try {
        cout << "\nSkenario 2: Rak index ke-5" << endl;
        cout << "Barang: " << toko.ambilProduk(5) << endl;
    }
    catch (string pesan) {
        cout << pesan << endl;
    }
}

int main() {
    int pilihan;

    do {
        readBarang();

        cout << "\n=== MENU TOKO GIBRAN JAYA ===" << endl;
        cout << "1. Create Barang" << endl;
        cout << "2. Read Barang" << endl;
        cout << "3. Update Barang" << endl;
        cout << "4. Delete Barang" << endl;
        cout << "5. Simulasi Etalase" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            createBarang();
            break;
        case 2:
            readBarang();
            break;
        case 3:
            updateBarang();
            break;
        case 4:
            deleteBarang();
            break;
        case 5:
            simulasiEtalase();
            break;
        case 0:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia." << endl;
        }

    } while (pilihan != 0);

    return 0;
}