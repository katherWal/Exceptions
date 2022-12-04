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

class invalidRangeException : public std::exception {
public:
	const char* what() {
		return "Character is not alphabetical or has switched cases.";
	}
};

int main() {
	char start;
	int offset;
	char temp;

	bool again = true;

	while (again) {
		cout << "\nEnter a letter: ";
		cin >> start;
		cout << "\nEnter a number to offset the letter by: ";
		cin >> offset;

		try {
			if (!isalpha(start)) {
				throw invalidCharacterException();
			}
			temp = start + offset;
			if (!isalpha(temp) || (start <= 90 && temp >= 97)) {
				throw invalidRangeException();
			}
			else if (!isalpha(temp) || (start >= 97 && temp <= 90)) {
				throw invalidRangeException();
			}
			
			cout << "\nYour character is '" << character(start, offset) << "'";
			cout << "\nProcess another character? Enter 1 for yes else enter 0: ";
			cin >> again;

		}
		catch (invalidCharacterException ice) {
			cout << "\n" << ice.what() << endl;
		}
		catch (invalidRangeException ire) {
			cout << "\n" << ire.what() << endl;
		}

		
	}


	cout << endl;
	system("pause");
	return 0;
}

char character(char start, int offset) {
	return start + offset;
}