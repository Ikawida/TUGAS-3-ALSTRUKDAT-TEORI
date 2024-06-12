// Program Priority Queue

#include <iostream>
#include <vector>
#include <limits.h>  // Digunakan untuk konstanta INT_MIN
using namespace std;

// Struktur untuk elemen dalam antrian prioritas
struct Item {
    int value;      // Nilai elemen
    int priority;   // Prioritas elemen
};

// Kelas untuk mengelola antrian prioritas
class PriorityQueue {
private:
    vector<Item> items;  // Penyimpanan dinamis menggunakan vector

public:
    // Fungsi untuk menambahkan elemen baru ke antrian prioritas
    void enqueue(int value, int priority) {
        Item newItem = {value, priority};
        items.push_back(newItem);  // Tambah elemen ke akhir vector
    }

    // Fungsi untuk melihat elemen dengan prioritas tertinggi
    int peek() {
        if (items.empty()) {
            cerr << "Antrian prioritas kosong.\n";
            return -1; // Kembalikan -1 jika antrian kosong
        }

        int highestPriority = INT_MIN;  // Inisialisasi prioritas tertinggi
        int index = -1;  // Indeks untuk elemen dengan prioritas tertinggi

        // Loop melalui semua elemen untuk mencari prioritas tertinggi
        for (int i = 0; i < items.size(); i++) {
            if (items[i].priority > highestPriority) {
                highestPriority = items[i].priority;
                index = i;
            } else if (items[i].priority == highestPriority && items[i].value > items[index].value) {
                index = i;
            }
        }

        return index;  // Kembalikan indeks elemen dengan prioritas tertinggi
    }

    // Fungsi untuk menghapus elemen dengan prioritas tertinggi
    void dequeue() {
        int index = peek();  // Dapatkan indeks elemen dengan prioritas tertinggi
        if (index == -1) return; // Jika antrian kosong, keluar dari fungsi

        items.erase(items.begin() + index);  // Hapus elemen dari vector
    }

    // Fungsi untuk mencetak elemen dengan prioritas tertinggi
    void printTop() {
        int index = peek();
        if (index != -1) {
            cout << items[index].value << endl;  // Cetak nilai elemen dengan prioritas tertinggi
        }
    }
};

// Fungsi utama
int main() {
    PriorityQueue pq;

    // Tambahkan elemen ke antrian prioritas
    pq.enqueue(10, 2);
    pq.enqueue(14, 4);
    pq.enqueue(16, 4);
    pq.enqueue(12, 3);

    pq.printTop(); // Cetak elemen dengan prioritas tertinggi, yaitu 16

    pq.dequeue();  // Hapus elemen dengan prioritas tertinggi
    pq.printTop(); // Cetak elemen dengan prioritas tertinggi yang berikutnya, yaitu 14

    pq.dequeue();  // Hapus elemen dengan prioritas tertinggi yang berikutnya
    pq.printTop(); // Cetak elemen dengan prioritas tertinggi yang berikutnya, yaitu 12

    return 0;
}
