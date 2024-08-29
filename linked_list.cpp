#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
struct Nodo_list {
    Nodo_list* next;
    T valor;

    Nodo_list(T val) : valor(val), next(nullptr) {}
};

template<typename T>
class Lista {
private:
    Nodo_list<T> *head;
public:
    Lista() : head(nullptr) {}

    ~Lista() {
        clear();
    }

    T front() {
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }
        return head->valor;
    }

    T back() {
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }
        Nodo_list<T>* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->valor;
    }

    void push_front(T a) {
        auto* nodo = new Nodo_list<T>(a);
        nodo->next = head;
        head = nodo;
    }

    void push_back(T a) {
        auto* nodo = new Nodo_list<T>(a);
        if (head == nullptr) {
            head = nodo;
        } else {
            Nodo_list<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nodo;
        }
    }

    T pop_front() {
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }
        Nodo_list<T>* temp = head;
        T valor = temp->valor;
        head = head->next;
        delete temp;
        return valor;
    }

    T pop_back() {
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }

        Nodo_list<T>* temp = head;

        if (temp->next == nullptr) {
            T valor = temp->valor;
            delete temp;
            head = nullptr;
            return valor;
        }

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        T valor = temp->next->valor;
        delete temp->next;
        temp->next = nullptr;
        return valor;
    }

    void clear() {
        while (head != nullptr) {
            Nodo_list<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int size() {
        int tam = 0;
        Nodo_list<T>* temp = head;
        while (temp != nullptr) {
            tam++;
            temp = temp->next;
        }
        return tam;
    }

    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Nodo_list<T>* prev = nullptr;
        Nodo_list<T>* current = head;
        Nodo_list<T>* next = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    bool empty() {
        return head == nullptr;
    }

    T operator[](int pos) {
        if (pos < 0) {
            throw out_of_range("Posición fuera de rango");
        }
        Nodo_list<T>* temp = head;
        for (int i = 0; i < pos && temp != nullptr; ++i) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            throw out_of_range("Posición fuera de rango");
        }
        return temp->valor;
    }

    void print(){
        auto temp=head;
        while (temp != nullptr){
            cout<<temp->valor<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};



int main() {
    Lista<int> listita;
    listita.push_back(4);
    cout << listita.front() << endl;
    cout << listita.back() << endl;
    listita.print();

    listita.push_front(2);
    cout << listita.front() << endl;
    listita.print();

    listita.push_back(6);
    listita.push_back(8);
    cout << listita.back() << endl;
    listita.print();

    listita.reverse();
    cout << listita.front() << endl;
    cout << listita.back() << endl;
    listita.print();

    listita.pop_front();
    listita.pop_back();
    listita.print();

    cout << listita.front() << endl;
    cout << listita.back() << endl;
    listita.print();
    listita.clear();
    listita.print();

    return 0;
}



