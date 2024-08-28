#include <stdexcept>

using namespace std;

template<typename T>
struct Nodo_list{
    Nodo_list* next;
    T valor;
};

template<typename T>
class Lista {
private:
    Nodo_list<T> *head;
public:
    T front() {
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }

        return *head;
    }

    T back() {
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }

        Nodo_list<T>* temp = head;

        while (temp->next != nullptr){
            temp = temp->next;
        }
        return temp->valor;
    }

    void push_front(T a) {
        auto* nodo = new Nodo_list<T>;
        nodo->valor=a;
        nodo->next=head;
        head=nodo;
    }

    void push_back(T a){
        Nodo_list<T>* temp = head;
        while (temp->next != nullptr){
            temp = temp->next;
        }
        auto nodo = new Nodo_list<T>;
        temp->next=&nodo;
        nodo->valor=a;
        nodo->next= nullptr;
    }

    T pop_front(){
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }

        Nodo_list<T>* temp = head;
        head = head->next;
        delete temp;
    }

    T pop_back() {
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }

        Nodo_list<T>* temp = head;

        if (temp->next == nullptr) {
            T data = temp->data;
            delete temp;
            head = nullptr;
            return data;
        }

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        T data = temp->next->data;
        delete temp->next;
        temp->next = nullptr;

        return data;
    }


    void clear(){
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }

        while(head != nullptr)
        {
            Nodo_list<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void reverse(){
        if (head == nullptr) {
            throw out_of_range("La lista está vacía");
        }

        Nodo_list<T>* temp;
        Nodo_list<T>* temp1;
        temp=head->next;
        head->next= nullptr;
        while (temp->next != nullptr){
            temp1=temp->next;
            temp->next=head;
            temp=temp1;
        }
        temp->next=head;
        head=temp;
    }

    bool empty(){
        return head == nullptr;
    }

    T operator[](int pos){
        Nodo_list<T>* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = head->next;
        }
        return *temp;
    }

};



