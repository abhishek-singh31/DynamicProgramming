#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int countSubsetSum(int arr[],int sum,int n){
    if(sum==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    if(dp[n][sum]!=-1)return dp[n][sum];
    if(arr[n-1]<=sum){
        return dp[n][sum]=countSubsetSum(arr,sum-arr[n-1],n-1) + countSubsetSum(arr,sum,n-1);
    }
    else{
        return dp[n][sum]=countSubsetSum(arr,sum,n-1);
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    cout<<countSubsetSum(arr,sum,n);
    return 0;
}