#include <stdio.h>
#include <iostream>

using namespace std;
const int M=1e5;

int a[M]={3,1,5,2,4,6,3,8};
int dp[M];

int lis (int a[], int n){
	int ans=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				dp[i]=max(dp[i],dp[j]+1)
			}
		}
		ans=max(ans,dp[i]);
	}
	return ans;
}

int dp1[M],int nli[M];

int lis1 (int a[],int n){
	int ans=0;
	for(int i=0;i<n;i++){
		int k=lower_bound(nli,nli+nn,a[i])-nli;
		if(k==ans) ans++;
		nli[k]=a[i];
		dp1[i]=k+1;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	
	return 0;
}