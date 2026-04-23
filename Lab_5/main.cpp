#include <iostream>
#include <windows.h>
using namespace std;

void demo_virtual_methods();
void demo_virtual_destructor();

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice = 0;
    while (true) {
        cout << "\nЛабораторная работа 5\n";
        cout << "1. Виртуальные методы\n";
        cout << "2. Виртуальный деструктор\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;

        switch (choice) {
            case 1: demo_virtual_methods();    break;
            case 2: demo_virtual_destructor(); break;
            case 0: return 0;
            default: cout << "Неверный выбор\n";
        }
    }
}
