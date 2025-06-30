//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include <conio.h>
//#include <iostream>
//#include <string>
//#include <stdexcept>
//#include <fstream>
//using namespace std;
//struct Flight {
//    double number;
//    string name;
//    int day;
//    Flight(double num, const string& n, int day) : number(num), name(n), day(day) {}
//};
//
//
//struct Node {
//public:
//    Flight field;
//    Node* prev;
//    Node* next;
//    Node(const Flight& flight) : field(flight), prev(nullptr), next(nullptr) {}
//};
//
//struct List {
//private:
//    Node* head;
//    Node* tail;
//    size_t size;
//
//public:
//    List() : head(nullptr), tail(nullptr), size(0) {}
//    ~List()
//    {
//        deleteall();
//    }
//
//
//
//    // initialization
//    void init(const Flight& a)
//    {
//        struct Node* newNode = new Node(a);
//        head = tail = newNode;
//        size++;
//
//    }
//    void addindex(int index, const Flight& flight)
//    {
//        if (index > size) 
//        {
//            cout << "error" << endl;
//        }
//             if (index == 0) 
//             {
//                    addbegin(flight);
//             }
//                else if (index == size) 
//                {
//                    addend(flight);
//                }
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
//    bool Empty() const 
//    {
//        return size == 0;
//    }
//    void addbegin(const Flight& flight) 
//    {
//        Node* newNode = new Node(flight);
//            newNode->next = head;
//            head->prev = newNode;
//            head = newNode;
//            size++;
//    }
//    void addend(const Flight& flight) 
//    {
//        Node* newNode = new Node(flight);
//        tail->next = newNode;
//        newNode->prev = tail;
//        tail = newNode;
//        size++;
//    }
//    void deleteindex(size_t index) 
//    {
//        if (index > size)
//        {
//            cout << "error" << endl;
//        }
//        if (index == 0)
//        {
//            deletebegin();
//        }
//        else if (index == size)
//        {
//            deleteend();
//        }
//          Node* current = head;
//              for (size_t i = 0; i < index; i++) 
//              {
//                    current = current->next;
//              }
//              current->prev->next = current->next;
//              current->next->prev = current->prev;
//              delete current;
//              size--;  
//    }
//    void deletebegin() {
//        if (Empty()) 
//            cout<<"list is empty";
//        Node* temp = head;
//        head = head->next;
//        if (head) head->prev = nullptr;
//        else tail = nullptr;
//        delete temp;
//        size--;
//    }
//
//    void deleteend() {
//        if (Empty())
//        cout << "list is empty";
//        Node* temp = tail;
//        tail = tail->prev;
//        if (tail) tail->next = nullptr;
//        else head = nullptr;
//        delete temp;
//        size--;
//    }
//    void deleteall() {
//        while (!Empty()) 
//        {
//            deletebegin();
//        }
//    }
//    void sort() 
//    {
//        for (Node* i = head; i != nullptr; i = i->next) {
//            for (Node* j = i->next; j != nullptr; j = j->next) {
//                if (i->field.number > j->field.number) {
//                    swap(i->field, j->field);
//                }
//            }
//        }
//    }
//    void print() 
//    {
//        Node* current = head;
//        while (current != nullptr) {
//            cout <<current->field.number << " " << current->field.name << " " << current->field.day << endl;
//            current = current->next;
//        }
//    }
//    void WriteToFile(const string& filename) 
//    {
//        fstream in (filename);
//        if (!in.is_open())
//        {
//            cout << "error" << endl;
//        }
//        Node* current = head;
//        while (current != nullptr) {
//            in << current->field.number << " " << current->field.name << " "<< current->field.day << endl;
//            current = current->next;
//        }
//        in.close();
//    }
//    void ReadFromFile(const string& filename) 
//    {
//        ifstream out(filename);
//        if (!out.is_open())
//        {
//            cout << "error" << endl;
//        }
//        deleteall(); 
//        double num;
//        string name;
//        int day;
//        while (out>> num >> name >> day)
//        {
//            addend(Flight(num, name, day));
//        }
//        out.close();
//    }
//};
//void Menu() {
//    cout << "Menu:" << endl;
//    cout << "1. Initialize" << endl;
//    cout << "2. Add to the beginning" << endl;
//    cout << "3. Add to the end" << endl;
//    cout << "4. Add by the index" << endl;
//    cout << "5. Delete from the beginning" << endl;
//    cout << "6. Delete from the end" << endl;
//    cout << "7. Delete by the index" << endl;
//    cout << "8. Delete all" << endl;
//    cout << "9. Sort" << endl;
//    cout << "10. Print" << endl;
//    cout << "11. Write to the file" << endl;
//    cout << "12. Read from the file" << endl;
//    cout << "0. Exit" << endl;
//}
//int main()
//{
//    List L;
//    while (true) {
//        Menu();
//        int a;
//        cin >> a;
//        try {
//            switch (a) {
//            case 1: 
//            {
//                double num; string name; int day;
//                cout << "Enter number, name, day ";
//                cin >> num >> name >> day;
//                L.init(Flight(num, name, day));
//                break;
//            }
//            case 2: {
//                double num; string name; int day;
//                cout << "Enter number, name, day ";
//                cin >> num >> name >> day;
//                L.addbegin(Flight(num, name, day));
//                break;
//            }
//            case 3: {
//                double num; string name; int day;
//                cout << "Enter number, name, day ";
//                cin >> num >> name >> day;
//                L.addend(Flight(num, name, day));
//                break;
//            }
//            case 4: {
//                int ind; double num; string name; int day;
//                cout << "Enter index, number, name, day ";
//                cin >> ind >> num >> name >> day;
//                L.addindex(ind, Flight(num, name, day));
//                break;
//            }
//            case 5:
//                L.deletebegin();
//                break;
//            case 6:
//                L.deleteend();
//                break;
//            case 7: {
//                size_t ind;
//                cout << "Enter index: ";
//                cin >> ind;
//                L.deleteindex(ind);
//                break;
//            }
//            case 8:
//                L.deleteall();
//                break;
//            case 9:
//                L.sort();
//                break;
//            case 10:
//                L.print();
//                break;
//            case 11: {
//                L.WriteToFile("fileout.txt");
//                break;
//            }
//            case 12: {
//                L.ReadFromFile("filein.txt");
//                break;
//            }
//            case 0:
//                return 0;
//
//            default:
//                cout << "wrong choice " << endl;
//            }
//        }
//        catch (const exception& e) {
//            cerr << "Error: " << e.what() << endl;
//        }
//    }
//
//    return 0;
//}