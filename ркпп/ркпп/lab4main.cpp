//#pragma once
//#include "header.h"
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