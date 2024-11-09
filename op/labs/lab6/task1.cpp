#include <cstdlib> // для rand() і srand()
#include <ctime>   // для time()
#include <iostream>

using namespace std;

void createArrayFromInput(int arr[], int n)
{
  cout << "Введіть елементи масиву:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Елемент " << i + 1 << ": ";
    cin >> arr[i];
  }
}

void createArrayRandomly(int arr[], int n, int minValue = 0, int maxValue = 100)
{
  srand(time(0)); // ініціалізація генератора випадкових чисел
  for (int i = 0; i < n; i++)
  {
    arr[i] = minValue + rand() % (maxValue - minValue + 1);
  }
}

void printArray(const int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swapMinMax(int arr[], int n)
{
  if (n <= 1)
    return; // перевірка на наявність більше одного елемента

  int maxIndex = 0, minIndex = 0;

  // Знаходження мінімального та максимального елементів
  for (int i = 1; i < n; i++)
  {
    if (arr[i] > arr[maxIndex])
      maxIndex = i;
    if (arr[i] < arr[minIndex])
      minIndex = i;
  }

  // Виведення значень та індексів
  cout << "Максимальний елемент: " << arr[maxIndex] << " на індексі "
       << maxIndex << endl;
  cout << "Мінімальний елемент: " << arr[minIndex] << " на індексі " << minIndex
       << endl;

  // Заміна місцями
  int temp = arr[maxIndex];
  arr[maxIndex] = arr[minIndex];
  arr[minIndex] = temp;
}

int main()
{
  int n;
  cout << "Введіть кількість елементів масиву: ";
  cin >> n;

  if (n <= 0)
  {
    cout << "Невірна кількість елементів!" << endl;
    return 1;
  }

  int arr[n];

  int choice;
  cout << "Виберіть спосіб створення масиву:\n1. Введення з клавіатури\n2. "
          "Псевдовипадкові числа\nВаш вибір: ";
  cin >> choice;

  if (choice == 1)
  {
    createArrayFromInput(arr, n);
  }
  else if (choice == 2)
  {
    createArrayRandomly(arr, n);
  }
  else
  {
    cout << "Невірний вибір!" << endl;
    return 1;
  }

  cout << "Вхідний масив: ";
  printArray(arr, n);

  swapMinMax(arr, n);

  cout << "Вихідний масив: ";
  printArray(arr, n);

  return 0;
}
