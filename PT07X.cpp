#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int dp[MAX][2];
int calCover(vector<int> AdjList[],int root,int state,int N,int parent){
	if(dp[root][0]!=-1 && dp[root][1]!=-1){
		return min(dp[root][0],dp[root][1]);
	}
	int cost=0;
	vector<int>::iterator itr=AdjList[root].begin();
	for(;itr!=AdjList[root].end();itr++){
		if(*itr!=parent){
			dp[*itr][0]= calCover(AdjList,*itr,0,N,root);
			dp[*itr][1]= 1 + calCover(AdjList,*itr,1,N,root);
			if(state==0){
				cost += dp[*itr][1];
			}
			else{
				cost += min(dp[*itr][1],dp[*itr][0]);
			}
		}
	}
	return cost;
}
int vtxCover(vector<int> AdjList[],int N){
	memset(dp,-1,sizeof(dp));
	dp[0][0] = calCover(AdjList,0,0,N,-1);
	dp[0][1] = 1+calCover(AdjList,0,1,N,-1);
	return min(dp[0][0],dp[0][1]);
}
int main(void){
	int N;
	cin >> N;
	int s,d;
	vector<int> AdjList[N];
	for(int i=0;i<N-1;i++){
		cin >> s >> d;
		AdjList[s-1].push_back(d-1);
		AdjList[d-1].push_back(s-1);
	}
	cout << vtxCover(AdjList,N) << "\n";
	return 0;
}