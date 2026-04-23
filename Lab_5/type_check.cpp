#include <iostream>
#include <string>
using namespace std;

class Shape {
public:
    virtual string classname() {
        return "Shape";
    }

    // isA возвращает true если объект является экземпляром указанного класса
    // или его предка — в отличие от classname(), который возвращает только
    // имя самого конкретного класса
    virtual bool isA(string name) {
        return name == "Shape";
    }
};

class Circle : public Shape {
public:
    string classname() override {
        return "Circle";
    }

    bool isA(string name) override {
        if (name == "Circle") return true;
        return Shape::isA(name); // проверяем предков
    }
};

class Ellipse : public Circle {
public:
    string classname() override {
        return "Ellipse";
    }

    bool isA(string name) override {
        if (name == "Ellipse") return true;
        return Circle::isA(name); // проверяем предков
    }
};

void demo_type_check() {
    Shape* s  = new Shape();
    Shape* c  = new Circle();
    Shape* e  = new Ellipse();

    cout << "classname():\n";
    cout << "s -> " << s->classname() << "\n";
    cout << "c -> " << c->classname() << "\n";
    cout << "e -> " << e->classname() << "\n";

    cout << "\nПроблема classname() — можно проверить только точный тип:\n";
    cout << "e->classname() == \"Circle\" : " << (e->classname() == "Circle" ? "true" : "false") << "\n";
    // Выведет false, хотя Ellipse является потомком Circle

    cout << "\nisA() — проверяет и предков тоже:\n";
    cout << "e->isA(\"Ellipse\") : " << (e->isA("Ellipse") ? "true" : "false") << "\n";
    cout << "e->isA(\"Circle\")  : " << (e->isA("Circle")  ? "true" : "false") << "\n";
    cout << "e->isA(\"Shape\")   : " << (e->isA("Shape")   ? "true" : "false") << "\n";
    cout << "c->isA(\"Ellipse\") : " << (c->isA("Ellipse") ? "true" : "false") << "\n";

    cout << "\ndynamic_cast — стандартное средство C++:\n";
    // Возвращает nullptr если приведение невозможно
    Circle* cast1 = dynamic_cast<Circle*>(e);
    Circle* cast2 = dynamic_cast<Circle*>(s);
    cout << "dynamic_cast<Circle*>(e) : " << (cast1 != nullptr ? "успех" : "nullptr") << "\n";
    cout << "dynamic_cast<Circle*>(s) : " << (cast2 != nullptr ? "успех" : "nullptr") << "\n";

    delete s;
    delete c;
    delete e;
}
