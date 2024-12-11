#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void nameOfAuthor()
{
    cout << "---------------------------------------" << endl;
    cout << "Лабораторна робота №9" << endl;
    cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
    cout << "Увести з клавіатури рядок символів, який містить слова та розділові "
            "символи. Слова - це лексеми, як не містять всередині розділових "
            "символів. Слова відділяються один від одного довільною кількістю "
            "пропусків, ком і крапок. Передбачити меню для виконання таких дій: "
            "визначити кількість слів і знайти найдовше слово; "
            "знайти слова, що складаються тільки з цифр, і знайти суму цифр в "
            "таких словах; "
            "видалити з рядка однолітерні слова та зайві пропуски, коми, крапки. "
            "Вивести на екран слова рядка, їх кількість, найдовше слово, суму "
            "цифр слова, рядок після перетворення"
         << endl;
    cout << "---------------------------------------" << endl;
}

// Функція для підрахунку слів і знаходження найдовшого слова
void countWordsAndFindLongest(const char *str, int &wordCount, char *longestWord)
{
    wordCount = 0;
    int maxLength = 0;
    const char *currentWord = nullptr;
    int currentLength = 0;

    for (int i = 0;; i++)
    {
        if (isspace(str[i]) || str[i] == '\0' || str[i] == ',' || str[i] == '.')
        {
            if (currentLength > 0)
            {
                wordCount++;
                if (currentLength > maxLength)
                {
                    maxLength = currentLength;
                    strncpy(longestWord, currentWord, currentLength);
                    longestWord[currentLength] = '\0'; // Завершити рядок
                }
                currentLength = 0;
            }
            if (str[i] == '\0')
                break; // Кінець рядка
        }
        else
        {
            if (currentLength == 0)
            {
                currentWord = &str[i]; // Запам'ятати початок слова
            }
            currentLength++;
        }
    }
}

// Функція для знаходження слів, що складаються тільки з цифр, та їх суми
void findDigitWordsAndSum(const char *str, int &digitWordSum)
{
    digitWordSum = 0;
    const char *currentWord = nullptr;
    int currentLength = 0;

    for (int i = 0;; i++)
    {
        if (isspace(str[i]) || str[i] == '\0' || str[i] == ',' || str[i] == '.')
        {
            if (currentLength > 0)
            {
                bool isDigitWord = true;
                for (int j = 0; j < currentLength; j++)
                {
                    if (!isdigit(currentWord[j]))
                    {
                        isDigitWord = false;
                        break;
                    }
                }
                if (isDigitWord)
                {
                    for (int j = 0; j < currentLength; j++)
                    {
                        digitWordSum += currentWord[j] - '0'; // Додавання цифр
                    }
                }
                currentLength = 0;
            }
            if (str[i] == '\0')
                break; // Кінець рядка
        }
        else
        {
            if (currentLength == 0)
            {
                currentWord = &str[i]; // Запам'ятати початок слова
            }
            currentLength++;
        }
    }
}

// Функція для видалення однолітерних слів та зайвих пробілів
void removeSingleLetterWords(char *str)
{
    char *result = (char *)malloc(strlen(str) + 1); // Результуючий рядок
    int resultIndex = 0;
    bool lastWasSpace = true;

    for (int i = 0;; i++)
    {
        if (isspace(str[i]) || str[i] == '\0' || str[i] == ',' || str[i] == '.')
        {
            if (!lastWasSpace)
            {
                if (resultIndex > 0)
                {
                    result[resultIndex++] = ' '; // Додати пробіл
                }
                lastWasSpace = true;
            }
            if (str[i] == '\0')
                break; // Кінець рядка
        }
        else
        {
            if (str[i + 1] == ' ' || str[i + 1] == '\0' || str[i + 1] == ',' ||
                str[i + 1] == '.')
            {
                // Якщо наступний символ - пробіл або розділовий, перевірити довжину слова
                if (resultIndex > 0 && result[resultIndex - 1] == ' ')
                {
                    resultIndex--; // Видалити останній пробіл
                }
                if (resultIndex > 0)
                {
                    result[resultIndex++] = str[i]; // Додати символ
                }
            }
            else
            {
                result[resultIndex++] = str[i]; // Додати символ
            }
            lastWasSpace = false;
        }
    }

    result[resultIndex] = '\0'; // Завершити рядок
    strcpy(str, result);        // Копіювати назад в початковий рядок
    free(result);               // Звільнити пам'ять
}

void displayMenu(char *input, int &wordCount, char *longestWord, int &digitWordSum)
{
    int choice;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Determine the number of words and find the longest word.\n";
        cout << "2. Find the words consisting only of digits and find the sum of the digits.\n";
        cout << "3. Delete single-letter words and unnecessary spaces.\n";
        cout << "4. Exit\n";
        cout << "Select an action: ";
        cin >> choice;
        cin.ignore(); // Ігнорувати символ нового рядка

        switch (choice)
        {
        case 1:
            countWordsAndFindLongest(input, wordCount, longestWord);
            cout << "The number of words: " << wordCount << endl;
            cout << "The longest word: " << longestWord << endl;
            break;
        case 2:
            findDigitWordsAndSum(input, digitWordSum);
            cout << "The sum of digits in words consisting only of digits: "
                 << digitWordSum << endl;
            break;
        case 3:
            removeSingleLetterWords(input);
            cout << "The string after conversion: " << input << endl;
            break;
        case 4:
            cout << "Exit the program." << endl;
            break;
        default:
            cout << "Wrong choice. Please try again." << endl;
        }
    } while (choice != 4);
}

int main()
{
    nameOfAuthor();
    const int MAX_LEN = 1000;
    char input[MAX_LEN];
    char longestWord[MAX_LEN]; // Виправлено тут
    int wordCount = 0, digitWordSum = 0;

    cout << "Enter a character string: ";
    cin.getline(input, MAX_LEN);

    displayMenu(input, wordCount, longestWord, digitWordSum);

    return 0;
}
