#include <iostream>
using namespace std;

double f(double a, double b)
{
    if (b == 0) return 0;
    if (a > b) return (a * a) / (b * b);
    if (a < b) return (b * b) - (a * a);
    return 1;
}

// Функция для проверки правильности ввода
bool isValidInput(double &x) 
{
    if (cin >> x) 
    {
        return true;
    }
    cin.clear();
    cin.ignore();
    return false;
}

int main() 
{
    cout << "---------------------------------------" << endl;
    cout << "Лабораторна робота №2" << endl;
    cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
    cout << "Завдання 1. Визначити значення функції в залежності від значення її аргументу, яке вводиться з клавіатури."
        << endl;
    cout << "F(x)={(0, b=0), (a^2 / b^2, a > b), (b^2 - a^2, a < b), (1, a = b)}" << endl;
    cout << "---------------------------------------" << endl;

    double a, b;

    cout << "Введіть a: ";
    while (!isValidInput(a)) 
    {
        cout << "Помилка ввода! Будьласка, введіть коректне число для a: ";
    }

    cout << "Введіть b: ";
    while (!isValidInput(b)) 
    {
        cout << "Помилка ввода! Будьласка, введіть коректне число для b: ";
    }

    double result = f(a, b);
    cout << "Результат f(" << a << ", " << b << ") = " << result << endl;
}
