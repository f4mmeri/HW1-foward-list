#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>
using namespace std;

template <class T>
struct Node {
    Node* next;
    T data;
    Node(T value) : data(value), next(nullptr) {}
};

template <class T>
class ForwardList {
private:
    Node<T>* head;

public:
    ForwardList() : head(nullptr) {}

    ~ForwardList() {
        clear();
    }

    T front() {
        if (head != nullptr) {
            cout << "Front: " << head->data << endl;
            return head->data;
        }
        return T();
    }

    T back() {
        if (head == nullptr) return T();
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }

    void push_front(T value) {
        Node<T>* new_node = new Node<T>(value);
        new_node->next = head;
        head = new_node;
    }

    void push_back(T value) {
        Node<T>* new_node = new Node<T>(value);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    T pop_front() {
        if (head == nullptr) return T();
        Node<T>* temp = head;
        T data = temp->data;
        head = head->next;
        delete temp;
        cout << "Pop Front: " << data << endl;
        return data;
    }


    T pop_back() {
        if (head == nullptr) return T();
        if (head->next == nullptr) {
            T data = head->data;
            delete head;
            head = nullptr;
            cout << "Pop Back: " << data << endl;
            return data;
        }
        Node<T>* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        T data = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        cout << "Pop Back: " << data << endl;
        return data;
    }


    T operator[](int index) {
        if (head == nullptr || index < 0) return T();
        Node<T>* temp = head;
        int counter = 0;
        while (temp != nullptr) {
            if (counter == index) {
                return temp->data;
            }
            counter++;
            temp = temp->next;
        }
        return T();
    }

    bool empty() {
        bool isEmpty = (head == nullptr);
        cout << "vacio: " << boolalpha << isEmpty << endl;
        return isEmpty;
    }


    int size() {
        int count = 0;
        Node<T>* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        cout << "Size: " << count << endl;
        return count;
    }

    void clear() {
        while (head != nullptr) {
            pop_front();
        }
    }


    void sort() {
        if (head == nullptr) return;
        Node<T>* temp1 = head;
        while (temp1 != nullptr) {
            Node<T>* temp2 = temp1->next;
            while (temp2 != nullptr) {
                if (temp1->data > temp2->data) {
                    T temp = temp1->data;
                    temp1->data = temp2->data;
                    temp2->data = temp;
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
    }

    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* curr = head;
        Node<T>* next = nullptr;
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    // Imprime los elementos de la lista para main
    void print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

#endif // FORWARD_LIST_H
