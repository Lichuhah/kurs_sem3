#define filepath "data"
#include<Windows.h>
#include"Data.h"


using namespace std;
void menu() {
    cout << "\n__________________________________________";
    cout << "\n\n --SUPER PUPER PROGRAMMA FOR TEACHERS--";
    cout << "\n                --(BIA)--";
    cout << "\n__________________________________________";
    cout << "\n\n1. ������� ������ ";
    cout << "\n2. �������� ��������";
    cout << "\n3. ������� ��������";
    cout << "\n4. ����������� �� �����";
    cout << "\n5. ����������� �� ������";
    cout << "\n6. �������� ���������";
    cout << "\n7. ����� ����������.";
    cout << "\n8. Exit.";
    cout << "\n__________________________________________";
}
void task() {
    cout << endl;
    cout << "\n__________________________________________";
    cout << "\n        --�������� ������--";
    cout << "\n        --������ ����������������--";
    cout << "\n        --�������: ����� �.�.";
    cout << "\n        --������: 4932";
    cout << "\n__________________________________________";
    cout << "\n\n���������� ������� ������ ������������ ���������.";
    cout << "\n������ � �������� �������� � ��������� � ������ STUDENT,";
    cout << "\n���������� ��������� ����";
    cout << "\n* ������� � ��������;";
    cout << "\n* ����� ������;";
    cout << "\n* ������������ (������ �� ���� ���������).";
    cout << "\n������� �� �����: ����� ���������, ��� ������� ��� �� ������ ";
    cout << "\n���������� ������������� ��������.";
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
        cout << "\n ��� ����� -- ";
        cin >> info;
        switch (info){
        case 1: testData.showData(); break;
        case 2: testData.insertInData(); break;
        case 3: cout << "������� ����� ���������� ��������: "; cin >> value; testData.deleteFromData(value);  break;
        case 4: testData.sortByFullName(); break;
        case 5: testData.sortByGroup(); break;
        case 6: testData.writeToFile(filepath); break;
        case 7: testData.findOtl(); break;
        case 8: exit(0); break;
        default: cout << "������������ ����" << endl; cin.clear(); cin.ignore(cin.rdbuf()->in_avail()); break;
        }
    }
    
    return 1;
}
