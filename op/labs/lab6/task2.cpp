
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

// Метод бульбашкового сортування
void bubbleSort(int arr[], int n, bool showIterations)
{
  int comparisons = 0, swaps = 0;

  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      comparisons++;
      if (arr[j] > arr[j + 1])
      {
        swaps++;
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }

    // Виведення проміжних результатів після кожної ітерації
    if (showIterations)
    {
      cout << "Ітерація " << i + 1 << ": ";
      printArray(arr, n);
    }
  }
  cout << "Кількість порівнянь при сортуванні: " << comparisons << endl;
  cout << "Кількість обмінів при сортуванні: " << swaps << endl;
}

// Лінійний пошук з підрахунком порівнянь
int linearSearch(const int arr[], int n, int target)
{
  int comparisons = 0;

  for (int i = 0; i < n; i++)
  {
    comparisons++;
    if (arr[i] == target)
    {
      cout << "Кількість порівнянь при пошуку: " << comparisons << endl;
      return i;
    }
  }

  cout << "Кількість порівнянь при пошуку: " << comparisons << endl;
  return -1;
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

  // Вибір режиму виведення результатів сортування
  bool showIterations;
  cout << "Виводити проміжні ітерації сортування? (1 - так, 0 - ні): ";
  cin >> showIterations;

  bubbleSort(arr, n, showIterations);

  cout << "Відсортований масив: ";
  printArray(arr, n);

  int target;
  cout << "Введіть значення для пошуку: ";
  cin >> target;

  int index = linearSearch(arr, n, target);
  if (index != -1)
  {
    cout << "Елемент знайдено на індексі: " << index << endl;
  }
  else
  {
    cout << "Елемент не знайдено." << endl;
  }

  return 0;
}
