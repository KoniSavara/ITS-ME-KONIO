#include <iostream>
using namespace std;

int f(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        a = a + b;
        b = a - b;
    }
    return a;
}

int main()
{
   
       int n;
        cin >> n;
        cout << f(n) << "\n";
   
system("pause");
return(0);
}
