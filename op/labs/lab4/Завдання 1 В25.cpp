#include <cmath>
#include <iostream>
using namespace std;

void NameOfAuthor()
{

    cout << "---------------------------------------" << endl;
    cout << "Лабораторна робота №4" << endl;
    cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
    cout << "Обчислити значення функції у, розвинувши функцію cos(x) у ряд Тейлора. Визначити похибку обчислення"
         << endl;
    cout << "{cos(x/2)/cos(x^2), -1<=x <0 \ny ={ \n   {cos(x/2)^2 * cos(2*x), x>0." << endl;
    cout << "---------------------------------------" << endl;
}
double TailorCos(double x, double precision)
{
    double sum = 1;
    double term = 1;
    double n = 1;

    while (fabs(term) > precision)
    {
        term *= -x * x / (n * (n + 1));
        sum += term;
        n += 2;
    }

    return sum;
}

int main()
{
    NameOfAuthor();
    double precision;
    double x;
    double step;
    cout << "Введіть точність " << endl;
    cin >> precision;
    cout << " Введіть значення для х (бажано вводити значенння між -2 та 2, бо тільки на цьому проміжку вона існує "
         << endl;
    cin >> x;
    cout << "Введіть крок" << endl;
    cin >> step;
    cout << "========================================================================================================"
         << endl;
    cout << "X                                Y            True                                         mistake      "
         << endl;
    if (x < -2 || x > 2)
    {
        cout << "помилка значення" << endl;
    }
    else
    {
        double answer = 0;
        do
        {
            if (-1 <= x < 0)
            {
                //{cos(x/2)/cos(x^2)
                answer = TailorCos(x / 2, precision) / TailorCos(x * x, precision);
            }
            else if (x > 0)
            {
                //{cos(x/2)^2 * cos(2*x)
                answer = TailorCos(x / 2, precision) * TailorCos(x / 2, precision) * TailorCos(2 * x, precision);
            }

            double TrueValue = 0;

            if (-1 <= x < 0)
            {
                TrueValue = cos(x / 2) / cos(pow(x, 2));
            }
            else if (x > 0)
            {
                TrueValue = pow(cos(x / 2), 2) * cos(2 * x);
            }

            double mistake = TrueValue - answer;

            cout << x << "                                " << answer << "             " << TrueValue
                 << "                                          " << mistake << "      " << endl;
            x += step;
        } while (x <= 2);
    }
    cout << "=========================================================================================================="
            "=="
         << endl;
}
