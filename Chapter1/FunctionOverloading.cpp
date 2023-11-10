#include <iostream>

using namespace std;

void MyFunc(void)
{
    cout << "MyFunc(void) Called" << endl;
    return;
}

void MyFunc(char c)
{
    cout << "MyFunc(char c) Called" << endl;
}

void MyFunc(int n)
{
    cout << "MyFunc(int n) Called" << endl;
}

int main(void)
{
    MyFunc();
    MyFunc(1);
    MyFunc('A');
    return 0;
}