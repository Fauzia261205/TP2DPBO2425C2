#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Kelas Produk
class Produk{
    private:
    string nama;
    string kode;
    int stok;

    // Konstruktor, getter, dan setter
    public:
    Produk(string nama, string kode, int stok){
            this->nama = nama;
            this->kode = kode;
            this->stok = stok;
        }

        string getNama(){
            return nama;
        }

        string getKode(){
            return kode;
        }

        int getStok(){
            return stok;
        }
};

// Kelas turunan dari Produk
// Kelas Elektronik
class barangElektronik : public Produk {
    private :
    string merk;
    string warna;
    string garansi;

    // Konstruktor, getter, dan setter
    public :
    barangElektronik(string nama, string kode, int stok, string merk, string warna, string garansi) : Produk(nama, kode, stok) {
        this->merk = merk;
        this->warna = warna;
        this->garansi = garansi;
    }
    string getMerk() {
        return merk;
    }
    string getWarna() {
        return warna;
    }
    string getGaransi() {
        return garansi;
    }
};

// Kelas Laptop
// Turunan dari kelas Elektronik
class Laptop : public barangElektronik {
    private :
    string ukuranlayar;
    string RAM;
    double harga;

    // Konstruktor, getter, dan setter
    public :
    Laptop(string nama, string kode, int stok, string merk, string warna, string garansi, string ukuranlayar, string RAM, double harga) : barangElektronik(nama, kode, stok, merk, warna, garansi) {
        this->ukuranlayar = ukuranlayar;
        this->RAM = RAM;
        this->harga = harga;
    }

    string getUkuranLayar() {
        return ukuranlayar;
    }
    string getRAM() {
        return RAM;
    }
    double getHarga() {
        return harga;
    }

};

// Fungsi untuk mencetak tabel
void cetakTabel(vector<Laptop> &daftarlaptop) {
    // Header kolom
    vector<string> header = {
        "Kode", "Nama Produk", "Stok", "Merk", "Warna",
        "Garansi", "Ukuran Layar", "RAM", "Harga"
    };

    // Hitung lebar kolom maksimum
    vector<size_t> lebarKolom(header.size());
    // Inisialisasi lebar kolom dengan panjang header
    for (size_t i = 0; i < header.size(); i++) {
        lebarKolom[i] = header[i].size(); // Inisialisasi dengan panjang header
    }

    // Periksa setiap data laptop untuk menentukan lebar kolom maksimum
    for (auto &laptop : daftarlaptop) {
        // Buat vektor sementara untuk menyimpan data baris
        vector<string> baris = {
            laptop.getKode(),
            laptop.getNama(),
            to_string(laptop.getStok()),
            laptop.getMerk(),
            laptop.getWarna(),
            laptop.getGaransi(),
            laptop.getUkuranLayar(),
            laptop.getRAM(),
            to_string((long long)laptop.getHarga())
        };
        // Bandingkan dan perbarui lebar kolom maksimum
        for (size_t i = 0; i < baris.size(); i++) {
            // Jika panjang data baris lebih besar, perbarui lebar kolom
            if (baris[i].size() > lebarKolom[i])
            // Perbarui lebar kolom
                lebarKolom[i] = baris[i].size();
        }
    }

    // Cetak header
    for (size_t i = 0; i < header.size(); i++) {
        // Set lebar kolom dan rata kiri
        cout << left << setw(lebarKolom[i] + 2) << header[i];
    }
    cout << endl;

    // Cetak garis
    for (size_t i = 0; i < header.size(); i++) {
        cout << string(lebarKolom[i] + 2, '-') ;
    }
    cout << endl;

    // Cetak isi tabel
    for (auto &laptop : daftarlaptop) {
        vector<string> baris = {
            laptop.getKode(),
            laptop.getNama(),
            to_string(laptop.getStok()),
            laptop.getMerk(),
            laptop.getWarna(),
            laptop.getGaransi(),
            laptop.getUkuranLayar(),
            laptop.getRAM(),
            to_string((long long)laptop.getHarga())
        };
        // Cetak setiap kolom dengan lebar yang sudah ditentukan
        for (size_t i = 0; i < baris.size(); i++) {
            cout << left << setw(lebarKolom[i] + 2) << baris[i];
        }
        cout << endl;
    }
}

// Fungsi untuk menambah laptop baru
void tambahLaptop(vector<Laptop> &daftarLaptop) {
    // Variabel untuk menyimpan input
    string kode, nama, merk, warna, garansi, ukuranLayar, RAM;
    int stok;
    double harga;

    // Input data laptop baru
    cout << "\nInput Data Laptop Baru" << endl;
    cout << "Kode Produk   : "; getline(cin, kode);

    // Cek apakah kode sudah ada
    int sudahAda = 0;
    // Loop untuk cek kode
    for (size_t i = 0; i < daftarLaptop.size(); i++) {
        if (daftarLaptop[i].getKode() == kode) {
            sudahAda = 1; // kode sudah ada
        }
    }

    // Jika kode sudah ada, tampilkan pesan dan keluar dari fungsi
    if (sudahAda) {
        cout << "Kode produk sudah ada, tidak bisa menambahkan laptop baru!\n";
        return;
    }

    // Lanjutkan input data lainnya
    cout << "Nama Produk   : "; getline(cin, nama);
    cout << "Stok          : "; cin >> stok; cin.ignore();
    cout << "Merk          : "; getline(cin, merk);
    cout << "Warna         : "; getline(cin, warna);
    cout << "Garansi       : "; getline(cin, garansi);
    cout << "Ukuran Layar  : "; getline(cin, ukuranLayar);
    cout << "RAM           : "; getline(cin, RAM);
    cout << "Harga         : "; cin >> harga; cin.ignore();

    // Tambah laptop baru ke dalam daftar
    daftarLaptop.push_back(Laptop(nama, kode, stok, merk, warna, garansi, ukuranLayar, RAM, harga));
    cout << "Laptop berhasil ditambahkan!\n";
}