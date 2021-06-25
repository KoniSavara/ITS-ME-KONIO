#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	long long x, fact;
	cout << "Выберите, какая программа вам нужна: [1]Факториал Числа [2]Последовательность Чисел " << endl;
	cin >> x; 
	switch (x) {
	case 1:
		cout << "Введите число: " << endl;
		cin >> x;
		fact = x;
		for (long long i = 1; i < x; i++) {
			fact = fact * i;
		}
		cout << "Факториал числа " << x << " это: " << fact << endl;
		break;
		
	case 2:
		cout << "Введите Число: " << endl;
		cin >> x;
		cout << "Ваша Последовательность: " << endl;
		for (long long i = 0; i <= x; i++) {
			cout << i << "\n";
			;
		}
	}
system("pause");
return(0);
}
