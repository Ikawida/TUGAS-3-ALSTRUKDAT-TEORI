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
