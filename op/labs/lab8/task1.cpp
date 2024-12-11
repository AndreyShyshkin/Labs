#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

void nameofauthor()
{
    cout << "---------------------------------------" << endl;
    cout << "лабораторна робота №8" << endl;
    cout << "студент шишкін андрій антонович, іпз-11, варіант 25" << endl;
    cout << "розробити програму, команди меню якої передбачають такі дії: "
         << endl;
    cout << "згенерувати розріджену матрицю довільної вимірності," << endl;
    cout << "  кількість нульових елементів якої більше за 60 % " << endl;
    cout << ".збереження матриці в оперативній" << endl;
    cout << " пам'яті здійснити в координатному форматі соо [1] у вигляді трьох "
            "одновимірних масивів, перший з яких зберігає значення ненульових "
            "елементів, другий – номери рядків, третій – номери стовпців "
            "ненульових елементів. вивести"
         << endl;
    cout << " на екран матрицю по рядках та стовпцях.вивести на екран" << endl;
    cout << "  одновимірні масиви," << endl;
    cout << " що зберігають розріджену матрицю.визначити суму діагональних "
            "елементів"
         << endl;
    cout << "розрідженої матриці за алгоритмом обробки розріджених матриць та"
         << endl;
    cout << " надрукувати результат визначити суму діагональних елементів"
         << endl;
    cout << "  розрідженої матриці за стандартним алгоритмом обробки" << endl;
    cout << " матриць та надрукувати результат порівняти час" << endl;
    cout << "  виконання операцій і обсяг пам'яті при використанні цих двох "
            "алгоритмів"
         << endl;
    cout << "---------------------------------------" << endl;
}

// генерація випадкового числа в межах [min, max]
double randomdouble(double min, double max)
{
    return min + (static_cast<double>(rand()) / RAND_MAX) * (max - min);
}

// створення розрідженої матриці у форматі coo
void createsparsematrix(int rows, int cols, double *&values, int *&rowindices,
                        int *&colindices, int &nonzerocount)
{
    nonzerocount = static_cast<int>(rows * cols * 0.4); // 40% ненульових елементів
    values = new double[nonzerocount];
    rowindices = new int[nonzerocount];
    colindices = new int[nonzerocount];

    bool *used = new bool[rows * cols](); // ініціалізація масиву використаних позицій

    for (int count = 0; count < nonzerocount;)
    {
        int row = rand() % rows;
        int col = rand() % cols;
        int index = row * cols + col;

        if (!used[index])
        { // якщо позиція не використана
            values[count] = randomdouble(1.0, 10.0);
            rowindices[count] = row;
            colindices[count] = col;
            used[index] = true; // позначаємо як використане
            count++;
        }
    }

    delete[] used; // очищення
}

// відображення матриці
void displaymatrix(int rows, int cols, double *values, int *rowindices,
                   int *colindices, int nonzerocount)
{
    double **temp = new double *[rows];
    for (int i = 0; i < rows; i++)
        temp[i] = new double[cols]();

    for (int i = 0; i < nonzerocount; i++)
        temp[rowindices[i]][colindices[i]] = values[i];

    cout << "\nmatrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << setw(8) << fixed << setprecision(2) << temp[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < rows; i++)
        delete[] temp[i];
    delete[] temp;
}

// виведення масивів у форматі coo
void displaycoo(double *values, int *rowindices, int *colindices,
                int nonzerocount)
{
    cout << "\ncoo format arrays:\nvalues: ";
    for (int i = 0; i < nonzerocount; i++)
        cout << setw(8) << fixed << setprecision(2) << values[i] << " ";

    cout << "\nrow indices: ";
    for (int i = 0; i < nonzerocount; i++)
        cout << setw(8) << rowindices[i] << " ";

    cout << "\ncolumn indices: ";
    for (int i = 0; i < nonzerocount; i++)
        cout << setw(8) << colindices[i] << " ";
    cout << "\n";
}

// обчислення суми діагональних елементів у розрідженій матриці
double calculatediagonalsumsparse(int rows, double *values, int *rowindices,
                                  int *colindices, int nonzerocount)
{
    double sum = 0.0;
    for (int i = 0; i < nonzerocount; i++)
    {
        if (rowindices[i] == colindices[i])
            sum += values[i];
    }
    return sum;
}

// обчислення суми діагональних елементів у стандартній матриці
double calculatediagonalsumstandard(int rows, int cols, double *values,
                                    int *rowindices, int *colindices,
                                    int nonzerocount)
{
    double **temp = new double *[rows];
    for (int i = 0; i < rows; i++)
        temp[i] = new double[cols]();

    for (int i = 0; i < nonzerocount; i++)
        temp[rowindices[i]][colindices[i]] = values[i];

    double sum = 0.0;
    for (int i = 0; i < min(rows, cols); i++)
        sum += temp[i][i];

    for (int i = 0; i < rows; i++)
        delete[] temp[i];
    delete[] temp;

    return sum;
}

// порівняння сум діагональних елементів
void comparediagonalsums(int rows, int cols, double *values, int *rowindices,
                         int *colindices, int nonzerocount)
{
    clock_t start, stop;
    
    start = clock();
    double sparsesum = calculatediagonalsumsparse(rows, values, rowindices,
                                                  colindices, nonzerocount);
    stop = clock();
    double sparseduration = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    double standardsum = calculatediagonalsumstandard(
        rows, cols, values, rowindices, colindices, nonzerocount);
    stop = clock();
    double standardduration = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000000;

    cout << "\nresults comparison:\n";
    cout << "sparse method sum: " << sparsesum
         << " (time: " << sparseduration << " microseconds)\n";
    cout << "standard method sum: " << standardsum
         << " (time: " << standardduration << " microseconds)\n";
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    nameofauthor();

    int rows, cols, nonzerocount;
    double *values = nullptr;
    int *rowindices = nullptr;
    int *colindices = nullptr;

    cout << "enter number of rows: ";
    cin >> rows;
    cout << "enter number of columns: ";
    cin >> cols;

    createsparsematrix(rows, cols, values, rowindices, colindices, nonzerocount);
    displaymatrix(rows, cols, values, rowindices, colindices, nonzerocount);
    displaycoo(values, rowindices, colindices, nonzerocount);
    comparediagonalsums(rows, cols, values, rowindices, colindices, nonzerocount);

    delete[] values;
    delete[] rowindices;
    delete[] colindices;

    return 0;
}
