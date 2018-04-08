#ifndef PASAR_H_INCLUDED
#define PASAR_H_INCLUDED
#include <iostream>
#include<stdlib.h>

#define nil NULL
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define anak(P) P->anak

using namespace std;

typedef struct pembelilist *addresspembeli;
typedef struct alamatbarang *addressalamat;
typedef struct penjuallist *addresspenjual;

struct infopembeli{
    string nama;
};

struct infoalamat{
    string barang;
    string alamat;
};

struct infopenjual{
    string nama;
    string barang;
    string alamat;
    int hitung;
};


struct pembelilist{
    infopembeli info;
    addresspembeli next;
    addresspembeli prev;
    addressalamat anak;
};

struct alamatbarang{
    infoalamat info;
    addressalamat next;
    addressalamat prev;
};

struct penjuallist{
    infopenjual info;
    addresspenjual next;
    addresspenjual prev;
};

struct listpembeli{
    addresspembeli first;
    addresspembeli last;
};

struct listbarang{
    addressalamat first;
    addressalamat last;
};

struct listpenjual{
    addresspenjual first;
    addresspenjual last;
};



void createlistpembeli(listpembeli &L);
void createlistbarang(listbarang &L);
void createlistpenjual(listpenjual &L);

addresspembeli alokasipembeli(infopembeli x);
addressalamat alokasibarang(infoalamat x);
addresspenjual alokasipenjual(infopenjual x);

void dealokasipembeli(addresspembeli &L);
void dealokasibarang(addressalamat &L);
void dealokasipenjual(addresspenjual &L);

void insertlastpembeli(listpembeli &L, addresspembeli P);
void insertlastbarang(addresspembeli &Q, listbarang &L, addressalamat P);
void insertlastpenjual(listpenjual &L, addresspenjual P);

void deletepembeli(listpembeli &L, addresspembeli &P); //pembatalan
void deletebarang(listbarang &L, addresspembeli &Q, addressalamat &P);
void deletepenjual(listpenjual &L, addresspenjual &P);

void deletefirstpembeli(listpembeli &L); //kalau sudah selesai
void deletefirstbarang( listbarang &L);

addresspembeli findelemenpembeli(listpembeli L, infopembeli x);
addressalamat findelemenbarang(listbarang L, infoalamat x);
addresspenjual findelemenpenjual(listpenjual L, infopenjual x);

void tampilkanpembeli(listpembeli &L);
void tampilkanpenjual(listpenjual &L);
//void tampilkanbarang(listbarang)

void menu();
void inputpenjual(listpenjual &L);
void inputpembeli(listpenjual &LP, listpembeli &L, listbarang &LB);
void hapuspenjual(listpenjual &L, listbarang &LPP);
void hapuspembeli(listpembeli &L, listbarang &LB, listpenjual &LPP);
void hapusbarang(listpembeli &L, listbarang &LB, listpenjual &LPP);
bool cekpenjual(listpenjual &L, addresspenjual Q);
void updatedataPenjual(listpenjual &L);

//void inputdata();
//void hapusdata();
#endif // PASAR_H_INCLUDED
