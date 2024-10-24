#include <iostream>
#include <cmath>
#include <cstdio>


using namespace std;

int y = 4;
int f(int x)
{
    x += 5;
    cout << x-- << endl;
    return x--;
}
int main()
{
    int z = f(++y);
    cout << y << endl;
    cout << z << endl;
}