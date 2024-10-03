#include <cfloat>
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

float factorial(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return n * factorial(n - 1);
}

float pow(int x, int n)
{
  if (n == 0)
    return 1;
  if (n < 0)
    return 1 / pow(x, -n);
  return x * pow(x, n - 1);
}

float Sigma(float precision)
{
  float overallSum = 0, sum = 0, member;

  cout << "==========================================================" << endl;
  cout << "     x     k               member               sum     " << endl;
  cout << "==========================================================" << endl;

  for (int x = 1; x <= 5; x++)
  {

    sum = 0;
    int k = 0;

    do
    {
      member =
          (pow(-1, k + 1) * pow(x, 2 * k - 1)) / ((2 * k - 1) * factorial(k));

      if (member != 0 && fabs(member) < FLT_MIN || member > FLT_MAX)
      {
        cout << "Переповнення — розрив циклу з k" << endl;
        break;
      }

      cout << setw(6) << x << setw(6) << k << setw(21) << member << setw(18)
           << sum << endl;

      sum += member;
      k++;

    } while (fabs(member) > precision);
    cout << "=========================================================="
         << endl;
  }
  return overallSum += sum;
}

int main()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №3" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Sigma x=1 to 5, Sigma k=0 to inf  ( pow(-1, k+1) * pow(x, 2 * k - "
          "1) ) / ( (2k - 1) * factorial(k) ) \n"
       << endl;
  cout << "---------------------------------------" << endl;

  float precision;

  cout << "Введіть бажане значення точності:" << endl;
  while (!isValidInput(precision))
  {
    cout << "Помилка ввода! Будьласка, введіть коректне число для a: ";
  }
  float result = Sigma(precision);

  cout << "Загальна сума: " << result << endl;
}
