<?php
session_start();

// Buat folder uploads jika belum ada
if (!file_exists('uploads')) {
    mkdir('uploads', 0777, true);
}

// Inisialisasi 5 data awal jika belum ada
if (!isset($_SESSION['produk'])) {
    $_SESSION['produk'] = [
        ['nama'=>'Laptop Gaming','kode'=>'L001','stok'=>20,'merk'=>'ASUS','warna'=>'Hitam','garansi'=>'2 Tahun','ukuranLayar'=>'15.6 inci','RAM'=>'16 GB','harga'=>12000000,'image'=>null],
        ['nama'=>'Laptop Bisnis','kode'=>'L002','stok'=>15,'merk'=>'Acer','warna'=>'Silver','garansi'=>'3 Tahun','ukuranLayar'=>'14 inci','RAM'=>'8 GB','harga'=>10000000,'image'=>null],
        ['nama'=>'Laptop Ultrabook','kode'=>'L003','stok'=>10,'merk'=>'Acer','warna'=>'Putih','garansi'=>'1 Tahun','ukuranLayar'=>'13.3 inci','RAM'=>'16 GB','harga'=>15000000,'image'=>null],
        ['nama'=>'Laptop Student','kode'=>'L004','stok'=>5,'merk'=>'Lenovo','warna'=>'Abu-abu','garansi'=>'2 Tahun','ukuranLayar'=>'14 inci','RAM'=>'8 GB','harga'=>13000000,'image'=>null],
        ['nama'=>'Laptop Kreator','kode'=>'L005','stok'=>8,'merk'=>'Apple','warna'=>'Silver','garansi'=>'1 Tahun','ukuranLayar'=>'16 inci','RAM'=>'32 GB','harga'=>25000000,'image'=>null]
    ];
}

// Fungsi cek duplikat kode
function cariIndexKode($kode) {
    //
    foreach ($_SESSION['produk'] as $i => $p) {
        if ($p['kode'] === $kode) return $i;
    }
    return -1;
}

// Fungsi upload gambar
function uploadImage() {
    if (!empty($_FILES['image']['name'])) { // Cek apakah ada file diupload
        $namaFile = time().'_'.basename($_FILES['image']['name']);
        $tujuan = 'uploads/'.$namaFile;
        if (move_uploaded_file($_FILES['image']['tmp_name'], $tujuan)) {
            return $namaFile; // Jika berhasil, kembalikan nama file
        }
    }
    return null; // Jika gagal atau tidak ada file
}

// Tambah data laptop
if (isset($_POST['tambah'])) { // Cek apakah form tambah dikirim
    $kode = $_POST['kode'];

     // Cek duplikat kode menggunakan fungsi cariIndexKode (seharusnya ada di Produk.php)
    if (cariIndexKode($kode) != -1) {
        $error = "⚠️ Kode sudah ada, data tidak ditambahkan.";
    } 
    else {
        $image = uploadImage(); // Panggil fungsi uploadImage untuk menyimpan file gambar

        // Tambahkan data laptop baru ke session
        $_SESSION['produk'][] = [
            'nama'=>$_POST['nama'],
            'kode'=>$kode,
            'stok'=>(int)$_POST['stok'],
            'merk'=>$_POST['merk'],
            'warna'=>$_POST['warna'],
            'garansi'=>$_POST['garansi'],
            'ukuranLayar'=>$_POST['ukuranLayar'],
            'RAM'=>$_POST['RAM'],
            'harga'=>(float)$_POST['harga'],
            'image'=>$image
        ];
        $sukses = "✅ Data produk berhasil ditambahkan!";
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Manajemen Laptop</title>
    <style>
         /* Styling dasar halaman */
        body { font-family: Arial; margin: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 20px; }
        table, th, td { border: 1px solid #aaa; padding: 8px; text-align: center; }
        img { max-width: 100px; }
        .msg { margin-top: 10px; }
    </style>
</head>
<body>
    <h1>Manajemen Laptop</h1>

    <!-- Tampilkan pesan sukses atau error jika ada -->
    <?php if(!empty($sukses)) echo "<p class='msg' style='color:green;'>$sukses</p>"; ?>
    <?php if(!empty($error)) echo "<p class='msg' style='color:red;'>$error</p>"; ?>

    <!-- Form tambah laptop baru -->
    <h2>Tambah Laptop Baru</h2>
    <form method="post" enctype="multipart/form-data">
        Nama Produk : <input type="text" name="nama" required><br>
        Kode        : <input type="text" name="kode" required><br>
        Stok        : <input type="number" name="stok" required><br>
        Merk        : <input type="text" name="merk" required><br>
        Warna       : <input type="text" name="warna" required><br>
        Garansi     : <input type="text" name="garansi" required><br>
        Ukuran Layar: <input type="text" name="ukuranLayar" required><br>
        RAM         : <input type="text" name="RAM" required><br>
        Harga       : <input type="number" name="harga" required><br>
        Gambar      : <input type="file" name="image" accept="image/*"><br><br>
        <button type="submit" name="tambah">Tambah Laptop</button>
    </form>

    <!-- Tabel daftar semua laptop -->
    <h2>Daftar Laptop</h2>
    <table>
        <tr>
            <th>Gambar</th>
            <th>Nama</th>
            <th>Kode</th>
            <th>Stok</th>
            <th>Merk</th>
            <th>Warna</th>
            <th>Garansi</th>
            <th>Ukuran Layar</th>
            <th>RAM</th>
            <th>Harga</th>
        </tr>
        <?php foreach($_SESSION['produk'] as $p): ?>
        <tr>
            <td>
                <?php 
                // Tampilkan gambar jika ada
                if($p['image']) echo "<img src='uploads/{$p['image']}'>"; 
                ?>
            </td>
            <td><?= htmlspecialchars($p['nama']) ?></td>
            <td><?= htmlspecialchars($p['kode']) ?></td>
            <td><?= htmlspecialchars($p['stok']) ?></td>
            <td><?= htmlspecialchars($p['merk']) ?></td>
            <td><?= htmlspecialchars($p['warna']) ?></td>
            <td><?= htmlspecialchars($p['garansi']) ?></td>
            <td><?= htmlspecialchars($p['ukuranLayar']) ?></td>
            <td><?= htmlspecialchars($p['RAM']) ?></td>
            <td><?= number_format($p['harga'], 0, ',', '.') ?></td>
        </tr>
        <?php endforeach; ?>
    </table>
</body>
</html>
