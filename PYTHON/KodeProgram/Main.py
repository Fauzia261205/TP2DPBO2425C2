from Produk import Laptop, tambah_laptop, cetak_tabel

# Fungsi utama untuk menjalankan program
def main():
    # Daftar laptop awal
    daftar_laptop = [
        Laptop("Laptop Gaming", "L001", 20, "ASUS", "Hitam", "2 Tahun", "15.6 inci", "16 GB", 12000000),
        Laptop("Laptop Bisnis", "L002", 15, "Acer", "Silver", "3 Tahun", "14 inci", "8 GB", 10000000),
        Laptop("Laptop Ultrabook", "L003", 10, "Acer", "Putih", "1 Tahun", "13.3 inci", "16 GB", 15000000),
        Laptop("Laptop Student", "L004", 5, "Lenovo", "Abu-abu", "2 Tahun", "14 inci", "8 GB", 13000000),
        Laptop("Laptop Kreator", "L005", 8, "Apple", "Silver", "1 Tahun", "16 inci", "32 GB", 25000000),
    ]

    # Menu interaktif
    while True:
        print("\n===== MENU =====")
        print("1. Tambah Laptop")
        print("2. Lihat Tabel Laptop")
        print("3. Keluar")
        # Input pilihan menu
        pilihan = input("Pilih: ")

        # Eksekusi berdasarkan pilihan
        # jika pilihan 1, panggil fungsi tambah_laptop
        if pilihan == "1":
            print("\nInput Data Laptop Baru")
            tambah_laptop(daftar_laptop)
        # jika pilihan 2, panggil fungsi cetak_tabel
        elif pilihan == "2":
            print("\nDaftar Laptop:")
            cetak_tabel(daftar_laptop)
        # jika pilihan 3, keluar dari program
        elif pilihan == "3":
            print("Program selesai.")
            return
        # jika pilihan tidak valid, tampilkan pesan kesalahan
        else:
            print("Pilihan tidak valid!")

# menjalankan fungsi utama jika file ini dijalankan langsung
if __name__ == "__main__":
    main()
