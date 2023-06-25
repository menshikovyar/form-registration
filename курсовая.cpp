// наброски курсовой 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <conio.h>
#include <io.h>
#pragma warning(disable : 4996)//т.к. использую getche
#include <windows.h>
//#include "stdafx.h"
//#include <WinUser.h>
//#include <afxwin.h>
using namespace std;

struct WarehouseItem
{
    int articul;
    string name;
    string izmerenie;
    double kolichestvo;
} w1;

struct Item
{
    int articul;
    string name;
    string izmerenie;
    double kolichestvo;
    string date;
    string operation;
} w;

void sortInventory();
void updateInventory();
void viewInventory();
void diagramma();
void sortWords();
//добавить линейный список

void sortWords()
{
    ifstream s("data1", ios::in | ios::binary);
    s.seekg(0,ios::end);
    int sizeFile = s.tellg();
    s.seekg(0, ios::beg);
    int sizeStruct = sizeof(w1);
    int qualityStructs = sizeFile / sizeStruct;
    WarehouseItem* b = new WarehouseItem[qualityStructs];
    int i = 0;
    while (s.read((char*)&b[i++], sizeof(w1)));
    //int count;
    WarehouseItem* buf = new WarehouseItem[qualityStructs];
    int lengroup = 1;      // длина группы
    while (lengroup < qualityStructs)
    {
        int i = 0, ik;
        int j, jk;
        int ibuf = 0;
        while (ibuf < qualityStructs)
        {
            ik = i + lengroup - 1;
            if (ik >= qualityStructs) ik = qualityStructs - 1;
            j = i + lengroup;
            jk = j + lengroup - 1;
            if (jk >= qualityStructs) jk = qualityStructs - 1;

            while (i <= ik && j <= jk)
            {
                if (b[i].name < b[j].name)
                {
                    buf[ibuf] = b[i];
                    i++;
                }
                else
                {
                    buf[ibuf] = b[j];
                    j++;
                }
                ibuf++;
            }
            while (i <= ik)
            {
                buf[ibuf] = b[i];
                i++; ibuf++;
            }
            while (j <= jk)
            {
                buf[ibuf] = b[j];
                j++; ibuf++;
            }
            i = jk + 1;
        }
        lengroup *= 2;
        memcpy(b, buf, qualityStructs * sizeof(int));
    }
    //s.close();
    delete[]buf;
    cout << "Данные после сортировки: \n";
    for (int i = 0; i < qualityStructs; i++)
    {
        printf("%5d %-10s %-10s %6.2f\n", b[i].name, b[i].articul, b[i].izmerenie, b[i].kolichestvo);
    }
    _getch();
}

// в 1 файл буду записывать артикул, единицы изм, наименование и количество
// во 2 дату, поступление/отпуск

void diagramma(HANDLE hConsole, HWND hcon, PWINDOWINFO pgwi)
{
    int k = 8;
    HDC hdc = GetDC(hcon);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    system("cls");
    HPEN hWhitePen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255)); // для рисования линий
    HBRUSH hBlackBrush = CreateSolidBrush(RGB(0, 0, 0));		 // для заполнения фигур
    HPEN hcp = (HPEN)SelectObject(hdc, hWhitePen);
    int osn = (pgwi->rcClient.bottom - pgwi->rcClient.top - 50);
    MoveToEx(hdc, 100, osn, NULL);	// перемещение курсора
    LineTo(hdc, 100 + k * 35, osn);
    RECT r;
    for (int i = 0; i < k; i++)		// здесь должны быть расчеты 
    {                               // для круговой диаграммы используем другие функции рисования
        int ran = rand() / 100 - 50;
        r.left = 100 + i * 35;
        r.top = osn - 300 + ran;
        r.right = 100 + (i + 1) * 35 - 10;
        r.bottom = osn;
        HBRUSH hBrush = CreateSolidBrush(RGB(i * 10 + 100, i * 20 + 50, i * 30 + 100));
        FillRect(hdc, &r, hBrush);
        DeleteObject(hBrush);
    }
    TextOutW(hdc, 150 + k * 35, 50, L"ДИАГРАММА", 10);
    system("pause");
    r.left = 0;
    r.top = 0;
    r.right = pgwi->rcClient.bottom;
    r.bottom = pgwi->rcClient.right;
    FillRect(hdc, &r, hBlackBrush);
    DeleteObject(hWhitePen);
    DeleteObject(hBlackBrush);
}

void sortInventory()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    cout << "В какой файл хотите ввести информацию?\n";
    cout << "1 - В первый\n";
    cout << "2 - Во второй\n";
    char s;
    s = getche();
    rewind(stdin); //
    if (s == '1')
    {
        WarehouseItem item;   
        cout << "Введите артикул:\n";  // в 1 файле должна быть структура из артикула, наименования, единиц измерения и количества
        cin >> item.articul;
        cout << "Введите наименование:\n";
        cin >> item.name;
        cout << "Введите единицы измерения:\n";
        cin >> item.izmerenie;
        cout << "Введите количество:\n";
        cin >> item.kolichestvo;
        fstream out("data1", ios::binary | ios::app); //выводим в файл в режиме добавления
        out.write((char*)&item, sizeof(item));
        out.close();
    }
    if (s == '2')
    {
        int p = 0; int o = 0; int i = 0;
        int A[50];
        Item item2;
        cout << "Введите артикул:\n";  
        cin >> item2.articul;
        cout << "Введите наименование:\n";
        cin >> item2.name;
        cout << "Введите единицы измерения:\n";
        cin >> item2.izmerenie;
        cout << "Введите количество:\n";
        cin >> item2.kolichestvo;
        cout << "Введите дату:\n";
        cin >> item2.date;
        cout << "Введите операцию поступление/отпуск:\n";
        cin >> item2.operation;
        cout << "Введите [P|p/o|O]:";
        int c;
        c = getch();
        if (c == 'P' || c == 'p')  //поступление
        {
            printf("\nСколько товара поступило? ");
            scanf_s("%d", &A[i]);
            p += A[i];
            //cout << p;
        }

        if (c == 'O' || c == 'o') //отпуск
        {
            cout<<"\nСколько товара отпущено? ";
            scanf_s("%d", &A[i]);
            o += A[i];
           // cout << o;
        }
        fstream out("data2", ios::binary | ios::app); //выводим в файл
        out.write((char*)&item2, sizeof(item2));
        out.close();
    }
}
   
void updateInventory()
{
        string input_file = "data2";
        string output_file = "data1";
        fstream input(input_file, ios::binary | ios::in); // Открытие файла для чтения
        input.seekg(0, ios::end); // Получение размера файла
        int file_size = input.tellg();
        input.seekg(0, ios::beg);
        vector<char> buffer(file_size); // Чтение данных из файла
        input.read(buffer.data(), file_size);
        input.close();
        fstream output(output_file, ios::app | ios::binary); // Открытие файла для записи
        output.write(buffer.data(), file_size); // Запись данных в файл
        output.close();
        cout << "Информация обновлена!\n";
}

void viewInventory()
{
    printf("\nВыберите:");
    printf("\n1 - Просмотреть 1 файл\n");
    printf("2 - Просмотреть 2 файл\n");
    char s;
    s = getche();
    if (s == '1')
    {
        //Item items;
        cout << "\nПросмотр 1го файла:" << endl;
       // WarehouseItem w1;
        FILE* in;
        fopen_s(&in, "data1", "rb+");
        // fstream in("data1", ios::binary | ios::in); //для чтения из файла в режиме чтения
       // in.seekg(0,ios::end); // если курсор в начале файла, перемещаем его в конец и определяем размер
        int sizeFile = filelength(fileno(in));
      //  in.seekg(0, ios::beg);
        int sizeStruct = sizeof(w1);
        int quantityStructs = sizeFile / sizeStruct; //кол-во структур в файле
  //      for (int i = 0; i < quantityStructs; i++)
    //    {
        for (int i = 0; i < quantityStructs; i++)
        {
            fread((char*)&w1, sizeof(w1), 1, in);
            cout << "Артикул: " << w1.articul << endl;
            cout << "Наименование:  " << w1.name << endl;
            cout << "Единицы измерения: " << w1.izmerenie << endl;
            cout << "Количество: " << w1.kolichestvo << endl;
        }
        fclose(in);
       // char ccc=_getch(); //добавил, чтобы убрать обработку исключений, но не особо помогло
        getchar();
    }
    else if (s == '2')
    {
        cout << "\nПросмотр 2го файла:" << endl;
        //Item w;
        //   fstream in("data2", ios::binary | ios::in);//для чтения из файла
        FILE* in;
        fopen_s(&in, "data2", "rb+");

       // in.seekg(0, ios::end);
        int sizeFile = filelength(fileno(in)); //in.tellg();
       // in.seekg(0, ios::beg);
        int sizeStruct = sizeof(w);
        int quantityStructs = sizeFile / sizeStruct;
        for (int i = 0; i < quantityStructs; i++)
        {
            //in.read((char*)&w, sizeof(w));
            fread((char*)&w, sizeof(w),1,in);
            cout << "Артикул: " << w.articul << endl;
            cout << "Наименование: " << w.name << endl;
            cout << "Единицы измерения: " << w.izmerenie << endl;
            cout << "Количество: " << w.kolichestvo << endl;
            cout << "Дата: " << w.date << endl;
            cout << "Операция: " << w.operation << endl;
        }
        //in.close();
        fclose(in);
        getchar(); // добавил, чтобы убрать обработку исключений, но не особо помогло
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    while (true) 
    {
        cout << "\nМеню:\n1. Добавить данные\n2. Посмотреть информацию\n3. Построить график\n4. Обновить информацию\n5. Сортировка\n6. Выйти\nВыберите пункт : ";
        int choice;
        cin >> choice;
        switch (choice) 
        {
        case 1:
            sortInventory();
            break;
        case 4:
            updateInventory();
           // rename("data2.txt", "data3.txt");
            break;
        case 2:
            cout << "Просмотр информации";
            viewInventory();
            sortWords();
            break;
        case 3:
            void diagramma();
        case 5:
            sortWords();
        case 6:
            return 0;
        default:
            cout << "Неверный пункт" << endl;
        }
    }
}

//alla.ispu@yandex.ru // почта Алыковой Алевтины Леонидовны
 
// задачи
//Лишние пробелы. Дан текст, состоящий из нескольких строк. Слова в тексте разделены пробелами. 
//Если между двумя соседними словами более одного пробела, удалить “лишние” пробелы. Скорректированный текст вывести на экран.
//#include <iostream>
//#include <fstream>
//#include <vector>
//#include <string>
//#include <windows.h>
//using namespace std;
//
//int main()
//{
//    SetConsoleCP(1251);  //работает только со шрифтом люсида!!!
//    SetConsoleOutputCP(1251);  // если в файле будет русский текст, все равно не работает!!!
//   // setlocale(LC_ALL, "Russian");
//    ifstream a("tekst.txt", ios::in);
//    vector<string> lines;// Читаем файл построчно и записываем строки в вектор
//    string line;
//    while (getline(a, line))
//    {
//        lines.push_back(line);
//    }
//    for (string& l : lines)// Исправляем двойные пробелы в каждой строке
//    {
//        size_t pos;
//        while ((pos = l.find("  ")) != string::npos) //ищем позицию двойного пробела и проверяем на существование такого пробела
//        {
//            l.replace(pos, 2, " ");
//        }
//    }
//    for (string& l : lines)// Выводим исправленный текст на экран
//    {
//        cout << l << endl;
//    }
//    return 0;
//}


//Прописные буквы.Дан текстовый файл.Получить новый файл, образованный из первого 
//заменой всех его строчных(маленьких) букв прописными(большими).
//Если замена не производилась, сообщить об этом.



