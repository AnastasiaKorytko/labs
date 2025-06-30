//#include <iostream>
//#include <time.h>
//#include <algorithm>
//#include <stdexcept>
//using namespace std;
//class Ar2020
//{
//	int* M;
//	int count;
//public:
//	Ar2020() :count(5)
//	{
//		M = new int[count];
//		for (int i = 0; i < count; i++)
//		{
//			M[i] = 0;
//		}
//	}
//	Ar2020(const Ar2020& other)
//	{
//		count = other.count;
//		M = new int[count];
//		for (int i = 0; i < count; i++)
//		{
//			M[i] = other.M[i];
//		}
//	}
//	Ar2020(int count)
//	{
//		this->count = count;
//		M = new int[count];
//		for (int i = 0; i < count; i++)
//		{
//			M[i] = rand() % 10 + 1;
//		}
//	}
//	Ar2020(Ar2020&& moved) : M(moved.M), count(moved.count)
//	{
//		moved.M = nullptr;
//		moved.count = 0;
//	}
//	~Ar2020()
//	{
//		delete[]M;
//	}
//
//
//	Ar2020& operator=(const Ar2020& other) //перегрузка copy=
//	{
//		if (this == &other)
//		{
//			return *this;
//		}
//		delete[]M;
//		count = other.count;
//		M = new int[count];
//		for (int i = 0; i < count; i++)
//		{
//			M[i] = other.M[i];
//		}
//		return *this;
//	}
//
//	int& operator[] (const int index) //перегрузка
//	{
//		if (index < 0 or index >= count)
//		{
//			throw out_of_range("out of range");
//		}
//		return M[index];
//	}
//
//	friend ostream& operator<<(ostream& out, const Ar2020& Ar) //перегрузка <<
//	{
//		for (int i = 0; i < Ar.count; i++)
//		{
//			out << Ar.M[i] << " ";
//		}
//		return out;
//	}
//
//	friend istream& operator>>(istream& in, Ar2020& Ar) //перегрузка >>
//	{
//		for (int i = 0; i < Ar.count; i++)
//		{
//			in >> Ar.M[i];
//		}
//		return in;
//	}
//
//	friend Ar2020 operator+(const Ar2020& Ar1, const Ar2020& Ar2) //перегрузка бинарного + для поэлементного сложения
//	{
//		if (Ar1.count != Ar2.count)
//		{
//			throw invalid_argument("different dimensions");
//		}
//			Ar2020 res(Ar1.count);
//			for (int i = 0; i < Ar1.count; i++)
//			{
//				res.M[i] = Ar1.M[i] + Ar2.M[i];
//			}
//			return res;
//	}
//
//	Ar2020& operator/(const int a) //перегрузка / для поэлементного деления на число
//	{
//		for (int i = 0; i < count; i++)
//		{
//			M[i] /= a;
//		}
//		return *this;
//	}
//
//	Ar2020& operator*(const int a) //перегрузка * для поэлементного деления на число
//	{
//		for (int i = 0; i < count; i++)
//		{
//			M[i] *= a;
//		}
//		return *this;
//	}
//
//	friend Ar2020 operator*(const Ar2020& Ar1, const Ar2020& Ar2) //перегрузка бинарного * для поэлементного умножения
//	{
//		if (Ar1.count != Ar2.count)
//		{
//			throw invalid_argument("different dimensions");
//		}
//		Ar2020 res(Ar1.count);
//		for (int i = 0; i < Ar1.count; i++)
//		{
//			res.M[i] = Ar1.M[i] * Ar2.M[i];
//		}
//		return res;
//	}
//
//	int operator+() //перегрузка унарного + для суммы элементов
//	{
//		int s = 0;
//		for (int i = 0; i < count; i++)
//		{
//			s += M[i];
//		}
//		return s;
//	}
//
//	int Sum() //сумма элементов
//	{
//		int s = 0;
//		for (int i = 0; i < count; i++)
//		{
//			s += M[i];
//		}
//		int sr = s / count;
//		s = 0;
//		for (int i = 0; i < count; i++)
//		{
//			if (M[i] < sr)
//			{
//				s += M[i];
//			}
//		}return s;
//	}
//	int Sum1(int a) //сумма чётных элементов
//	{
//		int s = 0;
//		for (int i = 0; i < count; i++)
//		{
//			if (M[i] != a)
//			{
//				if (M[i] % 2 == 0)
//				{
//					s += M[i];
//				}
//			}
//			else break;
//		}
//		return s;
//	}
//	int GrowingFragments() //количество возрастающих фрагментов
//	{
//		int k = 0;
//		for (int i = 0; i < count; )
//		{
//			if (M[i + 1] > M[i])
//			{
//				while (M[i + 1] > M[i]) { i++; }
//				k++;
//			}
//			i++;
//		}
//		return k;
//	}
//	void MaxProduct() // максимальное произведение двух элементов
//	{
//		int max = 0, p1, p2;
//		for (int i = 0; i < count; i++)
//		{
//			for (int j = 0; j < count; j++)
//			{
//				if (M[i] * M[j] > max and i != j)
//				{
//					max = M[i] * M[j];
//					p1 = M[i];
//					p2 = M[j];
//				}
//			}
//		}
//		cout << p1 << " " << p2 << endl;
//	}
//	void TwoIndex() //индексы двух максимальных элементов
//	{
//		int max = INT_MIN, index1 = 0, index2 = 0;
//		for (int i = 0; i < count; i++)
//		{
//			if (M[i] > max)
//			{
//				max = M[i];
//				index2 = index1;
//				index1 = i;
//			}
//		}
//		cout << index1 << " " << index2;
//	}
//	int Number() //сколько раз повторяется самое частое число
//	{
//		sort(M, M + count);
//		int k, n = 0;
//		for (int i = 0; i < count; i++)
//		{
//			k = 1;
//			if (M[i] == M[i + 1])
//			{
//				while (M[i] == M[i + 1])
//				{
//					i++;
//					k++;
//				}
//				if (k > n)
//				{
//					n = k;
//				}
//				k = 0;
//			}
//
//		}
//
//		return n;
//	}
//
//	void MaxDifference() //элементы, разность которых максимальна
//	{
//		/*sort(M, M + count);
//		int d = M[count-1]-M[0];
//		return d;*/
//		int min = M[0], max = 0;
//		for (int i = 0; i < count; i++)
//		{
//			if (M[i] < min)
//			{
//				min = M[i];
//			}
//			if (M[i] > max)
//			{
//				max = M[i];
//			}
//		}
//		cout << "numbers with max difference " << min << " " << max << endl;
//	}
//
//	int MaxSum() //максимальная сумма двух элементов
//	{
//		sort(M, M + count);
//		int i = count - 2;
//		while (M[count - 1] == M[i])
//		{
//			i--;
//		}
//		int s = M[count - 1] + M[i];
//		return s;
//	}
//
//	Ar2020 ShiftLeft() //сдвиг влево
//	{
//		int temp = M[0];
//		for (int i = 1; i < count; i++)
//		{
//			M[i - 1] = M[i];
//		}
//		M[count - 1] = temp;
//		return *this;
//
//	}
//	int Progression() //проверка на арифметическую прогрессию
//	{
//		sort(M, M + count);
//		for (int i = 0; i < count; i++)
//		{
//			if ((M[i + 2] - M[i + 1]) != (M[i + 1] - M[i]))
//			{
//				return i + 1;
//			}
//		}
//	}
//	bool Transposition(Ar2020& Ar) //можно из одного массива перестановкой получить второй
//	{
//		sort(M, M + count);
//		sort(Ar.M, Ar.M + Ar.count);
//		for (int i = 0; i < count; i++)
//		{
//			if (M[i] != Ar.M[i])
//				return false;
//		}
//		return true;
//	}
//	void countOccurrences()
//	{
//		sort(M, M + count, [](int a, int b) {return a < b; }); //lambda!!!!!
//		for (int i = 0; i < count; i++)
//		{
//			cout << M[i] << " ";
//		}
//		cout << endl;
//		int i = 0, k;
//		while (i < count)
//		{
//			k = 1;
//			if (M[i] == M[i + 1])
//			{
//				while (M[i] == M[i + 1])
//				{
//					i++;
//					k++;
//				}
//			}
//			i++;
//			cout << k << " times" << endl;
//		}
//	}
//};
//int main()
//{
//	srand(time(NULL));
//	Ar2020 a; //default
//	Ar2020 a1;
//	cout << "transposition " << a.Transposition(a1) << endl;
//	Ar2020 b(5); //with parameter
//	cout << b << endl;
//	Ar2020 l(5);
//	cout << "l " << l << endl;
//	Ar2020 m(5);
//	cout << "m " << m << endl;
//	Ar2020 c(a);
//	Ar2020 d = move(b);
//	Ar2020 f = l + m;
//	cout << "l+m " << f << endl;
//	cout << f[1] << endl;
//	a = f;
//	cout << a << endl;
//	/*Ar2020 e;
//	cin >> e;*/
//	//cout << a.Sum() << endl;
//	//a.TwoIndex();
//	//cout << endl;
//	cout << a / 2 << endl;
//	cout << a * 2 << endl;
//	cout << "left shift a " << a.ShiftLeft() << endl;
//	//Ar2020 x(20);
//	//cout << x<<endl;
//	//cout << x.Sum1(5) << endl;
//	//a.MaxProduct();
//	cout << a.GrowingFragments() << endl;
//	int s = +a;
//	cout << "sum a " << s << endl;
//	a.MaxDifference();
//	int s1 = a.MaxSum();
//	cout << "max sum " << s1 << endl;
//
//	Ar2020 h(10);
//	Ar2020 g(10);
//	cout << "h " << h << endl;
//	cout << "repeating number " << h.Number() << endl;
//	cout << "progression " << h.Progression() << endl;
//	cout << "transposition " << h.Transposition(g) << endl;
//	h.countOccurrences();
//	return 0;
//}