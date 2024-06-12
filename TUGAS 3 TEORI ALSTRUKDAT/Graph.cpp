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
