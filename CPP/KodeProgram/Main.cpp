#include <iostream>
#include <string>
#include <vector>
#include "Produk.cpp" // class Produk, Elektronik, Laptop, dan fungsi cetakTabel

using namespace std;

int main() {
    // Vektor untuk menyimpan daftar laptop
    vector<Laptop> daftarLaptop;

    // Data awal
    daftarLaptop.push_back(Laptop("Laptop Gaming", "L001", 20, "ASUS", "Hitam", "2 Tahun", "15.6 inci", "16 GB", 12000000));
    daftarLaptop.push_back(Laptop("Laptop Bisnis", "L002", 15, "Acer", "Silver", "3 Tahun", "14 inci", "8 GB", 10000000));
    daftarLaptop.push_back(Laptop("Laptop Ultrabook", "L003", 10, "Acer", "Putih", "1 Tahun", "13.3 inci", "16 GB", 15000000));
    daftarLaptop.push_back(Laptop("Laptop Student", "L004", 5, "Lenovo", "Abu-abu", "2 Tahun", "14 inci", "8 GB", 13000000));
    daftarLaptop.push_back(Laptop("Laptop Kreator", "L005", 8, "Apple", "Silver", "1 Tahun", "16 inci", "32 GB", 25000000));

    // Menu interaktif
    int pilihan;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Tambah Laptop" << endl;
        cout << "2. Lihat Tabel Laptop" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan; // input pilihan
        cin.ignore(); // bersihkan newline dari buffer

        // Proses pilihan
        if (pilihan == 1) {
            // jika pilihan 1, panggil fungsi tambahLaptop
            tambahLaptop(daftarLaptop); // panggil fungsi tambahLaptop
        } 
        // jika pilihan 2, panggil fungsi cetakTabel
        else if (pilihan == 2) {
            cout << "\nDaftar Laptop:\n";
            cetakTabel(daftarLaptop);
        }

    } 
    // jika pilihan 3, keluar dari loop
    while (pilihan != 3);

    cout << "Program selesai." << endl;
    
    return 0;
}