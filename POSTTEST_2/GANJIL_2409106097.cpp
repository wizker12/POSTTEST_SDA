#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

Item* head = NULL;

// Personalisasi berdasarkan NIM 097
int jumlahAwal = 97;        // Dua digit terakhir NIM
int posisiSisip = 7 + 1;    // Digit terakhir NIM (7) + 1 = 8

// Tambah Item Baru (di akhir)
void tambahItem(string nama, string tipe) {
    Item* baru = new Item{nama, jumlahAwal, tipe, NULL};
    if (!head) {
        head = baru;
    } else {
        Item* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    cout << "[+] Item " << nama << " berhasil ditambahkan (x" << jumlahAwal << ")\n";
}

// Sisipkan Item (posisi dari aturan NIM)
void sisipItem(string nama, string tipe) {
    Item* baru = new Item{nama, jumlahAwal, tipe, NULL};
    if (!head) {
        head = baru;
        cout << "[*] Item " << nama << " berhasil disisipkan di posisi 1\n";
        return;
    }
    
    // Jika posisi sisip = 1 (sisip di awal)
    if (posisiSisip == 1) {
        baru->next = head;
        head = baru;
        cout << "[*] Item " << nama << " berhasil disisipkan di posisi " << posisiSisip << "\n";
        return;
    }
    
    Item* temp = head;
    int count = 1;
    
    // Cari posisi sebelum posisi sisip
    while (temp->next && count < posisiSisip - 1) {
        temp = temp->next;
        count++;
    }
    
    baru->next = temp->next;
    temp->next = baru;
    cout << "[*] Item " << nama << " berhasil disisipkan di posisi " << posisiSisip << "\n";
}

// Hapus Item Terakhir
void hapusTerakhir() {
    if (!head) {
        cout << "[!] Bagpack kosong!\n";
        return;
    }
    if (!head->next) {
        delete head;
        head = NULL;
        cout << "[-] Item terakhir berhasil dihapus!\n";
        return;
    }
    Item* temp = head;
    while (temp->next->next) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
    cout << "[-] Item terakhir berhasil dihapus!\n";
}

// Fungsi paling kompleks: Gunakan Item
void gunakanItem(string nama) {
    if (!head) {
        cout << "[!] Bagpck kosong!\n";
        return;
    }
    
    Item* temp = head;
    Item* prev = NULL;
    bool found = false;
    
    // Cari item dalam linked list
    while (temp) {
        if (temp->namaItem == nama) {
            found = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    
    if (!found) {
        cout << "[!] Item '" << nama << "' tidak ditemukan!\n";
        return;
    }
    
    // Kurangi jumlah item
    temp->jumlah--;
    cout << "[>] Menggunakan " << temp->namaItem << " (sisa: " << temp->jumlah << ")\n";
    
    // Jika jumlah habis, hapus item dari inventory
    if (temp->jumlah <= 0) {
        cout << "[X] " << temp->namaItem << " habis dan dihapus dari Bagpack.\n";
        
        if (!prev) {
            // Jika item yang dihapus adalah head
            head = temp->next;
        } else {
            // Jika item yang dihapus bukan head
            prev->next = temp->next;
        }
        
        delete temp;
    }
}

// Tampilkan Inventory
void tampilkanInventory() {
    cout << "\n========== [ CYBERPUNK 2077 Bagpack ] ==========\n";
    if (!head) {
        cout << "               Bagpack KOSONG\n";
    } else {
        cout << "Nama Item\tJumlah\tTipe\n";
        cout << "--------------------------------------------\n";
        Item* temp = head;
        while (temp) {
            // Gunakan panjang tetap untuk format yang konsisten
            if (temp->namaItem.length() < 8)
                cout << temp->namaItem << "\t\t" << temp->jumlah << "\t" << temp->tipe << "\n";
            else if (temp->namaItem.length() < 16)
                cout << temp->namaItem << "\t" << temp->jumlah << "\t" << temp->tipe << "\n";
            else
                cout << temp->namaItem << "\t" << temp->jumlah << "\t" << temp->tipe << "\n";
            temp = temp->next;
        }
    }
    cout << "==================================================\n\n";
}

int main() {
    int pilihan;
    string nama, tipe;

    // Tampilkan informasi personalisasi
    cout << "+================================================+\n";
    cout << "|                     NIM: ...097                |\n";
    cout << "|                                                |\n";
    cout << "+================================================+\n";
    cout << "| - Jumlah awal item: " << jumlahAwal << "                        |\n";
    cout << "| - Posisi sisip item: " << posisiSisip << "                         |\n";
    cout << "+================================================+\n\n";

    do {
        cout << "\n+------------------------------------------------+\n";
        cout << "|     WELCOME TO INVENTORY Editor CYBERPUNK 2077     |\n";
        cout << "|        HELLO V. What can i help you V.         |\n";
        cout << "+------------------------------------------------+\n";
        cout << "1. Tambah Item  \n";
        cout << "2. Sisipkan Item  \n";
        cout << "3. Hapus Item Terakhir\n";
        cout << "4. Gunakan Item (Fungsi Kompleks)\n";
        cout << "5. Lihat Bagpack\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: "; 
                cin.ignore();
                getline(cin, nama);
                cout << "Masukkan tipe item: "; 
                getline(cin, tipe);
                tambahItem(nama, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: "; 
                cin.ignore();
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
                cin.ignore();
                getline(cin, nama);
                gunakanItem(nama);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Goodbye V. See you in NightCity...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);

    return 0;
}