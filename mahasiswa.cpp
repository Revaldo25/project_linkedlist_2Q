#include "mahasiswa.h"
#include <iostream>

LinkedList::LinkedList() {
    head = 0;
}

LinkedList::~LinkedList() {
    Mahasiswa* current = head;
    while (current != 0) {
        Mahasiswa* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::tambahMahasiswa(string nama) {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nama = nama;
    for (int i = 0; i < 14; ++i) {
        newMahasiswa->kehadiran[i] = 0;
    }
    newMahasiswa->next = head;
    head = newMahasiswa;
}

void LinkedList::tambahKehadiran(string nama, int pertemuan, bool hadir) {
    Mahasiswa* current = head;
    while (current != 0) {
        if (current->nama == nama) {
            current->kehadiran[pertemuan - 1] = hadir ? 1 : 0;
            break;
        }
        current = current->next;
    }
}

void LinkedList::cetakData() {
    Mahasiswa* current = head;
    while (current != 0) {
        cout << "Nama: " << current->nama << endl;
        cout << "Kehadiran: ";
        for (int i = 0; i < 14; ++i) {
            cout << current->kehadiran[i] << " ";
        }
        cout << endl;
        current = current->next;
    }
}
