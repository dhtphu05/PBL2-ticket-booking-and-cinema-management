
#include <iostream>
using namespace std;
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

template <class Type>
class Node
{
public:
    Type data;
    Node *next;
    Node *prev;
    Node(const Type &data) : data(data), next(nullptr), prev(nullptr) {}
};
template <class Type>
class DoubleLinkedList
{
private:
    Node<Type> *head;
    Node<Type> *tail;
    int size;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            Node<Type> *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
    bool isEmpty() const {
        return size==0;
    }
    void push_back(const Type &data)
    {
        Node<Type> *newNode = new Node<Type>(data);
        if (isEmpty())
        {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = nullptr;
        }
        tail = newNode;
        this->size++;
    }
    void push_front(const Type &data)
    {
        Node<Type> *newNode = new Node<Type>(data);
        if (isEmpty())
        {
            newNode->next = nullptr;
            newNode->prev = nullptr;
            head = newNode;
        }
        else
        {
            newNode->next = head;
            newNode->prev = nullptr;
            head->prev = newNode;
            head = newNode;
        }
        if (tail == nullptr)
        {
            tail = newNode;
        }
        this->size++;
    }
    void insert(int index, const Type &data)
    {
        if (index < 0 || index > size)
        {
            cout << "Index out of range" << endl;
            return;
        }
        if (index == 0)
        {
            push_front(data);
        }
        else if (index == size)
        {
            push_back(data);
        }
        else
        {
            Node<Type> *newNode = new Node<Type>(data);
            Node<Type> *prevNode = head;
            for (int i = 0; i < index - 1; i++)
            {
                prevNode = prevNode->next;
            }
            newNode->next = prevNode->next; // prevNode is on index-1.
            newNode->prev = prevNode;
            if (prevNode->next != nullptr)
            {
                prevNode->next->prev = newNode;
            }
            prevNode->next = newNode;
            this->size++;
        }
    }
    void pop_back()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        Node<Type> *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        this->size--;
    }
    void pop_front()
    {
        if (isEmpty())
        {
            cout << "List is empty" << endl;
            return;
        }
        if (size == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            this->size--;
            return;
        }
        Node<Type> *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
        this->size--;
    }
    void earse(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of range" << endl;
            return;
        }
        if (index == 0)
        {
            pop_front();
        }
        else if (index == size - 1)
        {
            pop_back();
        }
        else
        {
            Node<Type> *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            this->size--;
        }
    }
    
    Type& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<Type>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    } //using like array access
    void display(){
        Node<Type> *current=head;
        while(current!=nullptr){
            current->data.Display();  //call display function of each Type (class)
            current=current->next;
        }
        cout << endl;
    }
    Node<Type> *begin() const
    {
        return head;
    }
    Node<Type> *end() const
    {
        return tail;
    }
    int getSize() const
    {
        return size;
    }
};

#endif