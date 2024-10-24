#include <cfloat>
#include <iomanip>
#include <iostream>
using namespace std;

int x;
int k;
float sum = 0;
float accuracy;

void welcome()
{
  cout << "Lab work 3, var 25(3), developer Shyshkin Andrii, gr. IPZ-11.1"
       << endl;
  cout << "=====================================" << endl;
  cout << "To calculate the sum of row" << endl;
  cout << "external sum for x from 1 to 5" << endl;
  cout << "internal sum for k from 0 to inf" << endl;
  cout << "=====================================" << endl;
  cout << "  5      ∞                           " << endl;
  cout << " ___    ___         k + 1    (2k - 1)" << endl;
  cout << " ╲      ╲      (-1)         x        " << endl;
  cout << " ╱      ╱    = ──────────────────────" << endl;
  cout << " ‾‾‾    ‾‾‾          (2k - 1)k!      " << endl;
  cout << "x = 1  k = 0                         " << endl;
}

void displaySum(float member)
{
  cout << setw(5) << x << setw(5) << k << setw(15) << member << setw(15) << sum
       << endl;
}

void calcMemberAndSum()
{
  for (x = 1; x <= 5; x++)
  {
    k = 0;

    double xStep = 1.0f / x;
    double kStep = -1.0f;
    double denominatorBrackets = (2.0f * k - 1.0f);
    double kFactorial = 1.0f;
    double numerator = (kStep * xStep);
    double denominator = denominatorBrackets * kFactorial;
    float member = (numerator / denominator);
    sum += member;
    displaySum(member);
    do
    {
      k++;
      xStep *= (x * x);
      kStep = (k % 2 == 0) ? -1.0f : 1.0f;
      numerator = (kStep * xStep);
      denominatorBrackets = (2.0f * k - 1.0f);
      kFactorial *= k;
      denominator = denominatorBrackets * kFactorial;
      member = (numerator / denominator);
      sum += member;
      if (fabs(member) < FLT_MIN || fabs(member) > FLT_MAX)
      {
        cout << "overflow float member - break cycle with k" << endl;
        cout << "member = " << member << endl;
        break;
      }
      displaySum(member);
    } while (fabs(member) > accuracy);
    cout << "=====================================" << endl;
  }
}

int main()
{
  welcome();
  bool answer = 0;
  do
  {
    cout << "=====================================" << endl;
    cout << "Enter the accuracy of the calculation: " << endl;
    cin >> accuracy;
    cout << "Result of iterations:" << endl;
    cout << "=====================================" << endl;
    cout << "    x      k        member        sum" << endl;
    cout << "=====================================" << endl;
    calcMemberAndSum();
    cout << "Sum = " << sum << endl;
    cout << "Do you want to continue? Yes = 1, No = 0" << endl;
    cin >> answer;
  } while (answer != 0);

  return 0;
}
