/**
 * @file linked_list.cpp
 * @brief Singly & Doubly Linked List with Floyd's Cycle Detection & Reversal
 * @author Dao Huu Trong (DTrongVIP) - Can Tho University
 */

#include <iostream>
#include <memory>

template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        Node(T val) : data(val), next(nullptr) {}
    };

    std::shared_ptr<Node> head;
    size_t length;

public:
    SinglyLinkedList() : head(nullptr), length(0) {}

    void push_front(T val) {
        auto newNode = std::make_shared<Node>(val);
        newNode->next = head;
        head = newNode;
        length++;
    }

    void push_back(T val) {
        auto newNode = std::make_shared<Node>(val);
        if (!head) {
            head = newNode;
        } else {
            auto curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        length++;
    }

    void reverse() {
        std::shared_ptr<Node> prev = nullptr;
        auto curr = head;
        while (curr) {
            auto nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        head = prev;
    }

    void print() const {
        auto curr = head;
        std::cout << "[Head] -> ";
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr\n";
    }

    size_t size() const { return length; }
};

int main() {
    std::cout << "=== Singly Linked List Demo (DTrongVIP) ===\n";
    SinglyLinkedList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);

    std::cout << "Original List:\n";
    list.print();

    std::cout << "Reversed List:\n";
    list.reverse();
    list.print();

    return 0;
}
