#include <iostream>
#include "pasar.h"
using namespace std;
//void menu(listpenjual &lpp, listpembeli &lp, listbarang &l);
//void inputdata(listpenjual &lpp, listpembeli &lp, listbarang &l);
//void hapusdata(listpenjual &lpp, listpembeli &lp, listbarang &l);
//void hapuspenjual(listpenjual &lp);
//void tampil(listpenjual lpp, listpembeli lp, listbarang l);

int main()
{
  menu();
    // listpenjual lpp;
    // createlistpenjual(lpp);
    // listpembeli lp;
    // listbarang l;
    // menu(lpp,lp,l);
}

// void menu(listpenjual &lpp, listpembeli &lp, listbarang &l){
//     cout<<"======================MENU======================"<<endl;
//     cout<<"1. Masukkan data"<<endl;
//     cout<<"2. Hapus data"<<endl;
//     cout<<"3. tampilkan data"<<endl;
//     cout<<"9. Exit"<<endl;
//     cout<<"masukkan pilihan = ";
//     int pil;
//     cin>>pil;
//     if (pil == 1){
//         inputdata(lpp,lp,l);
//     }
//     else if(pil ==2){
//         hapusdata(lpp,lp,l);
//     }
//     else if(pil == 3){
//         tampil(lpp,lp,l);
//     }
//     else{
//
//     }
//
// }
//
//
// void inputdata(listpenjual &lpp, listpembeli &lp, listbarang &l){
//     createlistpembeli(lp);
//
//     cout<<"=============masukkan pilihan================"<<endl;
//     cout<<"1. Input pedagang"<<endl;
//     cout<<"2. input pembeli"<<endl;
//     cout<<"9. back"<<endl;
//     int pil;
//     cin>>pil;
//     if (pil==1){
//
//         infopenjual aa;
//         cout<<"masukkan nama penjual = ";
//         cin>>aa.nama;
//         cout<<"masukkan nama barang = ";
//         cin>>aa.barang;
//         cout<<"masukkan alamat penjual = ";
//         cin>>aa.alamat;
//         addresspenjual AA;
//         AA = alokasipenjual(aa);
//         insertlastpenjual(lpp, AA);
//         menu(lpp,lp,l);
//     }
//     else if(pil ==2){
//
//         infopembeli k;
//         cout<<"masukkan nama pembeli = ";
//         cin>>k.nama;
//         addresspembeli P = alokasipembeli(k);
//         insertlastpembeli(lp,P);
//     }
//     else if(pil == 9){
//
//         menu(lpp,lp,l);
//     }
// }
//
// void hapusdata(listpenjual &lpp, listpembeli &lp, listbarang &l){
//
//     cout<<"================masukkan pilihan=================="<<endl;
//     cout<<"1. hapus penjual"<<endl;
//     cout<<"2. hapus pembeli"<<endl;
//     cout<<"3. hapus barang"<<endl;
//     int pil;
//     cin>>pil;
//     if (pil == 1){
//
//         hapuspenjual(lpp);
//     }
// }
//
// void hapuspenjual(listpenjual &lp){
//
//     infopenjual bar;
//     cout<<"masukkan abrang yang dijual = ";
//     cin>>bar.barang;
//     addresspenjual P,Q;
//     P = first(lp);
//     while(P!=nil){
//         if(info(P).barang!=bar.barang){
//
//             P = next(P);
//         }
//         else{
//
//             Q = P;
//         }
//     }
//     deletepenjual(lp, Q);
// }
//
// void tampil(listpenjual lpp, listpembeli lp, listbarang l){
//     cout<<"===============masukkan pilihan================="<<endl;
//     cout<<"1. hapus pedagang"<<endl;
//     int pil;
//     cin>>pil;
//     if(pil==1){
//         hapuspenjual(lpp);
//     }
// }
