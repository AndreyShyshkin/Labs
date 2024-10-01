import { Moon, Sun } from "lucide-react";
import { useState } from "react";
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import {
  oneDark,
  oneLight,
} from "react-syntax-highlighter/dist/esm/styles/prism";
import Code from "../../components/Code/Code";

export default function CodeLab() {
  const [isDarkTheme, setIsDarkTheme] = useState(false);
  const taskCpp1 = `
#include <cmath> // бібліотека математичних функцій
#include <iostream> // бібліотека потоків вводу-виводу
#include <string>   // для роботи з рядками
using namespace std;

bool isValidInput(double &x)
{
  if (cin >> x)
  {
    return true;
  }
  cin.clear();
  cin.ignore();
  return false;
}

int main() {
  cout << "---------------------------------------" << endl;
  cout << "Лабораторна робота №1" << endl;
  cout << "Студент Шишкін Андрій Антонович, ІПЗ-11, Варіант 25" << endl;
  cout << "Завдання 1. За даними, що введені з клавіатури в оперативну "
          "пам’ять, визначити значення виразу, використовуючи математичні "
          "функції, і вивести результат на екран. Вираз вибрати згідно з "
          "варіантом 25. Довільні значення змінних A,B,C,D ввести з клавіатури."
       << endl;
  cout << "X=sin^3 C Cos^2 A / (e^A + 1 + SinB)" << endl;
  cout << "---------------------------------------" << endl;

  double A, B, C;

  cout << "Введіть a: ";
  while (!isValidInput(A))
  {
    cout << "Помилка ввода! Будьласка, введіть коректне число для a: ";
  }

  cout << "Введіть b: ";
  while (!isValidInput(B))
  {
    cout << "Помилка ввода! Будьласка, введіть коректне число для b: ";
  }

  cout << "Введіть c: ";
  while (!isValidInput(C))
  {
    cout << "Помилка ввода! Будьласка, введіть коректне число для c: ";
  }

  // Обчислення виразу
  double X = pow(sin(C), 3) * pow(cos(A), 2) / (exp(A) + 1 + sin(B));

  // Виведення результату
  cout << "Результат обчислення X = " << X << endl;
  return 0;
}
  `;

  const taskCpp2 = `
#include <cmath> // бібліотека математичних функцій
#include <iomanip> // бібліотека для форматування виводу
#include <iostream> // бібліотека потоків вводу-виводу
#include <string>   // для роботи з рядками
using namespace std;

// функція для обчислення меншої діагоналі ромба
double calculatesmallerdiagonal(double perimeter) 
{
  // сторона ромба
  double side = perimeter / 4;

  // половина сторони (оскільки висота ділить сторону навпіл)
  double halfside = side / 2;

  // висота ромба (за теоремою піфагора)
  double height = sqrt(side * side - halfside * halfside);

  // менша діагональ (за властивістю ромба)
  double smallerdiagonal = 2 * height;

  return smallerdiagonal;
}

bool isValidInput(double &x)
{
  if (cin >> x)
  {
    return true;
  }
  cin.clear();
  cin.ignore();
  return false;
}

int main() // основна функція - точка входу до програми
{          // початок основної функції

  cout << "---------------------------------------"
       << endl; // виведення відомостей про
                // лабораторну роботу
  cout << "лабораторна робота №1" << endl;
  cout << "студент шишкін андрій антонович, іпз-11, варіант 25" << endl;
  cout << "завдання 1. написати програму, що розв'язує задачу з математики та "
          "фізики шкільногого курсу, відповідно до варіантів таблиці 1.8"
       << endl;
  cout << "висота ромба, проведена з вершини тупого кута, ділить сторону "
          "навпіл. знайдіть меншу діагональ, якщо значення периметра ромба "
          "введене з клавіатури."
       << endl;
  cout << "---------------------------------------" << endl;

  double perimeter;

  cout << "Bведіть периметр ромба: ";
  while (!isValidInput(perimeter))
  {
    cout << "Помилка ввода! Будьласка, введіть коректне число для периметрa ромба: ";
  }

  // обчислення меншої діагоналі
  double result = calculatesmallerdiagonal(perimeter);

  // виведення результату
  cout << "менша діагональ ромба: " << fixed << setprecision(2)
       << result << endl; // форматне виведення результату

  return 0; // завершення програми
}

  `;

  const toggleTheme = () => {
    setIsDarkTheme(!isDarkTheme);
  };

  return (
    <Code
      codeText={
        <div>
          <div className="theme-toggle flex py-4">
            <p className="text-gray-600 my-auto">Вибрати тему:</p>
            <button
              onClick={toggleTheme}
              className="p-2 rounded-full hover:bg-gray-200 dark:hover:bg-gray-700"
            >
              {isDarkTheme ? <Sun size={24} /> : <Moon size={24} />}
            </button>
          </div>
          <div>
            <p className="text-sky-500">Код Завдання 1:</p>
            <SyntaxHighlighter
              language="cpp"
              style={isDarkTheme ? oneDark : oneLight}
              customStyle={{
                padding: "20px",
                borderRadius: "8px",
                fontSize: "14px",
              }}
            >
              {taskCpp1}
            </SyntaxHighlighter>
          </div>
          <div>
            <p className="text-sky-500">Код Завдання 2:</p>
            <SyntaxHighlighter
              language="cpp"
              style={isDarkTheme ? oneDark : oneLight}
              customStyle={{
                padding: "20px",
                borderRadius: "8px",
                fontSize: "14px",
              }}
            >
              {taskCpp2}
            </SyntaxHighlighter>
          </div>
        </div>
      }
    />
  );
}
