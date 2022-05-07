#include<bits/stdc++.h>
using namespace std;
int dp[105][100005];
bool subsetSum(int arr[],int sum,int n){
    if(sum==0){
        return true;
    }
    if(n==0){
        return false;
    }
    if(dp[n][sum]!=-1)return dp[n][sum];
    if(arr[n-1]<=sum){
        return dp[n][sum]=subsetSum(arr,sum-arr[n-1],n-1) || subsetSum(arr,sum,n-1);
    }
    else{
        return dp[n][sum]=subsetSum(arr,sum,n-1);
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
    if(subsetSum(arr,sum,n)){
        cout<<"Subset Present\n";
    }
    else{
        cout<<"Subset Not Present\n";
    }
    return 0;
}