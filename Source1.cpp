#include <iostream>
using namespace std;

int main() {
	int x;
	switch (x) {
	case 1:
		cout << "������ - ����� �� 100, �� ���������� ������?" << endl;
		break;
	case 2:
		cout << "������ - ������� �� ������!" << endl;
		break;
		case 3;
			cout << "���� - ������������ ������ ����������� �����, ��� �� ���� ����." << endl;
			break;
			case 4;
				cout << "����� - ������������ ��������� ������, ���� ������))" << endl;
				break;
				endl;
	}
	cout << "1. ������ \n2.������ \n3.���� \n4.�����" << endl;
	cin >> x;
	if (x > 6) {
		cout << "������� �������� �� 1 �� 6" << endl;
		cin >> x;
	}
}
system("pause");
return(0);
}