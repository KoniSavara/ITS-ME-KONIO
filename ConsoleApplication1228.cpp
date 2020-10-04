#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int x;
	cout << "1.Доллар \n2.Гривна \n3.Евро \n4.Гроши" << endl;
	cin >> x;
	if (x > 4) {
		cout << "Введите значение от 1 до 4" << endl;
		cin >> x;
	}
	switch (x) {
	case 1:
		cout << "Доллар - почти по 100, вы нормальные вообще?" << endl;
		break;
	case 2:
		cout << "Гривна - Украина це Европа!" << endl;
		break;
	case 3:
		cout << "Евро - Коллективная Валюта Европейских стран, как бы кайф ежжи." << endl;
		break;
	case 4:
		cout << "ГРОШИ - национальная еврейская валюта, жиды лютуют))" << endl;
		break;
	}

system("pause");
return(0);
}