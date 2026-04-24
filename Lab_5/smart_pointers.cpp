#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
    Base()  { cout << "[Base] конструктор\n"; }
    ~Base() { cout << "[Base] деструктор\n"; }
};

// Принимаем unique_ptr по значению — владение передаётся в функцию,
// после выхода объект удаляется
void take_unique(unique_ptr<Base> obj) {
    cout << "  внутри take_unique\n";
}

// Принимаем shared_ptr по значению — счётчик ссылок увеличивается,
// объект не удаляется после выхода из функции
void take_shared(shared_ptr<Base> obj) {
    cout << "  внутри take_shared, счётчик = " << obj.use_count() << "\n";
}

void demo_smart_pointers() {
    cout << "unique_ptr — единственный владелец объекта:\n";
    {
        unique_ptr<Base> u = make_unique<Base>();
        cout << "  unique_ptr создан\n";
    }
    // Объект удалился при выходе из блока — деструктор вызвался автоматически
    cout << "  вышли из блока — объект уже удалён\n";

    cout << "\nПередача unique_ptr в функцию — передаём владение:\n";
    unique_ptr<Base> u2 = make_unique<Base>();
    take_unique(move(u2));
    // move() передаёт владение в функцию, u2 становится nullptr
    cout << "  после передачи u2 == nullptr: " << (u2 == nullptr ? "да" : "нет") << "\n";

    cout << "\nshared_ptr — несколько владельцев:\n";
    {
        shared_ptr<Base> s1 = make_shared<Base>();
        cout << "  s1 создан, счётчик = " << s1.use_count() << "\n";
        {
            shared_ptr<Base> s2 = s1;
            cout << "  s2 = s1, счётчик = " << s1.use_count() << "\n";
        }
        cout << "  s2 удалён, счётчик = " << s1.use_count() << "\n";
    }
    // Объект удалится только когда счётчик станет 0 — то есть когда s1 выйдет из блока
    cout << "  вышли из блока — объект удалён\n";

    cout << "\nПередача shared_ptr в функцию:\n";
    shared_ptr<Base> s3 = make_shared<Base>();
    cout << "  до вызова, счётчик = " << s3.use_count() << "\n";
    take_shared(s3);
    cout << "  после вызова, счётчик = " << s3.use_count() << "\n";

    cout << "\nВыходим из функции:\n";
}
