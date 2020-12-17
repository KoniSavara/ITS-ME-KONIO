#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a = 0;
	cout << "Выберете дело" << endl;
	do {
		cin >> a;
		switch (a) {

		case 1:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 1";
			break;

		case 2:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 2";
			break;

		case 3:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 3";
			break;

		case 4:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 4";
			break;

		case 5:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 5";
			break;

		case 6:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 6";
			break;

		case 7:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 7";
			break;

		case 8:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 8";
			break;

		case 9:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 9";
			break;

		case 10:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 10";
			break;

		case 11:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 11";
			break;

		case 12:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 12";
			break;

		case 13:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 13";
			break;

		case 14:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 14";
			break;

		case 15:
			cout << "ЭТО СООБЩЕНИЕ НОМЕР 15";
			break;
		}
	} while (a != 15);
	system("pause");
	return(0);
}