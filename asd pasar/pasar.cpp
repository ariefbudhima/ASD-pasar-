#include "pasar.h"

void createlistpembeli(listpembeli &L){
    first(L) = nil;
    last(L) = nil;
}

void createlistbarang(listbarang &L){
    first(L) = nil;
    last(L) = nil;
}
void createlistpenjual(listpenjual &L){
    first(L) = nil;
    last(L) = nil;
}

addresspembeli alokasipembeli(infopembeli x){
    addresspembeli P = new pembelilist;
    info(P).nama = x.nama;
    prev(P) = nil;
    next(P) = nil;
    anak (P) = nil;
    return P;
}

addressalamat alokasibarang(infoalamat x){
    addressalamat P = new alamatbarang;
    info(P).barang = x.barang;
    info(P).alamat = x.alamat;
    next(P) = nil;
    return P;
}

addresspenjual alokasipenjual(infopenjual x){
    addresspenjual P = new penjuallist;
    info(P).nama = x.nama;
    info(P).barang = x.barang;
    info(P).alamat = x.alamat;
    next(P) = nil;
    return P;
}

void dealokasipembeli(addresspembeli &L){
    delete L;
}

void dealokasibarang(addressalamat &L){
    delete L;
}

void dealokasipenjual(addresspenjual &L){
    delete L;
}

void insertlastpembeli(listpembeli &L, addresspembeli P){
    if(first(L)==nil){listpenjual lpp;
    createlistpenjual(lpp);
        first(L) = P;
        last(L) = P;
    }
    else{
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void insertlastbarang(addresspembeli &Q, listbarang &L, addressalamat P){
    if(first(L)==nil){
        first(L) = P;
        last(L) = P;
        anak(Q) = P;
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void insertlastpenjual(listpenjual &L, addresspenjual P){
    if(first(L)==nil){
        first(L) = P;
        last(L) = P;
    }
    else{
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
}

void deletepembeli(listpembeli &L, addresspembeli &P){
    if(first(L)==nil){
        cout<<"list kosong";
    }
    else if(first(L)==last(L)){
        first(L) = nil;
        last(L) = nil;
    }
    else{
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
        next(P) = nil;
        prev(P) = nil;
        dealokasipembeli(P);
    }
}

void deletebarang(listbarang &L, addresspembeli &Q, addressalamat &P){

    if(first(L)==nil){
        cout<<"list kosong";
    }
    else if((P == first(L))&&(P == last(L))){
        first(L) = nil;
        last(L) = nil;
        dealokasibarang(P);
    }
    else if(P == first(L)){
        first(L) = next(P);
        anak(Q) = first(L);
        next(P) = nil;
        prev(first(L)) = nil;
        dealokasibarang(P);
    }
    else if(P == last(L)){
        last(L) = prev(P);
        next(last(L)) = nil;
        prev(P) = nil;
        dealokasibarang(P);
    }
    else{
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
        next(P) = nil;
        prev(P) = nil;
        dealokasibarang(P);
    }
}

void deletepenjual(listpenjual &L, addresspenjual &P){
    if(P==first(L)&&P==last(L)){
        first(L) = nil;
        last(L) = nil;
    }
    else if(P == first(L)){
        first(L) = next(P);
        prev(first(L)) = nil;
        next(P) = nil;
    }
    else if(P == last(L)){
        last(L) = prev(P);
        next(last(L)) = nil;
        prev(P) = nil;
    }
    else{
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
        next(P) = nil;
        prev(P) = nil;
        dealokasipenjual(P);
    }
}

void deletefirstpembeli(listpembeli &L){
    if(first(L)==nil){
        cout<<"list kosong";
    }
    else{
        addresspembeli P = first(L);
        first(L) = next(P);
        dealokasipembeli(P);
    }
}

void deletefirstbarang(listbarang &L){
    if(first(L)==nil){
        cout<<"list kosong";
    }
    else{
        addressalamat P = first(L);
        first(L) = next(P);
        dealokasibarang(P);
    }
}

addresspembeli findelemenpembeli(listpembeli L, infopembeli x){
    addresspembeli P = first(L);
    while(P!=nil){
        if (info(P).nama == x.nama){
            return P;
        }
        else{
            P = next(P);
        }
    }
    return P;
}

addresspenjual findelemenpenjual(listpenjual L, infopenjual x){
    addresspenjual P = first(L);
    while(P!=nil){
        if(info(P).barang == x.barang){
            return P;
        }
        else{
            P = next(P);
        }
    }
    return P;
}

void tampilkanpenjual(listpenjual &L){
    addresspenjual P = first(L);
    while (P!=nil){
        cout<<"Nama Penjual = "<<info(P).nama<<endl;
        cout<<"Barang yang dijual = "<<info(P).barang<<endl;
        cout<<"Alamat = "<<info(P).alamat<<endl;
        cout<<"hitung = ";
        cout<<info(P).hitung<<endl<<endl;
        P = next(P);
    }
}

void tampilkanpembeli(listpembeli &L){
    addresspembeli P = first(L);
    while(P!=nil){
        addressalamat Q = anak(P);
        while(Q!=nil){
            cout<<"nama = "<<info(P).nama<<endl;
            cout<<"barang = "<<info(Q).barang<<endl;
            cout<<"alamat = "<<info(Q).alamat<<endl<<endl;
            Q = next(Q);
        }
        P = next(P);
    }
}

void menu(){
  listpenjual lpp;
  createlistpenjual(lpp);
  listpembeli lp;
  createlistpembeli(lp);
  listbarang l;
  createlistbarang(l);
  int pil;
  do{
    system("cls");
    cout<<"||============================================||"<<endl;
    cout<<"||=================||MENU||===================||"<<endl;
    cout<<"||============================================||"<<endl;
    cout<<"||              1. Input penjual              ||"<<endl;
    cout<<"||              2. Input Pembeli              ||"<<endl;
    cout<<"||              3. Hapus Penjual              ||"<<endl;
    cout<<"||              4. Hapus Pembeli              ||"<<endl;
    cout<<"||              5. Hapus Barang               ||"<<endl;
    cout<<"||              6. Tampilkan penjual          ||"<<endl;
    cout<<"||              7. Tampilkan Pembeli          ||"<<endl;
    cout<<"||              8. Edit Data Penjual          ||"<<endl;
    cout<<"||              9. Exit                       ||"<<endl;
    cout<<"||============================================||"<<endl;
    cout<<"||============================================||"<<endl<<endl;
    cout<<" Masukkan pilihan "<<endl;
    cout<<" Pilihan = ";
    cin>>pil;
    switch(pil){
      case 1 : {
        system("cls");
          inputpenjual(lpp);
          system("pause");
          break;
      }
      case 2 : {
        system("cls");
        inputpembeli(lpp,lp,l);
        system("pause");
        break;
      }
      case 3 : {
        system("cls");
        hapuspenjual(lpp,l);
        system("pause");
        break;
      }
      case 4 : {
        system("cls");
        hapuspembeli(lp,l,lpp);
        system("pause");
        break;
      }
      case 5 : {
        system("cls");
        hapusbarang(lp,l,lpp);
        system("pause");
        break;
      }
      case 6 : {
        system("cls");
        tampilkanpenjual(lpp);
        system("pause");
        break;
      }
      case 7 : {
        system("cls");
        tampilkanpembeli(lp);
        system("pause");
        break;
      }
      case 8 : {
        system("cls");
        updatedataPenjual(lpp);
        system("pause");
        break;
      }
    }
  }while(pil!=9);
}

void inputpenjual(listpenjual &L){
  infopenjual x;
  cout<<"Masukkan nama penjual = ";
  cin>>x.nama;
  cout<<"masukkan nama barang = ";
  cin>>x.barang;
  cout<<"masukkan alamat penjual = ";
  cin>>x.alamat;
  addresspenjual P;
  P = alokasipenjual(x);
  if(cekpenjual(L,P)==false){
    insertlastpenjual(L,P);
    cout<<endl<<"--data berhasil diinputkan--"<<endl;
  }
  else{
    cout<<"alamat sudah di tempati"<<endl;
    cout<<"masukkan alamat lain"<<endl<<endl;
  }
  info(P).hitung=0;
}

void inputpembeli(listpenjual &LP, listpembeli &L, listbarang &LB){
  infopembeli x;
  addresspenjual R = first(LP);
  cout<<"masukkan nama pembeli = ";
  cin>>x.nama;
  addresspembeli P = alokasipembeli(x);
  insertlastpembeli(L,P);
  system("cls");
  int bny;
  cout<<"masukkan banyak barang yang ingin dibeli = ";
  cin>>bny;
  infoalamat y;
  addressalamat Q;
  for(int i=1;i<=bny;i++){
    cout<<"masukkan barang yang ingin dibeli = ";
    cin>>y.barang;
    while (R!=nil) {
        if(y.barang == info(R).barang){
          y.alamat = info(R).alamat;
          info(R).hitung++;
          break;
        }
      else{
        R = next(R);
      }
  }
    Q = alokasibarang(y);
    insertlastbarang(P,LB,Q);
    R = first(LP);
    cout<<endl<<"--data berhasil diinputkan--"<<endl;
    }
}

void hapuspenjual(listpenjual &L, listbarang &LPP){
  infopenjual x;
  addressalamat Q;
  cout<<"========hapus penjual=========="<<endl;
  cout<<"masukkan alamat = ";
  cin>>x.alamat;
  addresspenjual P = first(L);
  while(P!=nil){
    if(info(P).alamat != x.alamat){
      P = next(P);
    }
    else if(info(P).alamat == x.alamat){
      Q = first(LPP);
      while(Q!=nil){
        if(info(Q).alamat == info(P).alamat){
          info(Q).alamat = "\0";
          break;
        }
        else{
          Q = next(Q);
        }
      }
      deletepenjual(L,P);
      cout<<"--data berhasil dihapus--"<<endl;
      break;
    }
  }
  if(P==nil){
    cout<<"--data tidak dapat dihapus--"<<endl;
  }
}

void hapuspembeli(listpembeli &L, listbarang &LB, listpenjual &LPP){
  infopembeli x;
  cout<<"==========hapus pembeli=========="<<endl;
  cout<<"masukkan nama pembeli = ";
  cin>>x.nama;
  addresspembeli P = first(L);
  while(P!=nil){
    if (info(P).nama != x.nama){
      P = next(P);
    }
    else if(info(P).nama == x.nama){
      while(first(LB)!=nil){
        addressalamat R = first(LB);
        addresspenjual Q = first(LPP);
        while(Q!=nil){
            if(info(Q).alamat == info(R).alamat){
               info(Q).hitung--;
               break;
               }
            else{
                Q = next(Q);
                }
           }
        deletebarang(LB,P,R);
      }
        deletepembeli(L,P);
        cout<<"--data berhasil dihapus--"<<endl;
        break;
    }
  }
  if(P == nil){
    cout<<"--data tidak dapat dihapus--"<<endl;
  }
}

void hapusbarang(listpembeli &L, listbarang &LB, listpenjual &LPP){
  infopembeli x;
  infoalamat y;
  addresspenjual R = first(LPP);
  cout<<"masukkan nama pembeli = ";
  cin>>x.nama;
  addresspembeli P = first(L);
  while(P!=nil){
    if (info(P).nama == x.nama){
      break;
    }
    else{
      P = next(P);
    }
  }
  cout<<"masukkan nama barang yang ingin di hapus = ";
  cin>>y.barang;
  addressalamat Q = first(LB);
  while(Q!=nil){
    if(info(Q).barang == y.barang){
      while(R!=nil){
        if(info(R).alamat==info(Q).alamat){
          info(R).hitung--;
          break;
        }
        else{
          R = next(R);
        }
      }
      break;
    }
    else{
      Q = next(Q);
    }
  }
  deletebarang(LB,P,Q);
  cout<<"--data berhasil dihapus--"<<endl;
}

bool cekpenjual(listpenjual &L, addresspenjual Q){
  addresspenjual P = first(L);
  while(P!=nil){
    if (info(P).alamat == info(Q).alamat){
      return true;
      }
      else{
        P = next(P);
      }
    }
    return false;
}

void updatedataPenjual(listpenjual &L){
  addresspenjual P = first(L);
  infopenjual x;
  cout<<"masukkan alamat penjual yang ingin di update = ";
  cin>>x.alamat;
  cout<<"masukkan nama penjual yang ingin di update = ";
  cin>>x.nama;
  while(P!=nil){
    if((x.alamat == info(P).alamat)&&(x.nama == info(P).nama)){
      cout<<"Masukkan Data Baru"<<endl;
      // cout<<"Masukkan nama penjual = ";
      // cin>>x.nama;
      cout<<"Masukkan nama barang = ";
      cin>>x.barang;
      cout<<"Masukkan alamat penjual = ";
      cin>>x.alamat;
      x.hitung = 0;
      addresspenjual Q = alokasipenjual(x);
      next(Q) = next(P);
      prev(Q) = prev(P);
      info(P).barang = info(Q).barang;
      info(P).alamat = info(Q).alamat;
      cout<<endl<<"--data telah diupdate--"<<endl;
      break;
    }
    else{
        cout<<"data tidak ditemukan"<<endl;
      P = next(P);
    }
  }
}
