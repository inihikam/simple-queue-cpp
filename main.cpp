#include "pustaka.h"

int main(){

    int select;
    int antri;
    int antre;
    do{
        bersihlayar();
        gotoxy(1, 1);
        cout << "MENU UTAMA";
        gotoxy(1, 2);
        cout << "1. Tambah Data Pasien";
        gotoxy(1, 3);
        cout << "2. Tambah Data Pasien Darurat";
        gotoxy(1, 4);
        cout << "3. Hapus Data Pasien" << endl;
        gotoxy(1, 5);
        cout << "4. Tangani lebih dulu";
        gotoxy(1, 6);
        cout << "5. Tampil Data" << endl;
        gotoxy(1, 7);
        cout << "9. Keluar" << endl;
        gotoxy(1, 8);
        cout << "Pilihan anda [1 - 9] : ";
        cin >> select;

        cout << "\n";

        if (select == 1){
            if (checkFull() == true){
                gotoxy(40,14);
                cout << "Antrean Penuh";
                gotoxy(40,15);
                cout << "Press Any Key ...";
                getch();
            } else {
                inqueue();
            }
        }
        if (select == 2){
            if (checkFull() == true){
                gotoxy(40,14);
                cout << "Antrean Penuh";
                gotoxy(40,15);
                cout << "Press Any Key ...";
                getch();
            } else {
                cout << "Masukkan antrian pasien : ";
                cin >> antre;
                specialInqueue(antre);
            }
        }
        if (select == 3){
            if (checkEmpty() == true){
                gotoxy(40,14);
                cout << "Antrean Kosong";
                gotoxy(40,15);
                cout << "Press Any Key ...";
                getch();
            } else {
                dequeue();
            }
        }
        if (select == 4){
            if (checkEmpty() == true){
                gotoxy(40,14);
                cout << "Antrean Kosong";
                gotoxy(40,15);
                cout << "Press Any Key ...";
                getch();
            } else {
                cout << "Masukkan antrian pasien : ";
                cin >> antri;
                specialDequeue(antri);
            }
        }
        if (select == 5){
            showData();
        }
    } while (select != 9);
    


    return 0;
}