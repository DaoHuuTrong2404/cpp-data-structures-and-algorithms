/**
 * @file binary_search_tree.cpp
 * @brief Binary Search Tree (BST) with Recursive & Iterative Traversals
 * @author Dao Huu Trong (DTrongVIP) - Can Tho University
 */

#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->val) {
            node->right = insertRecursive(node->right, val);
        }
        return node;
    }

    void inOrder(TreeNode* node) const {
        if (!node) return;
        inOrder(node->left);
        std::cout << node->val << " ";
        inOrder(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    void printInOrder() const {
        std::cout << "BST In-Order Traversal: ";
        inOrder(root);
        std::cout << "\n";
    }

    bool search(int target) const {
        TreeNode* curr = root;
        while (curr) {
            if (curr->val == target) return true;
            curr = (target < curr->val) ? curr->left : curr->right;
        }
        return false;
    }
};

int main() {
    std::cout << "=== Binary Search Tree Demo (DTrongVIP) ===\n";
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.printInOrder();

    int target = 40;
    std::cout << "Searching for " << target << ": " 
              << (bst.search(target) ? "FOUND" : "NOT FOUND") << "\n";

    return 0;
}
