
#include <iostream>
using namespace std;

// Function to compute the continued fraction
double computeContinuedFraction(int n)
{
  double result = 0.0;

  // Start from the innermost fraction and work outward
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

  // Ask the user for the value of n
  cout << "Enter the value of n: ";
  cin >> n;

  // Compute and display the result of the continued fraction
  double result = computeContinuedFraction(n);
  cout << "The result of the continued fraction is: " << result << endl;

  return 0;
}
