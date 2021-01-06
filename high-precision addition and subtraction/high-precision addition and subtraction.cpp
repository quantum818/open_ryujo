/*⣼⣯⠄⣸⣠⣶⣶⣦⣾⠄⡅⡅⠄⠄⠄⠄⡉⠹⠄⡅⠄⠄⠄
⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀
⣴⣶⣶⡀⠄⠄⠙⢿⣿⣿⣿⣿⣿⣴⣿⣿⣿⢃⣤⣄⣀⣥⣿
⣿⣿⣿⣧⣀⢀⣠⡌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠿⣿⣿
⣤⣤⣤⣬⣙⣛⢿⣿⣿⣿⣿⣿⣿⡿⣿⣿⡍⠄⠄⢀⣤⣄⠉
⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⢇⣿⣿⡷⠶⠶⢿⣿⣿⠇
⣿⣿⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣷⣶⣥⣴
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣻⣿⣿⣧⠙⠛⠛⡭⠅⠒⠦⠭⣭⡻⣿⣿⣿⣿⣿⣿⣿⣿⡿
⣿⣿⣿⣿⡆⠄⠄⠄⠄⠄⠄⠄⠄⠹⠈⢋⣽⣿⣿⣿⣿⣵⣾
⣿⣿⣿⣿⣿⠄⣴⣿⣶⣄⠄⣴⣶⠄⢀⣾⣿⣿⣿⣿⣿⣿⠃
⠛⢿⣿⣿⣿⣦⠁⢿⣿⣿⡄⢿⣿⡇⣸⣿⣿⠿⠛⠁⠄⠄⠄
⠄⠄⠉⠻⣿⣿⣿⣦⡙⠻⣷⣾⣿⠃⠿⠋⠁⠄⠄⠄⠄⠄⢀
⣮⣥⠄⠄⠄⠛⢿⣿⣿⡆⣿⡿⠃⠄⠄⠄⠄⠄⠄⠄⣠⣴⣿
 */
#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[1000] = { 0 }, b[1000] = { 0 }, ans, midturn, i, j, sum = 0, ccon = 1, k, mmt;
	string ind1, ind2;
	cin >> ind1 >> ind2;
	i = ind1.length();
	j = ind2.length();
	reverse(ind1.begin(), ind1.end());
	reverse(ind2.begin(), ind2.end());
	midturn = max(i, j);
	mmt = min(i, j);
	ccon = midturn - 1;
	for (k = 0; k < midturn; k++) {
		if (k < mmt) {
			b[k] = (ind1[k] + ind2[k]) - 48 * 2 + b[k];
		}
		else b[k] = (ind1[k] + ind2[k]) - 48 + b[k];
		if (b[k] >= 10) {
			b[k + 1]++;
			b[k] = b[k] - 10;
			if (k == midturn - 1) {
				ccon = k + 1;
			}
		}
	}
	for (int p = 0; p <= ccon; p++) {
		sum = sum + b[p];
	}
	cout << sum % 3 << endl;
	return 0;
}