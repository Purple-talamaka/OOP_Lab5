#include <iostream>
using namespace std;

// Базовый класс с невиртуальным деструктором
class ShapeBad {
public:
    ShapeBad()  { cout << "[ShapeBad] конструктор\n"; }
    ~ShapeBad() { cout << "[ShapeBad] деструктор\n"; }
};

class CircleBad : public ShapeBad {
public:
    CircleBad()  { cout << "[CircleBad] конструктор\n"; }
    ~CircleBad() { cout << "[CircleBad] деструктор\n"; }
};

// Базовый класс с виртуальным деструктором
class ShapeGood {
public:
    ShapeGood()          { cout << "[ShapeGood] конструктор\n"; }
    virtual ~ShapeGood() { cout << "[ShapeGood] деструктор\n"; }
};

class CircleGood : public ShapeGood {
public:
    CircleGood()  { cout << "[CircleGood] конструктор\n"; }
    ~CircleGood() { cout << "[CircleGood] деструктор\n"; }
};

void demo_virtual_destructor() {
    cout << "Невиртуальный деструктор — удаляем CircleBad через ShapeBad*:\n";
    ShapeBad* b = new CircleBad();
    delete b;
    // Вызовется только [ShapeBad] деструктор — CircleBad не удалится, утечка памяти

    cout << "\nВиртуальный деструктор — удаляем CircleGood через ShapeGood*:\n";
    ShapeGood* g = new CircleGood();
    delete g;
    // Вызовутся оба деструктора: сначала CircleGood, потом ShapeGood
}
