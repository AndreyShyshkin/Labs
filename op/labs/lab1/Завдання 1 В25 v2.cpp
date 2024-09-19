#include <cmath> // бібліотека математичних функцій
#include <iostream> // бібліотека потоків вводу-виводу
#include <string>   // для роботи з рядками
using namespace std;

double inputValid(const string &prompt) {
  string input;
  double value;
  bool validInput = false;

  do {
    cout << prompt;
    cin >> input; // Читаємо введення як рядок

    try {
      value = stod(input); // Пробуємо перетворити рядок у число
      validInput = true; // Якщо вдалося, вводимо число
    } catch (invalid_argument &) {
      cout << "Помилка: можна ввести тільки число. Спробуйте ще раз.\n";
    }

  } while (!validInput);

  return value;
}

int main() {
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №1" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Завдання 1. За даними, що введені з клавіатури в оперативну "
          "пам’ять, визначити значення виразу, використовуючи математичні "
          "функції, і вивести результат на екран. Вираз вибрати згідно з "
          "варіантом 25. Довільні значення змінних A,B,C,D ввести з клавіатури."
       << endl;
  cout << "X=sin^3 C Cos^2 A / (e^A + 1 + SinB)" << endl;
  cout << "---------------------------------------" << endl;

  // Введення значень змінних
  double A = inputValid("Введіть значення A: ");
  double B = inputValid("Введіть значення B: ");
  double C = inputValid("Введіть значення C: ");

  // Обчислення виразу
  double X = pow(sin(C), 3) * pow(cos(A), 2) / (exp(A) + 1 + sin(B));

  // Виведення результату
  cout << "Результат обчислення X = " << X << std::endl;

  return 0;
}
