#include <iostream>


void exercise_1() {
	char s1[15] = { 'h', 'e', 'l', 'l', 'o', ' ', '\0'};
	char s2[] = {'w', 'o', 'r', 'l', 'd', '\0'};
	std::cout << strcat(s1, s2) << " \n";
	std::cout << strlen(s2) << "\n";
	std::cout << strset(s2, 's') << "\n";
}

int main()
{
	exercise_1();

}

