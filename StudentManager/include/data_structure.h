// data_structure.h
#pragma once

// Student Linked List class
#include "node.h"

template<typename T>
class DoublyLinkedList
{
    private:
        Node<T>* head;                      // Pointer to the head of the linked list
        Node<T>* tail;                      // Pointer to the tail of the linked list
        int size;                           // Number of students in the list
    public:
        DoublyLinkedList<T>();              // Constructor to initialize the list
        ~DoublyLinkedList<T>();             // Destructor to clean up the list

        void push_back(const T& value);     // Add a node to the end of the list
        void push_front(const T& value);    // Add a node to the front of the list
        void pop_front();                   // Remove the first node from the list
        void pop_back();                    // Remove the last node from the list
        Node<T>* get_head();                // Get the head of the list
        void remove(const T& value);        // Remove a specific node from the list
        void clear();                       // Clear the list
        int get_size();                     // Get the number of nodes in the list
        bool empty() const;                 // Check if the list is empty        
};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    clear();
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if (tail)
    {
        tail->set_next(newNode);
        newNode->set_prev(tail);
        tail = newNode;
    }
    else
    {
        head = tail = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T& value)
{
    Node<T>* newNode = new Node<T>(value);
    if (head)
    {
        head->set_prev(newNode);
        newNode->set_next(head);
        head = newNode;
    }
    else
    {
        head = tail = newNode;
    }
    size++;
}

template<typename T>
void DoublyLinkedList<T>::pop_front()
{
    if (head)
    {
        Node<T>* temp = head;
        head = head->get_next();
        if (head)
        {
            head->set_prev(nullptr);
        }
        else
        {
            tail = nullptr; // List is now empty
        }
        delete temp;
        size--;
    }
}

template<typename T>
void DoublyLinkedList<T>::pop_back()
{
    if (tail)
    {
        Node<T>* temp = tail;
        tail = tail->get_prev();
        if (tail)
        {
            tail->set_next(nullptr);
        }
        else
        {
            head = nullptr; // List is now empty
        }
        delete temp;
        size--;
    }
}

template<typename T>
Node<T>* DoublyLinkedList<T>::get_head()
{
    return head;
}

template<typename T>
void DoublyLinkedList<T>::remove(const T& value)
{
    Node<T>* current = head;
    while (current)
    {
        if (current->get_data()->getId() == value.getId())
        {
            if (current->get_prev())
            {
                current->get_prev()->set_next(current->get_next());
            }
            else
            {
                head = current->get_next(); // Update head if removing first node
            }
            if (current->get_next())
            {
                current->get_next()->set_prev(current->get_prev());
            }
            else
            {
                tail = current->get_prev(); // Update tail if removing last node
            }
            delete current;
            size--;
            return; // Exit after removing the first occurrence
        }
        current = current->get_next();
    }
}

template<typename T>
int DoublyLinkedList<T>::get_size()
{
    return size;
}

template<typename T>
bool DoublyLinkedList<T>::empty() const
{
    return size == 0;
}

template<typename T>
void DoublyLinkedList<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}
