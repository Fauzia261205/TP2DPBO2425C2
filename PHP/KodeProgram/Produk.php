<?php
// kelas Laptop yang sudah mewarisi kelas Produk dan elektronik
class Laptop {
    public $nama;
    public $kode;
    public $stok;
    public $merk;
    public $warna;
    public $garansi;
    public $ukuranLayar;
    public $ram;
    public $harga;
    public $image;

    // konstruktor
    public function __construct($nama, $kode, $stok, $merk, $warna, $garansi, $ukuranLayar, $ram, $harga, $image) {
        $this->nama = $nama;
        $this->kode = $kode;
        $this->stok = $stok;
        $this->merk = $merk;
        $this->warna = $warna;
        $this->garansi = $garansi;
        $this->ukuranLayar = $ukuranLayar;
        $this->ram = $ram;
        $this->harga = $harga;
        $this->image = $image;
    }
}
?>
