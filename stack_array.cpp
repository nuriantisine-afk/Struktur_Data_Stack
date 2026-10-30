#include <iostream>
#include <stdexcept>

using namespace std;

class StackArray {
    static constexpr int CAP = 5; // Kapasitas maksimum stack
    int a[CAP];
    int t = -1;                   // Indeks top awal (-1 berarti kosong)
public:
    bool empty() const { return t == -1; }
    
    void push(int x) {
        if (t == CAP - 1) throw overflow_error("penuh");
        a[++t] = x;
    }
    
    void pop() {
        if (empty()) throw underflow_error("kosong");
        --t;
    }
    
    int top() const {
        if (empty()) throw underflow_error("kosong");
        return a[t];
    }

    // Fungsi tambahan untuk melihat posisi indeks top saat ini
    int getTopIndex() const {
        return t;
    }
};

int main() {
    StackArray s;
    int pilihan, nilai;

    do {
        cout << "\n=========================================\n";
        cout << "  STACK DENGAN ARRAY TETAP (Kapasitas: 5)\n";
        cout << "=========================================\n";
        cout << "1. Push (Tambah elemen)\n";
        cout << "2. Pop (Hapus elemen teratas)\n";
        cout << "3. Top (Lihat elemen & indeks teratas)\n";
        cout << "4. Cek Status (Kosong/Tidak)\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;

        try {
            switch (pilihan) {
                case 1:
                    cout << "Masukkan angka yang ingin di-push: ";
                    cin >> nilai;
                    s.push(nilai);
                    cout << "-> Berhasil! Angka " << nilai << " ditambahkan. Indeks top (t) sekarang = " << s.getTopIndex() << "\n";
                    break;
                case 2:
                    cout << "Indeks top (t) sebelum pop = " << s.getTopIndex() << "\n";
                    s.pop();
                    cout << "-> Berhasil melakukan pop. Indeks top (t) sekarang = " << s.getTopIndex() << "\n";
                    break;
                case 3:
                    cout << "-> Elemen teratas (top): " << s.top() << "\n";
                    cout << "-> Posisi indeks top (t) saat ini = " << s.getTopIndex() << "\n";
                    break;
                case 4:
                    if (s.empty()) {
                        cout << "-> Status: Stack KOSONG (t = -1)\n";
                    } else {
                        cout << "-> Status: Stack TIDAK KOSONG. Indeks top (t) = " << s.getTopIndex() << "\n";
                    }
                    break;
                case 5:
                    cout << "Keluar dari program. Terima kasih!\n";
                    break;
                default:
                    cout << "Pilihan tidak valid, silakan coba lagi.\n";
            }
        } catch (const exception& e) {
            // Menangkap exception overflow ("penuh") atau underflow ("kosong")
            cerr << "-> Peringatan Error: Stack " << e.what() << "!\n";
        }

    } while (pilihan != 5);

    return 0;
}