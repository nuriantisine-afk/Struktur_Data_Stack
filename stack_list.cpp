#include <iostream>
#include <stdexcept>

using namespace std;

// Struktur Node untuk Linked List[cite: 2]
struct Node { 
    int v; 
    Node* next; 
};

class StackList {
    Node* head = nullptr; // Menandakan awal stack (TOP)[cite: 2]

public:
    // Mengecek apakah stack kosong[cite: 2]
    bool empty() const { 
        return !head; 
    }

    // Menambah elemen ke bagian atas stack[cite: 2]
    void push(int x) { 
        head = new Node{x, head}; 
    }

    // Menghapus elemen teratas stack[cite: 2]
    void pop() { 
        if (empty()) throw underflow_error("kosong"); 
        Node* old = head; 
        head = head->next; 
        delete old; 
    }

    // Melihat nilai elemen teratas tanpa menghapusnya[cite: 2]
    int top() const { 
        if (empty()) throw underflow_error("kosong"); 
        return head->v; 
    }

    // Destruktor untuk membersihkan memori secara otomatis[cite: 2]
    ~StackList() { 
        while (!empty()) pop(); 
    }
};

int main() {
    StackList s;
    int pilihan, nilai;

    do {
        cout << "\n==============================\n";
        cout << "   MENU STACK (LINKED LIST)   \n";
        cout << "==============================\n";
        cout << "1. Push (Tambah angka)\n";
        cout << "2. Pop (Hapus angka teratas)\n";
        cout << "3. Top (Lihat angka teratas)\n";
        cout << "4. Cek apakah Stack kosong\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        try {
            switch (pilihan) {
                case 1:
                    cout << "Masukkan angka yang ingin dimasukkan: ";
                    cin >> nilai;
                    s.push(nilai);
                    cout << "-> Angka " << nilai << " berhasil ditambahkan!\n";
                    break;
                case 2:
                    s.pop();
                    cout << "-> Elemen teratas berhasil dihapus (pop).\n";
                    break;
                case 3:
                    cout << "-> Elemen teratas saat ini: " << s.top() << "\n";
                    break;
                case 4:
                    if (s.empty()) {
                        cout << "-> Status: Stack kosong.\n";
                    } else {
                        cout << "-> Status: Stack tidak kosong.\n";
                    }
                    break;
                case 5:
                    cout << "Keluar dari program. Terima kasih!\n";
                    break;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi.\n";
            }
        } catch (const exception& e) {
            // Menangkap error jika stack underflow (kosong saat di-pop/top)
            cerr << "-> Peringatan: Stack " << e.what() << "!\n";
        }

    } while (pilihan != 5);

    return 0;
}