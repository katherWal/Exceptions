/*
Katherine Walsh
Exceptions
12/4/22
*/

#include <iostream>
#include <cctype>

using namespace std;

char character(char start, int offset);

class invalidCharacterException : public std::exception {
public:
	const char* what() {
		return "Start character must be alphabetical!";
	}
};

int main() {
	cout << character('a', 1) << endl;


	cout << endl;
	system("pause");
	return 0;
}

char character(char start, int offset) {
	try {
		if (!isalpha(start)) {
			throw invalidCharacterException();
		}
	}
	catch (invalidCharacterException ice) {
		cout << ice.what() << endl;
	}
}