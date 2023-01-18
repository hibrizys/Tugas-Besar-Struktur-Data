#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED

#include <iostream>
using namespace std;

#define first_mhs(L) L.first_mhs
#define last_mhs(L) L.last_mhs
#define next_mhs(P) P->next_mhs
#define info_mhs(P) P->info_mhs

#define first_makanF(L) L.first_makanF
#define next_makanF(P) P->next_makanF
#define prev_makanF(P) P->prev_makanF
#define info_makanF(P) P->info_makanF
#define last_makanF(L) L.last_makanF

#define first_relasi(L) L.first_relasi
#define next_relasi(P) P->next_relasi

struct infotype_mhs{
    string nama_mhs;
    string jurusan;
    int nim;
    string jenis_makanan_favorit; // ini yang direlasikan fungsionalitas nomor Basah, kering, campur
};

struct infotype_makanF{
     string nama_makanan;
     int harga;
     string jenis; // Basah, kering, campur
};

typedef infotype_mhs mhs;
typedef infotype_makanF makanF;
typedef struct elm_makanF *adr_makanF;
typedef struct elm_mhs *adr_mhs;
typedef struct elm_relasi *adr_relasi;

struct list_makanF{
    adr_makanF first_makanF;
    adr_makanF last_makanF;
};

struct list_mhs{
    adr_mhs first_mhs;
    adr_mhs last_mhs;
};

struct list_relasi{
    adr_relasi first_relasi;
};


struct elm_makanF{
    infotype_makanF info_makanF;
    adr_makanF next_makanF;
    adr_makanF prev_makanF;
};

struct elm_mhs{
    infotype_mhs info_mhs;
    adr_mhs next_mhs;
};

struct elm_relasi{
    adr_makanF next_makanF;
    adr_mhs next_mhs;
    adr_relasi next_relasi;
};

void createListmhs(list_mhs &d);
adr_mhs createElmmhs(mhs mhs);
void createListmakanF(list_makanF &m);
adr_makanF createElmmakanF(makanF makanF);
void createListrelasi(list_relasi &r);
adr_relasi createELmrelasi();

adr_makanF searchmakanF(list_makanF m, makanF makanF);
adr_mhs searchmhs(list_mhs d, mhs mhs);

void insertmakanF(list_makanF &m, adr_makanF p);
void insertMhs(list_mhs &d, adr_mhs q);
void insertRelasi(list_makanF m, list_mhs d, list_relasi &r, mhs mhs, makanF makanF);

void deleteAfterRelasi(list_relasi &r, adr_relasi p);
void deletemakanF(list_makanF &m, list_relasi &r, makanF makanF, mhs mhs);
void deleteMhs(list_mhs &d, list_relasi &r, mhs mhs);
void deleteAfterMhs(list_mhs &d, adr_mhs p);
void deleteAftermakanF(list_makanF &m, adr_makanF p);

void cariMhs(list_mhs d);
void carimakanF(list_makanF m);
void carimakanFRelasi(list_relasi r, list_mhs d);
void viewmakanF(list_makanF m);
void viewMhs(list_mhs d);
void viewBukanRelasi(list_mhs d, list_makanF m);
void viewRelasi(list_mhs d, list_relasi r);

void countjmlhmakanF(list_makanF m,list_relasi r, makanF makanF, list_mhs d);

int menuProgram();
void contohTampilan();
#endif // TUBES_H_INCLUDED
