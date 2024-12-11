#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int arr[MAX_SIZE];
int n;

void nameOfAuthor()
{
  cout << "---------------------------------------\n"
       << "Лабораторна робота №6\n"
       << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25\n"
       << "Створити одновимірний масив, вибрати спосіб створення масиву:\n"
       << "1) Введення з клавіатури\n"
       << "2) Генерація псевдовипадкових чисел.\n"
       << "Відсортувати масив (бульбашкове сортування) та здійснити пошук\n"
       << "ітераційним лінійним пошуком з виведенням проміжних результатів.\n"
       << "---------------------------------------\n";
}

void createArrayFromInput()
{
  cout << "Введіть елементи масиву:\n";
  for (int i = 0; i < n; ++i)
  {
    cout << "Елемент " << i + 1 << ": ";
    cin >> arr[i];
  }
}

// stackoverflow
void createArrayRandomly(int minValue = 0, int maxValue = 100)
{
  srand(static_cast<unsigned>(time(nullptr)));
  for (int i = 0; i < n; ++i)
  {
    arr[i] = minValue + rand() % (maxValue - minValue + 1);
  }
}

void printArray()
{
  for (int i = 0; i < n; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

// stackoverflow
void bubbleSort(bool showIterations)
{
  int comparisons = 0, swaps = 0;

  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = 0; j < n - i - 1; ++j)
    {
      ++comparisons;
      if (arr[j] > arr[j + 1])
      {
        ++swaps;
        swap(arr[j], arr[j + 1]);
      }
    }
    if (showIterations)
    {
      cout << "Ітерація " << i + 1 << ": ";
      printArray();
    }
  }
  cout << "Кількість порівнянь: " << comparisons << "\n"
       << "Кількість обмінів: " << swaps << endl;
}

int linearSearch(int target)
{
  int comparisons = 0;
  for (int i = 0; i < n; ++i)
  {
    ++comparisons;
    if (arr[i] == target)
    {
      cout << "Кількість порівнянь при пошуку: " << comparisons << endl;
      return i;
    }
  }
  cout << "Кількість порівнянь при пошуку: " << comparisons << endl;
  return -1;
}

void initializeArray()
{
  int choice;
  cout << "Виберіть спосіб створення масиву:\n1. Введення з клавіатури\n2. "
          "Псевдовипадкові числа\nВаш вибір: ";
  cin >> choice;

  if (choice == 1)
  {
    createArrayFromInput();
  }
  else if (choice == 2)
  {
    createArrayRandomly();
  }
  else
  {
    cout << "Невірний вибір! Завершення програми.\n";
    exit(1);
  }
}

void sortAndDisplay()
{
  bool showIterations;
  cout << "Виводити проміжні ітерації сортування? (1 - так, 0 - ні): ";
  cin >> showIterations;
  bubbleSort(showIterations);
  cout << "Відсортований масив: ";
  printArray();
}

void searchAndDisplay()
{
  bool continueSearch = true;

  while (continueSearch)
  {
    int target;
    cout << "Введіть значення для пошуку (або -1 для виходу): ";
    cin >> target;

    if (target == -1)
    {
      cout << "Вихід із програми." << endl;
      continueSearch = false;
    }
    else
    {
      int index = linearSearch(target);
      if (index != -1)
      {
        cout << "Елемент знайдено на індексі: " << index << endl;
      }
      else
      {
        cout << "Елемент не знайдено." << endl;
      }
    }
  }
}

int main()
{
    nameOfAuthor();

  cout << "Введіть кількість елементів масиву (від 1 до " << MAX_SIZE << "): ";

  while (!(cin >> n) || n <= 0 || n > MAX_SIZE)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Помилка ввода! Будьласка, введіть коректне кількість елементів "
            "масиву: ";
  }

  initializeArray();
  cout << "Вхідний масив: ";
  printArray();

  sortAndDisplay();
  searchAndDisplay();

  return 0;
}
