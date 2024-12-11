#include <iostream>
using namespace std;

void welcome()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №5" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Увести з клавіатури натуральне число n. Знайти суму його цифр, "
          "використовуючи рекурентне означення функції f(n):"
       << endl;
  cout << "            {a, b = Ka" << endl;
  cout << "GCD(a, b) = {b, a = Kb" << endl;
  cout << "            {GCD(a, b mod a), b >= a}" << endl;
  cout << "            {GCD(b, a mod b), b < a}" << endl;
  cout << "---------------------------------------" << endl;
}

int gcd_recursive(int a, int b, int &callCount)
{
  callCount++;
  if (b == 0)
  {
    return a;
  }
  return gcd_recursive(b, a % b, callCount);
}

int gcd_iterative(int a, int b, int &iterations)
{
  while (b != 0)
  {
    int temp = a % b;
    a = b;
    b = temp;
    iterations++;
  }
  return a;
}

void input()
{
  int m, n;
  cout << "Введіть два натуральних числа: ";
  cin >> m >> n;

  int callCount = 0;
  int gcdRec = gcd_recursive(m, n, callCount);
  cout << "НСД (рекурсивно): " << gcdRec
       << ", Кількість викликів: " << callCount << endl;

  int iterations = 0;
  int gcdIter = gcd_iterative(m, n, iterations);
  cout << "НСД (ітеративно): " << gcdIter
       << ", Кількість ітерацій: " << iterations << endl;
}

int main()
{
  welcome();
  input();
  return 0;
}
