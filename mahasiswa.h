#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int kehadiran[14];
    Mahasiswa* next;
};

class LinkedList {
private:
    Mahasiswa* head;
public:
    LinkedList();
    ~LinkedList();
    void tambahMahasiswa(string nama);
    void tambahKehadiran(string nama, int pertemuan, bool hadir);
    void cetakData();
};

#endif


