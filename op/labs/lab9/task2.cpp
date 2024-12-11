#include <cstdlib>
#include <cstring>
#include <iostream>

#define MAX_WORD_LENGTH 20
#define MAX_DICTIONARY_SIZE 100
#define MAX_CHAIN_SIZE 100

using namespace std;

void nameOfAuthor()
{
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №9" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Ввести два слова і словник слів, який поданий масивом рядків. Слова "
          "- це лексеми, як не містять всередині розділових символів. "
          "Необхідно перетворити одне слово в інше, міняючи за один крок одну "
          "літеру, причому кожне нове слово має бути в словнику. У випадку "
          "відсутності слів у словнику передбачити додавання потрібних слів. "
          "На екран вивести лінцюжок перетворення одного слова в інше або "
          "повідомлення про неможливість такого перетворення. Контрольний "
          "тест. Вхідний рядок слів: hit ;  cog"
          ". Вхідний словник слів:  hot , dot , dog , lot , log"
          ". Варіант отримуваного в результаті ланцюжка :  hit -> hot -> dot "
          "-> dog -> cog."
       << endl;
  cout << "---------------------------------------" << endl;
}

// Перевірити, чи відрізняються слова однією літерою
int is_one_letter_diff(const char *word1, const char *word2)
{
  if (strlen(word1) != strlen(word2))
    return 0;

  int diff = 0;
  for (int i = 0; word1[i]; i++)
  {
    if (word1[i] != word2[i])
    {
      diff++;
      if (diff > 1)
        return 0;
    }
  }
  return diff == 1;
}

// Пошук перетворення з відновленням шляху
int find_transformation_chain(const char *start_word, const char *end_word,
                              char dictionary[][MAX_WORD_LENGTH],
                              int &dictionary_size,
                              char chain[][MAX_WORD_LENGTH])
{
  // Масив для відстеження відвіданих слів
  int visited[MAX_DICTIONARY_SIZE] = {0};

  // Масив для зберігання попереднього слова в шляху
  int prev[MAX_DICTIONARY_SIZE];
  for (int i = 0; i < MAX_DICTIONARY_SIZE; i++)
    prev[i] = -1;

  // Черга для BFS
  int queue[MAX_CHAIN_SIZE];
  int front = 0, rear = 0;

  // Додаємо початкове слово до словника, якщо його немає
  int start_index = -1;
  for (int i = 0; i < dictionary_size; i++)
  {
    if (strcmp(dictionary[i], start_word) == 0)
    {
      start_index = i;
      break;
    }
  }

  if (start_index == -1)
  {
    strcpy(dictionary[dictionary_size], start_word);
    start_index = dictionary_size++;
  }

  // Додаємо кінцеве слово до словника, якщо його немає
  int end_index = -1;
  for (int i = 0; i < dictionary_size; i++)
  {
    if (strcmp(dictionary[i], end_word) ==  0)
    {
      end_index = i;
      break;
    }
  }

  if (end_index == -1)
  {
    strcpy(dictionary[dictionary_size], end_word);
    end_index = dictionary_size++;
  }

  // Починаємо BFS з початкового слова
  queue[rear++] = start_index;
  visited[start_index] = 1;

  while (front < rear)
  {
    int current = queue[front++];

    // Якщо досягли кінцевого слова
    if (current == end_index)
    {
      // Відновлюємо шлях
      int path_length = 0;
      int current_word = end_index;

      while (current_word != -1)
      {
        strcpy(chain[path_length++], dictionary[current_word]);
        current_word = prev[current_word];
      }

      // Розгортаємо шлях
      for (int i = 0; i < path_length / 2; i++)
      {
        char temp[MAX_WORD_LENGTH];
        strcpy(temp, chain[i]);
        strcpy(chain[i], chain[path_length - 1 - i]);
        strcpy(chain[path_length - 1 - i], temp);
      }

      return path_length;
    }

    // Перевіряємо всі слова в словнику
    for (int next = 0; next < dictionary_size; next++)
    {
      if (!visited[next] &&
          is_one_letter_diff(dictionary[current], dictionary[next]))
      {
        queue[rear++] = next;
        visited[next] = 1;
        prev[next] = current;
      }
    }
  }

  return 0;
}

void transformChain(int chain_size, char chain[MAX_CHAIN_SIZE][MAX_WORD_LENGTH])
{
  if (chain_size > 0)
  {
    cout << "Transformation chain:\n";
    for (int i = 0; i < chain_size; i++)
    {
      cout << chain[i];
      if (i < chain_size - 1)
      {
        cout << " -> ";
      }
    }
    cout << "\n";
  }
  else
  {
    cout << "Unable to find a transformation chain.\n";
  }
}

void inputWords(char start_word[MAX_WORD_LENGTH],
                char end_word[MAX_WORD_LENGTH], int &dictionary_size,
                char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH])
{
  cout << "Enter the starting word: ";
  cin >> start_word;
  cout << "Enter the ending word: ";
  cin >> end_word;

  cout << "Enter the dictionary words (one per line, enter 'end' to finish):\n";
  while (dictionary_size < MAX_DICTIONARY_SIZE)
  {
    cin >> dictionary[dictionary_size];
    if (strcmp(dictionary[dictionary_size], "end") == 0)
    {
      break;
    }
    dictionary_size++;
  }
}

int main()
{
  nameOfAuthor();
  char start_word[MAX_WORD_LENGTH];
  char end_word[MAX_WORD_LENGTH];
  char dictionary[MAX_DICTIONARY_SIZE][MAX_WORD_LENGTH];
  int dictionary_size = 0;
  char chain[MAX_CHAIN_SIZE][MAX_WORD_LENGTH];

  inputWords(start_word, end_word, dictionary_size, dictionary);

  int chain_size = find_transformation_chain(
      start_word, end_word, dictionary, dictionary_size, chain);
  transformChain(chain_size, chain);

  return 0;
}
