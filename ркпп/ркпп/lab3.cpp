//#include <iostream>
//#include <regex>
//#include <string>
//#include <fstream>
//using namespace std;
//int main() 
//{
//    setlocale(LC_ALL, "RUS");
//    regex rgx1(R"(\+375(44|29|33|25)[0-9]{7})");
//    regex rgx2(R"(375(44|29|33|25)[0-9]{7})");
//    regex rgx3(R"(80(17|16|15|23|22)[0-9]{7})");
//    string st;
//    string* str = new string[100];
//    fstream fin, fout;
//    int i = 0;
//    fin.open("input.txt");
//    fout.open("output.txt");
//    if (!fin.is_open())
//    {
//        cout << "error" << endl;
//    }
//    else
//    {
//            while (!fin.eof())
//            {
//                st = "";
//                getline(fin, st);
//                str[i] = st;
//                i++;
//                cout << st << " ";
//                if (regex_match(st, rgx1) || regex_match(st, rgx2) || regex_match(st, rgx3))
//                {
//                    cout << "номер телефона" << endl;
//                }
//                else
//                {
//                    cout << "не номер телефона" << endl;
//                }
//            }
//    }
//    fin.close();
//    if (!fout.is_open())
//    {
//        cout << "error" << endl;
//    }
//    else
//    {
//        if (!fout.eof())
//        {
//            for (int j = 0; j < i; j++)
//            {
//                fout << str[j] << " ";
//                if (regex_match(str[j], rgx1) || regex_match(str[j], rgx2) || regex_match(str[j], rgx3))
//                {
//                    fout << "номер телефона" << endl;
//                }
//                else
//                {
//                    fout << "не номер телефона" << endl;
//                }
//            }
//        }
//    }
//    fout.close();
//    return 0;
//}