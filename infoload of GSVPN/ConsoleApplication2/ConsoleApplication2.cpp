#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<time.h>
#include<io.h>
#include<direct.h>
using namespace std;
int main() {
	time_t info;
	struct tm bst;
	string ind, ind2, ind3, mon, day, hour, min, sum;
	char cmp[10000] = { 0 }, cmp2[100] = { 0 }, cmp3[10000] = { 0 }, cmp4[10000] = { 0 }, tim[1000] = { 0 }, temp;
	FILE* fp;
	bool flag = true;
	long y, m, d;
	ind2 = "D:\\360MoveData\\Users\\Administrator\\Desktop\\岛风go\\";
	time(&info);
	gmtime_s(&bst, &info);
	y = bst.tm_year;
	y = y + 1900;
	while (y!=0) {
		temp = '0' + y % 10;
		ind3 = ind3 + temp;
		y = y / 10;
	}
	reverse(ind3.begin(),ind3.end());
	m = bst.tm_mon + 1;
	while (m != 0) {
		temp = '0' + m % 10;
		mon = mon + temp;
		m = m / 10;
	}
	reverse(mon.begin(), mon.end());
	d = bst.tm_mday;
	while (d != 0) {
		temp = '0' + d % 10;
		day = day + temp;
		d = d / 10;
	}
	reverse(day.begin(), day.end());
	bst.tm_hour = (bst.tm_hour + 8) % 24;
	while (bst.tm_hour != 0) {
		temp = '0' + bst.tm_hour % 10;
		hour = hour + temp;
		bst.tm_hour = bst.tm_hour / 10;
	}
	reverse(hour.begin(), hour.end());
	while (bst.tm_min != 0) {
		temp = '0' + bst.tm_min % 10;
		min = min + temp;
		bst.tm_min = bst.tm_min / 10;
	}
	reverse(min.begin(), min.end());
	sum = ind3 + "年 " + mon + "月 " + day + "日 " + hour + ':' + min;
	for (int j = 0; j < sum.length(); j++) {
		tim[j] = sum[j];
	}
	tim[sum.length()] = '\0';
	getline(cin,ind);
	ind = ind + ".txt";
	ind2 = ind2 + ind;
	cout << "输入使用状态" << ": ";
	scanf("%s", cmp2);
	for (int i = 0; i < ind2.length(); i++) {
		cmp[i] = ind2[i];
		
	}
	cmp[ind2.length()] = '\0';
	ind = "卡号： " + ind;
	for (int i = 0; i < ind.length(); i++) {
		if (i < ind.length()-4) { 
			cmp4[i] = ind[i]; 
		}
     }
	cmp4[ind.length()-4] = '\0';
	if ((_access("D:\\360MoveData\\Users\\Administrator\\Desktop\\岛风go", 0)) == -1) {
		_mkdir("D:\\360MoveData\\Users\\Administrator\\Desktop\\岛风go");
		cout << "已创建文件夹" << endl;
		}
	if ((fp = fopen(cmp, "rb")) == NULL) {
		fp = fopen(cmp, "w");
		fputs(cmp4, fp);
		fseek(fp, 1L, 1);
		fputc('\n', fp);
		fputs(cmp2, fp);
		fseek(fp, 1L, 1);
		fputc('\n', fp);
		fseek(fp, 0L, 1);
		fputs(tim,fp);
		flag = true;
	}
		else {
		cout << "cnm文件已存在" << endl;
		system("pause");
		return 0;
	}
	system("pause");
}