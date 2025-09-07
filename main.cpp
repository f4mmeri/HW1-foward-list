#include <iostream>
#include "foward_list.h"
using namespace std;

int main() {
    cout << "FowardList tests:" << endl;
    ForwardList<int> Lista;
    Lista.push_front(7);
    Lista.push_front(1);
    Lista.push_front(3);
    Lista.push_front(6);
    Lista.push_front(4);
    Lista.push_front(5);

    cout << "Lista después de agregar elemento: ";
    Lista.print();

    Lista.front();
    Lista.back();
    Lista.push_back(12);
    Lista.push_back(2);
    Lista.push_back(8);
    Lista.pop_back();
    Lista.pop_front();
    cout << "Lista después de cambios: ";
    Lista.print();

    Lista[3];
    Lista.empty();
    Lista.size();
    Lista.sort();
    Lista.print();

    Lista.reverse();
    Lista.print();
    Lista.clear();
    Lista.print();
}