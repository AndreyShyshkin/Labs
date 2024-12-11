#include <ctime>
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

const int MAX_SIZE = 1000;
double matrix[MAX_SIZE];
double cofactor[MAX_SIZE];
double inverse[MAX_SIZE];
double minorArray[MAX_SIZE];
int n;

void nameOfAuthor()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №7" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Створити квадратну матрицю A, кількість рядків та стовпчиків m>=3 "
          "якої ввести з клавіатури. Передбачити меню вибору способу створення "
          "матриці: введення з клавіатури або генерація псевдовипадкових "
          "додатніх та від'ємних чисел. Знайти обернену матрицю за формулою"
       << endl;
  cout << "A^-1 = (A^T ↓ y)/det(A)" << endl;
  cout << ", використовуючи алгебраїчні доповнення елементів матриці" << endl;
  cout << "A↓ij = (-1)^i+j M↓ij" << endl;
  cout << "Вивести на екран вхідну, обернену матриці, значення визначника. "
          "Передбачити можливість виведення проміжних результатів "
          "(алгебраїчних доповнень) за вимогою користувача."
       << endl;
  cout << "---------------------------------------" << endl;
}

void printMatrix(const double *mat, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << setw(10) << mat[i * size + j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

int getDimension()
{
  cout << "Введіть розмірність матриці (m >= 3): ";
  cin >> n;

  if (n < 3)
  {
    throw runtime_error("Розмірність матриці повинна бути не менше 3!");
  }
  if (n * n > MAX_SIZE)
  {
    throw runtime_error("Перевищено допустимий розмір матриці!");
  }
  return n;
}

int getChoice()
{
  int choice;
  cout << "Оберіть спосіб заповнення матриці:\n";
  cout << "1. Введення з клавіатури\n";
  cout << "2. Заповнення псевдовипадковими числами\n";
  cout << "Ваш вибір: ";
  cin >> choice;

  if (choice != 1 && choice != 2)
  {
    throw runtime_error("Невірний вибір!");
  }
  return choice;
}

void fillMatrixManually(int size)
{
  cout << "Введіть елементи матриці:" << endl;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout << "matrix[" << i << "][" << j << "]: ";
      cin >> matrix[i * size + j];
    }
  }
}

void fillMatrixRandomly(int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      matrix[i * size + j] = rand() % 21 - 10;
    }
  }
}
double determinant(const double *mat, int size)
{
  if (size == 1)
    return mat[0];
  if (size == 2)
    return mat[0] * mat[3] - mat[1] * mat[2];

  double det = 0;
  for (int col = 0; col < size; col++)
  {
    int minorIndex = 0;
    for (int i = 1; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        if (j == col)
          continue;
        minorArray[minorIndex++] = mat[i * size + j];
      }
    }
    det +=
        (col % 2 == 0 ? 1 : -1) * mat[col] * determinant(minorArray, size - 1);
  }
  return det;
}

void cofactorMatrix(const double *mat, double *cofactor, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      int minorIndex = 0;
      for (int row = 0; row < size; row++)
      {
        for (int col = 0; col < size; col++)
        {
          if (row == i || col == j)
            continue;
          minorArray[minorIndex++] = mat[row * size + col];
        }
      }
      cofactor[i * size + j] =
          ((i + j) % 2 == 0 ? 1 : -1) * determinant(minorArray, size - 1);
    }
  }
}
void transpose(double *mat, int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      swap(mat[i * size + j], mat[j * size + i]);
    }
  }
}

void calculateInverseMatrix(const double *mat, double *inverse, int size,
                            double det)
{
  cofactorMatrix(mat, cofactor, size);
  transpose(cofactor, size);

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      inverse[i * size + j] = cofactor[i * size + j] / det;
    }
  }
}

void processMatrix()
{
  try
  {
    getDimension();
    int choice = getChoice();

    if (choice == 1)
    {
      fillMatrixManually(n);
    }
    else
    {
      fillMatrixRandomly(n);
    }

    cout << "Вхідна матриця:" << endl;
    printMatrix(matrix, n);

    double det = determinant(matrix, n);
    cout << "Визначник матриці: " << det << endl;

    if (det == 0)
    {
      throw runtime_error(
          "Оберненої матриці не існує, оскільки визначник дорівнює нулю.");
    }

    calculateInverseMatrix(matrix, inverse, n, det);

    cout << "Обернена матриця:" << endl;
    printMatrix(inverse, n);
  }
  catch (const exception &e)
  {
    cout << e.what() << endl;
  }
}

int main()
{
  nameOfAuthor();
  processMatrix();
}
