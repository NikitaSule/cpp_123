#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Функция для красивого вывода заголовка
void printHeader(const string& title) {
    cout << "\n[ - - - " << title << " - - - ]\n";
}

// 1. Фигуры
class Shape {
public:
    virtual double area() const = 0;
    virtual void printInfo() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    void printInfo() const override {
        cout << "Круг: радиус = " << radius << ", площадь = " << fixed << setprecision(2) << area() << endl;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override { return width * height; }
    void printInfo() const override {
        cout << "Прямоугольник: " << width << " x " << height 
             << ", площадь = " << area() << endl;
    }
};

void shapeDemo() {
    printHeader("Задание 1: Фигуры");
    vector<Shape*> shapes = {
        new Circle(5),
        new Rectangle(4, 6)
    };
    
    for (auto shape : shapes) {
        shape->printInfo();
        delete shape;
    }
}

// 2. Животные
class Animal {
public:
    virtual void sound() const = 0;
    virtual void info() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() const override { cout << "Гав!" << endl; }
    void info() const override { cout << "Собака: "; sound(); }
};

class Cat : public Animal {
public:
    void sound() const override { cout << "Мяу!" << endl; }
    void info() const override { cout << "Кошка: "; sound(); }
};

void animalDemo() {
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

// 3. Сотрудники
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
        cout << "Полная занятость: зарплата = " << calculateSalary() << endl;
    }
};

class PartTimeEmployee : public Employee {
    double hourlyRate;
    int hours;
public:
    PartTimeEmployee(double rate, int h) : hourlyRate(rate), hours(h) {}
    double calculateSalary() const override { return hourlyRate * hours; }
    void printInfo() const override {
        cout << "Частичная занятость: ставка = " << hourlyRate 
             << ", часы = " << hours << ", зарплата = " << calculateSalary() << endl;
    }
};

void employeeDemo() {
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

// 4. Транспорт
class Vehicle {
public:
    virtual void move() const = 0;
    virtual void info() const = 0;
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
public:
    void move() const override { cout << "Машина едет" << endl; }
    void info() const override { cout << "Автомобиль: "; move(); }
};

class Bike : public Vehicle {
public:
    void move() const override { cout << "Велосипед крутит педали" << endl; }
    void info() const override { cout << "Велосипед: "; move(); }
};

void vehicleDemo() {
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

// 5. Счета
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
        cout << "Сберегательный счет: баланс = " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double b) : Account(b) {}
    void withdraw(double amount) override {
        balance -= amount;
    }
    void printBalance() const override {
        cout << "Текущий счет: баланс = " << balance << endl;
    }
};

void accountDemo() {
    printHeader("Задание 5: Банковские счета");
    vector<Account*> accounts = {
        new SavingsAccount(1000),
        new CheckingAccount(1000)
    };
    
    for (auto acc : accounts) {
        acc->withdraw(200);
        acc->printBalance();
        delete acc;
    }
}

// 6. Медиа
class Media {
public:
    virtual void play() const = 0;
    virtual void info() const = 0;
    virtual ~Media() {}
};

class Audio : public Media {
public:
    void play() const override { cout << "Воспроизводится аудио..." << endl; }
    void info() const override { cout << "Аудио: "; play(); }
};

class Video : public Media {
public:
    void play() const override { cout << "Воспроизводится видео..." << endl; }
    void info() const override { cout << "Видео: "; play(); }
};

void mediaDemo() {
    printHeader("Задание 6: Медиа");
    vector<Media*> media = {
        new Audio(),
        new Video()
    };
    
    for (auto m : media) {
        m->info();
        delete m;
    }
}

// 7. Люди
class Person {
public:
    virtual void introduce() const = 0;
    virtual void info() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
public:
    void introduce() const override { cout << "Я студент" << endl; }
    void info() const override { cout << "Студент: "; introduce(); }
};

class Teacher : public Person {
public:
    void introduce() const override { cout << "Я учитель" << endl; }
    void info() const override { cout << "Учитель: "; introduce(); }
};

void personDemo() {
    printHeader("Задание 7: Люди");
    vector<Person*> people = {
        new Student(),
        new Teacher()
    };
    
    for (auto p : people) {
        p->info();
        delete p;
    }
}

// 8. Книги
class Book {
public:
    virtual void getInfo() const = 0;
    virtual void printFullInfo() const = 0;
    virtual ~Book() {}
};

class EBook : public Book {
public:
    void getInfo() const override { cout << "Электронная книга" << endl; }
    void printFullInfo() const override { 
        cout << "Тип: "; getInfo(); 
        cout << "Формат: PDF/EPUB" << endl;
    }
};

class PrintedBook : public Book {
public:
    void getInfo() const override { cout << "Печатная книга" << endl; }
    void printFullInfo() const override { 
        cout << "Тип: "; getInfo(); 
        cout << "Материал: Бумага" << endl;
    }
};

void bookDemo() {
    printHeader("Задание 8: Книги");
    vector<Book*> books = {
        new EBook(),
        new PrintedBook()
    };
    
    for (auto b : books) {
        b->printFullInfo();
        delete b;
    }
}

// 9. Бытовая техника
class Appliance {
public:
    virtual void turnOn() const = 0;
    virtual void info() const = 0;
    virtual ~Appliance() {}
};

class WashingMachine : public Appliance {
public:
    void turnOn() const override { cout << "Стиральная машина запущена" << endl; }
    void info() const override { 
        cout << "Стиральная машина: "; 
        turnOn();
        cout << "Функции: стирка, отжим" << endl;
    }
};

class Refrigerator : public Appliance {
public:
    void turnOn() const override { cout << "Холодильник охлаждает" << endl; }
    void info() const override { 
        cout << "Холодильник: "; 
        turnOn();
        cout << "Функции: охлаждение, заморозка" << endl;
    }
};

void applianceDemo() {
    printHeader("Задание 9: Бытовая техника");
    vector<Appliance*> appliances = {
        new WashingMachine(),
        new Refrigerator()
    };
    
    for (auto a : appliances) {
        a->info();
        delete a;
    }
}

// 10. Игры
class Game {
public:
    virtual void play() const = 0;
    virtual void gameInfo() const = 0;
    virtual ~Game() {}
};

class BoardGame : public Game {
public:
    void play() const override { cout << "Играем в настольную игру" << endl; }
    void gameInfo() const override { 
        cout << "Настольная игра: "; 
        play();
        cout << "Пример: Монополия, Шахматы" << endl;
    }
};

class VideoGame : public Game {
public:
    void play() const override { cout << "Играем в видеоигру" << endl; }
    void gameInfo() const override { 
        cout << "Видеоигра: "; 
        play();
        cout << "Платформы: PC, консоли" << endl;
    }
};

void gameDemo() {
    printHeader("Задание 10: Игры");
    vector<Game*> games = {
        new BoardGame(),
        new VideoGame()
    };
    
    for (auto g : games) {
        g->gameInfo();
        delete g;
    }
}

int main() {
    cout << "=== Демонстрация полиморфизма ===" << endl;
    shapeDemo();
    animalDemo();
    employeeDemo();
    vehicleDemo();
    accountDemo();
    mediaDemo();
    personDemo();
    bookDemo();
    applianceDemo();
    gameDemo();
    
    cout << "\n=== Все демонстрации завершены ===" << endl;
    return 0;
}