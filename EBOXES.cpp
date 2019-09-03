//SPOJ Question Link: https://www.spoj.com/problems/EBOXES/
//Please read the question properly to understand the solution.
/*Solution: Consider the following test case
	N(Initial number of boxes on the table)=11
	K(Number of smaller boxes)=8
	T(Number of times the process is repeated)=2
	F(Total number of empty boxes remaining)=102

	Hence the equation becomes:
	N - x + Kx - y + Ky = F
	N + (K-1)x + (K-1)y = F
	x + y = (F-N)/(K-1)
	where,
		x: A random number of type1 boxes selected.
		y: A random number of type2 boxes selected.
	x + y = Number of non empty boxes.
	Therefore, the total number of boxes on the table = Empty boxes + non-empty boxes
	Total boxes = F + (x+y)
*/
//Implementation
#include<bits/stdc++.h>
using namespace std;
int main(void){
	int C;
	cin >> C;
	while(C!=0){
		int N,K,T,F;
		cin >> N >> K >> T >> F;
		long long int total=F;
		total += ((F-N)/(K-1));
		cout << total << "\n";
		C--;
	}
	return 0;
}