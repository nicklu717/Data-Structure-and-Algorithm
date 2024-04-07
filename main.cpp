#include "DataStructure/LinkedList/SingleLinkedList.cpp"

void testSingleLinkedList() {
    SingleLinkedList<int> list = SingleLinkedList<int>();
    list.append(3);
    list.append(5);
    list.append(6);
    list.append(8);
    list.append(1111);
    list.print();
}

int main() {
    testSingleLinkedList();

    return 0;
}