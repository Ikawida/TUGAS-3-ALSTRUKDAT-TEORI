// Program Hash Table 

#include <iostream>
#include <list>
#include <string>

// Kelas HashTable
class HashTable {
private:
    int size;  // Ukuran dari hash table
    std::list<std::pair<std::string, int>> *table;  // Array dari linked list untuk chaining

    // Fungsi hash untuk menghasilkan indeks dari kunci
    int hashFunction(const std::string &key) {
        int hash = 0;
        // Menghitung hash berdasarkan nilai ASCII dari karakter dalam string
        for (char ch : key) {
            hash = (hash * 31 + ch) % size;  // Hash dengan modulus untuk memastikan berada dalam ukuran tabel
        }
        return hash;
    }

public:
    // Konstruktor untuk inisialisasi tabel hash
    HashTable(int size) {
        this->size = size;  // Menetapkan ukuran tabel
        table = new std::list<std::pair<std::string, int>>[size];  // Membuat array dari linked list
    }

    // Destruktor untuk menghapus tabel hash
    ~HashTable() {
        delete[] table;  // Menghapus array dari linked list
    }

    // Fungsi untuk memasukkan pasangan kunci-nilai ke dalam tabel
    void insert(const std::string &key, int value) {
        int hash = hashFunction(key);  // Menghasilkan indeks dengan fungsi hash
        auto &chain = table[hash];  // Mendapatkan linked list (chain) di indeks tersebut

        // Memeriksa apakah kunci sudah ada dalam chain
        for (auto &kv : chain) {
            if (kv.first == key) {  // Jika kunci sudah ada
                kv.second = value;  // Memperbarui nilai
                return;
            }
        }
        chain.emplace_back(key, value);  // Menambahkan pasangan kunci-nilai baru ke chain
    }

    // Fungsi untuk mencari nilai berdasarkan kunci
    bool search(const std::string &key, int &value) {
        int hash = hashFunction(key);  // Menghasilkan indeks dengan fungsi hash
        auto &chain = table[hash];  // Mendapatkan chain di indeks tersebut

        // Mencari kunci dalam chain
        for (auto &kv : chain) {
            if (kv.first == key) {  // Jika kunci ditemukan
                value = kv.second;  // Mengembalikan nilai yang ditemukan
                return true;
            }
        }
        return false;  // Jika kunci tidak ditemukan
    }

    // Fungsi untuk menghapus pasangan kunci-nilai dari tabel
    bool remove(const std::string &key) {
        int hash = hashFunction(key);  // Menghasilkan indeks dengan fungsi hash
        auto &chain = table[hash];  // Mendapatkan chain di indeks tersebut

        // Mencari kunci dalam chain
        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (it->first == key) {  // Jika kunci ditemukan
                chain.erase(it);  // Menghapus elemen dari chain
                return true;
            }
        }
        return false;  // Jika kunci tidak ditemukan
    }

    // Fungsi untuk menampilkan tabel hash
    void display() const {
        for (int i = 0; i < size; ++i) {
            std::cout << "Index " << i << ": ";  // Menampilkan indeks tabel
            for (const auto &kv : table[i]) {  // Menampilkan pasangan kunci-nilai dalam chain
                std::cout << "(" << kv.first << ", " << kv.second << ") ";  // Menampilkan kunci dan nilai
            }
            std::cout << std::endl;  // Baris baru untuk setiap indeks
        }
    }
};

int main() {
    // Membuat tabel hash dengan ukuran 10
    HashTable hashTable(10);

    // Memasukkan pasangan kunci-nilai ke dalam tabel hash
    hashTable.insert("apple", 10);
    hashTable.insert("banana", 20);
    hashTable.insert("orange", 30);

    // Menampilkan tabel hash setelah memasukkan elemen
    std::cout << "Table after inserting elements:" << std::endl;
    hashTable.display();

    // Mencari nilai berdasarkan kunci
    int value;
    if (hashTable.search("banana", value)) {
        std::cout << "\nSearching for 'banana': " << value << std::endl;  // Menampilkan nilai yang ditemukan
    } else {
        std::cout << "\n'banana' not found." << std::endl;  // Jika kunci tidak ditemukan
    }

    // Menghapus kunci dari tabel hash
    std::cout << "\nDeleting 'apple':" << std::endl;
    hashTable.remove("apple");
    hashTable.display();  // Menampilkan tabel hash setelah penghapusan

    return 0;
}
