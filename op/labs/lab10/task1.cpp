#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

void nameOfAuthor()
{
    cout << "---------------------------------------" << endl;
    cout << "Лабораторна робота №10" << endl;
    cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
    cout << "Створити масив структур. Кожна структура складається з таких елементів: місто, фірма, продукт, кількість продукту, ціна одиниці продукту, вартість продуктів. Реалізувати запити: "
            "визначити місцезнаходження фірми, що виробляє заданий продукт; "
            "визначити сумарну вартість продуктів, що виробляються у даному місті; "
            "упорядкувати список продуктів за ціною для даного міста. "
            "Результати запитів вивести у вигляді таблиць"
         << endl;
    cout << "---------------------------------------" << endl;
}

// Структура для зберігання інформації про продукт
struct Product
{
  char city[50];
  char company[50];
  char product[50];
  int quantity;
  double price;
  double total_cost;
};

// Прототипи функцій
void createProductArray(Product *arr, int &size);
void displayProductArray(Product *arr, int size);
void findCompanyByProduct(Product *arr, int size);
void calculateTotalCostByCity(Product *arr, int size);
void sortProductsByPrice(Product *arr, int size);

// Функція виведення меню
int displayMenu() {
    cout << "\nМеню:\n";
    cout << "1. Створити масив продуктів\n";
    cout << "2. Вивести масив продуктів\n";
    cout << "3. Знайти фірму за продуктом\n";
    cout << "4. Обчислити сумарну вартість продуктів у місті\n";
    cout << "5. Упорядкувати продукти за ціною\n";
    cout << "0. Вийти\n";
    cout << "Введіть вибір: ";
    
    int choice;
    cin >> choice;
    return choice;
}

// Функція обробки меню
void processMenu(Product *products, int &size) {
    int choice;
    do {
        choice = displayMenu();

        switch (choice) {
        case 1:
            createProductArray(products, size);
            break;
        case 2:
            displayProductArray(products, size);
            break;
        case 3:
            findCompanyByProduct(products, size);
            break;
        case 4:
            calculateTotalCostByCity(products, size);
            break;
        case 5:
            sortProductsByPrice(products, size);
            break;
        case 0:
            cout << "Завершення програми.\n";
            break;
        default:
            cout << "Невірний вибір. Спробуйте знову.\n";
        }
    } while (choice != 0);
}

int main() {
    nameOfAuthor();
    const int MAX_SIZE = 100;
    Product products[MAX_SIZE];
    int size = 0;

    srand(time(NULL));

    processMenu(products, size);

    return 0;
}

// Функція створення масиву продуктів
void createProductArray(Product *arr, int &size)
{
  cout << "Введіть кількість продуктів (макс. 100): ";
  cin >> size;

  for (int i = 0; i < size; i++)
  {
    cout << "Продукт " << i + 1 << ":\n";

    cout << "Місто: ";
    cin >> arr[i].city;

    cout << "Фірма: ";
    cin >> arr[i].company;

    cout << "Назва продукту: ";
    cin >> arr[i].product;

    cout << "Кількість: ";
    cin >> arr[i].quantity;

    cout << "Ціна за одиницю: ";
    cin >> arr[i].price;

    arr[i].total_cost = arr[i].quantity * arr[i].price;
  }
}

// Функція виведення масиву продуктів
void displayProductArray(Product *arr, int size)
{
  if (size == 0)
  {
    cout << "Масив порожній.\n";
    return;
  }

  cout << setw(5) << "№" << setw(15) << "Місто" << setw(15) << "Фірма"
       << setw(15) << "Продукт" << setw(10) << "Кількість" << setw(10) << "Ціна"
       << setw(15) << "Загальна вартість" << endl;

  for (int i = 0; i < size; i++)
  {
    cout << setw(5) << i + 1 << setw(15) << arr[i].city << setw(15)
         << arr[i].company << setw(15) << arr[i].product << setw(10)
         << arr[i].quantity << setw(10) << arr[i].price << setw(15)
         << arr[i].total_cost << endl;
  }
}

// Функція пошуку фірми за продуктом
void findCompanyByProduct(Product *arr, int size)
{
  char searchProduct[50];
  cout << "Введіть назву продукту: ";
  cin >> searchProduct;

  cout << setw(15) << "Фірма" << setw(15) << "Місто" << endl;

  bool found = false;
  for (int i = 0; i < size; i++)
  {
    if (strcmp(arr[i].product, searchProduct) == 0)
    {
      cout << setw(15) << arr[i].company << setw(15) << arr[i].city << endl;
      found = true;
    }
  }

  if (!found)
  {
    cout << "Продукт не знайдено.\n";
  }
}

// Функція обчислення сумарної вартості продуктів у місті
void calculateTotalCostByCity(Product *arr, int size)
{
  char searchCity[50];
  cout << "Введіть назву міста: ";
  cin >> searchCity;

  double totalCost = 0.0;
  for (int i = 0; i < size; i++)
  {
    if (strcmp(arr[i].city, searchCity) == 0)
    {
      totalCost += arr[i].total_cost;
    }
  }

  cout << "Сумарна вартість продуктів у місті " << searchCity << ": "
       << totalCost << endl;
}

// Функція сортування продуктів за ціною для міста
void sortProductsByPrice(Product *arr, int size)
{
  char searchCity[50];
  cout << "Введіть назву міста: ";
  cin >> searchCity;

  // Тимчасовий масив для фільтрації
  Product filteredArr[100];
  int filteredSize = 0;

  // Фільтрація за містом
  for (int i = 0; i < size; i++)
  {
    if (strcmp(arr[i].city, searchCity) == 0)
    {
      filteredArr[filteredSize++] = arr[i];
    }
  }

  // Сортування бульбашкою
  for (int i = 0; i < filteredSize - 1; i++)
  {
    for (int j = 0; j < filteredSize - i - 1; j++)
    {
      if (filteredArr[j].price > filteredArr[j + 1].price)
      {
        Product temp = filteredArr[j];
        filteredArr[j] = filteredArr[j + 1];
        filteredArr[j + 1] = temp;
      }
    }
  }

  // Виведення відсортованих продуктів
  cout << "Продукти міста " << searchCity << ", відсортовані за ціною:\n";
  displayProductArray(filteredArr, filteredSize);
}
