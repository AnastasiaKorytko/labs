//#include <iostream>
//#include <string>
//#pragma once
//using namespace std;
//class Processor
//{
//public:
//	int power;
//public:
//	Processor() {};
//	Processor(int a)
//	{
//		power = a;
//	};
//	~Processor() {};
//};
//
//class Computer
//
//{
//protected:
//	static int count;
//	const int id;
//public:
//	Computer(int id) : id(id)
//	{
//		count++;
//	}
//
//	virtual ~Computer() 
//	{
//		count--;
//	}
//	Computer();
//	static int Getсount() 
//	{
//		return count;
//	}
//	virtual void Information() = 0;
//	
//}; 
//int Computer::count = 0;
//
//class Desktop: public Computer
//{
//protected:
//	string mark;
//	int price;
//	Processor pr;
//public:
//	Desktop(int id, string m, int p, int power): Computer(id), pr(power)
//	{
//		mark = m;
//		price = p;
//		
//	};
//	void Information() override
//	{
//		cout<< "настольный компьютер: " <<endl<< "id " << id << endl << "мощность  " << this->pr.power << endl << "марка " << this->mark << endl << "цена " << this->price << endl;
//	}
//	~Desktop() {};
//};
//class Monitor: public Computer
//{
//protected:
//	string mark;
//	int price;
//	Processor pr;
//	int monsize;
//public:
//	Monitor(int id, int mon, string m, int p, int power): Computer (id), pr(power)
//	{
//		monsize = mon;
//		mark = m;
//		price = p;
//	}
//	void Information() override
//	{
//		cout << "компьютер с монитором: " << endl << "id " << id << endl << "мощность " << this->pr.power << endl << "марка " << this->mark << endl << "цена  " << this->price << endl << "диагональ монитора " << this->monsize << endl;
//	}
//	~Monitor() {};
//	
//};
//int main()
//{
//	setlocale(LC_ALL, "ru");
//	int id1, id2, id3, p1, p2, p3, pow1, pow2, pow3, s1, s2;
//	string mark1, mark2, mark3;
//	cout << "введите id, марку, цену и мощность первого компьютера " << endl;
//	cin >> id1 >> mark1 >> p1 >> pow1;
//	Desktop d(id1, mark1, p1, pow1);
//	d.Information();
//	cout << "Всего компьютеров " << Computer::Getсount() << endl;
//	cout << "введите id, диагональ монитора, марку, цену и мощность второго компьютера " << endl;
//	cin >> id2>>s1 >> mark2 >> p2 >> pow2;
//	Monitor m1(id2, s1 , mark2, p2, pow2);
//	m1.Information();
//	cout << "введите id, диагональ монитора, марку, цену и мощность третьего компьютера " << endl;
//	cin >> id3 >> s2 >> mark3 >> p3 >> pow3;
//	Monitor m2(id3, s2, mark3, p3, pow3);
//	m2.Information();
//	cout << endl;
//	cout << "Всего компьютеров " << Computer::Getсount()<< endl;
//	
//	
//}
//
//
//
