#pragma once

template<typename T>
class Node
{
    private:
        T data;
        Node<T>* prev;
        Node<T>* next;
    public:
        Node<T>(const T& value) : data(value), prev(nullptr), next(nullptr) {}
        ~Node<T>() = default; // Destructor
        
        T* get_data() { return &data; }
        Node<T>* get_prev() const { return prev; }
        Node<T>* get_next() const { return next; }
        
        void set_prev(Node<T>* p) { prev = p; }
        void set_next(Node<T>* n) { next = n; }
};
