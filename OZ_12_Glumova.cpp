#include <iostream>
#include <set>
using namespace std;
int main() {
	int startInd = int('A');
	int endInd = int('z');
	string str;
	set<char> delSymb = {'[', ']', '^', '_', '`'};
	set<char> allowedSymb;

	for (int i = startInd; i <= endInd; i++)
	{
		if (delSymb.find(char(i)) == delSymb.end() && i != 92) {
			allowedSymb.insert(char(i));
		}
	}

	std::cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (allowedSymb.find(str[i]) == allowedSymb.end()) {
			cout << "Error";
			return 0;
		}
	}	
	cout << "Correct";
	for (const auto& el: allowedSymb){
		cout << el;
	}
}