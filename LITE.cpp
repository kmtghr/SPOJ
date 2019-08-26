#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100005
int tree[4*MAX_SIZE];
bool lazy[4*MAX_SIZE];
void updateTree(int node,int start,int end,int l,int r){
	if(lazy[node]){
		tree[node] = (end-start+1)-tree[node];
		if(start!=end){
			lazy[2*node+1] = !lazy[2*node+1];
			lazy[2*node+2] = !lazy[2*node+2];
		}
		lazy[node]=false;
	}
	if(start>r ||end<l)	return;
	if(l<=start && end<=r){
		tree[node] = (end-start+1)-tree[node];
		if(start!=end){
			lazy[2*node+1] = !lazy[2*node+1];
			lazy[2*node+2] = !lazy[2*node+2];
		}
		return;
	}
	int mid = (start+end)/2;
	updateTree(2*node+1,start,mid,l,r);
	updateTree(2*node+2,mid+1,end,l,r);
	tree[node] = tree[2*node+1] + tree[2*node+2];
}
int queryTree(int node,int start,int end,int l,int r){
	if(lazy[node]){
		tree[node] = (end-start+1)-tree[node];
		if(start!=end){
			lazy[2*node+1] = !lazy[2*node+1];
			lazy[2*node+2] = !lazy[2*node+2];
		}
		lazy[node]=false;
	}
	if(start>r || end<l)	return 0;
	if(l<=start && end<=r)	return tree[node];
	int mid = (start+end)/2;
	int n1 = queryTree(2*node+1,start,mid,l,r);
	int n2 = queryTree(2*node+2,mid+1,end,l,r);
	return (n1+n2);
}
int main(void){
	int N,M;
	cin >> N >> M;
	while(M!=0){
		int a,b,c;
		cin >> a >> b >> c;
		if(a==0){
			updateTree(0,0,N-1,b-1,c-1);
		}
		else{
			cout << queryTree(0,0,N-1,b-1,c-1) << "\n";
		}
		M--;
	}
	return 0;
}