
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;
bool isValidInput(float &x)
{
  if (cin >> x)
  {
    return true;
  }
  cin >> ws;
  return false;
}
float pow(int x, int n)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 1 / pow(x, -n);
  return x * pow(x, n - 1);
}
// Функція для розкладу косинуса у ряд Тейлора
double cos_taylor(double x, int terms)
{
  double result = 1;
  double term = 1;
  for (int n = 1; n < terms; n++)
  {
    term *= -x * x / (2 * n * (2 * n - 1));
    result += term;
  }
  return result;
}

// Функція для обчислення y(x) згідно з умовами
double calculate_y(double x, int terms)
{
  if (x >= -1 && x <= 0)
  {
    return cos_taylor(x / 2, terms) / cos_taylor(x * x, terms);
  }
  else
  {
    return pow(cos_taylor(x / 2, terms), 2) * cos_taylor(2 * x, terms);
  }
}

// Основна програма
int main()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №4" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Обчислити значення функції у, розвинувши функцію cos(x) у ряд "
       << endl;
  cout << "Тейлора. Визначити похибку обчислення" << endl;
  cout << "Y= {cos(x/2)/cos(x^2),   -1<=x<=0," << endl;
  cout << "   {cos^2(x/2)*cos(2*x), x>0" << endl;
  cout << "---------------------------------------" << endl;

  // Введення значення x
  double x;
  int terms;
  cout << "Введіть значення x: ";
  cin >> x;
  cout << "Введіть кількість членів ряду Тейлора: ";
  cin >> terms;

  // Обчислення значення y(x)
  double y_approx = calculate_y(x, terms);

  // Порівняння з реальним значенням через стандартну бібліотеку cos()
  double y_real;
  if (x >= -1 && x <= 0)
  {
    y_real = cos(x / 2) / cos(x * x);
  }
  else
  {
    y_real = pow(cos(x / 2), 2) * cos(2 * x);
  }

  // Виведення результатів
  cout << setprecision(10) << "Приблизне значення y(x): " << y_approx << endl;
  cout << "Точне значення y(x): " << y_real << endl;
  cout << "Похибка обчислення: " << fabs(y_real - y_approx) << endl;

  return 0;
}
