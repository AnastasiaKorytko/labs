//#include <iostream>
//#include <fstream>
//#include <string>
//#include <stdexcept>
//
//using namespace std;
//
//struct Flight {
//    double flightNumber;
//    string name;
//    int dayOfWeek;
//
//    Flight(double num, const string& n, int day) : flightNumber(num), name(n), dayOfWeek(day) {}
//};
//
//class Node {
//public:
//    Flight data;
//    Node* prev;
//    Node* next;
//
//    Node(const Flight& flight) : data(flight), prev(nullptr), next(nullptr) {}
//};
//
//class DoublyLinkedList {
//private:
//    Node* head;
//    Node* tail;
//    size_t size;
//
//public:
//    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
//
//    ~DoublyLinkedList() {
//        clear();
//    }
//
//    void addToFront(const Flight& flight) {
//        Node* newNode = new Node(flight);
//        if (isEmpty()) {
//            head = tail = newNode;
//        }
//        else {
//            newNode->next = head;
//            head->prev = newNode;
//            head = newNode;
//        }
//        size++;
//    }
//
//    void addToEnd(const Flight& flight) {
//        Node* newNode = new Node(flight);
//        if (isEmpty()) {
//            head = tail = newNode;
//        }
//        else {
//            tail->next = newNode;
//            newNode->prev = tail;
//            tail = newNode;
//        }
//        size++;
//    }
//
//    void addAtIndex(size_t index, const Flight& flight) {
//        if (index > size) throw out_of_range("Index out of range");
//        if (index == 0) {
//            addToFront(flight);
//        }
//        else if (index == size) {
//            addToEnd(flight);
//        }
//        else {
//            Node* newNode = new Node(flight);
//            Node* current = head;
//            for (size_t i = 0; i < index; i++) {
//                current = current->next;
//            }
//            newNode->prev = current->prev;
//            newNode->next = current;
//            current->prev->next = newNode;
//            current->prev = newNode;
//            size++;
//        }
//    }
//
//    void removeFromFront() {
//        if (isEmpty()) throw runtime_error("List is empty");
//        Node* temp = head;
//        head = head->next;
//        if (head) head->prev = nullptr;
//        else tail = nullptr;
//        delete temp;
//        size--;
//    }
//
//    void removeFromEnd() {
//        if (isEmpty()) throw runtime_error("List is empty");
//        Node* temp = tail;
//        tail = tail->prev;
//        if (tail) tail->next = nullptr;
//        else head = nullptr;
//        delete temp;
//        size--;
//    }
//
//    void removeAtIndex(size_t index) {
//        if (index >= size) throw out_of_range("Index out of range");
//        if (index == 0) removeFromFront();
//        else if (index == size - 1) removeFromEnd();
//        else {
//            Node* current = head;
//            for (size_t i = 0; i < index; i++) {
//                current = current->next;
//            }
//            current->prev->next = current->next;
//            current->next->prev = current->prev;
//            delete current;
//            size--;
//        }
//    }
//
//    void clear() {
//        while (!isEmpty()) {
//            removeFromFront();
//        }
//    }
//
//    bool isEmpty() const {
//        return size == 0;
//    }
//
//    void sort() {
//        if (size < 2) return;
//
//        for (Node* i = head; i != nullptr; i = i->next) {
//            for (Node* j = i->next; j != nullptr; j = j->next) {
//                if (i->data.flightNumber > j->data.flightNumber) {
//                    swap(i->data, j->data);
//                }
//            }
//        }
//    }
//
//    void print() const {
//        Node* current = head;
//        while (current != nullptr) {
//            cout << "Flight Number: " << current->data.flightNumber
//                << ", Name: " << current->data.name
//                << ", Day of Week: " << current->data.dayOfWeek << endl;
//            current = current->next;
//        }
//    }
//
//    void saveToFile(const string& filename) const {
//        ofstream file(filename);
//        if (!file.is_open()) throw runtime_error("Could not open file");
//
//        Node* current = head;
//        while (current != nullptr) {
//            file << current->data.flightNumber << " "
//                << current->data.name << " "
//                << current->data.dayOfWeek << endl;
//            current = current->next;
//        }
//
//        file.close();
//    }
//
//    void loadFromFile(const string& filename) {
//        ifstream file(filename);
//        if (!file.is_open()) throw runtime_error("Could not open file");
//
//        clear(); // Clear existing list
//
//        double num;
//        string name;
//        int day;
//
//        while (file >> num >> name >> day) {
//            addToEnd(Flight(num, name, day));
//        }
//
//        file.close();
//    }
//};
//
//void displayMenu() {
//    cout << "Menu:" << endl;
//    cout << "1. Add flight to front" << endl;
//    cout << "2. Add flight to end" << endl;
//    cout << "3. Add flight at index" << endl;
//    cout << "4. Remove flight from front" << endl;
//    cout << "5. Remove flight from end" << endl;
//    cout << "6. Remove flight at index" << endl;
//    cout << "7. Clear all flights" << endl;
//    cout << "8. Sort flights" << endl;
//    cout << "9. Print flights" << endl;
//    cout << "10. Save flights to file" << endl;
//    cout << "11. Load flights from file" << endl;
//    cout << "0. Exit" << endl;
//}
//
//int main() {
//    DoublyLinkedList list;
//
//    while (true) {
//        displayMenu();
//
//        int choice;
//        cin >> choice;
//
//        try {
//            switch (choice) {
//            case 1: {
//                double num; string name; int day;
//                cout << "Enter flight number, name, and day of week: ";
//                cin >> num >> name >> day;
//                list.addToFront(Flight(num, name, day));
//                break;
//            }
//            case 2: {
//                double num; string name; int day;
//                cout << "Enter flight number, name, and day of week: ";
//                cin >> num >> name >> day;
//                list.addToEnd(Flight(num, name, day));
//                break;
//            }
//            case 3: {
//                size_t index; double num; string name; int day;
//                cout << "Enter index, flight number, name, and day of week: ";
//                cin >> index >> num >> name >> day;
//                list.addAtIndex(index, Flight(num, name, day));
//                break;
//            }
//            case 4:
//                list.removeFromFront();
//                break;
//            case 5:
//                list.removeFromEnd();
//                break;
//            case 6: {
//                size_t index;
//                cout << "Enter index: ";
//                cin >> index;
//                list.removeAtIndex(index);
//                break;
//            }
//            case 7:
//                list.clear();
//                break;
//            case 8:
//                list.sort();
//                break;
//            case 9:
//                list.print();
//                break;
//            case 10: {
//                /*string filename;
//                cout << "Enter filename: ";
//                cin >> filename;*/
//                list.saveToFile("fileout.txt");
//                break;
//            }
//            case 11: {
//                list.loadFromFile("filein.txt");
//                break;
//            }
//            case 0:
//                return 0;
//
//            default:
//                cout << "Invalid choice. Please try again." << endl;
//            }
//        }
//        catch (const exception& e) {
//            cerr << "Error: " << e.what() << endl;
//        }
//    }
//
//    return 0;
//}