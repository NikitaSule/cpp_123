#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

// Функция для красивого вывода заголовка
void printHeader(const string& title) {
    cout << "\n[ - - - " << title << " - - - ]\n";
}

// ==================== ЗАДАНИЕ 1 ====================
class Shape1 {
public:
    virtual double area() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape1() {}
};

class Circle : public Shape1 {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    void printInfo() const override {
        cout << "○ Круг: радиус = " << radius 
             << ", площадь = " << fixed << setprecision(2) << area() << endl;
    }
};

class Rectangle : public Shape1 {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    void printInfo() const override {
        cout << "□ Прямоугольник: " << width << " x " << height 
             << ", площадь = " << area() << endl;
    }
};

void task1() {
    printHeader("Задание 1: Фигуры (площадь)");
    vector<Shape1*> shapes = {
        new Circle(5),
        new Rectangle(4, 6)
    };
    
    for (auto shape : shapes) {
        shape->printInfo();
        delete shape;
    }
}

// ==================== ЗАДАНИЕ 2 ====================
class Animal {
public:
    virtual void sound() const = 0;
    virtual void info() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() const override { cout << "Гав!"; }
    void info() const override { cout << "🐶 Собака: "; sound(); cout << endl; }
};

class Cat : public Animal {
public:
    void sound() const override { cout << "Мяу!"; }
    void info() const override { cout << "🐱 Кошка: "; sound(); cout << endl; }
};

void task2() {
    printHeader("Задание 2: Животные");
    vector<Animal*> animals = {
        new Dog(),
        new Cat()
    };
    
    for (auto animal : animals) {
        animal->info();
        delete animal;
    }
}

// ==================== ЗАДАНИЕ 3 ====================
class Employee {
public:
    virtual double calculateSalary() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Employee() {}
};

class FullTimeEmployee : public Employee {
    double monthlySalary;
public:
    FullTimeEmployee(double salary) : monthlySalary(salary) {}
    double calculateSalary() const override { return monthlySalary; }
    void printInfo() const override {
        cout << "👔 Полная занятость: зарплата = " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
    double hourlyRate;
    int hours;
public:
    PartTimeEmployee(double rate, int h) : hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
    void printInfo() const override {
        cout << "⏱ Частичная занятость: ставка = " << hourlyRate 
             << ", часы = " << hours << ", зарплата = " << calculateSalary() << endl;
    }
};

void task3() {
    printHeader("Задание 3: Сотрудники");
    vector<Employee*> employees = {
        new FullTimeEmployee(5000),
        new PartTimeEmployee(20, 80)
    };
    
    for (auto emp : employees) {
        emp->printInfo();
        delete emp;
    }
}

// ==================== ЗАДАНИЕ 4 ====================
class Vehicle {
public:
    virtual void move() const = 0;
    virtual void info() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void move() const override { cout << "едет по дороге"; }
    void info() const override { cout << "🚗 Автомобиль: "; move(); cout << endl; }
};

class Bike : public Vehicle {
public:
    void move() const override { cout << "крутит педали"; }
    void info() const override { cout << "🚲 Велосипед: "; move(); cout << endl; }
};

void task4() {
    printHeader("Задание 4: Транспорт");
    vector<Vehicle*> vehicles = {
        new Car(),
        new Bike()
    };
    
    for (auto v : vehicles) {
        v->info();
        delete v;
    }
}

// ==================== ЗАДАНИЕ 5 ====================
class Account {
protected:
    double balance;
public:
    Account(double b) : balance(b) {}
    virtual void withdraw(double amount) = 0;
    virtual void printBalance() const = 0;
    virtual ~Account() {}
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        if (balance - amount >= 0) balance -= amount;
    }
    void printBalance() const override {
        cout << "💰 Сберегательный счет: баланс = " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        balance -= amount;
    }
    void printBalance() const override {
        cout << "💳 Текущий счет: баланс = " << balance << endl;
    }
};

void task5() {
    printHeader("Задание 5: Банковские счета");
    vector<Account*> accounts = {
        new SavingsAccount(1000),
        new CheckingAccount(1000)
    };
    
    for (auto acc : accounts) {
        cout << "До снятия: ";
        acc->printBalance();
        acc->withdraw(200);
        cout << "После снятия 200: ";
        acc->printBalance();
        delete acc;
    }
}

// ==================== ЗАДАНИЕ 6 ====================
class Shape2 {
public:
    virtual void draw() const = 0;
    virtual void info() const = 0;
    virtual ~Shape2() {}
};

class Triangle : public Shape2 {
public:
    void draw() const override { cout << "▲"; }
    void info() const override { 
        cout << "Треугольник: "; 
        draw(); 
        cout << " (3 стороны)" << endl; 
    }
};

class Square : public Shape2 {
public:
    void draw() const override { cout << "■"; }
    void info() const override { 
        cout << "Квадрат: "; 
        draw(); 
        cout << " (4 равные стороны)" << endl; 
    }
};

void task6() {
    printHeader("Задание 6: Фигуры (рисование)");
    vector<Shape2*> shapes = {
        new Triangle(),
        new Square()
    };
    
    for (auto shape : shapes) {
        shape->info();
        delete shape;
    }
}

// ==================== ЗАДАНИЕ 7 ====================
class Media {
public:
    virtual void play() const = 0;
    virtual void info() const = 0;
    virtual ~Media() {}
};

class Audio : public Media {
public:
    void play() const override { cout << "♫ Воспроизводится аудио"; }
    void info() const override { 
        cout << "🎵 Аудиофайл: "; 
        play(); 
        cout << " (формат: MP3)" << endl; 
    }
};

class Video : public Media {
public:
    void play() const override { cout << "▶ Воспроизводится видео"; }
    void info() const override { 
        cout << "🎬 Видеофайл: "; 
        play(); 
        cout << " (формат: MP4)" << endl; 
    }
};

void task7() {
    printHeader("Задание 7: Медиа");
    vector<Media*> media = {
        new Audio(),
        new Video()
    };
    
    for (auto m : media) {
        m->info();
        delete m;
    }
}

// ==================== ЗАДАНИЕ 8 ====================
class Person {
public:
    virtual void introduce() const = 0;
    virtual void info() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
public:
    void introduce() const override { cout << "Я студент"; }
    void info() const override { 
        cout << "🎓 Студент: "; 
        introduce(); 
        cout << " (учится в университете)" << endl; 
    }
};

class Teacher : public Person {
public:
    void introduce() const override { cout << "Я учитель"; }
    void info() const override { 
        cout << "👨‍🏫 Учитель: "; 
        introduce(); 
        cout << " (преподает в школе)" << endl; 
    }
};

void task8() {
    printHeader("Задание 8: Люди");
    vector<Person*> people = {
        new Student(),
        new Teacher()
    };
    
    for (auto p : people) {
        p->info();
        delete p;
    }
}

// ==================== ЗАДАНИЕ 9 ====================
class Shape3 {
public:
    virtual double perimeter() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape3() {}
};

class Ellipse : public Shape3 {
    double a, b;
public:
    Ellipse(double a, double b) : a(a), b(b) {}
    double perimeter() const override {
        return 2 * 3.14159 * sqrt((a*a + b*b) / 2);
    }
    void printInfo() const override {
        cout << "⬭ Эллипс: a = " << a << ", b = " << b 
             << ", периметр ≈ " << fixed << setprecision(2) << perimeter() << endl;
    }
};

class Polygon : public Shape3 {
    int sides;
    double length;
public:
    Polygon(int s, double l) : sides(s), length(l) {}
    double perimeter() const override { return sides * length; }
    void printInfo() const override {
        cout << "⬢ Многоугольник: сторон = " << sides 
             << ", длина = " << length 
             << ", периметр = " << perimeter() << endl;
    }
};

void task9() {
    printHeader("Задание 9: Фигуры (периметр)");
    vector<Shape3*> shapes = {
        new Ellipse(5, 3),
        new Polygon(6, 4)
    };
    
    for (auto shape : shapes) {
        shape->printInfo();
        delete shape;
    }
}

// ==================== ЗАДАНИЕ 10 ====================
class Book {
public:
    virtual void getInfo() const = 0;
    virtual void printFullInfo() const = 0;
    virtual ~Book() {}
};

class EBook : public Book {
public:
    void getInfo() const override { cout << "Электронная книга"; }
    void printFullInfo() const override { 
        cout << "📱 "; 
        getInfo(); 
        cout << " (форматы: PDF, EPUB)" << endl; 
    }
};

class PrintedBook : public Book {
public:
    void getInfo() const override { cout << "Печатная книга"; }
    void printFullInfo() const override { 
        cout << "📖 "; 
        getInfo(); 
        cout << " (переплет: твердый/мягкий)" << endl; 
    }
};

void task10() {
    printHeader("Задание 10: Книги");
    vector<Book*> books = {
        new EBook(),
        new PrintedBook()
    };
    
    for (auto b : books) {
        b->printFullInfo();
        delete b;
    }
}

// ==================== ЗАДАНИЕ 11 ====================
class Appliance {
public:
    virtual void turnOn() const = 0;
    virtual void info() const = 0;
    virtual ~Appliance() {}
};

class WashingMachine : public Appliance {
public:
    void turnOn() const override { cout << "Запущена стирка"; }
    void info() const override { 
        cout << "🧺 Стиральная машина: "; 
        turnOn(); 
        cout << " (режимы: хлопок, шерсть)" << endl; 
    }
};

class Refrigerator : public Appliance {
public:
    void turnOn() const override { cout << "Охлаждение включено"; }
    void info() const override { 
        cout << "❄ Холодильник: "; 
        turnOn(); 
        cout << " (температура: -18°C)" << endl; 
    }
};

void task11() {
    printHeader("Задание 11: Бытовая техника");
    vector<Appliance*> appliances = {
        new WashingMachine(),
        new Refrigerator()
    };
    
    for (auto a : appliances) {
        a->info();
        delete a;
    }
}

// ==================== ЗАДАНИЕ 12 ====================
class Game {
public:
    virtual void play() const = 0;
    virtual void gameInfo() const = 0;
    virtual ~Game() {}
};

class BoardGame : public Game {
public:
    void play() const override { cout << "Играем в настольную игру"; }
    void gameInfo() const override { 
        cout << "🎲 "; 
        play(); 
        cout << " (пример: Монополия)" << endl; 
    }
};

class VideoGame : public Game {
public:
    void play() const override { cout << "Играем в видеоигру"; }
    void gameInfo() const override { 
        cout << "🎮 "; 
        play(); 
        cout << " (платформа: PC/консоль)" << endl; 
    }
};

void task12() {
    printHeader("Задание 12: Игры");
    vector<Game*> games = {
        new BoardGame(),
        new VideoGame()
    };
    
    for (auto g : games) {
        g->gameInfo();
        delete g;
    }
}

// ==================== ЗАДАНИЕ 13 ====================
class Shape4 {
public:
    virtual double volume() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape4() {}
};

class Sphere : public Shape4 {
    double radius;
public:
    Sphere(double r) : radius(r) {}
    double volume() const override {
        return (4.0/3.0) * 3.14159 * radius * radius * radius;
    }
    void printInfo() const override {
        cout << "🔵 Сфера: радиус = " << radius 
             << ", объем = " << fixed << setprecision(2) << volume() << endl;
    }
};

class Cube : public Shape4 {
    double side;
public:
    Cube(double s) : side(s) {}
    double volume() const override { return side * side * side; }
    void printInfo() const override {
        cout << "🟦 Куб: сторона = " << side 
             << ", объем = " << volume() << endl;
    }
};

void task13() {
    printHeader("Задание 13: Объемные фигуры");
    vector<Shape4*> shapes = {
        new Sphere(5),
        new Cube(4)
    };
    
    for (auto shape : shapes) {
        shape->printInfo();
        delete shape;
    }
}

// ==================== ЗАДАНИЕ 14 ====================
class Device {
public:
    virtual void powerOn() const = 0;
    virtual void info() const = 0;
    virtual ~Device() {}
};

class Smartphone : public Device {
public:
    void powerOn() const override { cout << "Смартфон включен"; }
    void info() const override { 
        cout << "📱 Смартфон: "; 
        powerOn(); 
        cout << " (ОС: Android/iOS)" << endl; 
    }
};

class Laptop : public Device {
public:
    void powerOn() const override { cout << "Ноутбук загружается"; }
    void info() const override { 
        cout << "💻 Ноутбук: "; 
        powerOn(); 
        cout << " (Процессор: Intel/AMD)" << endl; 
    }
};

void task14() {
    printHeader("Задание 14: Устройства");
    vector<Device*> devices = {
        new Smartphone(),
        new Laptop()
    };
    
    for (auto d : devices) {
        d->info();
        delete d;
    }
}

// ==================== ЗАДАНИЕ 15 ====================
class Furniture {
public:
    virtual void assemble() const = 0;
    virtual void info() const = 0;
    virtual ~Furniture() {}
};

class Chair : public Furniture {
public:
    void assemble() const override { cout << "Стул собран"; }
    void info() const override { 
        cout << "🪑 Стул: "; 
        assemble(); 
        cout << " (материал: дерево/металл)" << endl; 
    }
};

class Table : public Furniture {
public:
    void assemble() const override { cout << "Стол собран"; }
    void info() const override { 
        cout << "🪓 Стол: "; 
        assemble(); 
        cout << " (размер: 120x80 см)" << endl; 
    }
};

void task15() {
    printHeader("Задание 15: Мебель");
    vector<Furniture*> furniture = {
        new Chair(),
        new Table()
    };
    
    for (auto f : furniture) {
        f->info();
        delete f;
    }
}

// ==================== ЗАДАНИЕ 16 ====================
class Tool {
public:
    virtual void use() const = 0;
    virtual void toolInfo() const = 0;
    virtual ~Tool() {}
};

class Hammer : public Tool {
public:
    void use() const override { cout << "Забиваем гвозди"; }
    void toolInfo() const override { 
        cout << "🔨 Молоток: "; 
        use(); 
        cout << " (вес: 500г)" << endl; 
    }
};

class Screwdriver : public Tool {
public:
    void use() const override { cout << "Закручиваем винты"; }
    void toolInfo() const override { 
        cout << "🪛 Отвертка: "; 
        use(); 
        cout << " (тип: крестовая)" << endl; 
    }
};

void task16() {
    printHeader("Задание 16: Инструменты");
    vector<Tool*> tools = {
        new Hammer(),
        new Screwdriver()
    };
    
    for (auto t : tools) {
        t->toolInfo();
        delete t;
    }
}

// ==================== ЗАДАНИЕ 17 ====================
class Plant {
public:
    virtual void grow() const = 0;
    virtual void plantInfo() const = 0;
    virtual ~Plant() {}
};

class Flower : public Plant {
public:
    void grow() const override { cout << "Цветок растет и цветет"; }
    void plantInfo() const override { 
        cout << "🌷 Цветок: "; 
        grow(); 
        cout << " (период цветения: весна)" << endl; 
    }
};

class Tree : public Plant {
public:
    void grow() const override { cout << "Дерево растет в высоту"; }
    void plantInfo() const override { 
        cout << "🌳 Дерево: "; 
        grow(); 
        cout << " (высота: до 10м)" << endl; 
    }
};

void task17() {
    printHeader("Задание 17: Растения");
    vector<Plant*> plants = {
        new Flower(),
        new Tree()
    };
    
    for (auto p : plants) {
        p->plantInfo();
        delete p;
    }
}

// ==================== ЗАДАНИЕ 18 ====================
class Clothing {
public:
    virtual void wear() const = 0;
    virtual void clothingInfo() const = 0;
    virtual ~Clothing() {}
};

class Shirt : public Clothing {
public:
    void wear() const override { cout << "Надеваем рубашку"; }
    void clothingInfo() const override { 
        cout << "👕 Рубашка: "; 
        wear(); 
        cout << " (размер: M)" << endl; 
    }
};

class Pants : public Clothing {
public:
    void wear() const override { cout << "Надеваем брюки"; }
    void clothingInfo() const override { 
        cout << "👖 Брюки: "; 
        wear(); 
        cout << " (длина: 32)" << endl; 
    }
};

void task18() {
    printHeader("Задание 18: Одежда");
    vector<Clothing*> clothes = {
        new Shirt(),
        new Pants()
    };
    
    for (auto c : clothes) {
        c->clothingInfo();
        delete c;
    }
}

// ==================== ЗАДАНИЕ 19 ====================
class Sport {
public:
    virtual void play() const = 0;
    virtual void sportInfo() const = 0;
    virtual ~Sport() {}
};

class Football : public Sport {
public:
    void play() const override { cout << "Играем в футбол"; }
    void sportInfo() const override { 
        cout << "⚽ Футбол: "; 
        play(); 
        cout << " (игроков: 11)" << endl; 
    }
};

class Basketball : public Sport {
public:
    void play() const override { cout << "Играем в баскетбол"; }
    void sportInfo() const override { 
        cout << "🏀 Баскетбол: "; 
        play(); 
        cout << " (корзина на 3.05м)" << endl; 
    }
};

void task19() {
    printHeader("Задание 19: Спорт");
    vector<Sport*> sports = {
        new Football(),
        new Basketball()
    };
    
    for (auto s : sports) {
        s->sportInfo();
        delete s;
    }
}

// Главная функция для запуска всех заданий
int main() {
    cout << "=== Демонстрация полиморфизма в C++ ===\n";
    cout << "=== Всего 19 заданий ===\n\n";
    
    task1();  // Фигуры (площадь)
    task2();  // Животные
    task3();  // Сотрудники
    task4();  // Транспорт
    task5();  // Банковские счета
    task6();  // Фигуры (рисование)
    task7();  // Медиа
    task8();  // Люди
    task9();  // Фигуры (периметр)
    task10(); // Книги
    task11(); // Бытовая техника
    task12(); // Игры
    task13(); // Объемные фигуры
    task14(); // Устройства
    task15(); // Мебель
    task16(); // Инструменты
    task17(); // Растения
    task18(); // Одежда
    task19(); // Спорт
    
    cout << "\n=== Все задания выполнены! ===\n";
    return 0;
}