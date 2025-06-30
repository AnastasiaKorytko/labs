//#pragma once
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
//    List();
//    ~List();
//    void init(const Flight& a);
//    void addindex(int index, const Flight& flight);
//    bool Empty() const;
//    void addbegin(const Flight& flight);
//    void addend(const Flight& flight);
//    void deleteindex(size_t index);
//    void deletebegin();
//    void deleteend();
//    void deleteall();
//    void sort();
//    void print();
//    void WriteToFile(const string& filename);
//    void ReadFromFile(const string& filename);
//};
//
//
//
//
//    