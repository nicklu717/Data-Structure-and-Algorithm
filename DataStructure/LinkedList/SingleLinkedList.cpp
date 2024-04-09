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

    bool insert(const Element& element, const int& index) {
        if (index == 0) {
            Node* newNode = new Node(element);
            newNode->next = head;
            head = newNode;
            return true;
        } else if (index > 0) {
            Node* currentNode = head;
            for (int i = 1; i < index && currentNode; i++) {
                currentNode = currentNode->next;
            }
            if (currentNode) {
                Node* newNode = new Node(element);
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    
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
    
    optional<Element> remove(const int& index) {
        if (head) {
            if (index > 0) {
                Node* currentNode = head;
                for (int i = 1; i < index && currentNode; i++) {
                    currentNode = currentNode->next;
                }
                if (currentNode && currentNode->next) {
                    Node* removedNode = currentNode->next;
                    currentNode->next = removedNode->next;
                    Element removedElement = removedNode->element;
                    delete removedNode;
                    return removedElement;
                } else {
                    return nullopt;
                }
            } else if (index == 0) {
                Node* previousHead = head;
                Element removedElement = previousHead->element;
                head = head->next;
                delete previousHead;
                return removedElement;
            } else {
                return nullopt;
            }
        } else {
            return nullopt;
        }
    }

    void print() const {
        Node* currentNode = head;
        while (currentNode) {
            cout << currentNode->element << " -> ";
            currentNode = currentNode->next;
        }
        cout << "NULL" << endl;
    }
};