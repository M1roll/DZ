#include <iostream>
#include <set>

using namespace std;

int CntNumSimb(string str) {
	set <char> allowedChar = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '+', '-', '*' };
	int cnt = 0;
	for (char ch : str) {
		if (allowedChar.find(ch) != allowedChar.end()) {
			cnt++;
		}
	}
	return cnt;
}

int main(){
	string str = "aBncndk00+-*";
	int ans = CntNumSimb(str);
	cout << ans;
	return 0;
}