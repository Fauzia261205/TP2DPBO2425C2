import java.util.Scanner;
import java.util.ArrayList;

// kelas Main
public class Main {

    // Fungsi cetak tabel
    public static void cetakTabel(ArrayList<Laptop> daftarLaptop) {
        String format = "%-8s %-20s %-6s %-10s %-10s %-10s %-15s %-10s %-12s%n";

        // Header tabel
        System.out.printf(format, "Kode", "Nama Produk", "Stok", "Merk", "Warna", "Garansi", "Ukuran Layar", "RAM", "Harga");
        System.out.println("-------------------------------------------------------------------------------------------------------------");

        // Isi tabel
        for (Laptop l : daftarLaptop) {
            System.out.printf(format,
                    l.getKode(),
                    l.getNama(),
                    l.getStok(),
                    l.getMerk(),
                    l.getWarna(),
                    l.getGaransi(),
                    l.getUkuranLayar(),
                    l.getRAM(),
                    (long) l.getHarga());
        }
    }

    // Fungsi tambah laptop
    public static void tambahLaptop(ArrayList<Laptop> daftarLaptop, Scanner sc) {
        System.out.println("\nInput Data Laptop Baru"); // Judul input data
        System.out.print("Kode Produk   : "); // Input kode produk
        String kode = sc.nextLine(); // Menerima input kode produk

        // cek apakah kode sudah ada
        int sudahAda = 0;
        // Loop untuk mengecek kode produk yang sudah ada
        for (Laptop l : daftarLaptop) {
            if (l.getKode().equals(kode)) { // Jika kode sudah ada
                sudahAda = 1; // Tandai sudah ada
            }
        }

        // Jika kode sudah ada, tampilkan pesan error
        if (sudahAda == 1) {
            System.out.println("Kode produk sudah ada, tidak bisa menambahkan laptop baru!");
        } 
        // Jika kode belum ada, lanjutkan input data laptop baru
        else {
            System.out.print("Nama Produk   : ");
            String nama = sc.nextLine();
            System.out.print("Stok          : ");
            int stok = Integer.parseInt(sc.nextLine());
            System.out.print("Merk          : ");
            String merk = sc.nextLine();
            System.out.print("Warna         : ");
            String warna = sc.nextLine();
            System.out.print("Garansi       : ");
            String garansi = sc.nextLine();
            System.out.print("Ukuran Layar  : ");
            String ukuranLayar = sc.nextLine();
            System.out.print("RAM           : ");
            String RAM = sc.nextLine();
            System.out.print("Harga         : ");
            double harga = Double.parseDouble(sc.nextLine());

            // Menambahkan laptop baru ke dalam daftar
            daftarLaptop.add(new Laptop(nama, kode, stok, merk, warna, garansi, ukuranLayar, RAM, harga));
            System.out.println("Data berhasil ditambahkan!");
        }
    }

    // Main method
    public static void main(String[] args) {
        // Inisialisasi daftar laptop dan scanner
        ArrayList<Laptop> daftarLaptop = new ArrayList<>();
        Scanner sc = new Scanner(System.in); // Scanner untuk input

        // Data awal
        daftarLaptop.add(new Laptop("Laptop Gaming", "L001", 20, "ASUS", "Hitam", "2 Tahun", "15.6 inci", "16 GB", 12000000));
        daftarLaptop.add(new Laptop("Laptop Bisnis", "L002", 15, "Acer", "Silver", "3 Tahun", "14 inci", "8 GB", 10000000));
        daftarLaptop.add(new Laptop("Laptop Ultrabook", "L003", 10, "Acer", "Putih", "1 Tahun", "13.3 inci", "16 GB", 15000000));
        daftarLaptop.add(new Laptop("Laptop Student", "L004", 5, "Lenovo", "Abu-abu", "2 Tahun", "14 inci", "8 GB", 13000000));
        daftarLaptop.add(new Laptop("Laptop Kreator", "L005", 8, "Apple", "Silver", "1 Tahun", "16 inci", "32 GB", 25000000));

        int pilihan; // Variabel untuk menyimpan pilihan menu
        do {
            System.out.println("\n===== MENU =====");
            System.out.println("1. Tambah Laptop");
            System.out.println("2. Lihat Tabel Laptop");
            System.out.println("3. Keluar");
            System.out.print("Pilih: "); // Prompt untuk pilihan menu
            pilihan = Integer.parseInt(sc.nextLine()); // Menerima input pilihan menu

            // Menangani pilihan menu
            if (pilihan == 1) {
                tambahLaptop(daftarLaptop, sc);
            } 
            // jika pilihan adalah 2, cetak tabel laptop
            else if (pilihan == 2) {
                System.out.println("\nDaftar Laptop:");
                cetakTabel(daftarLaptop);
            }

        } 

        // Ulangi selama pilihan bukan 3 (keluar)
        while (pilihan != 3);

        System.out.println("Program selesai.");
        sc.close();
    }
}
