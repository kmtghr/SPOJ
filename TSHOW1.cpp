#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(void){
	int N;
	cin >> N;
	while(N!=0){
		ll K;
		cin >> K;
		ll val=0,digits=0,bin;
		while(val<K){
			val += pow(2,digits);
			digits++;
		}
		if(val==K){
			bin=0;
		}
		else{
			digits--;
			val -= pow(2,digits);
			bin=K-val;
		}
		string str;
		while(bin){
			if(bin%2==0){
				str += '5';
			}
			else{
				str += '6';
			}
			bin = bin >> 1;
		}
    reverse(str.begin(),str.end());
		int len = str.length();
		string str2;
		if(digits>len){
			int count = digits-len;
			while(count!=0){
				str2 += '5';
        count--;
			}
		}
		str2 = str2.append(str);
		cout << str2 << "\n";
		N--;
	}
	return 0;
}