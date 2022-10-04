#include <iostream>
#include <conio.h>
#include <Windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;

struct antrian
{
    char nama[30];
    char sex;
    int umur;
};

struct antrian pasien[100];

int dataNo = 1;
int maks = 5;

// Untuk membersihkan layar
void bersihlayar()
{
    for (int a = 0; a < 80; a++)
    {
        for (int b = 0; b <= 50; b++)
        {
            gotoxy(a, b);
            cout << " ";
        }
    }
}

bool checkFull()
{
    if (dataNo > maks)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool checkEmpty()
{
    if (dataNo <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void inqueue()
{

    // Menginputkan Data Pasien
    gotoxy(20, 15);
    cout << "Masukkan nama pasien: ";
    cin >> pasien[dataNo].nama;
    gotoxy(20, 16);
    cout << "Masukkan jenis kelamin pasien: ";
    cin >> pasien[dataNo].sex;
    gotoxy(20, 17);
    cout << "Masukkan Umur pasien: ";
    cin >> pasien[dataNo].umur;

    cout << "\n";

    dataNo++;
}

void dequeue()
{

    // Menampilkan Data yang akan di hapus
    gotoxy(40, 12);
    cout << "Pasien yang akan masuk adalah :" << endl;
    gotoxy(40, 13);
    cout << pasien[1].nama << " ";
    cout << pasien[1].sex << " ";
    cout << pasien[1].umur << "\n\n";

    // Memindahkan data maju saat sudah ada dequeue
    for (int i = 2; i < dataNo; i++)
    {
        pasien[i - 1] = pasien[i];
    }

    dataNo--;

    gotoxy(40, 15);
    cout << "Press Any Key ...";
    getch();
}

void specialInqueue(int x)
{

    if (x > dataNo || x < 1){
        gotoxy(40,14);
        cout << "Harap mengisi antrean selanjutnya terlebih dahulu";
        gotoxy(40,15);
        cout << "Press Any Key ...";
        getch();
    } else {
        // Menginputkan Data Pasien
        dataNo++;

        for (int i = dataNo; i > x; i--)
        {
            pasien[i] = pasien[i - 1];
        }

        gotoxy(20, 15);
        cout << "Masukkan nama pasien: ";
        cin >> pasien[x].nama;
        gotoxy(20, 16);
        cout << "Masukkan jenis kelamin pasien: ";
        cin >> pasien[x].sex;
        gotoxy(20, 17);
        cout << "Masukkan Umur pasien: ";
        cin >> pasien[x].umur;

        cout << "\n";
    }

}

void specialDequeue(int x)
{

    if (x > dataNo-1 || x < 1){
        gotoxy(40,14);
        cout << "Antrean Tidak Ditemukan";
        gotoxy(40,15);
        cout << "Press Any Key ...";
        getch();
    } else {
        // Menampilkan Data yang akan di hapus
        gotoxy(40, 12);
        cout << "Pasien yang akan masuk duluan adalah :" << endl;
        gotoxy(40, 13);
        cout << pasien[x].nama << " ";
        cout << pasien[x].sex << " ";
        cout << pasien[x].umur << "\n\n";

        // Memindahkan data maju saat sudah ada dequeue
        for (int i = x; i < dataNo; i++)
        {
            pasien[i] = pasien[i + 1];
        }

        dataNo--;

        gotoxy(40, 15);
        cout << "Press Any Key ...";
        getch();
    }
    

}

void showData()
{

    // Menampilkan data
    gotoxy(40, 10);
    cout << "Daftar Pasien\n";
    for (int i = 1; i < dataNo; i++)
    {
        gotoxy(40, 11 + i);
        cout << i << ". " << pasien[i].nama;
        cout << " " << pasien[i].sex;
        cout << " " << pasien[i].umur;
        cout << "\n";
    }

    gotoxy(40, 30);
    cout << "Press Any Key ...";
    getch();
}