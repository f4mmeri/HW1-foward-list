#include <iostream>
#include "foward_list.h"

using namespace std;

int main() {
    ForwardList<int> list;

    list.push_front(10);
    list.push_back(20);
    list.push_front(5);
    list.push_back(25);
    list.push_back(15);

    cout << "Lista después de agregar elementos (push_front, push_back): ";
    list.print();

    list.pop_front();
    list.pop_back();
    cout << "Lista después de pop_front y pop_back: ";
    list.print();

    list[1];
    list.empty();
    list.size();

    list.sort();
    cout << "Lista después de ordenar: ";
    list.print();

    list.reverse();
    cout << "Lista después de invertir: ";
    list.print();

    list.clear();
    cout << "Lista después de clear: ";
    list.print();

    return 0;
}
