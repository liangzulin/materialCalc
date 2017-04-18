#ifndef TEST1_H
#define TEST1_H

#include<string>
#include<iostream>
using namespace std;
void runTest(){
	string a="wefawef123g32r2";
//	char* c = "wefawef123g32r2";
	string b=a.substr (3,5);
	cout<<a<<endl;
	cout<<b<<endl;
	
	string str="We think in generalities, but we live in details."; // (quoting Alfred N. Whitehead)
	string str2 = str.substr (3,5);     // "think"
	size_t pos = str.find("live");      // position of "live" in str
	string str3 = str.substr (pos);     // get from "live" to the end
	cout << str2 << ' ' << str3 << '\n';
}

#endif
