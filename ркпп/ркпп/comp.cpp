#include <fstream>
#include <iostream>
#include <algorithm>
struct Fruit_Form {
	std::string name;
	std::string section;
	Fruit_Form() : name(""), section("") {}
	Fruit_Form(const std::string& n_, const std::string& s_) : name(n_), section(s_) {}
	bool operator<(const Fruit_Form& to_compare) {
		return (name < to_compare.name);
	}
	bool operator==(const Fruit_Form& to_compare) {
		return (name == to_compare.name);
	}
	friend std::ostream& operator<< (std::ostream& os, const Fruit_Form& arr);
	friend std::istream& operator>> (std::istream& is, Fruit_Form& arr);
};
std::ostream& operator<< (std::ostream& os, const Fruit_Form& arr) {
	os << arr.name << "\t\t\t\t" << arr.section;
	return os;
}
std::istream& operator>> (std::istream& is, Fruit_Form& arr) {
	is >> arr.name;
	is >> arr.section;
	return is;
}

struct Bag_Form {
	std::string name;
	int count;
	std::string section;
	Bag_Form() : name(""), count(0), section("") {}
	Bag_Form(const std::string& n_, const int& c_, const std::string& s_) : name(n_), count(c_), section(s_) {}
	bool operator<(const Bag_Form& to_compare) {
		return (name < to_compare.name);
	}
	bool operator==(const Bag_Form& to_compare) {
		return (name == to_compare.name);
	}
	friend std::ostream& operator<< (std::ostream& os, const Bag_Form& arr);
	friend std::istream& operator>> (std::istream& is, Bag_Form& arr);
};
std::ostream& operator<< (std::ostream& os, const Bag_Form& arr) {
	os << arr.name << "\t\t\t\t" << arr.count << "\t\t\t" << arr.section;
	return os;
}
std::istream& operator>> (std::istream& is, Bag_Form& arr) {
	is >> arr.name;
	is >> arr.count;
	is >> arr.section;
	return is;
}

class ABS_COMP
{
public:
	virtual void GetData(std::ifstream&) = 0;
	virtual void PutData(std::ofstream&) = 0;
	virtual ABS_COMP* Merge(ABS_COMP*, ABS_COMP*) = 0;
	virtual void Sort() = 0;
	virtual void FindInMass(const std::string& name) = 0;
};

class Fruit : public ABS_COMP {
public:
	Fruit() : size_(0), arr(nullptr) {}

	Fruit(const int& s) : size_(s), arr(new Fruit_Form[size_]) {}

	Fruit(const Fruit& to_copy) {
		size_ = to_copy.size_;
		for (int i = 0; i < size_; ++i)
			arr[i] = to_copy.arr[i];
	}
	Fruit& operator=(const Fruit& to_copy) {
		if (&to_copy == this)
			return *this;
		else {
			delete[]arr;
			arr = new Fruit_Form[to_copy.size_];
			size_ = to_copy.size_;
			for (int i = 0; i < size_; ++i)
				arr[i] = to_copy.arr[i];
			return *this;
		}
	}
	void GetData(std::ifstream& file) override {
		char* str = new char[1024];
		int i = 0;
		while (!file.eof())
		{
			file.getline(str, 1024, '\n');
			i++;
		}
		delete[] arr;
		size_ = i / 2;
		arr = new Fruit_Form[size_];
		file.seekg(0);
		i = 0;
		while (!file.eof())
		{
			file >> arr[i];
			i++;
		}
	}
	void PutData(std::ofstream& file) override {
		file << "Наименование товара\t\tСекция\n";
		for (size_t i = 0; i < size_; i++)
		{
			file << arr[i] << "\n";
		}
	}
	bool operator< (const Fruit& to_compare) {
		return (arr->name < to_compare.arr->name);
	}
	ABS_COMP* Merge(ABS_COMP* a_1, ABS_COMP* a_2) override {
		Fruit* mass_1 = (Fruit*)a_1;
		Fruit* mass_2 = (Fruit*)a_2;
		delete[] arr;
		size_ = mass_2->GetCount();
		if (mass_1->GetCount() <= mass_2->GetCount())
			size_ = mass_1->GetCount();
		arr = new Fruit_Form[size_];
		int i = 0, j = 0, k = 0;
		mass_1->Sort();
		mass_2->Sort();
		while (i < mass_1->GetCount() && j < mass_2->GetCount()) {
			if (mass_1->arr[i] < mass_2->arr[j])
				i++;
			else if (mass_2->arr[j] < mass_1->arr[i])
				j++;
			else {
				arr[k].name = mass_2->arr[j].name;
				arr[k].section = mass_2->arr[j].section;
				i++;
				j++;
				k++;
			}
		}
		size_ = k;
		return this;
	}
	int GetCount() {
		return size_;
	}
	Fruit_Form& operator[](const int& b) {
		return arr[b];
	}
	void Sort() override {
		QSort(arr, 0, size_ - 1);
	}
	void QSort(Fruit_Form* M, int left, int right) {
		int mid = (left + right) / 2;
		Fruit_Form x = M[mid];
		int i = left, j = right;
		do {
			while (M[i].name < x.name) i++;
			while (x.name < M[j].name) j--;
			if (i <= j) {
				std::swap(M[i], M[j]);
				i++;
				j--;
			}
		} while (i < j);
		if (left < j) QSort(M, left, j);
		if (i < right) QSort(M, i, right);
	}
	void FindInMass(const std::string& name) {
		bool flag = false;
		for (size_t i = 0; i < GetCount(); i++)
		{
			if (name == arr[i].name) {
				std::cout << arr[i];
				flag = true;
			}
		}
		if (!flag) std::cout << "Нет такого значения.";
	}
	virtual ~Fruit() {
		delete[] arr;
	}
private:
	Fruit_Form* arr;
	int size_;
};

class Bag : public ABS_COMP {
public:
	Bag() : size_(0), arr(nullptr) {}

	Bag(const int& s) : size_(s), arr(new Bag_Form[size_]) {}

	Bag(const Bag& to_copy) {
		size_ = to_copy.size_;
		for (int i = 0; i < size_; ++i)
			arr[i] = to_copy.arr[i];
	}
	Bag& operator=(const Bag& to_copy) {
		if (&to_copy == this)
			return *this;
		else {
			delete[]arr;
			arr = new Bag_Form[to_copy.size_];
			size_ = to_copy.size_;
			for (int i = 0; i < size_; ++i)
				arr[i] = to_copy.arr[i];
			return *this;
		}
	}
	void GetData(std::ifstream& file) override {
		char* str = new char[1024];
		int i = 0;
		while (!file.eof())
		{
			file.getline(str, 1024, '\n');
			i++;
		}
		delete[] arr;
		size_ = i / 3;
		arr = new Bag_Form[size_];
		file.seekg(0);
		i = 0;
		while (!file.eof())
		{
			file >> arr[i];
			i++;
		}
	}
	void PutData(std::ofstream& file) override {
		file << "Наименование товара\t\tКоличество\tСекция\n";
		for (size_t i = 0; i < size_; i++)
		{
			file << arr[i] << "\n";
		}
	}
	bool operator< (const Bag& to_compare) {
		return (arr->name < to_compare.arr->name);
	}
	ABS_COMP* Merge(ABS_COMP* a_1, ABS_COMP* a_2) override {
		Bag* mass_1 = (Bag*)a_1;
		Bag* mass_2 = (Bag*)a_2;
		delete[] arr;
		size_ = mass_2->GetCount();
		if (mass_1->GetCount() <= mass_2->GetCount())
			size_ = mass_1->GetCount();
		arr = new Bag_Form[size_];
		int i = 0, j = 0, k = 0;
		mass_1->Sort();
		mass_2->Sort();
		while (i < mass_1->GetCount() && j < mass_2->GetCount()) {
			if (mass_1->arr[i] < mass_2->arr[j])
				i++;
			else if (mass_2->arr[j] < mass_1->arr[i])
				j++;
			else {
				arr[k].name = mass_2->arr[j].name;
				arr[k].section = mass_2->arr[j].section;
				arr[k].count = mass_2->arr[j].count;
				i++;
				j++;
				k++;
			}
		}
		size_ = k;
		return this;
	}
	void FindInMass(const std::string& name) {
		bool flag = false;
		for (size_t i = 0; i < GetCount(); i++)
		{
			if (name == arr[i].name) {
				std::cout << arr[i];
				flag = true;
			}
		}
		if (!flag) std::cout << "Нет такого значения.";
	}
	int GetCount() {
		return size_;
	}
	Bag_Form& operator[](const int& b) {
		return arr[b];
	}
	void Sort() override {
		QSort(arr, 0, size_ - 1);
	}
	void QSort(Bag_Form* M, int left, int right) {
		int mid = (left + right) / 2;
		Bag_Form x = M[mid];
		int i = left, j = right;
		do {
			while (M[i].name < x.name) i++;
			while (x.name < M[j].name) j--;
			if (i <= j) {
				std::swap(M[i], M[j]);
				i++;
				j--;
			}
		} while (i < j);
		if (left < j) QSort(M, left, j);
		if (i < right) QSort(M, i, right);
	}
	virtual ~Bag() {
		delete[] arr;
	}
private:
	Bag_Form* arr;
	int size_;
};



int main() {
	setlocale(LC_ALL, "rus");
	ABS_COMP* A1, * A2, * A3, * A4;
	std::ifstream in1("Ob1.txt");
	std::ifstream in2("Ob2.txt");
	std::ofstream out1("Ob.txt", std::ios::app);
	Fruit M1, M2, M3;
	Bag K1, K2, K3;
	/*A1 = &M1;
	A1->GetData(in1);
	A2 = &M2;
	A2->GetData(in2);
	A3 = &M3;
	A3->Merge(A1, A2);
	A1->PutData(out1);
	A2->PutData(out1);
	A3->PutData(out1);*/
	std::ifstream in3("TOb1.txt");
	std::ifstream in4("TOb2.txt");
	std::ofstream out2("TOb.txt");
	A1 = &K1;
	A1->GetData(in3);
	A2 = &K2;
	A2->GetData(in4);
	A3 = &K3;
	A3->Merge(A1, A2);
	A3->PutData(out2);
	A1->FindInMass("Apple");
	return 0;
}