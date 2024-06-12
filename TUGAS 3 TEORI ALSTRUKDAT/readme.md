# <h1 align="center">TUGAS 3 TEORI ALGORITMA DAN STRUKTUR DATA </h1>

<p align="center">Nama: Ika Wida Nuragustin</p>
<p align="center">NIM: 2311110001</p>
<p align="center">Kelas: SISD-04A</p>

## 1.	Berikan penjelasan dan contoh program(beserta penjelasan alur program) dari masing-masing materi struktur data berikut:
### A. Priority Queue

Priority Queue adalah struktur data yang berbasis Queue, tetapi memiliki prinsip operasi yang berbeda. Dalam Priority Queue, elemen yang akan diambil atau dihapus adalah elemen yang memiliki prioritas tertinggi. Prioritas dapat berupa waktu kedatangan, prioritas yang diberikan oleh pengguna, atau kriteria lain yang relevan [1].

Antrian prioritas adalah jenis antrian yang mengatur elemen berdasarkan tingkat prioritasnya. Biasanya, elemen dengan prioritas lebih tinggi akan diambil terlebih dahulu sebelum elemen dengan prioritas lebih rendah.

Dalam antrian prioritas, setiap elemen memiliki nilai prioritas yang terkait dengannya. Ketika elemen ditambahkan ke dalam antrian, posisinya akan ditentukan oleh nilai prioritasnya. Sebagai contoh, jika elemen dengan prioritas tinggi ditambahkan ke dalam antrian prioritas, maka elemen tersebut mungkin akan ditempatkan di depan antrian, sementara elemen dengan prioritas rendah akan ditempatkan di belakang.

Ada beberapa cara untuk menerapkan antrian prioritas, seperti menggunakan array, linked list, heap, atau binary search tree. Setiap metode memiliki kelebihan dan kekurangan masing-masing, dan pilihan terbaik akan tergantung pada kebutuhan khusus dari aplikasi yang digunakan.

Antrian prioritas sering digunakan dalam sistem real-time, di mana urutan pemrosesan elemen memiliki dampak yang signifikan. Mereka juga digunakan dalam algoritma untuk meningkatkan efisiensi, seperti algoritma Dijkstra untuk mencari jalur terpendek dalam graf dan algoritma pencarian A* untuk pencarian jalur [2].

Priority Queue dibedakan menjadi dua tipe:
- Ascending Priority Queue: Queue yang diurutkan dengan prioritas menaik, yaitu dari elemen yang memiliki prioritas terendah hingga prioritas tertinggi.
- Descending Priority Queue: Queue yang diurutkan dengan prioritas menurun, yaitu dari elemen yang memiliki prioritas tertinggi hingga prioritas terendah.

#### Kode Program 
```C++
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
```

#### Output

```
16
14
12
```

#### Penjelasan 
Berikut adalah penjelasan mengenai alur program. Pertama, sebuah `struct` bernama `Item` didefinisikan untuk menyimpan `value` dan `priority` dari setiap elemen. Kemudian, kelas `PriorityQueue` dideklarasikan untuk mengelola antrian ini. Kelas ini memiliki `vector<Item>` untuk menyimpan elemen-elemen.

Fungsi `enqueue` digunakan untuk menambahkan elemen baru ke dalam antrian dengan memasukkan elemen tersebut ke akhir `vector`. Fungsi `peek` mencari dan mengembalikan indeks elemen dengan prioritas tertinggi dalam `vector`, dengan mempertimbangkan elemen dengan nilai lebih besar jika ada beberapa elemen dengan prioritas yang sama.

Fungsi `dequeue` menghapus elemen dengan prioritas tertinggi dari antrian, menggunakan indeks yang ditemukan oleh `peek`. Selain itu, fungsi `printTop` mencetak nilai elemen dengan prioritas tertinggi ke konsol.

Dalam `main`, beberapa elemen dengan nilai dan prioritas tertentu dimasukkan ke antrian. Program kemudian mencetak dan menghapus elemen dengan prioritas tertinggi secara berurutan, menunjukkan bagaimana antrian prioritas dikelola secara efektif. Hasil dari program ini adalah bahwa elemen dengan prioritas tertinggi selalu diproses pertama kali, dan jika ada elemen dengan prioritas yang sama, elemen dengan nilai yang lebih besar diprioritaskan. Dari referensi pertama.

### B. Hash Table 

Hash table adalah struktur data yang digunakan untuk mempercepat proses pencarian dan pengarsipan data. Dalam struktur ini, data diorganisir ke dalam baris dan kolom dengan menggunakan kunci tertentu. Hash table dapat mengurangi biaya waktu pencarian karena data dapat dicari secara langsung dari lokasi yang telah ditentukan berdasarkan kunci tersebut.

Hash table juga dapat digunakan dalam aplikasi seperti pencarian kata dalam kamus, pengarsipan data, dan pengembangan algoritma data mining. Dalam beberapa kasus, hash table dapat menjadi alternatif yang efektif untuk algoritma pencarian biner, terutama dalam aplikasi yang memerlukan waktu pencarian yang konstan dan efisiensi dalam penggunaan sumber daya.

Fungsi hash membuat pemetaan antara kunci dan nilai, hal ini dilakukan melalui penggunaan rumus matematika yang dikenal sebagai fungsi hash. Hasil dari fungsi hash disebut sebagai nilai hash atau hash. Nilai hash adalah representasi dari string karakter asli tetapi biasanya lebih kecil dari aslinya.

Operasi Hash Table: 

1.	Insertion:
   
Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash untuk menentukan posisi bucket yang tepat, dan kemudian menambahkan data ke bucket tersebut.

2.	Deletion:
   
Menghapus data dari hash table dengan mencari data menggunakan fungsi hash, dan kemudian menghapusnya dari bucket yang sesuai.

3.	Searching:
   
Mencari data dalam hash table dengan memasukkan input kunci ke fungsi hash untuk menentukan posisi bucket, dan kemudian mencari data di dalam bucket yang sesuai.

4.	Update:
   
Memperbarui data dalam hash table dengan mencari data menggunakan fungsi hash, dan kemudian memperbarui data yang ditemukan.

5.	Traversal:
   
Melalui seluruh hash table untuk memproses semua data yang ada dalam tabel.


Namun, hash table memiliki kendala, seperti collision, yang dapat diatasi dengan menggunakan teknik seperti hash matrix, chaining, re-hashing, linear probing, dan quadratic probing. Dalam beberapa implementasi, hash table digunakan sebagai tempat penyimpanan pointer untuk merangkai elemen dalam Linked List, sehingga dapat meningkatkan efisiensi dalam proses pencarian [3].


#### Kode Program 
```C++
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
```

#### Output

```
Table after inserting elements:
Index 0:
Index 1:
Index 2: (banana, 20)
Index 3: (orange, 30)
Index 4: 
Index 5: 
Index 6: 
Index 7: 
Index 8: 
Index 9: (apple, 10) 

Searching for 'banana': 20

Deleting 'apple':
Index 0:
Index 1:
Index 2: (banana, 20)
Index 3: (orange, 30)
Index 4: 
Index 5: 
Index 6: 
Index 7: 
Index 8: 
Index 9: 
```

#### Penjelasan 

Berikut adalah penjelasan mengenai alur program diatas.
Program hash table ini dimulai dengan inisialisasi, di mana ukuran hash table ditentukan dan sebuah instance dari kelas `HashTable` dibuat dengan ukuran yang telah ditentukan. Pada tahap ini, memori dialokasikan untuk sebuah array dari linked list yang akan digunakan untuk penyimpanan data menggunakan teknik chaining. Kemudian, program memasukkan elemen-elemen ke dalam hash table menggunakan metode `insert`, yang menerima pasangan kunci dan nilai. Kunci tersebut melalui fungsi hash untuk menghasilkan indeks, kemudian pasangan kunci-nilai tersebut ditambahkan ke linked list pada indeks yang sesuai dalam hash table. Fungsi hash menggunakan metode hashing yang mengalikan nilai ASCII dari setiap karakter dalam kunci dengan angka 31 dan mengambil modulus dengan ukuran tabel untuk memastikan bahwa indeks yang dihasilkan sesuai dengan ukuran tabel.

Setelah elemen-elemen dimasukkan, program menampilkan isi hash table dengan menggunakan metode `display`. Metode ini mencetak semua elemen yang ada di setiap indeks hash table dengan cara mengiterasi melalui tabel dan mencetak pasangan kunci-nilai yang ada di setiap linked list. Selanjutnya, program melakukan pencarian elemen menggunakan metode `search`. Metode ini menerima kunci yang akan dicari, kemudian menggunakan fungsi hash untuk menentukan indeks yang sesuai dan mencari kunci tersebut dalam linked list pada indeks tersebut. Jika kunci ditemukan, nilai yang terkait dengan kunci tersebut dikembalikan.

Program juga memungkinkan penghapusan elemen dari hash table menggunakan metode `remove`. Metode ini mencari dan menghapus pasangan kunci-nilai dari linked list pada indeks yang ditentukan oleh fungsi hash. Setelah melakukan operasi penghapusan, program kembali menampilkan isi hash table untuk memastikan bahwa elemen yang dihapus benar-benar telah dihapus. Dengan demikian, hash table ini mampu menangani operasi dasar seperti penambahan, pencarian, dan penghapusan elemen dengan efisien melalui penggunaan teknik hashing dan chaining.

### C. Rekursif 

Rekursif adalah sebuah algoritma yang berisi pemanggilan dirinya sendiri sehingga menghasilkan looping. Harus ada batasan di dalam rekursif sehingga looping dapat dibatalkan, jika tidak maka akan terjadi infinity loop dan dapat menyebabkan memori penuh [4].

Fungsi rekursif adalah fungsi yang memanggil dirinya sendiri. Fungsi ini akan terus berjalan sampai kondisi berhenti terpenuhi, oleh karena itu dalam sebuah fungsi rekursif perlu terdapat 2 blok penting, yaitu blok yang menjadi titik berhenti dari sebuah proses rekursi dan blok yang memanggil dirinya sendiri.

Kode rekursif cenderung lebih singkat dan lebih mudah dibuat dibandingkan dengan kode iteratif. Biasanya, perulangan dapat diubah menjadi fungsi rekursif saat proses kompilasi atau interpretasi. Rekursi sangat efektif untuk menangani tugas yang dapat diuraikan menjadi sub tugas yang serupa. Sebagai contoh, masalah pengurutan, pencarian, dan penjelajahan sering kali dapat diselesaikan dengan solusi rekursif yang sederhana.

Jenis-jenis Rekursi
Terdapat dua jenis fungsi rekursi yaitu:

a. Rekursi langsung

Dalam rekursi langsung, fungsi memanggil dirinya sendiri secara langsung. 

b. Rekursi tidak langsung

Jika sebuah fungsi memanggil dirinya sendiri secara tidak langsung dari fungsi lain.

#### Kode Program 
```C++
// Program Rekursif

#include <iostream>

int factorial(int n) {
    if (n == 0 || n == 1) {  // Basis kasus
        return 1;
    } else {
        return n * factorial(n - 1);  // Pemanggilan rekursif
    }
}

int main() {
    int number = 5;  // angka yang akan dicari faktorialnya
    std::cout << "Factorial of " << number << " is " << factorial(number) << std::endl;
    return 0;
}
```

#### Output

```
Factorial of 5 is 120
```

#### Penjelasan 

Berikut adalah penjelasan mengenai alur program diatas. Di dalam program ini, terdapat fungsi rekursif bernama `factorial` yang menerima sebuah parameter `n`, yang merupakan bilangan bulat. Fungsi ini dirancang untuk menghitung faktorial dari `n`. Faktorial dari `n` dihitung dengan basis kasus di mana jika `n` bernilai 0 atau 1, fungsi akan langsung mengembalikan nilai 1, karena faktorial dari 0 dan 1 adalah 1. Ini adalah basis kasus yang menghentikan pemanggilan rekursif untuk mencegah loop tak terbatas. Untuk nilai `n` yang lebih besar dari 1, fungsi akan memanggil dirinya sendiri dengan nilai `n` yang dikurangi satu (`n - 1`), dan mengalikan hasilnya dengan `n`. Dengan cara ini, setiap pemanggilan rekursif mengurangi nilai `n` hingga mencapai basis kasus. Sebagai contoh, untuk menghitung faktorial dari 5 (`5!`), fungsi akan memanggil `factorial(4)`, kemudian `factorial(3)`, dan seterusnya hingga mencapai `factorial(0)` atau `factorial(1)`, yang mengembalikan 1. Nilai ini kemudian dikalikan kembali ke atas rantai pemanggilan hingga menghasilkan nilai akhir. Pada fungsi `main`, variabel `number` diinisialisasi dengan nilai 5, dan fungsi `factorial` dipanggil dengan `number` sebagai parameter. Hasil faktorial dari 5 kemudian dicetak ke layar menggunakan `std::cout`. Akhirnya, program berakhir dengan perintah `return 0`, yang menunjukkan bahwa program telah selesai dijalankan dengan sukses tanpa kesalahan.

### D. Graph dan Tree

Graf adalah kumpulan noktah (simpul) di dalam bidang dua dimensi yang dihubungkan dengan sekumpulan garis (sisi).Graph dapat digunakan untuk merepresentasikan objek-objek diskrit dan hubungan antara objek-objek tersebut. Representasi visual dari graph adalah dengan menyatakan objek sebagai noktah, bulatan atau titik (Vertex), sedangkan hubungan antara objek dinyatakan dengan garis (Edge).

Ada beberapa cara untuk menyimpan graph di dalam sistem komputer. 
Struktur data bergantung pada struktur graph dan algoritma yang digunakan untuk memanipulasi graph. Secara teori salah satu dari keduanya dapat dibedakan antara struktur linked list dan matriks (array dimensi 2), tetapi dalam penggunaannya struktur terbaik yang sering digunakan adalah kombinasi keduanya [5]. 

Terdapat beberapa jenis graph yaitu 

- Graph tak berarah (undirected graph atau non-directed graph) dimana urutan simpul dalam sebuah busur tidak dipentingkan. Misal busur e1 dapat disebut busur AB atau BA. 
- Graph berarah (directed graph) dimana urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8. 
-  Graph Berbobot (Weighted Graph) 

-> Jika setiap busur mempunyai nilai yang menyatakan hubungan antara 2 
buah simpul, maka busur tersebut dinyatakan memiliki bobot. 

-> Bobot sebuah busur dapat menyatakan panjang sebuah jalan dari 2 buah 
titik, jumlah rata-rata kendaraan perhari yang melalui sebuah jalan, dll. 

Tree adalah struktur data yang terdiri dari kumpulan node yang saling terhubung dengan struktur data hirarki (one-to-many). Setiap node dapat memiliki 0 atau lebih node anak, dan disebut node induk (parent) jika memiliki node anak. Node yang berada di pangkal tree disebut node root (akar), sedangkan node yang berada paling ujung pada piramida tree disebut node leaf (daun) [6].

jenis-jenis tree sebagai berikut [7]:
- Binary Tree

Binary Tree adalah tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua subtree dan kedua subtree tersebut harus terpisah. Sesuai dengan definisi tersebut, maka tiap node dalam binary tree hanya boleh memiliki paling banyak dua child. contoh implementasi binary tree.

jenis-jenis binary tree:

1. Full Binary Tree

Full binary tree adalah binary tree yang tiap node-nya (kecuali leaf) memiliki dua child dan tiap subtree harus mempunyai panjang path yang sama.

2. Complete Binary Tree

Complete binary tree adalah binary tree yang mirip dengan full binary tree, namun tiap subtree boleh memiliki panjang path yang berbeda. Node kecuali leaf memiliki 0 atau 2 child.

3. Skewed Binary Tree

Skewed binary t ree adalah binary tree yang semua node nya (kecuali leaf) hanya memiliki satu child.

4. Binary search tree (BST)

Binary search t ree (BST) adalah jenis pohon terurut yang digunakan untuk menyimpan data sehingga memudahkan pencarian kembali data tersebut.

Operasi pada Tree:

- Create
Create digunakan untuk membentuk binary tree baru yang masih kosong.

- Clear
Clear digunakan untuk mengosongkan binary tree yang sudah ada.

- Empty
Empty digunakan untuk memeriksa apakah binary tree masih kosong.

- Insert

Insert digunakan untuk memasukkan sebuah node ke dalam tree.

- Find

Find digunakan untuk mencari root, parent, left child , atau right child dari suatu node dengan syarat tree tidak boleh kosong.

- Update

Update digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong.

- Retrieve

Retrieve digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.

- Delete Sub

DeleteSub digunakan untuk menghapus sebuah sub-tree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.

- Characteristic

Characteristic digunakan untuk mengetahui karakteristik dari suatu tree, yakni size, height, serta average length-nya.

- Traverse

Traverse digunakan untuk mengunjungi seluruh node-node pada tree, masing-masing sekali.

Tree Traversal: 

Tree traversal merupakan sebuah kunjungan yang berawal dari root, mengunjungi setiap node dalam tree masing-masing sekali. Kunjungan atau traversing dapat dilakukan dengan 3 cara yaitupre order, in order dan post order.

A.  Preorder

Algoritma preorder :

- Mencetak info pada node yang dikunjungi.
- Mengunjungi cabang kiri.
- Mengunjungi cabang kanan.

B. Inorder

Algoritma inorder :

- Mengunjungi cabang kiri.
- Mencetak info pada node yang dikunjungi.
- Mengunjungi cabang kanan.

c. Postorder

Algoritma postorder :
- Mengunjungi cabang kiri.
- Mengunjungi cabang kanan.
- Mencetak info pada node yang dikunjungi.
- Breadth-first search (BFS) dan Depth-First-Search (DFS).

Breadth-first search (BFS):

Breadth-first search (BFS) melakukan proses searching pada semua node yang berada pada level atau hierarki yang sama terlebih dahulu sebelum melanjutkan proses searching pada node di level berikutnya.

Depth-First-Search (DFS):

Depth-First-Search (DFS) adalah salah satu algoritma penelusuran struktur tree berdasarkan kedalaman. Simpul ditelusuri dari root kemudian ke salah satu simpul anaknya (misalnya prioritas penelusuran berdasarkan anak pertama [simpul sebelah kiri]), maka penelusuran dilakukan terus melalui simpul anak pertama dari simpul anak pertama level sebelumnya hingga mencapai level terdalam. Setelah sampai di level terdalam, penelusuran akan kembali ke 1 level sebelumnya untuk menelusuri simpul anak kedua pada pohon biner [simpul sebelah kanan] lalu kembali ke langkah sebelumnya dengan menelusuri simpul anak pertama lagi sampai level terdalam dan seterusnya.

#### Kode Program Graph 
```C++
// Program Graph 

#include <iostream>
#include <list>
#include <unordered_map>

// Kelas untuk Graph menggunakan adjacency list
class Graph {
private:
    std::unordered_map<int, std::list<int>> adjList;  // Peta untuk adjacency list

public:
    // Menambahkan edge dari node u ke node v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Menampilkan adjacency list
    void display() {
        for (auto const &pair : adjList) {
            std::cout << pair.first << " -> ";
            for (auto const &v : pair.second) {
                std::cout << v << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g;

    // Menambahkan edge-edge pada graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    // Menampilkan adjacency list dari graph
    std::cout << "Adjacency List of Graph:" << std::endl;
    g.display();

    return 0;
}
```

#### Output

```
Adjacency List of Graph:
0 -> 1 2 
1 -> 2 
2 -> 0 3 
3 -> 3 
```

#### Penjelasan 

Berikut adalah penjelasan mengenai alur program diatas. Pada awalnya, kita mendefinisikan sebuah kelas bernama `Graph` yang menggunakan adjacency list untuk merepresentasikan graph. Struktur data yang digunakan untuk adjacency list adalah `std::unordered_map`, di mana kunci dari map adalah simpul dalam graph (dalam hal ini, bertipe integer), dan nilai dari map adalah daftar (list) simpul-simpul yang terhubung langsung ke simpul tersebut.

Kelas `Graph` memiliki dua metode utama:
1. `addEdge(int u, int v)`: Metode ini digunakan untuk menambahkan sebuah edge ke dalam graph dari simpul `u` ke simpul `v`. Ini dilakukan dengan menambahkan simpul `v` ke dalam daftar adjacency list dari simpul `u`.
2. `display()`: Metode ini digunakan untuk menampilkan adjacency list dari graph. Ini mencetak setiap simpul dalam graph, diikuti oleh daftar simpul-simpul yang terhubung langsung ke simpul tersebut.

Di dalam fungsi `main`, kita membuat sebuah objek `Graph` bernama `g`. Kemudian, kita menambahkan beberapa edge ke dalam graph menggunakan metode `addEdge`, sesuai dengan edge-edge yang kita inginkan. Setelah itu, kita memanggil metode `display` untuk menampilkan adjacency list dari graph yang telah kita buat.

Hasil dari program ini adalah mencetak adjacency list dari graph yang telah kita definisikan, yang menunjukkan koneksi antara simpul-simpul dalam graph tersebut.

#### Kode Program Tree
```C++
// Program Tree

#include <iostream>
#include <queue>

// Struktur untuk simpul dari binary tree
struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Kelas untuk Binary Tree
class BinaryTree {
public:
    TreeNode *root;

    BinaryTree() {
        root = nullptr;
    }

    // Menambahkan node ke binary tree
    void insert(int value) {
        if (root == nullptr) {
            root = new TreeNode(value);
        } else {
            insertHelper(root, value);
        }
    }

    // Pre-order traversal
    void preOrder(TreeNode *node) {
        if (node == nullptr) return;

        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // In-order traversal
    void inOrder(TreeNode *node) {
        if (node == nullptr) return;

        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }

    // Post-order traversal
    void postOrder(TreeNode *node) {
        if (node == nullptr) return;

        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }

private:
    // Fungsi utilitas untuk menambahkan node ke tree
    void insertHelper(TreeNode *node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new TreeNode(value);
            } else {
                insertHelper(node->left, value);
            }
        } else {
            if (node->right == nullptr) {
                node->right = new TreeNode(value);
            } else {
                insertHelper(node->right, value);
            }
        }
    }
};

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Pre-order traversal: ";
    tree.preOrder(tree.root);
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    tree.inOrder(tree.root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postOrder(tree.root);
    std::cout << std::endl;

    return 0;
}
```

#### Output 

```
Pre-order traversal: 50 30 20 40 70 60 80 
In-order traversal: 20 30 40 50 60 70 80 
Post-order traversal: 20 40 30 60 80 70 50 
```

#### Penjelasan

Berikut adalah penjelasan mengenai alur program diatas. Program ini menggunakan binary tree. Binary tree adalah struktur data hierarkis di mana setiap simpul memiliki maksimal dua anak, yaitu kiri dan kanan.

Diawali dengan mendefinisikan struktur data `TreeNode`, yang merupakan simpul dari binary tree. Setiap simpul memiliki tiga atribut: data (nilai yang disimpan di simpul tersebut), pointer ke anak kiri, dan pointer ke anak kanan.

Kemudian, didefinisikan kelas `BinaryTree` yang merepresentasikan binary tree. Kelas ini memiliki satu atribut `root` yang merupakan pointer ke simpul akar dari binary tree. Konstruktor `BinaryTree` digunakan untuk menginisialisasi nilai `root` menjadi `nullptr`.

Metode `insert(int value)` digunakan untuk menambahkan sebuah nilai ke binary tree. Jika binary tree masih kosong (nilai `root` adalah `nullptr`), simpul baru dengan nilai tersebut akan menjadi akar binary tree. Jika tidak, metode rekursif `insertHelper` akan dipanggil untuk menemukan posisi yang tepat untuk menyisipkan nilai baru sesuai dengan aturan binary tree.

Metode traversal `preOrder`, `inOrder`, dan `postOrder` digunakan untuk melakukan penjelajahan (traversal) dari binary tree sesuai dengan urutan pre-order, in-order, dan post-order. Penjelajahan pre-order mencetak nilai simpul sebelum mencetak nilai anak-anaknya, penjelajahan in-order mencetak nilai simpul setelah mencetak nilai anak kiri dan sebelum mencetak nilai anak kanan, dan penjelajahan post-order mencetak nilai simpul setelah mencetak nilai anak-anaknya.

Di dalam fungsi `main`, sebuah objek `BinaryTree` dibuat, dan beberapa nilai ditambahkan ke dalam binary tree menggunakan metode `insert`. Setelah itu, dilakukan penjelajahan binary tree menggunakan metode `preOrder`, `inOrder`, dan `postOrder`, dan hasilnya ditampilkan ke layar.

Output dari program ini akan menampilkan nilai-nilai yang telah diurutkan sesuai dengan jenis penjelajahan yang digunakan (pre-order, in-order, dan post-order).

## Daftar Referensi

[1] Y. P. Harahap dan A. Prapanca, "Analisis Algoritma Penjadwalan Priority Queueing (PQ) Terhadap Quality of Service (QoS) pada Jaringan Mobile WiMAX Menggunakan OPNET Modeler," *Journal of Informatics and Computer Science*, vol. 3, no. 2, pp. 104, 2021.

[2] GeeksforGeeks, "Priority Queue (Set 1) - Introduction," GeeksforGeeks, 2024. [Online]. Available: https://www.geeksforgeeks.org/priority-queue-set-1-introduction/. [Accessed: Jun. 11, 2024].

[3] V. Mutiawani, "Hashtable sebagai alternatif dari algoritma pencarian biner pada aplikasi E-ACESIA," *Jurnal Informatika*, vol. 8, no. 2, pp. 943-952, 2014.

[4] F.A. T. Tobing, Prayogo, dan A. Chandra, "Analisis Perbandingan Fibonacci dengan Iterasi dan Rekursi Terhadap Efektifitas Waktu," *Jurnal Sains dan Teknologi Widya*, vol. 1, no. 2, pp. 188-195, 2022.

[5] A. R. Rahman, "Graph I," in *Praktikum Algoritma dan Struktur Data*, PENS, 2020. [Online]. Available: https://arna.lecturer.pens.ac.id/Praktikum_ASD/14%20Graph%201.pdf. [Accessed: Jun. 11, 2024].

[6] Hafnani, S. Amri, and Mahmudi, "TREE LEECH," *FIBONACCI: Jurnal Pendidikan Matematika dan Matematika*, vol. 6, no. 1, pp. 1-10, 2020.

[7] Bocah Ngoding, "Pengertian Tree pada Struktur Data," *Bocah Ngoding*, Jan. 10, 2018. [Online]. Available: https://bocahngoding.blogspot.com/2018/01/pengertian-tree-pada-struktur-data.html. [Accessed: Jun. 11, 2024].




