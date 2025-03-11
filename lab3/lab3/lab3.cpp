#include <iostream>
using namespace std;

void exercise_1() {
	char s1[15] = "hello ";
	char s2[] = "world";
	cout << strcat(s1, s2) << " \n";
	cout << strlen(s2) << "\n";	
	cout << strset(s2, 's') << "\n";
}

void exercise_2() {
	setlocale(LC_ALL, "ru_RU.UTF-8"); 
	char array[20][10];
	short n;
	wcout << L"Введите количество слов:";
	cin >> n;
	for (short i = 0; i < n; i++) {
		cin >> array[i];
	}
	cout << '\n';
	for (short i = 1; i < n; i += 2) {
		cout << array[i] << '\n';
	}
}



int main()
{
	//exercise_1();
	exercise_2();
	return 0;
}

