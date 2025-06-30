#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include "Windows.h"

using namespace std;

struct Element2;
struct Element3;

struct Element1 {
public:
    char Name[50];
    char Addr[50];
    Element1() {
        Name[0] = '0';
        Addr[0] = '0';
    };
     Element1(const char* name, const char* addr)
     {
            strcpy(Name, name); 
            strcpy(Addr, addr); 
        }
    
    friend istream& operator>>(istream& is, Element1& elem) {
        is >> elem.Name >> elem.Addr;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Element1& elem) {
        os << elem.Name << " "<<elem.Addr << endl;
        return os;
    }

    Element1& operator=(const Element1& other) {
        if (this != &other) { 
            strcpy(Name, other.Name); 
            strcpy(Addr, other.Addr); 
        }
        return *this; 
    }
    template<class T>
    bool operator==(const T& other) const 
    {
        return (strcmp(Name, other.Name) == 0);
    }
    bool operator < (Element1& m2)
    {
        if (strcmp(Name, m2.Name) > 0)
            return true;
        else return false;
    }
    };

    struct Element2
    {
        char Name[50];
        int  data;
        Element2() {
            Name[0] = '0';
            data = 0;
        };
        Element2(const char* name, int data)
        {
            strcpy(Name, name);
            this->data = data;
        }
        friend istream& operator>>(istream& is, Element2& elem) {
            is >> elem.Name >> elem.data;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Element2& elem) {
            os <<  elem.Name << " " << elem.data << endl;
            return os;
        }

        Element2& operator=(const Element2& other) {
            if (this != &other) {
                strcpy_s(Name, other.Name);
                data = other.data;
            }
            return *this;
        }

        template<class T>
        bool operator==(const T& other) const
        {
            return (strcmp(Name, other.Name) == 0);
        }
        bool operator>(const Element2& other) const {
            return this->data > other.data; 
        }
        /*template<class T>*/
        bool operator>(const int d) const {
            return this->data > d;
        }

    };

    struct Element3
    {
        char Name[50];
        char Addr[50];
        double Price;
        Element3() {
            Name[0] = '0';
            Addr[0] = '0';
            Price = 0;
        };
        Element3(const char* name, const char* addr, double price)
        {
            strcpy(Name, name);
            strcpy(Addr, addr);
            this->Price = price;
        }
        friend istream& operator>>(istream& is, Element3& elem) {
            is >> elem.Name >> elem.Addr >> elem.Price;
            return is;
        }

        friend ostream& operator<<(ostream& os, const Element3& elem) {
            os << elem.Name << " " << elem.Addr << " " << elem.Price << endl;
            return os;
        }
        Element3& operator=(const Element3& other) {
            if (this != &other) {
                strcpy(Name, other.Name);
                strcpy(Addr, other.Addr);
                Price = other.Price;
            }
            return *this;
        }
        Element3& operator=( Element1& other) {
            if (this->Name!=other.Name || this->Addr!= other.Addr) {
                strcpy(Name, other.Name);
                strcpy(Addr, other.Addr);
                Price = 100;
            }
            return *this;
        }
        template<class T>
        bool operator==(const T& other) const 
        {
            return (strcmp(Name, other.Name) == 0);
        }
        bool operator < (Element3& m2)
        {
            if (strcmp(Name, m2.Name) > 0)
                return true;
            else return false;
        }
    };

    template <typename T>
    class MASSIV
    {
    private:
        int count;
        T* data;
    public:
        MASSIV() : count(0), data(nullptr) {}
        MASSIV(int size) : count(size) 
        {
            data = new T[count];
        }

        ~MASSIV()
        {
            delete (T*)data;
        }

        int GetCount()
        {
            return count;

        }

        void SetCount(int k)
        {
            count = k;
        }

       /* void Search(T k)
        {
            for (int i = 0; i < n, i++)

                if (M[i] == k)
                {
                    cout << M[i] << endl;
                }
        }*/

        void WriteData(string s)
        {
            fstream out;
            out.open(s, ofstream::out | ofstream::binary); if (!out.is_open())
            {
                cout << "не удалось открыть файл" << endl;

            }
            else
            {
                int i = 0;
                int k = 0;
                out.seekp(k, ios::end);
                while (i < count)
                {
                    out.write((char*)&data[i], sizeof(T));
                    i++;
                }
                out.close();
            }
        }
        void WriteData1(string s)
        {
            fstream out;
            out.open(s, ofstream::out | ofstream::binary); if (!out.is_open())
            {
                cout << "не удалось открыть файл" << endl;

            }
            else
            {
                cout << "какой элемент записываем" << endl;
                int k;
                cin >> k;
                out.write((char*)&data[k], sizeof(T));
               
            }
            out.close();
        }

        void WriteTextData(string s)
        {
            fstream out;
            out.open(s, ofstream::out);
            if (!out.is_open())
            {
                cout << "не удалось открыть файл" << endl;
            }
            else
            {
                int i = 0;

                while (i < count)
                {
                    out << data[i];
                    i++;
                }
                out.close();
            }
        }

        
        void ReadData(string s)
        {
            fstream in;
            in.open(s, ofstream::in | ofstream::binary);
            if (!in.is_open())
            {
                cout << "не удалось открыть файл" << endl;
            }
            else {
                cout << "чтение из двоичного" << endl;
                /*cout << "что читаем из двоичного (начало и конец)" << endl;
                int begin, end;
                cin >> begin >> end;*/
                for (int i = 0; i < count; i++)
                {
                    in.read((char*)&data[i], sizeof(T));
                    cout << data[i];
                }
                cout << "какой элемент читаем" << endl;
                int k;
                cin >> k;
                in.read((char*)&data[k], sizeof(T));
                cout << data[k - 1];

                in.close();
            }
        }
        

        void ReadTextData(string s)
        {
            fstream in;
            in.open(s, ofstream::in);
            if (!in.is_open())
            {
                cout << "не удалось открыть файл" << endl;

            }
            else
            {
                data = new T[100];
                int i = 0;

                while (!in.eof())
                {
                    in >> data[i];
                    i++;
                }
                count = i - 1;
                in.close();
            }
        }

        friend ostream& operator<< (ostream& out, MASSIV& m)
        {
            out << "MASSIV :" << endl;
            for (int j = 0; j < m.GetCount(); j++)
                out << m[j]<<endl;
            return out;
        }

        friend istream& operator>> (istream& in, MASSIV& m)
        {
            cout << "ENTER MASSIV : " << endl;
            for (int j = 0; j < sizeof(m); j++)
                in >> m[j];
            return in;
        }

        T& operator[] (int m)
        {
            return data[m];
        }
        template <class T>
        MASSIV& operator=(const MASSIV& other) {
            if (this != &other) { 
                delete[] data; 
                count = other.count; 
                data = new T[count]; 

                for (int i = 0; i < count; ++i) {
                    data[i] = other.data[i]; 
                }
            }
            return *this; 
        }

        template<class T2>
        MASSIV operator = (MASSIV <T2>& m)
        {
            count = m.GetCount();
            if (this->count != count && this->data != m.data)
            {
                *this = m;
            }
            return *this;

        }
        void Sort()
        {
            T temp; 

            
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (data[j] > data[j + 1]) {
                        temp = data[j];
                        data[j] = data[j + 1];
                        data[j + 1] = temp;
                    }
                }
            }
            for (int i = 0; i < count; i++)
            {
                cout << data[i];
            }
        }
        /*template<class T>*/
        void Searchdata(int d)
        {
            for (int i = 0; i < count; i++)
            {
                if (data[i] > d)
                {
                    cout << data[i];
                }
            }
        }
        template<class T1, class T2>
        void SUBTRACTION(MASSIV<T1>& x, MASSIV<T2>& y)
        {
            cout << endl << "SUBTRACTION " << endl << endl;
            int k = 0;
            for (int i = 0; i < x.GetCount(); i++) {
                bool found = false;

                for (int j = 0; j < y.GetCount(); j++) {
                    if (x[i] == y[j]) {
                        found = true;
                        break;
                    }
                }


                if (!found)
                {
                    data[k] = x[i];
                    k++;
                }
            }
            count = k;
           

        }
    };
    
    int main()
    {
        setlocale(LC_ALL, "RUS");
        MASSIV <Element1> M(3);
        Element1 m1("st1", "123");
        Element1 m2("st2", "124");
        Element1 m3("st3", "125");
        M[0] = m1;
        M[1] = m2;
        M[2] = m3;
       
        M.WriteTextData("textElement1.txt");
        SetConsoleCP(1251);
        M.WriteData("Element1.txt");
       /* M.WriteData1("Element1.txt");*/
        M.ReadData("Element1.txt");
        M.ReadTextData("textElement1.txt");
        cout << M;
        cout << endl;
       
        MASSIV <Element2> K(3);
        Element2 k1("st1", 5);
        Element2 k2("st4", 12);
        Element2 k3("st5", 7);
        K[0] = k1;
        K[1] = k2;
        K[2] = k3;
       
        K.WriteTextData("textElement2.txt");
        SetConsoleCP(1251);
        K.WriteData("Element2.txt");
        K.ReadData("Element2.txt");
        SetConsoleCP(866);
        K.ReadTextData("textElement2.txt");
        cout << K;
        cout << endl << "сортировка массива Element2 по полю data " << endl;
        K.Sort();
        cout << endl;
        int d;
        cout << "введите дату" << endl;
        cin >> d;
        cout << "студенты, вернувшие книги после даты d " << endl;
        K.Searchdata(d);
        cout << endl;
        MASSIV <Element3> R(3);
        R.SUBTRACTION(M, K);
        cout << R;
        MASSIV <int>L(3);
        int l1 = 1;
        int l2 = 5;
        int l3 = 3;
        L[0] = l1;
        L[1] = l2;
        L[2] = l3;
        cout<<"массив инта" << endl;
        cout << L;
        L.WriteTextData("Int.txt");
        cout << "сортировка инта " << endl; ;
        L.Sort();
        int n;
        cout <<endl<< "введите число для поиска";
        cout << endl;
        cin >> n;
        cout << "поиск по инту " << endl;
        L.Searchdata(n);
        cout << endl;
        MASSIV<int>N(3);
        int n1 = 1;
        int n2 = 4;
        int n3 = 3;
        N[0] = n1;
        N[1] = n2;
        N[2] = n3;
        cout << "второй массив инта" << endl;
        cout << N;
        MASSIV<int>F(3);
        cout << "разность L и N" << endl;
        F.SUBTRACTION(L, N);
        cout << F;
        return 0;
    }


