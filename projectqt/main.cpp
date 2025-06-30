#include <QCoreApplication>
#include <QList>
#include <QDebug>
#include <QMap>
#include <QMultiMap>
#include <algorithm>
#include <numeric>

void printList(const QList<int>& lst)
{
    for (const auto& item : lst)
        qDebug() << item << " ";
}

void printStdList(const std::list<int>& lst)
{
    for (const auto& item : lst)
        qDebug() << item << " ";
}

std::list<int> qtostd(const QList<int>& qlist)
{
    return std::list<int>(qlist.begin(), qlist.end());
}

QList<int> stdtoq(const std::list<int>& stdlist)
{
    return QList<int>(stdlist.begin(), stdlist.end());
}

QList<int>::iterator qFind(QList<int>::iterator begin, QList<int>::iterator end, const int& value)
{
    for (auto i = begin;  i < end; ++i)
    { if (*i == value) return i; }
    return end;
}

uint qcountTrailingZeroBits(quint64 v)
{
    uint count = 0;
    while(v % 2 == 0)
    {
        v /= 2;
        count++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "RUS");
    QMultiMap <int, int> myMap;
    srand(time(NULL));

    for (int i = 0; i < 10; ++i)
    {
        int key =  rand() % 10 + 1;
        int value = rand() % 100 + 1;
        myMap.insert(key, value);
    }

    qDebug() << "Содержимое QMultiMap:";
    for (auto it = myMap.begin(); it != myMap.end(); ++it)
    { qDebug() << "Ключ:" << it.key() << "Значение:" << it.value(); }

    QList<int> myList;
    for (int i = 0; i < 10; ++i) { myList.append(rand() % 10 + 1); }

    std::list<int> stdList = qtostd(myList);
    qDebug() << "Содержимое преобразованного std::list:";
    printStdList(stdList);

    QList<int> convertedList = stdtoq(stdList);
    qDebug() << "Содержимое преобразованного QList:";
    printList(convertedList);

    QList<int>::iterator i1  = qFind(myList.begin(),myList.end(), 5);
    qDebug() << "найденный элемент"<< *i1;
    uint k = 32;
    qDebug() <<"количество нулей до первой 1 начиная от младшего бита"<< qcountTrailingZeroBits(k);

    int choice;
    do
    {
        qDebug() << "Текущее состояние списка:";
        printList(myList);
        qDebug() << "Меню:";
        qDebug() << "1. Добавить несколько элементов в заданную позицию";
        qDebug() << "2. Удалить элемент равный заданному";
        qDebug() << "3. Переместить часть элементов (диапазон) в заданную позицию";
        qDebug() << "4. Удалить элемент по значению";
        qDebug() << "5. Частично отсортировать список";
        qDebug() << "6. Вычислить сумму квадратов элементов";
        qDebug() << "7. Выход из программы";
        qDebug() << "Выберите опцию:";

        QTextStream in(stdin);
        in>>choice;

        switch (choice)
        {
        case 1:
        {
            int pos, count;
            qDebug() << "Введите позицию для вставки:";
            in>>pos;
            qDebug() << "Введите количество элементов для добавления:";
            in>>count;

            QList<int> newElements;
            for (int i = 0; i < count; ++i)
            {
                newElements.append(rand() % 100 + 1);
            }
            for (int i = pos; i < pos+count; ++i)
            {
                myList.insert(i-1,newElements[i-pos]);
            }
            break;
        }
        case 2:
        {
            int x;
            qDebug() << "Введите значение для удаления:";
            in>>x;
            myList.removeAll(x);
            break;
        }
        case 3:
        {
            int startPos, endPos, newPos;
            qDebug() << "Введите стартовую позицию:";
            in>>startPos;
            qDebug() << "Введите конечную позицию:";
            in>>endPos;
            qDebug() << "Введите новую позицию:";
            in>>newPos;

            QList<int> elementsToMove = myList.mid(startPos-1, endPos - startPos+1);
            for (int i = startPos; i <= endPos; ++i)
            {
                myList.removeAt(startPos-1);
            }
            for (int i = elementsToMove.size() - 1; i >= 0; --i)
            {
                myList.insert(newPos-1, elementsToMove[i]);
            }
            break;
        }
        case 4:
        {
            int x;
            qDebug() << "Введите значение для удаления:";
            in>>x;
            myList.removeAll(x);
            break;
        }
        case 5:
        {
            int pos, count;
            qDebug() << "Введите позицию для частичной сортировки и количество элементов:";
            in>>pos;
            in>>count;

            if (pos + count > myList.size())
            {
                qDebug() << "Ошибка: выход за границы списка";
                break;
            }

            auto startIt = myList.begin() + pos-1;
            auto endIt = startIt + count;
            std::sort(startIt-1, endIt);

            qDebug() << "Список после частичной сортировки:";
            printList(myList);
            break;
        }
        case 6:
        {
            int sumOfSquares = std::accumulate(myList.begin(), myList.end(), 0, [](int sum, int val)
            { return sum + val * val; });
            qDebug() << "Сумма квадратов элементов:" << sumOfSquares;
            break;
        }
        case 7:
        {
            qDebug() << "Выход из программы";
            break;
        }
        default:
        {
            qDebug() << "Неверный выбор";
            break;
        }
        }
    } while (choice != 7);
    return a.exec();
}
