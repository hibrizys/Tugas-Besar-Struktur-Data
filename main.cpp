#include "tubes.h"

int main()
{
    list_mhs d;
    createListmhs(d);
    list_makanF m;
    createListmakanF(m);
    list_relasi r;
    createListrelasi(r);
    adr_mhs p;
    adr_makanF q;
    mhs mhs;
    makanF makanF;
    int pilihan = -1;
    while (pilihan != 0){
        viewBukanRelasi(d,m);
        pilihan = menuProgram();

        if (pilihan == 1){
            cout<<endl;
            cout << "Masukan Nama Mahasiswa : ";
            cin >> mhs.nama_mhs;
            cout << "Masukan Jurusan : ";
            cin >> mhs.jurusan;
            cout << "Masukan NIM : ";
            cin >> mhs.nim;
            cout << "Masukan Jenis Makanan Favorit : ";
            cin >> mhs.jenis_makanan_favorit;
            p = createElmmhs(mhs);
            insertMhs(d,p);
            cout<<endl;
                system("pause");
                system("cls");
        } else if ( pilihan == 2){
            cout<<endl;
            viewMhs(d);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 3){
            cout<<endl;
            cout << "Masukkan Nama Mahasiswa yang mau dihapus: ";
            cin >> mhs.nama_mhs;
            deleteMhs(d,r,mhs);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 4){
            cout<<endl;
            cariMhs(d);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 5){
            cout<<endl;
            carimakanF(m);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 6){
            cout<<endl;
            cout << "Masukan Nama Makanan : ";
            cin >> makanF.nama_makanan;
            cout << "Masukan Harga : ";
            cin >> makanF.harga;
            cout << "Masukan Jenis Makanan : ";
            cin >> makanF.jenis;
            q = createElmmakanF(makanF);
            insertmakanF(m,q);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 7){
            cout<<endl;
            cout << "Masukkan Nama Mahsiswa: ";
            cin >> mhs.nama_mhs;
            cout << "Masukkan Nama Makanan: ";
            cin >> makanF.nama_makanan;
            insertRelasi(m,d,r,mhs,makanF);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 8){
            cout<<endl;
            viewRelasi(d,r);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 9){
            cout<<endl;
            carimakanFRelasi(r,d);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 10){
            cout<<endl;
            cout << "<- Daftar yang akan dihapus ->" << endl;
            cout << "Masukkan Nama Mahsiswa: ";
            cin >> mhs.nama_mhs;
            cout << "Masukkan Nama Makanan: ";
            cin >> makanF.nama_makanan;
            deletemakanF(m,r,makanF,mhs);
                system("pause");
                system("cls");
        } else if (pilihan == 11){
            cout<<endl;
            countjmlhmakanF(m,r,makanF,d);
            cout<<endl;
                system("pause");
                system("cls");
        } else if (pilihan == 12){
                system("cls");
            contohTampilan();
                system("pause");
                system("cls");
        } else if (pilihan == 0){
            cout << "\t\t\t[ PROGRAM KELUAR!! ]" << endl;
        }
    }
    return 0;
}
