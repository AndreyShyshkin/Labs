
#include <cstdlib> // для rand() і srand()
#include <ctime>   // для time()
#include <iostream>

using namespace std;

// Функція для введення координат вектора з клавіатури
void inputVector(double vec[3], const string &name)
{
  cout << "Введіть координати вектора " << name << " (x y z): ";
  cin >> vec[0] >> vec[1] >> vec[2];
}

// Функція для генерації вектора псевдовипадковими числами
void generateVector(double vec[3], const string &name, double minValue = -10.0,
                    double maxValue = 10.0)
{
  for (int i = 0; i < 3; i++)
  {
    vec[i] = minValue +
             static_cast<double>(rand()) / RAND_MAX * (maxValue - minValue);
  }
  cout << "Згенеровано вектор " << name << ": (" << vec[0] << ", " << vec[1]
       << ", " << vec[2] << ")" << endl;
}

// Функція для виведення вектора
void printVector(const double vec[3], const string &name)
{
  cout << name << " = (" << vec[0] << "; " << vec[1] << "; " << vec[2] << ")"
       << endl;
}

// Функція для обчислення детермінанту 3x3 матриці
double determinant(double mat[3][3])
{
  return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]) -
         mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0]) +
         mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
}

// Функція для розв'язання системи рівнянь методом Крамера
bool solveCramer(double a[3], double b[3], double c[3], double X[3],
                 double &alpha, double &beta, double &gamma)
{
  double mat[3][3] = {
      {a[0], b[0], c[0]}, {a[1], b[1], c[1]}, {a[2], b[2], c[2]}};

  double det = determinant(mat);
  if (det == 0)
  {
    return false; // Система не має єдиного розв'язку
  }

  // Матриці для α, β, γ
  double mat_alpha[3][3] = {
      {X[0], b[0], c[0]}, {X[1], b[1], c[1]}, {X[2], b[2], c[2]}};

  double mat_beta[3][3] = {
      {a[0], X[0], c[0]}, {a[1], X[1], c[1]}, {a[2], X[2], c[2]}};

  double mat_gamma[3][3] = {
      {a[0], b[0], X[0]}, {a[1], b[1], X[1]}, {a[2], b[2], X[2]}};

  double det_alpha = determinant(mat_alpha);
  double det_beta = determinant(mat_beta);
  double det_gamma = determinant(mat_gamma);

  alpha = det_alpha / det;
  beta = det_beta / det;
  gamma = det_gamma / det;

  return true;
}

int main()
{
  srand(static_cast<unsigned int>(
      time(0))); // Ініціалізація генератора випадкових чисел

  double X[3];
  cout << "Введення координат вектора X:" << endl;
  inputVector(X, "X");

  // Вибір способу створення векторів a, b, c
  int choice;
  cout << "Виберіть спосіб створення векторів a, b, c:\n1. Введення з "
          "клавіатури\n2. Псевдовипадкові числа\nВаш вибір: ";
  cin >> choice;

  double a[3], b[3], c_vec[3];

  if (choice == 1)
  {
    cout << "Введення координат вектора a:" << endl;
    inputVector(a, "a");
    cout << "Введення координат вектора b:" << endl;
    inputVector(b, "b");
    cout << "Введення координат вектора c:" << endl;
    inputVector(c_vec, "c");
  }
  else if (choice == 2)
  {
    generateVector(a, "a");
    generateVector(b, "b");
    generateVector(c_vec, "c");
  }
  else
  {
    cout << "Невірний вибір!" << endl;
    return 1;
  }

  // Виведення вхідних векторів
  cout << "\nВхідні вектори:" << endl;
  printVector(X, "X");
  printVector(a, "a");
  printVector(b, "b");
  printVector(c_vec, "c");

  // Розв'язання системи для знаходження α, β, γ
  double alpha, beta, gamma;
  bool solvable = solveCramer(a, b, c_vec, X, alpha, beta, gamma);

  if (!solvable)
  {
    cout << "\nСистема рівнянь не має єдиного розв'язку. Вектори a, b, c "
            "можуть бути лінійно залежними."
         << endl;
    return 1;
  }

  // Виведення результату розкладання
  cout << "\nРозкладання вектора X по векторах a, b, c:" << endl;
  cout << "X = " << alpha << " * a + " << beta << " * b + " << gamma << " * c"
       << endl;

  // Перевірка результату
  double X_calc[3] = {alpha * a[0] + beta * b[0] + gamma * c_vec[0],
                      alpha * a[1] + beta * b[1] + gamma * c_vec[1],
                      alpha * a[2] + beta * b[2] + gamma * c_vec[2]};

  cout << "Перевірка розкладання:" << endl;
  printVector(X_calc, "αa + βb + γc");
  return 0;
}
