#include <iostream>
#include <windows.h>
using namespace std;

void demo_virtual_methods();
void demo_virtual_destructor();
void demo_type_check();
void demo_passing_objects();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice = 0;
    while (true) {
        cout << "\nЛабораторная работа 5\n";
        cout << "1. Виртуальные методы\n";
        cout << "2. Виртуальный деструктор\n";
        cout << "3. Проверка типа (classname, isA, dynamic_cast)\n";
        cout << "4. Передача объектов в функции\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: demo_virtual_methods();    break;
            case 2: demo_virtual_destructor(); break;
            case 3: demo_type_check();         break;
            case 4: demo_passing_objects();    break;
            case 0: return 0;
            default: cout << "Неверный выбор\n";
        }
    }
}
