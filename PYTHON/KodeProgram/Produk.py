# kelas Produk
class Produk:
    def __init__(self, nama, kode, stok): # atribut dasar produk
        self.nama = nama
        self.kode = kode
        self.stok = stok

# kelas BarangElektronik yang mewarisi kelas Produk
class BarangElektronik(Produk):
    # atribut tambahan untuk barang elektronik
    def __init__(self, nama, kode, stok, merk, warna, garansi):
        # memanggil konstruktor kelas induk
        super().__init__(nama, kode, stok)
        self.merk = merk
        self.warna = warna
        self.garansi = garansi

# kelas Laptop yang mewarisi kelas BarangElektronik
class Laptop(BarangElektronik):
    # atribut tambahan untuk laptop
    def __init__(self, nama, kode, stok, merk, warna, garansi, ukuran_layar, RAM, harga):
        # memanggil konstruktor kelas induk
        super().__init__(nama, kode, stok, merk, warna, garansi)
        self.ukuran_layar = ukuran_layar
        self.RAM = RAM
        self.harga = harga

# fungsi untuk mencetak tabel daftar laptop
def cetak_tabel(daftar_laptop):
    # Header tabel
    header = ["Kode", "Nama Produk", "Stok", "Merk", "Warna", "Garansi", "Ukuran Layar", "RAM", "Harga"]
    # Lebar kolom berdasarkan panjang header
    lebar = [len(h) for h in header]
    # Hitung lebar kolom berdasarkan data
    for l in daftar_laptop:
        # Ambil data sebagai string untuk menghitung panjangnya
        data = [l.kode, l.nama, str(l.stok), l.merk, l.warna, l.garansi, l.ukuran_layar, l.RAM, str(int(l.harga))]
        for i in range(len(data)):
            lebar[i] = max(lebar[i], len(data[i]))
    
    # Cetak header
    for i, h in enumerate(header):
        # Cetak nama kolom dengan lebar yang sesuai
        print(h.ljust(lebar[i] + 2), end="")
        print()
        print("-" * (sum(lebar) + 2 * len(lebar)))

    # Cetak isi tabel
    for l in daftar_laptop:
        # Ambil data sebagai string untuk konsistensi
        data = [l.kode, l.nama, str(l.stok), l.merk, l.warna, l.garansi, l.ukuran_layar, l.RAM, str(int(l.harga))]
        # Cetak setiap kolom dengan lebar yang sesuai
        for i, d in enumerate(data):
            print(d.ljust(lebar[i] + 2), end="")
            print()

# fungsi untuk menambahkan laptop baru ke daftar
def tambah_laptop(daftar_laptop):
    # Input data laptop baru
    kode = input("Kode Produk   : ")

    # Cek apakah kode sudah ada
    if any(l.kode == kode for l in daftar_laptop):
        print("Kode produk sudah ada, tidak bisa menambahkan laptop baru!")
        return

        # Jika kode belum ada, lanjutkan input data lainnya
        nama = input("Nama Produk   : ")
        stok = int(input("Stok          : "))
        merk = input("Merk          : ")
        warna = input("Warna         : ")
        garansi = input("Garansi       : ")
        ukuran_layar = input("Ukuran Layar  : ")
        RAM = input("RAM           : ")
        harga = float(input("Harga         : "))
        # Buat objek Laptop baru dan tambahkan ke daftar
        daftar_laptop.append(Laptop(nama, kode, stok, merk, warna, garansi, ukuran_layar, RAM, harga))
        print("Data berhasil ditambahkan!")
