#include <iostream>
#include <optional>

using namespace std;

template <class Element>
class SingleLinkedList {
private:
    class Node {
    public:
        Element element;
        Node* next;

        Node(const Element& element):
            element(element),
            next(nullptr) {}
    };

    Node* head;

public:
    SingleLinkedList(): head(nullptr) {}
    ~SingleLinkedList() {
        Node* currentNode = head;
        while (currentNode) {
            Node* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }

    void append(const Element& element) {
        if (head) {
            Node* currentNode = head;
            while (currentNode->next) {
                currentNode = currentNode->next;
            }
            currentNode->next = new Node(element);
        } else {
            head = new Node(element);
        }
    }

    // bool insert(const Element& element, const int& index) {}
    
    optional<Element> element(const int& index) {
        Node* current = head;
        if (index > 0) {
            for (int i = 1; i <= index && current; i++) {
                current = current->next;
            }
        }
        if (current) {
            return current->element;
        } else {
            return nullopt;
        }
    }
    
    // Element* remove(const int& index) {}

    void print() const {
        Node* currentNode = head;
        while (currentNode) {
            cout << currentNode->element << " -> ";
            currentNode = currentNode->next;
        }
        cout << "NULL" << endl;
    }
};