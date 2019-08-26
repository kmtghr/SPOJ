#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
using namespace std;
int main(void){
	int P;
	cin >> P;
	while(P!=0){
		cpp_int N,K,M;
		cin >> N >> K >> M;
		long long int t=0;
		N *= K;
		while(N<=M){
			t++;
			N *= K;
		}
		cout << t << "\n";
		P--;
	}
	return 0;
}