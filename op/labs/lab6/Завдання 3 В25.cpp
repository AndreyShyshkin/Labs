#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

void nameOfAuthor()
{
  cout << "---------------------------------------\n"
       << "Лабораторная работа №6\n"
       << "Студент: Шишкин Андрей Антонович, ИПЗ-11, Вариант 25\n"
       << "Увести координати вектора X=(x, y, z) в тривимірному просторі. "
          "Визначити розкладання вектора X по векторах a=(a1, a2, a3), b=(b1, "
          "b2, b3, c=(c1, c2, c3), координати яких генерувати або задавати з "
          "клавіатури. [3.1]"
       << endl;
  cout << "Контрольний тест : при X = (-4; 4; 4), a = (3; 1; 0), b = (-1; 0; "
          "6), c = (-1; 2; 0) отримали розкладання :"
       << endl;
  cout << "x = -(8/21)a + (2/3)b + (46/21)c " << endl;
  cout << "Вивести на екран вирази за прикладом контрольного тесту." << endl;
  cout << "---------------------------------------" << endl;
}

void inputVector(double vec[3], const string &name)
{
  cout << "Введите координаты вектора " << name << " (x y z): ";
  cin >> vec[0] >> vec[1] >> vec[2];
}

void generateVector(double vec[3], const string &name, double minValue = -10.0,
                    double maxValue = 10.0)
{
  for (int i = 0; i < 3; ++i)
  {
    vec[i] = minValue +
             static_cast<double>(rand()) / RAND_MAX * (maxValue - minValue);
  }
  cout << "Сгенерирован вектор " << name << ": (" << vec[0] << ", " << vec[1]
       << ", " << vec[2] << ")" << endl;
}

void printVector(const double vec[3], const string &name)
{
  cout << name << " = (" << vec[0] << "; " << vec[1] << "; " << vec[2] << ")"
       << endl;
}

double determinant(const double mat[3][3])
{
  double det = 0.0;
  int sign = 1;

  for (int col = 0; col < 3; ++col)
  {
    double minor = mat[1][(col + 1) % 3] * mat[2][(col + 2) % 3] -
                   mat[1][(col + 2) % 3] * mat[2][(col + 1) % 3];
    det += sign * mat[0][col] * minor;
    sign = -sign;
  }

  return det;
}

bool solveCramer(const double a[3], const double b[3], const double c[3],
                 const double X[3], double &alpha, double &beta, double &gamma)
{
  double mat[3][3] = {
      {a[0], b[0], c[0]}, {a[1], b[1], c[1]}, {a[2], b[2], c[2]}};
  double det = determinant(mat);

  if (det == 0)
  {
    return false;
  }

  double mat_alpha[3][3] = {
      {X[0], b[0], c[0]}, {X[1], b[1], c[1]}, {X[2], b[2], c[2]}};
  double mat_beta[3][3] = {
      {a[0], X[0], c[0]}, {a[1], X[1], c[1]}, {a[2], X[2], c[2]}};
  double mat_gamma[3][3] = {
      {a[0], b[0], X[0]}, {a[1], b[1], X[1]}, {a[2], b[2], X[2]}};

  alpha = determinant(mat_alpha) / det;
  beta = determinant(mat_beta) / det;
  gamma = determinant(mat_gamma) / det;

  return true;
}

void setupVectors(double a[3], double b[3], double c[3])
{
  int choice;
  cout << "Выберите способ задания векторов a, b, c:\n"
       << "1. Ввод с клавиатуры\n"
       << "2. Генерация случайных чисел\n"
       << "Ваш выбор: ";
  cin >> choice;

  if (choice == 1)
  {
    inputVector(a, "a");
    inputVector(b, "b");
    inputVector(c, "c");
  }
  else if (choice == 2)
  {
    generateVector(a, "a");
    generateVector(b, "b");
    generateVector(c, "c");
  }
  else
  {
    cerr << "Некорректный выбор! Завершение программы." << endl;
    exit(1);
  }
}

void decomposeVector(const double X[3], const double a[3], const double b[3],
                     const double c[3])
{
  double alpha, beta, gamma;
  if (!solveCramer(a, b, c, X, alpha, beta, gamma))
  {
    cerr << "\nСистема уравнений не имеет единственного решения. Векторы a, b, "
            "c могут быть линейно зависимыми."
         << endl;
    exit(1);
  }

  cout << "\nРазложение вектора X по векторам a, b, c:" << endl;
  cout << fixed << setprecision(3);
  cout << "X = " << alpha << " * a + " << beta << " * b + " << gamma << " * c"
       << endl;

  double X_calc[3] = {alpha * a[0] + beta * b[0] + gamma * c[0],
                      alpha * a[1] + beta * b[1] + gamma * c[1],
                      alpha * a[2] + beta * b[2] + gamma * c[2]};

  cout << "\nПроверка разложения:" << endl;
  printVector(X_calc, "αa + βb + γc");
}

int main()
{
  srand(static_cast<unsigned int>(time(0)));

  nameOfAuthor();

  double X[3];
  cout << "Введите координаты вектора X:" << endl;
  inputVector(X, "X");

  double a[3], b[3], c[3];
  setupVectors(a, b, c);

  cout << "\nВходные данные:" << endl;
  printVector(X, "X");
  printVector(a, "a");
  printVector(b, "b");
  printVector(c, "c");

  decomposeVector(X, a, b, c);

  return 0;
}
