#include <iostream>
#include <string>
using namespace std;

namespace passing {

class Base {
public:
    string name;

    Base()           { cout << "[Base] конструктор по умолчанию\n"; }
    Base(Base* obj)  { cout << "[Base] конструктор с указателем\n"; name = obj->name; }
    Base(Base& obj)  { cout << "[Base] конструктор копирования\n";  name = obj.name; }
    ~Base()          { cout << "[Base] деструктор\n"; }
};

class Desc : public Base {
public:
    Desc()           { cout << "[Desc] конструктор по умолчанию\n"; }
    Desc(Desc* obj)  { cout << "[Desc] конструктор с указателем\n"; name = obj->name; }
    Desc(Desc& obj)  { cout << "[Desc] конструктор копирования\n";  name = obj.name; }
    ~Desc()          { cout << "[Desc] деструктор\n"; }
};

void func1(Base obj)  { cout << "  func1: внутри функции\n"; }
void func2(Base* obj) { cout << "  func2: внутри функции\n"; }
void func3(Base& obj) { cout << "  func3: внутри функции\n"; }

void run() {
    cout << "Создаём объекты:\n";
    Base b;
    Desc d;

    cout << "\nfunc1 — по значению, передаём Base:\n";
    func1(b);
    // Создаётся копия — вызовется конструктор копирования и деструктор при выходе из функции

    cout << "\nfunc1 — по значению, передаём Desc:\n";
    func1(d);
    // Срезка объекта: Desc приводится к Base, часть Desc теряется

    cout << "\nfunc2 — по указателю, передаём Base:\n";
    func2(&b);

    cout << "\nfunc2 — по указателю, передаём Desc:\n";
    func2(&d);

    cout << "\nfunc3 — по ссылке, передаём Base:\n";
    func3(b);

    cout << "\nfunc3 — по ссылке, передаём Desc:\n";
    func3(d);

    cout << "\nВыходим из функции:\n";
}

} // namespace passing

void demo_passing_objects() { passing::run(); }
