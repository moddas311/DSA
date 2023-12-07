#include <bits/stdc++.h>
using namespace std;
void fun(int *&p)
{
    // *p = 30;
    // p=NULL;
    cout << &p << endl;
}
int main()
{
    int value = 10;
    int *ptr = &value;
    fun(ptr);
    cout << &ptr << endl;
    return 0;
}