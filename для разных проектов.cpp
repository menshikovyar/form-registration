////                                                 ПРИЛОЖЕНИЕ ВХОДА В СИСТЕМУ, ЛОГИН И ПАРОЛЬ
//#include <iostream>
//#include <fstream>
//#include <string>
//
//using namespace std;
//
//void registration()
//{
//    system("cls");
//    string user1, password1, us1, pass1;
//    cout << "\t\t\tРегистрация нового пользователя: " << endl;
//    cout << "\t\t\tЛогин: " << endl;
//    cin >> user1;
//    cout << "\t\t\tПароль: " << endl;
//    cin >> password1;
//    ofstream in1("data.txt",ios::app);
//    in1 << user1 << "  " << password1 << endl;
//    system("cls");
//    cout << "\n\t\t\tРегистрация прошла успешно! \n";
//}
//
//void entrance()
//{
//    system("cls");
//    cout << "\t\t\tВход: " << endl;
//    int c = 0;
//    string user, password, us, pass;
//    cout << "\t\t\tВведите логин и пароль " << endl;
//    cout << "\t\t\tЛогин: " << endl;
//    cin >> user;
//    cout << "\t\t\tПароль: " << endl;
//    cin >> password;
//    ifstream in("data.txt");
//    while (in >> us >> pass)
//    {
//        if (us == user && pass == password)
//        {
//            c = 1;
//            system("cls");
//        }
//    }
//    in.close();
//    if (c == 1)
//    {
//        cout << user << "  " << "Авторизация прошла успешно!\n" << endl;
//    }
//    else
//    {
//        cout << user << "  " << "При авторизации возникла ошибка!\n" << endl;
//    }
//}
//
//void instruction()
//{
//    system("cls");
//    int operation;
//    cout << "\t\t\tНе беспокоитесь, если вы забыли пароль! \n";
//    cout << "Нажмите 1 для поиска никнейма " << endl;
//    cin >> operation;
//    switch (operation)
//    {
//    case 1:
//        {
//            int a = 0;
//            string user2, us2, pass2;
//            cout << "\n\t\t\tВедите логин: " << endl;
//            cin >> user2;
//            ifstream in2("data.txt");
//            while (in2 >> us2 >> pass2)
//            {
//                if (us2 == user2)
//                    a = 1;
//            }
//            in2.close();
//            if (a == 1)
//            {
//                cout << "\n\nВаша учетная запись восстановлена \n" << endl;
//                cout << "\n\nВаш пароль: \n" << pass2;
//            }
//            else
//            {
//                cout << "\n\nВаша учетная запись не найдена \n" << endl;
//            }
//        }
//        break;
//    default:
//        {
//            cout << "\t\t\tНет такого варианта! \n";
//            instruction();
//        }
//    }
//}
//
//    int main()
//{
//    system("chcp 1251");
//    ////float c = 1.5f; // f значит, что число типа float, если не написать f, то тип будет double
//    //char a = '\\'; // \ рассматривается как спецсимвол, который указывает на последующий символ
//    //cout << a;
//    //return 0;
//    cout << "\t\t\t______________________________________\n\n";
//    cout << "\t\t\t            Главное меню               \n\n";
//    cout << "                                              \n";
//    cout << "\t\t\t| 1. Регистрация нового пользователя   |" << endl;
//    cout << "\t\t\t| 2. Вход в систему                    |" << endl;
//    cout << "\t\t\t| 3. Что делать, если забыл пароль     |" << endl;
//    cout << "\t\t\t| 4. Выйти                             |" << endl;
//        cout << "Выберите: ";
//        int choice;
//        cin >> choice;
//        switch (choice)
//        {
//        case 1:
//            registration();
//            break;
//        case 2:
//            entrance();
//            break;
//        case 3:
//            instruction();
//            break;
//        case 4:
//            cout << "\t\t\t           Спасибо за внимание!!!         \n\n";
//            return 0;
//        default:
//            system("cls");
//            cout << "\t\t\t           Нет такого варианта            \n\n";
//        }
//}
//
//
//
//
