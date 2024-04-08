#include "DataStructure/LinkedList/SingleLinkedList.cpp"

void testSingleLinkedList() {
    SingleLinkedList<int> list = SingleLinkedList<int>();
    list.append(3);
    list.append(5);
    list.append(6);
    list.append(8);
    list.append(1111);
    list.print();
    cout << *list.element(0) << endl;
    cout << *list.element(1) << endl;
    cout << *list.element(2) << endl;
    cout << *list.element(3) << endl;
    cout << *list.element(4) << endl;
    cout << *list.element(5) << endl;
    cout << *list.element(6) << endl;
}

int main() {
    testSingleLinkedList();

    return 0;
}