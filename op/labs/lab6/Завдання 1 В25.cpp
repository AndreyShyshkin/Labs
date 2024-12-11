#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;
int arr[MAX_SIZE];
int n;

void nameOfAuthor()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №6" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Створити одновимірний массив, кількість елементів якого ввести з "
          "клавіатури. Передбачити меню вибору способу створення масиву: "
          "введення з клавіатури або генерація псевдовипадкових чисел. У "
          "масиві поміняти місцями максимальний і мінімальний елементи. "
          "Надрукувати максимальний та мінімальний елементи, їх індекси, "
          "вхідний та вихідний масиви."
       << endl;
  cout << "---------------------------------------" << endl;
}

void getArraySize()
{
  cout << "Введіть кількість елементів масиву: (від 1 до " << MAX_SIZE << ") ";

  while (!(cin >> n) || n <= 0 || n > MAX_SIZE)
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // stackoverflow
    cout << "Помилка ввода! Будьласка, введіть коректне кількість елементів "
            "масиву: ";
  }
}

int getChoice()
{
  int choice;
  cout << "Виберіть спосіб створення масиву:\n"
       << "1. Введення з клавіатури\n"
       << "2. Псевдовипадкові числа\n"
       << "Ваш вибір: ";

  while (!(cin >> choice) || (choice != 1 && choice != 2))
  {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // stackoverflow
    cout << "Помилка ввода! Будьласка, введіть коректне число способу "
            "створення масиву: ";
  }
  return choice;
}

void createArrayFromInput()
{
  cout << "Введіть елементи масиву:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << "Елемент " << i + 1 << ": ";
    cin >> arr[i];
  }
}

void createArrayRandomly(int minValue = 0, int maxValue = 100)
{
  srand(static_cast<unsigned>(time(0)));
  for (int i = 0; i < n; i++)
  {
    arr[i] = minValue + rand() % (maxValue - minValue + 1);
  }
}

void printArray()
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swapMinMax()
{
  if (n <= 1)
    return;

  int maxIndex = 0, minIndex = 0;

  for (int i = 1; i < n; i++)
  {
    if (arr[i] > arr[maxIndex])
      maxIndex = i;
    if (arr[i] < arr[minIndex])
      minIndex = i;
  }

  cout << "Максимальний елемент: " << arr[maxIndex] << " на індексі "
       << maxIndex << endl;
  cout << "Мінімальний елемент: " << arr[minIndex] << " на індексі " << minIndex
       << endl;

  swap(arr[maxIndex], arr[minIndex]); // learn.microsoft
}

void processArray()
{
  getArraySize();

  int choice = getChoice();
  if (choice == 1)
  {
    createArrayFromInput();
  }
  else
  {
    createArrayRandomly();
  }

  cout << "Вхідний масив: ";
  printArray();

  swapMinMax();

  cout << "Вихідний масив: ";
  printArray();
}

int main()
{
  nameOfAuthor();
  processArray();
  return 0;
}
