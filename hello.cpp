#include <iostream>
#include "node.cpp"

int main() {
    Node root(0);
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);

    std::cout << "добавление новой вершины в соответствии со значением ее ключа." << std::endl;
    root.setChildren(&n3);
    root.setChildren(&n4);
    root.setChildren(&n1);
    root.setChildren(&n2);
    std::cout << "Итоговое дерево" << std::endl;
    // построчный вывод дерева в наглядном виде с помощью обратно-симметричного обхода.
    root.inOrderTraversCall();

    std::cout << "\nпоиск вершины с заданным значением ключа, со значением 3 из корня 0" << std::endl;

    Node* n = root.getNodeByValue(3);
    
    std::cout << "\nНайдено дерево со значением: " << n->value << std::endl;
}