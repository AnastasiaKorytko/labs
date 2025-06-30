//#pragma once
//#include "header.h"
//List::List() : head(nullptr), tail(nullptr), size(0) {}
//List::~List()
//{
//    deleteall();
//}
//void List:: init(const Flight& a)
//{
//    struct Node* newNode = new Node(a);
//    head = tail = newNode;
//    size++;
//
//}
//void List::addindex(int index, const Flight& flight)
//{
//    if (index > size+1)
//    {
//        cout << "error" << endl;
//    }
//    else if (index == 0)
//    {
//        addbegin(flight);
//    }
//    else if (index == size+1)
//    {
//        addend(flight);
//    }
//    else if (index != 0 && index != size+1) {
//        Node* newNode = new Node(flight);
//        Node* current = head;
//        for (int i = 0; i < index; i++)
//        {
//            current = current->next;
//        }
//        newNode->prev = current->prev;
//        newNode->next = current;
//        current->prev->next = newNode;
//        current->prev = newNode;
//        size++;
//    }
//    
//}
//
//bool List::Empty() const
//{
//    return size == 0;
//}
//void List:: addbegin(const Flight& flight)
//{
//        Node* newNode = new Node(flight);
//        newNode->next = head;
//        head->prev = newNode;
//        head = newNode;
//        size++;
//}
//void List:: addend(const Flight& flight)
//{
//    Node* newNode = new Node(flight);
//    if (Empty()) 
//    {
//        head = tail = newNode;
//    }
//    else 
//    {
//        tail->next = newNode;
//        newNode->prev = tail;
//        tail = newNode;
//    }
//    size++;
//}
//void List::deleteindex(size_t index)
//{
//
//    /*if (index > size+1)
//    {
//        cout << "error" << endl;
//    }
//    else if (index == 0)
//    {
//        deletebegin();
//    }
//    else if (index == size+1)
//    {
//        deleteend();
//    }*/
//    if (Empty())
//    {
//        cout << "list is empty" << endl;;
//    }
//    else {
//        Node* current = head;
//        for (size_t i = 0; i < index; i++)
//        {
//            current = current->next;
//        }
//        current->prev->next = current->next;
//        current->next->prev = current->prev;
//        delete current;
//        size--;
//    }
//}
//void List:: deletebegin() {
//    if (Empty())
//    {
//        cout << "list is empty" << endl;
//    }
//    else {
//        Node* temp = head;
//        head = head->next;
//        if (head) head->prev = nullptr;
//        else tail = nullptr;
//        delete temp;
//        size--;
//    }
//}
//
//void List:: deleteend() {
//    if (Empty())
//    {
//        cout << "list is empty" << endl;
//    }
//    else {
//        Node* temp = tail;
//        tail = tail->prev;
//        if (tail) tail->next = nullptr;
//        else head = nullptr;
//        delete temp;
//        size--;
//    }
//}
//void List:: deleteall() {
//    if (Empty())
//    {
//        cout << "list is empty" << endl;
//    }
//    else {
//        while (!Empty())
//        {
//            deletebegin();
//        }
//    }
//}
//void List:: sort()
//{
//    for (Node* i = head; i != nullptr; i = i->next) {
//        for (Node* j = i->next; j != nullptr; j = j->next) {
//            if (i->field.number > j->field.number) {
//                swap(i->field, j->field);
//            }
//        }
//    }
//}
//void List:: print()
//{
//    Node* current = head;
//    if (current==nullptr)
//    {
//        cout << "list is empty" << endl;
//    }
//    else
//    {
//        do {
//            cout << current->field.number << " " << current->field.name << " " << current->field.day << endl;
//            current = current->next;
//        } while (current != nullptr);
//    }
//}
//void List:: WriteToFile(const string& filename)
//{
//    fstream in(filename);
//    if (!in.is_open())
//    {
//        cout << "error" << endl;
//    }
//    Node* current = head;
//    while (current != nullptr) {
//        in << current->field.number << " " << current->field.name << " " << current->field.day << endl;
//        current = current->next;
//    }
//    in.close();
//}
//void List:: ReadFromFile(const string& filename)
//{
//    ifstream out(filename);
//    if (!out.is_open())
//    {
//        cout << "error" << endl;
//    }
//   // deleteall();
//    double num;
//    string name;
//    int day;
//    while (out >> num >> name >> day)
//    {
//        addend(Flight(num, name, day));
//    }
//    out.close();
//}