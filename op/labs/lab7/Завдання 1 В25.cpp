#include <ctime>
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int matrix[MAX_SIZE];
int n;

void nameOfAuthor()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №7" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Створити квадратну матрицю, розмірність якої n>=3 ввести з "
          "клавіатури. Передбачити меню вибору способу створення матриці: "
          "введення з клавіатури або генерація псевдовипадкових чисел. У "
          "створеній квадратній матриці знайти суму значень елементів, що "
          "розташовані на головній діагоналі або вище від неї і є більшими за "
          "всі елементи, розташовані нижче від головної діагоналі. Отриману "
          "суму елементів записати в якості елементів n+1 рядка та n+1 стовпця "
          "створеної раніше матриці. Передбачити контроль ситуації виходу за "
          "межі матриці виведенням відповідного повідомлення. Надрукувати "
          "вхідну матрицю у вигляді рядків і стовпчиків, шукану суму "
          "елементів, модифіковану матрицю."
       << endl;
  cout << "---------------------------------------" << endl;
}

void printMatrix(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << matrix[i * n + j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

int getDimension()
{
  cout << "Введіть розмірність матриці (n >= 3): ";
  while (!(cin >> n) || n < 3 || n * n > MAX_SIZE)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // stackoverflow

    cout << "Помилка ввода! Будьласка, введіть коректне розмірність матриці ";
  }
  return n;
}

int getChoice()
{
  int choice;
  cout << "Оберіть спосіб створення матриці:\n";
  cout << "1. Введення з клавіатури\n";
  cout << "2. Заповнення псевдовипадковими числами\n";
  cout << "Ваш вибір: ";
  while (!(cin >> choice) || (choice != 1 && choice != 2))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // stackoverflow

    cout << "Помилка ввода! Невірний вибір!";
  }
  return choice;
}

void fillMatrixManually(int n)
{
  cout << "Введіть елементи матриці:" << endl;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "matrix[" << i << "][" << j << "]: ";
      cin >> matrix[i * n + j];
    }
  }
}

// stackoverflow
void fillMatrixRandomly(int n)
{
  srand(time(0));
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      matrix[i * n + j] = rand() % 3;
    }
  }
}

int calculateSum(int n)
{
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    bool isGreater = true;
    for (int j = i + 1; j < n; j++)
    {
      if (matrix[i * n + i] <= matrix[j * n + j])
      {
        isGreater = false;
        break;
      }
    }
    if (isGreater)
      sum += matrix[i * n + i];
  }
  return sum;
}

void createModifiedMatrix(int n, int sum)
{
  for (int i = 0; i < n; i++)
  {
    matrix[i * n + n] = sum;
    matrix[n * n + i] = sum;
  }
  matrix[n * n + n] = sum;
}

void processMatrix()
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
  printMatrix(n);

  int sum = calculateSum(n);
  cout << "Сума елементів, що відповідає умовам: " << sum << endl;

  createModifiedMatrix(n, sum);
  cout << "Модифікована матриця:" << endl;
  printMatrix(n + 1);
}

int main()
{
  nameOfAuthor();
  processMatrix();
}
