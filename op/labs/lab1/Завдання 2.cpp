#include <cmath>    // бібліотека математичних функцій
#include <iomanip>  // бібліотека для форматування виводу
#include <iostream> // бібліотека потоків вводу-виводу

// Функція для обчислення меншої діагоналі ромба
double calculateSmallerDiagonal(double perimeter) {
  // Сторона ромба
  double side = perimeter / 4;

  // Половина сторони (оскільки висота ділить сторону навпіл)
  double halfSide = side / 2;

  // Висота ромба (за теоремою Піфагора)
  double height = std::sqrt(side * side - halfSide * halfSide);

  // Менша діагональ (за властивістю ромба)
  double smallerDiagonal = 2 * height;

  return smallerDiagonal;
}

int main() // основна функція - точка входу до програми
{          // початок основної функції
  double perimeter;

  // Введення периметра з клавіатури
  std::cout << "Введіть периметр ромба: "; // вивід повідомлення на екран
  std::cin >> perimeter;                   // ввід значення з клавіатури

  // Обчислення меншої діагоналі
  double result = calculateSmallerDiagonal(perimeter);

  // Виведення результату
  std::cout << "Менша діагональ ромба: " << std::fixed << std::setprecision(2)
            << result << std::endl; // форматне виведення результату

  return 0; // завершення програми
}