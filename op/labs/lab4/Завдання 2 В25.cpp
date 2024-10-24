#include <iostream>
using namespace std;

bool isValidInput(int &x)
{
  if (cin >> x)
  {
    return true;
  }
  cin >> ws;
  return false;
}

double computeContinuedFraction(int n)
{
  double result = 0.0;

  for (int i = 2 * n + 1; i >= 1; i -= 2)
  {
    result = i + 1.0 / result;
  }

  return result;
}

int main()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №4" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Обчислити скінчений ланцюговий дріб, задавши значення n з клавіатури"
       << endl;
  cout << "1+ 1/ 3+ 1/ ... 2n-1/ 1/ 2n+1" << endl;
  cout << "---------------------------------------" << endl;

  int n;

  cout << "Enter the value of n: ";
  cin >> n;
  while (!isValidInput(n))
  {
    cout << "Помилка ввода! Будьласка, введіть коректне число для n: ";
  }

  double result = computeContinuedFraction(n);
  cout << "The result of the continued fraction is: " << result << endl;

  return 0;
}
