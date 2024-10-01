#include <cmath> // бібліотека математичних функцій
#include <iomanip> // бібліотека для форматування виводу
#include <iostream> // бібліотека потоків вводу-виводу
#include <string>   // для роботи з рядками
using namespace std;

// функція для обчислення меншої діагоналі ромба
double calculatesmallerdiagonal(double perimeter) {
  // сторона ромба
  double side = perimeter / 4;

  // половина сторони (оскільки висота ділить сторону навпіл)
  double halfside = side / 2;

  // висота ромба (за теоремою піфагора)
  double height = sqrt(side * side - halfside * halfside);

  // менша діагональ (за властивістю ромба)
  double smallerdiagonal = 2 * height;

  return smallerdiagonal;
}

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

int main() // основна функція - точка входу до програми
{          // початок основної функції

  cout << "---------------------------------------"
       << endl; // виведення відомостей про
                // лабораторну роботу
  cout << "лабораторна робота №1" << endl;
  cout << "студент шишкін андрій антонович, іпз-11, варіант 25" << endl;
  cout << "завдання 1. написати програму, що розв'язує задачу з математики та "
          "фізики шкільногого курсу, відповідно до варіантів таблиці 1.8"
       << endl;
  cout << "висота ромба, проведена з вершини тупого кута, ділить сторону "
          "навпіл. знайдіть меншу діагональ, якщо значення периметра ромба "
          "введене з клавіатури."
       << endl;
  cout << "---------------------------------------" << endl;

  double perimeter;

  cout << "Bведіть периметр ромба: ";
  while (!isValidInput(perimeter))
  {
    cout << "Помилка ввода! Будьласка, введіть коректне число для периметрa ромба: ";
  }

  // обчислення меншої діагоналі
  double result = calculatesmallerdiagonal(perimeter);

  // виведення результату
  cout << "менша діагональ ромба: " << fixed << setprecision(2)
       << result << endl; // форматне виведення результату

  return 0; // завершення програми
}
