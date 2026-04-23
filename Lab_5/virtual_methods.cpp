#include <iostream>
using namespace std;

// Базовый класс
class Shape {
public:
    Shape()  { cout << "[Shape] конструктор\n"; }
    ~Shape() { cout << "[Shape] деструктор\n"; }

    void draw() {
        cout << "[Shape] draw() — невиртуальный\n";
    }

    virtual void describe() {
        cout << "[Shape] describe() — виртуальный\n";
    }
};

// Потомок
class Circle : public Shape {
public:
    Circle()  { cout << "[Circle] конструктор\n"; }
    ~Circle() { cout << "[Circle] деструктор\n"; }

    void draw() {
        cout << "[Circle] draw() — невиртуальный\n";
    }

    void describe() override {
        cout << "[Circle] describe() — виртуальный\n";
    }
};

void demo_virtual_methods() {
    cout << "Создаём Circle через указатель на Shape\n";
    Shape* s = new Circle();

    cout << "\nВызов draw() — невиртуальный:\n";
    s->draw();
    // Выведет [Shape], хотя объект Circle — метод невиртуальный, тип указателя Shape*

    cout << "\nВызов describe() — виртуальный:\n";
    s->describe();
    // Выведет [Circle] — вызывается метод реального объекта

    cout << "\nУдаляем через Shape*:\n";
    delete s;
    // Деструктор Shape не виртуальный — Circle не удалится, утечка памяти

    cout << "\n\nСоздаём Circle через Circle*\n";
    Circle* c = new Circle();

    cout << "\nВызов draw():\n";
    c->draw();

    cout << "\nВызов describe():\n";
    c->describe();

    cout << "\nУдаляем через Circle*:\n";
    delete c;
    // Оба деструктора вызовутся в правильном порядке
}
