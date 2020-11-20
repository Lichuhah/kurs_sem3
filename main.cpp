#define filepath "data"
#include<Windows.h>
#include"Data.h"


using namespace std;
void menu() {
    cout << "\n__________________________________________";
    cout << "\n\n --SUPER PUPER PROGRAMMA FOR TEACHERS--";
    cout << "\n                --(BIA)--";
    cout << "\n__________________________________________";
    cout << "\n\n1. Вывести список ";
    cout << "\n2. Добавить студента";
    cout << "\n3. Удалить студента";
    cout << "\n4. Сортировать по имени";
    cout << "\n5. Сортировать по группе";
    cout << "\n6. Записать изменения";
    cout << "\n7. Найти хорошистов.";
    cout << "\n8. Exit.";
    cout << "\n__________________________________________";
}
void task() {
    cout << endl;
    cout << "\n__________________________________________";
    cout << "\n        --Курсовая работа--";
    cout << "\n        --ОСНОВЫ ПРОГРАММИРОВАНИЯ--";
    cout << "\n        --Студент: Белов А.И.";
    cout << "\n        --Группа: 4932";
    cout << "\n__________________________________________";
    cout << "\n\nПредметная область –«Учет успеваемости студентов».";
    cout << "\nДанные о студенте хранятся в структуре с именем STUDENT,";
    cout << "\nсодержащей следующие поля";
    cout << "\n* фамилия и инициалы;";
    cout << "\n* номер группы;";
    cout << "\n* успеваемость (массив из пяти элементов).";
    cout << "\nЗадание на поиск: найти студентов, чей средний бал не меньше ";
    cout << "\nуказанного пользователем значения.";
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    task();
    menu();
    DataStudent testData;
    testData.readFromFile(filepath);
    int info, value;
    while (true) {
        cout << "\n Ваш выбор -- ";
        cin >> info;
        switch (info){
        case 1: testData.showData(); break;
        case 2: testData.insertInData(); break;
        case 3: cout << "Введите номер удаляемого студента: "; cin >> value; testData.deleteFromData(value);  break;
        case 4: testData.sortByFullName(); break;
        case 5: testData.sortByGroup(); break;
        case 6: testData.writeToFile(filepath); break;
        case 7: testData.findOtl(); break;
        case 8: exit(0); break;
        default: cout << "Некорректный ввод" << endl; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); break;
        }
    }
    
    return 1;
}
