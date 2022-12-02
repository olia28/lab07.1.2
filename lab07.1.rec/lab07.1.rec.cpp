#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo);
void PrintRow(int** a, const int rowNo, const int colCount, int colNo);
void Sort(int** a, const int rowCount, const int colCount, int j0, int j1);
void Change(int** a, const int col1, const int col2, const int rowCount, int i);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int ij, int j);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -26;
    int High = 23;
    int rowCount = 8;
    int colCount = 6;
    int** a = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High, 0, 0);
    PrintRows(a, rowCount, colCount, 0);
    Sort(a, rowCount, colCount, 0, 0);
    PrintRows(a, rowCount, colCount, 0);

    int S = 0;
    int k = 0;

    Calc(a, rowCount, colCount, S, k, 0, 0);

    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    PrintRows(a, rowCount, colCount, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];

    delete[] a;
    return 0;
}

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High, int i, int j)
{
    if (j < colCount)
    {
        a[i][j] = Low + rand() % (High - Low + 1);
        j++;
    }
    else
    {
        j = 0;
        i++;
    }

    if (i >= rowCount)
    {
        return;
    }

    Create(a, rowCount, colCount, Low, High, i, j);
}

void PrintRow(int** a, const int rowNo, const int colCount, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < colCount - 1)
        PrintRow(a, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}
void PrintRows(int** a, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(a, rowNo, colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(a, rowCount, colCount, rowNo + 1);
    else
        cout << endl;
}

void Sort(int** a, const int rowCount, const int colCount, int j0, int j1)
{
    if (j1 < colCount - j0 - 1)
    {
        if ((a[0][j1] > a[0][j1 + 1]) || (a[0][j1] == a[0][j1 + 1] && a[1][j1] < a[1][j1 + 1]) ||
            (a[0][j1] == a[0][j1 + 1] && a[1][j1] == a[1][j1 + 1] && a[2][j1] > a[2][j1 + 1]))
        {
            Change(a, j1, j1 + 1, rowCount, 0);
        }
        j1++;
    }
    else
    {
        j1 = 0;
        j0++;
    }

    if (j0 >= colCount - 1)
    {
        return;
    }

    Sort(a, rowCount, colCount, j0, j1);
}

void Change(int** a, const int col1, const int col2, const int rowCount, int i)
{
    if (!(i < rowCount))
    {
        return;
    }
    else
    {
        int tmp;
        tmp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = tmp;
    }
    Change(a, col1, col2, rowCount, i + 1);
}

void Calc(int** a, const int rowCount, const int colCount, int& S, int& k, int i, int j)
{
    if (j < colCount)
    {
        if (!(a[i][j] % 2 == 0 && !(a[i][j] < 0)))
        {
            S += a[i][j];
            k++;
            a[i][j] = 0;
        }
        j++;
    }
    else
    {
        j = 0;
        i++;
    }

    if (i >= rowCount)
    {
        return;
    }

    Calc(a, rowCount, colCount, S, k, i, j);
}