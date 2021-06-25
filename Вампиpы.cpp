#include <iostream>
using namespace std;

 int main()
 {
   setlocale(LC_ALL, "Russian");
   int a[4]; int chis[10]; int number; 

   for ( int x = 1000; x < 10000; x++) 
    {
     if ( x % 10 != 0 & ( x % 100 ) / 10 != 0 & ( x % 1000 ) / 100 != 0) 
      {
        number = x; 
        for ( int i = 1; i < 5; i++ )
        {
          a[i] = number % 10;
          number /= 10; 
        }
        number = x;

        chis[0]=(a[1]*10+a[2])*(a[3]*10+a[4]); 
        chis[1]=(a[2]*10+a[1])*(a[3]*10+a[4]);
        chis[2]=(a[1]*10+a[2])*(a[4]*10+a[3]);
        chis[3]=(a[2]*10+a[1])*(a[4]*10+a[3]);
        chis[4]=(a[1]*10+a[3])*(a[2]*10+a[4]);
        chis[5]=(a[3]*10+a[1])*(a[2]*10+a[4]);
        chis[6]=(a[1]*10+a[3])*(a[4]*10+a[2]);
        chis[7]=(a[3]*10+a[1])*(a[4]*10+a[2]);
        chis[7]=(a[1]*10+a[4])*(a[2]*10+a[3]);
        chis[8]=(a[4]*10+a[1])*(a[2]*10+a[3]);
        chis[9]=(a[1]*10+a[4])*(a[3]*10+a[2]);
        chis[10]=(a[4]*10+a[1])*(a[3]*10+a[2]);

        if ( chis [0] == number | chis [1] == number | chis [2] == number | chis [3] == number | chis [4] == number | chis [5] == number | chis [6] == number | chis [7] == number | chis [8] == number | chis [9] == number | chis [10] == number ) 
        {
          cout << number << endl; 
        }

      }
    }
   system ("pause");
   return (0);
 }
