#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

struct Item {
    int id;
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
    Item* prev;
};

Item* head = NULL;
Item* tail = NULL;
int autoID = 1;           // ID otomatis untuk setiap item

// Personalisasi NIM 097
int jumlahAwal = 97;      
int posisiSisip = 7 + 1;  

// Tambah Item Baru (di akhir)
void tambahItem(string nama, string tipe) {
    Item* baru = new Item{autoID++, nama, jumlahAwal, tipe, NULL, NULL};

    if (!head) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "[+] Item " << nama << " berhasil ditambahkan (x" << jumlahAwal << ")\n";
}

// Sisipkan Item pada posisi sesuai NIM
void sisipItem(string nama, string tipe) {
    Item* baru = new Item{autoID++, nama, jumlahAwal, tipe, NULL, NULL};

    if (!head) {
        head = tail = baru;
        cout << "[*] Item " << nama << " berhasil disisipkan di posisi 1\n";
        return;
    }

    if (posisiSisip == 1) { // sisip di awal
        baru->next = head;
        head->prev = baru;
        head = baru;
        cout << "[*] Item " << nama << " berhasil disisipkan di posisi " << posisiSisip << "\n";
        return;
    }

    Item* temp = head;
    int count = 1;
    while (temp->next && count < posisiSisip - 1) {
        temp = temp->next;
        count++;
    }

    baru->next = temp->next;
    baru->prev = temp;
    if (temp->next) temp->next->prev = baru;
    temp->next = baru;
    if (!baru->next) tail = baru; // update tail jika disisip di akhir

    cout << "[*] Item " << nama << " berhasil disisipkan di posisi " << posisiSisip << "\n";
}

// Hapus Item Terakhir
void hapusTerakhir() {
    if (!head) {
        cout << "[!] Bagpack kosong!\n";
        return;
    }

    if (!head->next) { // hanya 1 item
        delete head;
        head = tail = NULL;
        cout << "[-] Item terakhir berhasil dihapus!\n";
        return;
    }

    Item* hapus = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete hapus;
    cout << "[-] Item terakhir berhasil dihapus!\n";
}

// Gunakan Item
void gunakanItem(string nama) {
    if (!head) {
        cout << "[!] Bagpack kosong!\n";
        return;
    }

    Item* temp = head;
    while (temp && temp->namaItem != nama) {
        temp = temp->next;
    }

    if (!temp) {
        cout << "[!] Item '" << nama << "' tidak ditemukan!\n";
        return;
    }

    temp->jumlah--;
    cout << "[>] Menggunakan " << temp->namaItem << " (sisa: " << temp->jumlah << ")\n";

    if (temp->jumlah <= 0) {
        cout << "[X] " << temp->namaItem << " habis dan dihapus dari Bagpack.\n";

        if (temp == head && temp == tail) { 
            head = tail = NULL;
        } else if (temp == head) {
            head = head->next;
            head->prev = NULL;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
}

// Traversal dari depan
void tampilkanInventory() {
    cout << "\n========== [ CYBERPUNK 2077 Bagpack ] ==========\n";
    if (!head) {
        cout << "               Bagpack KOSONG\n";
    } else {
        cout << left << setw(5) << "ID"
             << setw(20) << "Nama Item"
             << setw(10) << "Jumlah"
             << setw(15) << "Tipe" << "\n";
        cout << "---------------------------------------------------\n";
        Item* temp = head;
        while (temp) {
            cout << left << setw(5) << temp->id
                 << setw(20) << temp->namaItem
                 << setw(10) << temp->jumlah
                 << setw(15) << temp->tipe << "\n";
            temp = temp->next;
        }
    }
    cout << "==================================================\n\n";
}

// Traversal dari belakang
void tampilkanInventoryBelakang() {
    cout << "\n===== [ Traversal dari Belakang ] =====\n";
    if (!tail) {
        cout << "Bagpack KOSONG\n";
        return;
    }
    Item* temp = tail;
    while (temp) {
        cout << "[ID " << temp->id << "] " << temp->namaItem
             << " (" << temp->jumlah << "x, tipe: " << temp->tipe << ")\n";
        temp = temp->prev;
    }
    cout << "========================================\n\n";
}

// Cari detail berdasarkan ID atau Nama
void cariDetail() {
    if (!head) {
        cout << "[!] Bagpack kosong!\n";
        return;
    }

    cout << "Cari berdasarkan (1 = ID, 2 = Nama): ";
    int opsi;
    cin >> opsi;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (opsi == 1) {
        int idCari;
        cout << "Masukkan ID: ";
        cin >> idCari;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Item* temp = head;
        while (temp) {
            if (temp->id == idCari) {
                cout << "\n[ DETAIL ITEM ]\n";
                cout << "ID     : " << temp->id << "\n";
                cout << "Nama   : " << temp->namaItem << "\n";
                cout << "Jumlah : " << temp->jumlah << "\n";
                cout << "Tipe   : " << temp->tipe << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "[!] Item dengan ID " << idCari << " tidak ditemukan.\n";
    } 
    else if (opsi == 2) {
        string namaCari;
        cout << "Masukkan Nama Item: ";
        getline(cin, namaCari);

        Item* temp = head;
        while (temp) {
            if (temp->namaItem == namaCari) {
                cout << "\n[ DETAIL ITEM ]\n";
                cout << "ID     : " << temp->id << "\n";
                cout << "Nama   : " << temp->namaItem << "\n";
                cout << "Jumlah : " << temp->jumlah << "\n";
                cout << "Tipe   : " << temp->tipe << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "[!] Item dengan nama '" << namaCari << "' tidak ditemukan.\n";
    } 
    else {
        cout << "[!] Pilihan tidak valid.\n";
    }
}

int main() {
    int pilihan;
    string nama, tipe;

    cout << "+================================================+\n";
    cout << "|                     NIM: ...097                |\n";
    cout << "+================================================+\n";
    cout << "| - Jumlah awal item: " << jumlahAwal << "\n";
    cout << "| - Posisi sisip item: " << posisiSisip << "\n";
    cout << "+================================================+\n\n";

    do {
        cout << "\n+------------------------------------------------+\n";
        cout << "|     WELCOME TO INVENTORY Editor CYBERPUNK 2077 |\n";
        cout << "+------------------------------------------------+\n";
        cout << "1. Tambah Item\n";
        cout << "2. Sisipkan Item\n";
        cout << "3. Hapus Item Terakhir\n";
        cout << "4. Gunakan Item\n";
        cout << "5. Lihat Bagpack (depan)\n";
        cout << "6. Lihat Bagpack (belakang)\n";
        cout << "7. Cari Detail Item (ID/Nama)\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                getline(cin, nama);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                tambahItem(nama, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                getline(cin, nama);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                sisipItem(nama, tipe);
                break;
            case 3:
                hapusTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang digunakan: ";
                getline(cin, nama);
                gunakanItem(nama);
                break; 
            case 5:
                tampilkanInventory();
                break;
            case 6:
                tampilkanInventoryBelakang();
                break;
            case 7:
                cariDetail();
                break;
            case 0:
                cout << "Goodbye V. See you in NightCity...\n";
                break;
            default:
                cout << "[!] Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}
