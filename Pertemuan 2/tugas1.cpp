#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
};

Node* head = NULL;

void tambahAwal(int nilai) {
    Node* baru = new Node();
    baru->nilai = nilai;
    baru->next = head;
    head = baru;
}

void tambahAkhir(int nilai) {
    Node* baru = new Node();
    baru->nilai = nilai;
    baru->next = NULL;
    if (head == NULL) {
        head = baru;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
}

void tambahSetelahNilai(int nilaiCari, int nilaiBaru) {
    Node* temp = head;
    while (temp != NULL && temp->nilai != nilaiCari) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Nilai " << nilaiCari << " tidak ditemukan dalam list!" << endl;
        return;
    }
    Node* baru = new Node();
    baru->nilai = nilaiBaru;
    baru->next = temp->next;
    temp->next = baru;
}

void hapusBerdasarkanNilai(int nilai) {
    if (head == NULL) {
        cout << "Linked List kosong!" << endl;
        return;
    }
    if (head->nilai == nilai) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr != NULL && curr->nilai != nilai) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        cout << "Nilai " << nilai << " tidak ditemukan dalam list!" << endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}

void tampilkanList() {
    cout << "Isi Linked List: ";
    Node* temp = head;
    if (temp == NULL) {
        cout << "NULL" << endl;
        return;
    }
    while (temp != NULL) {
        cout << temp->nilai << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    system("cls");
    
    int pilihan, nilai, nilaiCari, nilaiBaru;

    do {
        cout << "===== MENU SINGLE LINKED LIST =====" << endl;
        cout << "1. Tambah di awal" << endl;
        cout << "2. Tambah di akhir" << endl;
        cout << "3. Tambah setelah nilai tertentu" << endl;
        cout << "4. Hapus berdasarkan nilai" << endl;
        cout << "5. Tampilkan Linked List" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAwal(nilai);
                tampilkanList();
                break;
            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                tambahAkhir(nilai);
                tampilkanList();
                break;
            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilaiBaru;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                tambahSetelahNilai(nilaiCari, nilaiBaru);
                tampilkanList();
                break;
            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                hapusBerdasarkanNilai(nilai);
                tampilkanList();
                break;
            case 5:
                tampilkanList();
                break;
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 0);

    return 0;
}