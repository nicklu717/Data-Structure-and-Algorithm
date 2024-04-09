#include "DataStructure/LinkedList/SingleLinkedList.cpp"

void testSingleLinkedList();

int main() {
    testSingleLinkedList();

    return 0;
}

// MARK: - Testing methods
void testSingleLinkedList() {
    SingleLinkedList<int> list = SingleLinkedList<int>();
    list.append(3);
    list.append(5);
    list.append(6);
    list.append(8);
    list.append(1111);
    list.print();

    cout << "Element 0: " << *list.element(0) << endl;
    auto element_2 = list.element(2);
    if (element_2.has_value()) {
        cout << "Element 2: " << element_2.value() << endl;
    } else {
        cout << "Element 2: NULL" << endl;
    }
    auto element_5 = list.element(5);
    if (element_5.has_value()) {
        cout << "Element 5: " << element_5.value() << endl;
    } else {
        cout << "Element 5: NULL" << endl;
    }
    cout << "Element 6: " << *list.element(6) << endl;

    list.insert(7, 3);
    list.insert(4, 1);
    list.insert(99, 0);
    list.insert(23489, 23);
    list.print();

    list.remove(6);
    list.print();
    list.remove(6);
    list.print();
    list.remove(6);
    list.print();
    list.remove(0);
    list.print();
}