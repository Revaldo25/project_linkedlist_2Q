#include <iostream>
#include "mahasiswa.h"

using namespace std;

void tampilkanMenu() {
    cout << "===================================" << endl;
    cout << "           MENU UTAMA             " << endl;
    cout << "===================================" << endl;
    cout << "[1] Tambah Mahasiswa" << endl;
    cout << "[2] Tambah Kehadiran" << endl;
    cout << "[3] Cetak Data" << endl;
    cout << "[4] Keluar" << endl;
    cout << "===================================" << endl;
    cout << "\nPilih: ";
}

int main() {
    LinkedList list;
    int pilihan;
    string nama;
    int pertemuan;
    int hadir;
    int jumlahMahasiswa;
    char lanjut;

    do {
        tampilkanMenu();
        cin >> pilihan;

        // Validasi input pilihan
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nPilihan tidak valid. Silakan masukkan angka." << endl;
            continue;
        }

        switch (pilihan) {
            case 1:
                cout << "\nJumlah mahasiswa yang ingin ditambah: ";
                cin >> jumlahMahasiswa;

                // Validasi input jumlahMahasiswa
                if (cin.fail() || jumlahMahasiswa <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "\nJumlah mahasiswa tidak valid." << endl;
                    continue;
                }

                for (int i = 0; i < jumlahMahasiswa; ++i) {
                    cout << "\nNama mahasiswa: ";
                    cin >> nama;
                    list.tambahMahasiswa(nama);
                }
                cout << "\nData mahasiswa berhasil ditambahkan." << endl;
                break;
            case 2:
                cout << "\nNama mahasiswa: ";
                cin >> nama;
                do {
                    cout << "\nPertemuan ke: ";
                    cin >> pertemuan;

                    // Validasi input pertemuan
                    if (cin.fail() || pertemuan < 1 || pertemuan > 14) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nPertemuan tidak valid. Harus antara 1 dan 14." << endl;
                        continue;
                    }

                    cout << "\nHadir (1) atau Tidak Hadir (0): ";
                    cin >> hadir;

                    // Validasi input hadir
                    if (cin.fail() || (hadir != 0 && hadir != 1)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\nInput kehadiran tidak valid. Masukkan 1 untuk Hadir atau 0 untuk Tidak Hadir." << endl;
                        continue;
                    }

                    list.tambahKehadiran(nama, pertemuan, hadir);
                    cout << "\nApakah Anda ingin menambahkan data kehadiran lagi? (y/n): ";
                    cin >> lanjut;
                } while (lanjut == 'y' || lanjut == 'Y');
                cout << "\nData kehadiran mahasiswa berhasil ditambahkan." << endl;
                break;
            case 3:
                list.cetakData();
                break;
            case 4:
                cout << "Keluar program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 4);

    return 0;
}
