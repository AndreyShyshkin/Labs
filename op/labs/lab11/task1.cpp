#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

void nameOfAuthor()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №11" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Створити текстовий файл, кожний рядок якого містить різні слова. "
          "Виконати такі дії: "
          "Знайти найкоротше слово в кожному рядку файлу, "
          "Переписати знайдені слова в новий текстовий файл, порахувавши їх "
          "кількість."
          "Записати останнім рядком нового файлу кількість слів у файлі. "
       << endl;
  cout << "---------------------------------------" << endl;
}

// Прототипи функцій
void createTextFile();
void displayFileContents();
void processFile();
void findShortestWords();

// Функція виведення меню
int displayMenu()
{
  cout << "\nМеню:\n";
  cout << "1. Створити текстовий файл\n";
  cout << "2. Вивести вміст файлу\n";
  cout << "3. Знайти найкоротші слова\n";
  cout << "0. Вийти\n";
  cout << "Введіть вибір: ";
  int choice;
  cin >> choice;
  return choice;
}

// Функція обробки меню
void processMenu()
{
  int choice;
  do
  {
    choice = displayMenu();

    switch (choice)
    {
    case 1:
      createTextFile();
      break;
    case 2:
      displayFileContents();
      break;
    case 3:
      findShortestWords();
      break;
    case 0:
      cout << "Завершення програми.\n";
      break;
    default:
      cout << "Невірний вибір. Спробуйте знову.\n";
    }
  } while (choice != 0);
}

// Головна функція
int main()
{
  nameOfAuthor();
  processMenu();
  return 0;
}

// Функція створення текстового файлу
void createTextFile()
{
  ofstream file("input.txt");

  if (!file.is_open())
  {
    cout << "Помилка відкриття файлу!\n";
    return;
  }

  char line[256];
  cin.ignore(); // Очищення буфера вводу

  cout << "Введіть рядки тексту (порожній рядок для завершення):\n";
  while (true)
  {
    cin.getline(line, sizeof(line));

    if (strlen(line) == 0)
    {
      break;
    }

    file << line << endl;
  }

  file.close();
  cout << "Файл створено успішно.\n";
}

// Функція виведення вмісту файлу
void displayFileContents()
{
  ifstream file("input.txt");

  if (!file.is_open())
  {
    cout << "Помилка відкриття файлу!\n";
    return;
  }

  char line[256];
  cout << "Вміст файлу:\n";

  while (file.getline(line, sizeof(line)))
  {
    cout << line << endl;
  }

  file.close();
}

// Функція знаходження найкоротших слів
void findShortestWords()
{
  ifstream inputFile("input.txt");
  ofstream outputFile("output.txt");

  if (!inputFile.is_open() || !outputFile.is_open())
  {
    cout << "Помилка відкриття файлу!\n";
    return;
  }

  char line[256];
  int totalWordCount = 0;

  while (inputFile.getline(line, sizeof(line)))
  {
    char *word = strtok(line, " ");
    char *shortestWord = word;

    // Знаходження найкоротшого слова в рядку
    while (word != NULL)
    {
      if (strlen(word) < strlen(shortestWord))
      {
        shortestWord = word;
      }
      word = strtok(NULL, " ");
    }

    // Запис найкоротшого слова у вихідний файл
    if (shortestWord != NULL)
    {
      outputFile << shortestWord << endl;
      totalWordCount++;
    }
  }

  // Запис кількості слів у кінець файлу
  outputFile << "Кількість слів: " << totalWordCount << endl;

  inputFile.close();
  outputFile.close();

  cout << "Найкоротші слова збережено у файлі output.txt\n";
}
