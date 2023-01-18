#include "tubes.h"


void createListmhs(list_mhs &d)
{
    first_mhs(d) = NULL;
    last_mhs(d) = NULL;
}
adr_mhs createElmmhs(mhs mhs)
{
    adr_mhs p = new elm_mhs;
    info_mhs(p) = mhs;
    next_mhs(p) = NULL;
    return p;
}
void createListmakanF(list_makanF &m)
{
    first_makanF(m) = NULL;
    last_makanF(m) = NULL;
}
adr_makanF createElmmakanF(makanF makanF)
{
    adr_makanF p = new elm_makanF;
    info_makanF(p) = makanF;
    next_makanF(p) = NULL;
    return p;
}
void createListrelasi(list_relasi &r)
{
    first_relasi(r) = NULL;
}
adr_relasi createELmrelasi(list_relasi r)
{
    adr_relasi p = new elm_relasi;
    next_mhs(p) = NULL;
    next_makanF(p) = NULL;
    next_relasi(p) = NULL;
    return p;
}

adr_makanF searchmakanF(list_makanF m, makanF makanF)
{
    adr_makanF q = first_makanF(m);
    while (q != NULL){
        if (info_makanF(q).nama_makanan == makanF.nama_makanan){
            return q;
        }
        q = next_makanF(q);
    }
    return NULL;
}
adr_mhs searchmhs(list_mhs d, mhs mhs)
{
    adr_mhs p = first_mhs(d);
    while (p != NULL){
        if (info_mhs(p).nama_mhs == mhs.nama_mhs){
            return p;
        }
        p = next_mhs(p);
    }
    return NULL;
}

void insertMhs(list_mhs &d, adr_mhs q)
{
    /** Menggunakan insert First Circular Single linked list dengan Tambahan Pointer Last */
    if(first_mhs(d) == NULL){
         first_mhs(d) = q;
         last_mhs(d) = q;
         next_mhs(q) = q;
        next_mhs(last_mhs(d)) = NULL;
    } else {
        next_mhs(q) = first_mhs(d);
        first_mhs(d) = q;
        q = NULL;
        next_mhs(last_mhs(d)) = q;
    }
    cout << "PENAMBAHAN BERHASIL" << endl;
}

void insertmakanF(list_makanF &m, adr_makanF p)
{
    /** Menggunakan Insert Last Double Linked List **/
    if (first_makanF(m) == NULL){
        first_makanF(m) = p;
        last_makanF(m) = p;

   } else {
        prev_makanF(p) = last_makanF(m);
        next_makanF(last_makanF(m)) = p;
        last_makanF(m) = p;
    }
    cout << "PENAMBAHAN BERHASIL" << endl;
}

void insertRelasi(list_makanF m, list_mhs d, list_relasi &r, mhs mhs, makanF makanF)
{
    adr_mhs p = searchmhs(d,mhs);
    adr_makanF q = searchmakanF(m,makanF);
    if ( p != NULL && q != NULL && info_mhs(p).jenis_makanan_favorit == info_makanF(q).jenis ){
        adr_relasi rr = createELmrelasi(r);
        next_mhs(rr) = p;
        next_makanF(rr) = q;
        if (first_relasi(r) == NULL){
            first_relasi(r) = rr;
        } else{
            next_relasi(rr) = first_relasi(r);
            first_relasi(r) = rr;
        }
        cout << "BERHASIL DIRELASIKAN" << endl;
    } else if (p == NULL && q == NULL){
        cout << "TIDAK ADA DATA MAHASISWA DAN DATA MAKANAN FAVORITE!" << endl;
    } else if (p == NULL) {
        cout << "TIDAK ADA DATA MAHASISWA!" << endl;
    } else if (q == NULL) {
        cout << "TIDAK ADA DATA MAKANAN FAVORITE!" << endl;
    } else if (info_mhs(p).jenis_makanan_favorit != info_makanF(q).jenis) {
        cout << "TIDAK BISA DIRELASIKAN DIKARENAKAN JENIS MAKANAN FAVORIT TIDAK SAMA!" << endl;
    }
}

void deleteAfterRelasi(list_relasi &r, adr_relasi p)
{
    if (p == first_relasi(r)){
        first_relasi(r) = next_relasi(p);
    } else{
        adr_relasi rr = first_relasi(r);
        while (next_relasi(rr) != p){
            rr = next_relasi(rr);
        }
        next_relasi(rr) = next_relasi(p);
    }
}

void deletemakanF(list_makanF &m, list_relasi &r, makanF makanF, mhs mhs)
{
    adr_makanF q = searchmakanF(m, makanF);
    adr_relasi rr = first_relasi(r);
    if (q != NULL){
        while (rr != NULL && info_mhs(next_mhs(rr)).nama_mhs == mhs.nama_mhs && info_makanF(next_makanF(rr)).jenis == info_mhs(next_mhs(rr)).jenis_makanan_favorit){
            if (next_makanF(rr) == q){
                next_makanF(rr) = NULL;
                next_mhs(rr) = NULL;
                deleteAfterRelasi(r,rr);
            }
            rr = next_relasi(rr);
        }
        if (q == first_makanF(m)){
            first_makanF(m) = next_makanF(q);
            next_makanF(q) = NULL;
        } else if (next_makanF(q) == NULL){
            adr_makanF o = first_makanF(m);
            while (next_makanF(o) != q){
                o = next_makanF(o);
            }
            next_makanF(o) = next_makanF(q);
            next_makanF(q) = NULL;
        } else {
            deleteAftermakanF(m,q);
        }
        cout << "PENGHAPUSAN BERHASIL" << endl;
    } else {
        cout << "( EMPTY )" << endl;
    }
}
void deleteMhs(list_mhs &d, list_relasi &r, mhs mhs)
{
    adr_mhs p = searchmhs(d,mhs);
    adr_relasi rr = first_relasi(r);
    if (p != NULL){
        while (rr != NULL){
            if (next_mhs(rr) == p){
                next_mhs(rr) = NULL;
                next_makanF(rr) = NULL;
                deleteAfterRelasi(r,rr);
            }
            rr = next_relasi(rr);
        }
        if (p == first_mhs(d)){
            first_mhs(d) = next_mhs(p);
            next_mhs(p) = NULL;
        } else if (next_mhs(p) == NULL){
            adr_mhs t = first_mhs(d);
            while (next_mhs(t) != p){
                t = next_mhs(t);
            }
            next_mhs(t) = next_mhs(p);
            next_mhs(p) = NULL;
        } else {
            deleteAfterMhs(d,p);
        }
        cout << "PENGHAPUSAN BERHASIL" << endl;
    } else {
        cout << "( EMPTY )" << endl;
    }
}
void deleteAfterMhs(list_mhs &d, adr_mhs p)
{
    if (p == first_mhs(d)){
        first_mhs(d) = next_mhs(p);
    } else {
        adr_mhs q = first_mhs(d);
        while (next_mhs(q) != p){
            q = next_mhs(q);
        }
        next_mhs(q) = next_mhs(p);
    }
}
void deleteAftermakanF(list_makanF &m, adr_makanF p)
{
    if (p == first_makanF(m)){
        first_makanF(m) = next_makanF(p);
    } else{
        adr_makanF q = first_makanF(m);
        while (next_makanF(q) != p){
            q = next_makanF(q);
        }
        next_makanF(q) = next_makanF(p);
    }
}

void carimakanFRelasi(list_relasi r, list_mhs d)
{
    mhs mhs;
    adr_mhs p = first_mhs(d);
    adr_relasi rr = first_relasi(r);
    cout << "Masukkan nama Mahasiswa : ";
    cin >> mhs.nama_mhs;
    if (p != NULL){
            while (rr != NULL){
                makanF makanF;
                if (info_mhs(next_mhs(rr)).nama_mhs == mhs.nama_mhs && info_mhs(next_mhs(rr)).jenis_makanan_favorit == info_makanF(next_makanF(rr)).jenis ){
                    cout << endl;
                    cout << "Nama Makanan\t: " << info_makanF(next_makanF(rr)).nama_makanan << endl;
                    cout << "Harga\t\t: " << info_makanF(next_makanF(rr)).harga << endl;
                    cout << "Jenis\t\t: " << info_makanF(next_makanF(rr)).jenis;
                    cout << endl;
                }
                rr = next_relasi(rr);
            }

    } else {
        cout << "( EMPTY )" << endl;
    }

}

void cariMhs(list_mhs d)
{
    mhs mhs;
    adr_mhs p = first_mhs(d);
    cout << "Masukkan Jenis makanan favorite Mahasiswa: "; // Basah, Kering, Campur
    cin >> mhs.jenis_makanan_favorit;
     if (p == NULL){
        cout << "( EMPTY )" << endl;
    }
    while (p != NULL){
        if (info_mhs(p).jenis_makanan_favorit == mhs.jenis_makanan_favorit){
                cout << "Nama Mahasiswa\t\t : " << info_mhs(p).nama_mhs << endl;
                cout << "Jurusan\t\t\t : " <<info_mhs(p).jurusan << endl;
                cout << "NIM\t\t\t : " <<info_mhs(p).nim << endl;
                cout << "Jenis Makanan Favorite\t : " <<info_mhs(p).jenis_makanan_favorit << endl;
                cout << endl;
        }
        p = next_mhs(p);
    }
}

void carimakanF(list_makanF m)
{
    makanF makanF;
    adr_makanF p = first_makanF(m);
    cout << "Masukkan Jenis Makanan: "; // Basah, Kering, Campur
    cin >> makanF.jenis;
     if (p == NULL){
        cout << "( EMPTY )" << endl;
    }
    while (p != NULL){
        if (info_makanF(p).jenis == makanF.jenis){
                cout << "Nama Makanan\t: " << info_makanF(p).nama_makanan << endl;
                cout << "Harga \t\t: " << info_makanF(p).harga << endl;
                cout << "Jenis \t\t: " << info_makanF(p).jenis << endl;
                cout << endl;
        }
        p = next_makanF(p);
    }
}

void viewMhs(list_mhs d)
{
    adr_mhs p = first_mhs(d);
    if (p == NULL){
        cout << "( EMPTY )" << endl;
    }else {
        while (p != NULL){
            cout << "Nama Mahasiswa\t\t : " << info_mhs(p).nama_mhs << endl;
            cout << "Jurusan\t\t\t : " <<info_mhs(p).jurusan << endl;
            cout << "NIM\t\t\t : " <<info_mhs(p).nim << endl;
            cout << "Jenis Makanan Favorite\t : " <<info_mhs(p).jenis_makanan_favorit << endl;
            p = next_mhs(p);
            cout << endl;
        }
    }
}
void viewBukanRelasi(list_mhs d, list_makanF m)
{
    adr_mhs p = first_mhs(d);
    cout << "===============================================================================" << endl;
    cout << "\t\t[Data Mahasiswa Memiliki Makanan Favorite]" << endl;
    cout << "===============================================================================" << endl;
    cout << "Data Mahasiswa  : " << endl;
    if (p == NULL){
            cout << "( EMPTY )" << endl;
    }else {
        while (p != NULL){
            cout << info_mhs(p).nama_mhs <<", " <<info_mhs(p).jurusan << ", " <<info_mhs(p).nim << ", " <<info_mhs(p).jenis_makanan_favorit;
            p = next_mhs(p);
            cout << endl;
        }
    }

    adr_makanF q = first_makanF(m);
    cout << "Data Makanan Favorite : "<< endl;
    if (q == NULL){
            cout << "( EMPTY )" << endl;
    } else{
        while (q != NULL){
            cout << info_makanF(q).nama_makanan << ", " <<info_makanF(q).harga << ", " <<info_makanF(q).jenis;
            q = next_makanF(q);
            cout << endl;
        }

    }
    cout << "===============================================================================" << endl;
}
void viewRelasi(list_mhs d, list_relasi r)
{
    adr_mhs p = first_mhs(d);
    adr_relasi rr = first_relasi(r);
    if (p != NULL && rr != NULL){
        while (p != NULL){
            cout << "Nama Mahasiswa\t\t : " << info_mhs(p).nama_mhs << endl;
            cout << "Jurusan\t\t\t : " << info_mhs(p).jurusan << endl;
            cout << "NIM\t\t\t : " << info_mhs(p).nim << endl;
            cout << "Jenis Makanan Favorite\t : " << info_mhs(p).jenis_makanan_favorit << endl;
            cout << endl;
            cout << "Makanan Favorite Mahasiswa -> " << endl;
            adr_relasi rr = first_relasi(r);
            while (rr != NULL){
                if (info_mhs(next_mhs(rr)).nama_mhs == info_mhs(p).nama_mhs){
                    cout << "Nama Makanan\t: " << info_makanF(next_makanF(rr)).nama_makanan<< endl;
                    cout << "Harga \t\t: " << info_makanF(next_makanF(rr)).harga<< endl;
                    cout << "Jenis \t\t: " << info_makanF(next_makanF(rr)).jenis<< endl;
                    cout << endl;
                }
                rr = next_relasi(rr);
            }

            cout << "===============================================================================";
            p = next_mhs(p);
            cout <<""<< endl;
        }
    } else if (p != NULL && rr == NULL){
        while (p != NULL){
            cout << "Nama mhs\t\t : " << info_mhs(p).nama_mhs << endl;
            cout << "Jurusan\t\t\t : " << info_mhs(p).jurusan << endl;
            cout << "NIM\t\t\t : " << info_mhs(p).nim << endl;
            cout << "Jenis Makanan Favorite\t : " << info_mhs(p).jenis_makanan_favorit << endl;
            cout << endl;
            cout << "Makanan Favorite Mahasiswa  -> " << endl;
            cout << "Nama Makanan\t: ( EMPTY )" <<  endl;
            cout << "harga \t\t: ( EMPTY ) " << endl;
            cout << "Jenis \t\t: ( EMPTY )" << endl;
            cout << "===============================================8================================" << endl;
            p = next_mhs(p);
        }
    } else if (p == NULL && rr == NULL){
        cout << "Data Mahasiswa dan Data Makanan Favorite belum direlasikan" << endl;
        cout << "Nama mhs\t\t : ( EMPTY )" << endl;
        cout << "Jurusan\t\t\t : ( EMPTY )" << endl;
        cout << "NIM\t\t\t : ( EMPTY )" << endl;
        cout << "Jenis Makanan Favorite\t : ( EMPTY )" << endl;
        cout << endl;
        cout << "Makanan Favorite Mahasiswa  -> " << endl;
        cout << "Nama Makanan\t: ( EMPTY )" <<  endl;
        cout << "harga \t\t: ( EMPTY ) " << endl;
        cout << "Jenis \t\t: ( EMPTY )" << endl;
        cout << "===============================================================================" << endl;
    }
}

void countjmlhmakanF(list_makanF m,list_relasi r, makanF makanF, list_mhs d)
{
    mhs mhs;
    cout << "Masukkan Nama Mahasiswa: ";
    cin >> mhs.nama_mhs;
    adr_relasi rr = first_relasi(r);
    int n;
    n = 0;
    while(rr != NULL){
        if(mhs.nama_mhs == info_mhs(next_mhs(rr)).nama_mhs){
            if(info_mhs(next_mhs(rr)).jenis_makanan_favorit == info_makanF(next_makanF(rr)).jenis){
                n++;
            } else {
                cout << "Tidak ada Data! "<< endl;
            }
        }
        rr = next_relasi(rr);
    }
        cout << "Jumlah Data Makanan Favoritenya : " << n << endl;

}
int menuProgram()
{
    cout << "\t\t\t [CREATED BY SULISTIYO] " << endl;
    cout << "===============================================================================" << endl;
    cout << "1.  Insert Data Mahasiswa dari depan/belakang" << endl;
    cout << "2.  Show all data parent" << endl;
    cout << "3.  Menghapus data parent beserta relasinya" << endl;
    cout << "4.  Mencari data parent" << endl;
    cout << "5.  Mencari data child" << endl;
    cout << "6.  Menambahkan data child" << endl;
    cout << "7.  Menghubungkan data parent ke data child" << endl;
    cout << "8.  Menampilkan seluruh data parent beserta childnya" << endl;
    cout << "9.  Mencari data child pada parent tertentu" << endl;
    cout << "10. Menghapus data child pada parent tertentu beserta relasinya" << endl;
    cout << "11. Menghitung jumlah data child dari parent tertentu" << endl;
    cout << "12. Main program" << endl;
    cout << "0.  Exit" << endl;
    cout << "===============================================================================" << endl;
    cout << "Pilihan menu : ";
    int pilihan;
    cin >> pilihan;

    return pilihan;
}

void contohTampilan()
{
    cout << "===============================================================================" << endl;
    cout << "\t\t\t [CREATED BY HIBRIZY SULISTIYO] " << endl;
    cout << "===============================================================================" << endl;
    cout << "1.  Insert Data Mahasiswa dari depan/belakang" << endl;
    cout << "2.  Show all data parent" << endl;
    cout << "3.  Menghapus data parent beserta relasinya" << endl;
    cout << "4.  Mencari data parent" << endl;
    cout << "5.  Mencari data child" << endl;
    cout << "6.  Menambahkan data child" << endl;
    cout << "7.  Menghubungkan data parent ke data child" << endl;
    cout << "8.  Menampilkan seluruh data parent beserta childnya" << endl;
    cout << "9.  Mencari data child pada parent tertentu" << endl;
    cout << "10. Menghapus data child pada parent tertentu beserta relasinya" << endl;
    cout << "11. Menghitung jumlah data child dari parent tertentu" << endl;
    cout << "12. Main program" << endl;
    cout << "0.  Exit" << endl;
    cout << "===============================================================================" << endl;
}
