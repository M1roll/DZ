#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int cntLeter = 0;
	int cntNum = 0;
	int cntgls = 0;
	int cntsgls = 0;

	string str;

	set<char> mark;
	set<char> let;
	set<char> delSymb = { '[', ']', '^', '_', '`' };
	set<char> num = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };
	set<char> gls = { 'a', 'e', 'i', 'u', 'o', 'y', 'A', 'E', 'I', 'U', 'O', 'Y'};

	cin >> str;
	for (int i = 65; i <= 122; i++)
	{
		if (delSymb.find(char(i)) == delSymb.end() && i != 92) {
			let.insert(char(i));
		}
		
	}

	for (char el : str) {
		if (let.find(el) != let.end()) {
			cntLeter++;
			if (gls.find(el) != gls.end()) {
				cntgls++;
			}
			else
				cntsgls++;
		}
		if (num.find(el) != num.end()) {
			cntNum++;
		}
		if (let.find(el) == let.end() && num.find(el) == num.end()) {
			mark.insert(el);
		}
	}
	if (cntLeter > cntNum) {
		cout << "1) Laters more than Numbers" << endl;
	}
	if (cntLeter < cntNum) {
		cout << "1) Numbers more than Laters" << endl;
	}
	cout << "2) " << cntgls << ' ' << cntsgls << endl;
	for (const auto& el : mark) {
		cout << el;
	}

}