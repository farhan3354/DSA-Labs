#include<iostream>
using namespace std;

bool Palindrome(string n, int s, int end) {
	if (s >= end) {
		return true;
	}
	if (n[s] != n[end]) {
		return false;
	}
	return Palindrome(n, s + 1, end - 1);
}

int main() {
	string s = "leve";
	if (Palindrome(s, 0, s.length() - 1)) {
		cout << "String is palindrome";
	}
	else
	{
		cout << "String is not a palindrome";
	}

	return 0;
}
