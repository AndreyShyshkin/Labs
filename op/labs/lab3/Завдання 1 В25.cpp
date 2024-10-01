#include <cmath>
#include <iomanip>
#include <iostream>

double factorial(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return n * factorial(n - 1);
}

double power(double base, int exp)
{
  if (exp == 0)
    return 1;
  if (exp < 0)
    return 1 / power(base, -exp);
  return base * power(base, exp - 1);
}

int main()
{
  double epsilon, total_sum = 0;
  std::cout << "Enter the precision (e.g., 1e-6): ";
  std::cin >> epsilon;

  std::cout << std::setw(10) << "x" << std::setw(10) << "k" << std::setw(20)
            << "Term" << std::setw(20) << "Sum" << std::endl;

  for (int x = 1; x <= 5; ++x)
  {
    double x_sum = 0;
    int k = 0;
    double term;

    do
    {
      term = power(-1, k + 1) * power(x, 2 * k - 1) / factorial(2 * k);

      if (std::abs(term) < 1e-38 || std::abs(term) > 1e38)
      {
        break;
      }

      x_sum += term;

      std::cout << std::setw(10) << x << std::setw(10) << k << std::setw(20)
                << std::scientific << std::setprecision(10) << term
                << std::setw(20) << x_sum << std::endl;

      k++;
    } while (std::abs(term) > epsilon);

    total_sum += x_sum;
  }

  std::cout << "\nTotal sum: " << std::scientific << std::setprecision(10)
            << total_sum << std::endl;

  return 0;
}
