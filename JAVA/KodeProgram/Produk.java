import java.util.ArrayList;
import java.util.Scanner;

// kelas Produk
class Produk {
    private String nama;
    private String kode;
    private int stok;

    // Konstruktor untuk inisialisasi atribut
    public Produk(String nama, String kode, int stok) {
        this.nama = nama;
        this.kode = kode;
        this.stok = stok;
    }

    // Getter untuk atribut
    public String getNama() {
        return nama;
    }

    public String getKode() {
        return kode;
    }

    public int getStok() {
        return stok;
    }
}

// kelas BarangElektronik yang mewarisi kelas Produk
class BarangElektronik extends Produk {
    private String merk;
    private String warna;
    private String garansi;

    // konstruktor untuk inisialisasi atribut
    public BarangElektronik(String nama, String kode, int stok, String merk, String warna, String garansi) {
        super(nama, kode, stok);
        this.merk = merk;
        this.warna = warna;
        this.garansi = garansi;
    }

    // Getter untuk atribut
    public String getMerk() {
        return merk;
    }

    public String getWarna() {
        return warna;
    }

    public String getGaransi() {
        return garansi;
    }
}

// kelas Laptop yang mewarisi kelas BarangElektronik
class Laptop extends BarangElektronik {
    private String ukuranLayar;
    private String RAM;
    private double harga;

    // konstruktor untuk inisialisasi atribut
    public Laptop(String nama, String kode, int stok, String merk, String warna, String garansi,
        String ukuranLayar, String RAM, double harga) {
                    
        // Memanggil konstruktor kelas induk
        super(nama, kode, stok, merk, warna, garansi);
        this.ukuranLayar = ukuranLayar;
        this.RAM = RAM;
        this.harga = harga;
    }

    // Getter untuk atribut
    public String getUkuranLayar() {
        return ukuranLayar;
    }

    public String getRAM() {
        return RAM;
    }

    public double getHarga() {
        return harga;
    }
}
