#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
int dp[MAX][2];
//root = the node we are currently on.
//state = It has two values. 0: indicates the parent of root was excluded from vertex cover. 1: indicates that the parent of root was included in the vertex cover
int calCover(vector<int> AdjList[],int root,int state,int N,int parent){
	//Base condition
	if(dp[root][0]!=-1 && dp[root][1]!=-1){
		return min(dp[root][0],dp[root][1]);
	}
	int cost=0; //To store the sum of the minimum vertex covers of all the children of root.
	vector<int>::iterator itr=AdjList[root].begin();
	//DFS
	for(;itr!=AdjList[root].end();itr++){
		if(*itr!=parent){	//Do not traverse the parent again.
			dp[*itr][0]= calCover(AdjList,*itr,0,N,root); 	//Vertex cover obtained by excluding *itr
			dp[*itr][1]= 1 + calCover(AdjList,*itr,1,N,root);	//Vertex cover obtained by incuding *itr
			if(state==0){
				cost += dp[*itr][1];	//If parent of *itr was excluded then its child(*itr) must be included
			}
			else{
				cost += min(dp[*itr][1],dp[*itr][0]);	//If parent of *itr was included then take the minimum of the vertex cover obtained by
			}						// including and excluding *itr
		}
	}
	return cost;
}
int vtxCover(vector<int> AdjList[],int N){
	memset(dp,-1,sizeof(dp));	//initializing the entire dp array with -1
	dp[0][0] = calCover(AdjList,0,0,N,-1);	//vertex cover obtained by excluding vertex 0
	dp[0][1] = 1+calCover(AdjList,0,1,N,-1);	//vertex cover obtained by including vertex 0
	return min(dp[0][0],dp[0][1]);	//Returning the minimum of the above two
}
int main(void){
	int N;
	cin >> N;
	int s,d;
	vector<int> AdjList[N];	//An array of vectors to store edges.
	for(int i=0;i<N-1;i++){
		cin >> s >> d;
		// Bi-directional
		AdjList[s-1].push_back(d-1);
		AdjList[d-1].push_back(s-1);
	}
	cout << vtxCover(AdjList,N) << "\n";
	return 0;
}