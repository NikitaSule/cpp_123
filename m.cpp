#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm>

// ANSI escape codes for colors
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"

void printTaskHeader(int taskNumber, const std::string& description) {
    std::cout << COLOR_CYAN << "[ - - - " << COLOR_YELLOW << taskNumber << COLOR_CYAN << " - - - ]" 
              << COLOR_RESET << " " << COLOR_GREEN << description << COLOR_RESET << "\n";
}

// 1. Shape classes
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        if (r < 0) throw std::invalid_argument("Radius cannot be negative");
    }
    double area() const override { return 3.14159 * radius * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {
        if (w < 0 || h < 0) throw std::invalid_argument("Sides cannot be negative");
    }
    double area() const override { return width * height; }
};

// 2. Animal classes
class Animal {
public:
    virtual void speak() const = 0;
    virtual ~Animal() {}
};

class Dog : public Animal {
    std::string name;
public:
    Dog(const std::string& n) : name(n) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
    }
    void speak() const override { std::cout << "Woof! My name is " << name << std::endl; }
};

class Cat : public Animal {
    std::string name;
public:
    Cat(const std::string& n) : name(n) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
    }
    void speak() const override { std::cout << "Meow! My name is " << name << std::endl; }
};

// 3. BankAccount classes
class BankAccount {
protected:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    virtual void withdraw(double amount) {
        if (amount > balance) throw std::runtime_error("Insufficient balance");
        balance -= amount;
    }
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override {
        if (amount > 15000) throw std::runtime_error("Savings account withdrawal limit exceeded");
        BankAccount::withdraw(amount);
    }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(double b) : BankAccount(b) {}
    void withdraw(double amount) override {
        if (amount > 7500) throw std::runtime_error("Checking account withdrawal limit exceeded");
        BankAccount::withdraw(amount);
    }
};

// 4. FileHandler classes
class FileHandler {
public:
    virtual void open(const std::string& filename) = 0;
    virtual ~FileHandler() {}
};

class TextFileHandler : public FileHandler {
public:
    void open(const std::string& filename) override {
        std::ifstream file(filename);
        if (!file) throw std::runtime_error("Text file not found: " + filename);
        std::cout << "Text file opened: " << filename << std::endl;
    }
};

class BinaryFileHandler : public FileHandler {
public:
    void open(const std::string& filename) override {
        std::ifstream file(filename, std::ios::binary);
        if (!file) throw std::runtime_error("Binary file not found: " + filename);
        std::cout << "Binary file opened: " << filename << std::endl;
    }
};

// 5. DrawableShape classes
class DrawableShape {
public:
    virtual void draw() const = 0;
    virtual ~DrawableShape() {}
};

class Triangle : public DrawableShape {
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {
        if (a <= 0 || b <= 0 || c <= 0 || a + b <= c || a + c <= b || b + c <= a)
            throw std::invalid_argument("Invalid triangle sides");
    }
    void draw() const override { std::cout << "Drawing triangle with sides " << a << ", " << b << ", " << c << std::endl; }
};

class Square : public DrawableShape {
    double side;
public:
    Square(double s) : side(s) {
        if (s <= 0) throw std::invalid_argument("Square side must be positive");
    }
    void draw() const override { std::cout << "Drawing square with side " << side << std::endl; }
};

// 6. Person classes
class Person {
public:
    virtual void display() const = 0;
    virtual ~Person() {}
};

class Student : public Person {
    std::string name;
    int age;
public:
    Student(const std::string& n, int a) : name(n), age(a) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
        if (a < 6 || a > 25) throw std::invalid_argument("Invalid student age");
    }
    void display() const override {
        std::cout << "Student: " << name << ", Age: " << age << std::endl;
    }
};

class Teacher : public Person {
    std::string name;
    int age;
public:
    Teacher(const std::string& n, int a) : name(n), age(a) {
        if (n.empty()) throw std::invalid_argument("Name cannot be empty");
        if (a < 25 || a > 70) throw std::invalid_argument("Invalid teacher age");
    }
    void display() const override {
        std::cout << "Teacher: " << name << ", Age: " << age << std::endl;
    }
};

// 7. Calculator classes
class Calculator {
public:
    virtual double calculate(double a, double b) const = 0;
    virtual ~Calculator() {}
};

class Addition : public Calculator {
public:
    double calculate(double a, double b) const override { return a + b; }
};

class Division : public Calculator {
public:
    double calculate(double a, double b) const override {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
};

// 8. Game classes
class Game {
public:
    virtual void start() = 0;
    virtual ~Game() {}
};

class Chess : public Game {
public:
    void start() override {
        std::cout << "Chess game started" << std::endl;
    }
};

class Tennis : public Game {
    int players;
public:
    Tennis(int p) : players(p) {
        if (p != 2 && p != 4) throw std::invalid_argument("Tennis requires 2 or 4 players");
    }
    void start() override {
        std::cout << "Tennis game started with " << players << " players" << std::endl;
    }
};

// 9. Document classes
class Document {
public:
    virtual void save(const std::string& filename) = 0;
    virtual ~Document() {}
};

class PDFDocument : public Document {
public:
    void save(const std::string& filename) override {
        if (filename.empty()) throw std::runtime_error("Filename cannot be empty");
        size_t pos = filename.rfind('.');
        if (pos == std::string::npos || filename.substr(pos) != ".pdf")
            throw std::runtime_error("PDF filename must end with .pdf");
        std::cout << "PDF document saved as " << filename << std::endl;
    }
};

class WordDocument : public Document {
public:
    void save(const std::string& filename) override {
        if (filename.empty()) throw std::runtime_error("Filename cannot be empty");
        size_t pos = filename.rfind('.');
        if (pos == std::string::npos || filename.substr(pos) != ".docx")
            throw std::runtime_error("Word filename must end with .docx");
        std::cout << "Word document saved as " << filename << std::endl;
    }
};

// 10. Matrix classes
class Matrix {
protected:
    int rows, cols;
public:
    Matrix(int r, int c) : rows(r), cols(c) {}
    virtual double getElement(int r, int c) const = 0;
    virtual ~Matrix() {}
};

class IntMatrix : public Matrix {
    std::vector<std::vector<int>> data;
public:
    IntMatrix(int r, int c) : Matrix(r, c), data(r, std::vector<int>(c)) {}
    double getElement(int r, int c) const override {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("Matrix index out of range");
        return data[r][c];
    }
};

class FloatMatrix : public Matrix {
    std::vector<std::vector<float>> data;
public:
    FloatMatrix(int r, int c) : Matrix(r, c), data(r, std::vector<float>(c)) {}
    double getElement(int r, int c) const override {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("Matrix index out of range");
        return data[r][c];
    }
};

int main() {
    try {
        printTaskHeader(1, "Shape classes demonstration");
        Circle c(12.5);
        std::cout << "Circle area: " << c.area() << std::endl;
        Rectangle r(8.4, 6.3);
        std::cout << "Rectangle area: " << r.area() << std::endl;

        printTaskHeader(2, "Animal classes demonstration");
        Dog d("Buddy");
        d.speak();
        Cat cat("Whiskers");
        cat.speak();

        printTaskHeader(3, "BankAccount classes demonstration");
        SavingsAccount sa(20000);
        sa.withdraw(12000);
        CheckingAccount ca(10000);
        ca.withdraw(6000);

        printTaskHeader(4, "FileHandler classes demonstration");
        TextFileHandler tfh;
        tfh.open("test.txt");
        BinaryFileHandler bfh;
        bfh.open("data.bin");

        printTaskHeader(5, "DrawableShape classes demonstration");
        Triangle t(5, 6, 7);
        t.draw();
        Square s(4.2);
        s.draw();

        printTaskHeader(6, "Person classes demonstration");
        Student student("Alice", 20);
        student.display();
        Teacher teacher("Mr. Smith", 45);
        teacher.display();

        printTaskHeader(7, "Calculator classes demonstration");
        Addition add;
        std::cout << "15 + 7 = " << add.calculate(15, 7) << std::endl;
        Division div;
        std::cout << "100 / 4 = " << div.calculate(100, 4) << std::endl;

        printTaskHeader(8, "Game classes demonstration");
        Chess chess;
        chess.start();
        Tennis tennis(2);
        tennis.start();

        printTaskHeader(9, "Document classes demonstration");
        PDFDocument pdf;
        pdf.save("report.pdf");
        WordDocument word;
        word.save("essay.docx");

        printTaskHeader(10, "Matrix classes demonstration");
        IntMatrix im(5, 5);
        std::cout << "Matrix element: " << im.getElement(0, 0) << std::endl;
        FloatMatrix fm(3, 3);
        std::cout << "Matrix element: " << fm.getElement(0, 0) << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << COLOR_RED << "Error: " << e.what() << COLOR_RESET << std::endl;
    }

    return 0;
}