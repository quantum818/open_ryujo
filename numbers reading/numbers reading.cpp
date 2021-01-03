#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<iostream>
#include <algorithm>
using namespace std;
string n, p;
string shuzi(char i);
string replace(string p);
string shuzi(char i) {


	if (i == '1' || i == 1) { n = "yi"; }
	else if (i == '2' || i == 2) { n = "er"; }
	else if (i == '3' || i == 3) { n = "san"; }
	else if (i == '4' || i == 4) { n = "si"; }
	else if (i == '5' || i == 5) { n = "wu"; }
	else if (i == '6' || i == 6) { n = "liu"; }
	else if (i == '7' || i == 7) { n = "qi"; }
	else if (i == '8' || i == 8) { n = "ba"; }
	else if (i == '9' || i == 9) { n = "jiu"; }
	else if (i == '0' || i == 0) { n = "ling"; }
	else if (i == 10) { n = "shi"; }
	else if (i == 11) { n = "bai"; }
	else if (i == 12) { n = "qian"; }
	else if (i == 13) { n = "wan"; }
	return n;
}
string replace(string p) {
	p = p.substr(3, p.length() - 1);
	return p;
}
int main(void) {
	string str[20] = { "shi ","bai ","qian ","wan ","shi wan ","bai wan ","qian wan ","yi " };
	string ans, m;
	char c[12] = { 0 };
	int re, temp, i = 1;
	cin >> m;
	re = m.length();
	temp = re;
	if (m == "0") { cout << "ling" << endl; return 0; }

	for (int i = 0; i < re; i++, temp--) {
		if (m[i] != '0') {
			if (i - 1 >= 0 && m[i - 1] == '0')
				ans = ans + "ling" + " ";
			ans = ans + shuzi(m[i] - '0') + " ";
			switch (temp % 4) {
			case 0:ans = ans + str[2]; break;
			case 3:ans = ans + str[1]; break;
			case 2:ans = ans + str[0]; break;
			default:
				break;
			}
		}
		if (temp == 9) { ans = ans + str[7]; }
		else if (temp == 5) { ans = ans + str[3]; }
	}
	ans = ans.substr(0, ans.length() - 1);
	if ((re == 9 || re == 10) && (m.substr(1, re) == "00000000" || m.substr(1, re) == "000000000")) {
		ans = ans.substr(0, ans.length() - 5);
	}
	if (ans.substr(0, 6) == "yi shi") {
		cout << replace(ans) << endl;
	}
	else cout << ans << endl;
	return 0;
}