#include<bits/stdc++.h>
using namespace std;

int main(){
	int a , b ,x;
	cin >> a >> b >> x;
	int one, zero;
	zero = x / 2 + x % 2;
	one = zero + (x % 2 == 0 ? 1 : 0);
	string s ;
	for(int i = 0 ; i < a - one + 1 ; i ++)
	    s += "1";
    for(int i = 0 ; i < b - zero + 1 ; i ++)
        s += "0";
	while(-- one ){
		s += "1";
		if(-- zero)
		    s += "0";
	}
	cout << s;
	return 0 ;
} 