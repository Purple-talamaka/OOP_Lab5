#include <iostream>
using namespace std;

namespace returning {

class Base {
public:
    Base()        { cout << "[Base] конструктор\n"; }
    Base(const Base&)   { cout << "[Base] конструктор копирования\n"; }
    ~Base()       { cout << "[Base] деструктор\n"; }
};

// Возвращаем локальный объект по значению
Base func1() {
    cout << "  func1: создаём локальный объект\n";
    Base obj;
    return obj;
}

// Возвращаем указатель на локальный объект — опасно,
// объект удалится при выходе из функции
Base* func2() {
    cout << "  func2: создаём локальный объект\n";
    Base obj;
    return &obj;
}

// Возвращаем ссылку на локальный объект — та же проблема
Base& func3() {
    cout << "  func3: создаём локальный объект\n";
    Base obj;
    return obj;
}

// Возвращаем динамический объект по значению — оригинал в куче никто не удалит
Base func4() {
    cout << "  func4: создаём динамический объект\n";
    Base* obj = new Base();
    return *obj;
}

// Возвращаем указатель на динамический объект — вызывающая сторона должна вызвать delete
Base* func5() {
    cout << "  func5: создаём динамический объект\n";
    return new Base();
}

// Возвращаем ссылку на динамический объект
Base& func6() {
    cout << "  func6: создаём динамический объект\n";
    return *new Base();
}

void run() {
    cout << "func1 — возврат локального объекта по значению:\n";
    Base r1 = func1();

    cout << "\nfunc2 — возврат указателя на локальный объект:\n";
    Base* r2 = func2();
    // r2 указывает на уже удалённый объект — неопределённое поведение

    cout << "\nfunc3 — возврат ссылки на локальный объект:\n";
    Base& r3 = func3();
    // та же проблема

    cout << "\nfunc4 — возврат динамического объекта по значению:\n";
    Base r4 = func4();
    // создаётся копия, оригинал в куче не удаляется — утечка памяти

    cout << "\nfunc5 — возврат указателя на динамический объект:\n";
    Base* r5 = func5();
    cout << "  удаляем объект:\n";
    delete r5;

    cout << "\nfunc6 — возврат ссылки на динамический объект:\n";
    Base& r6 = func6();
    cout << "  удаляем объект:\n";
    delete &r6;

    cout << "\nВыходим из функции:\n";
}

} // namespace returning

void demo_returning_objects() { returning::run(); }
