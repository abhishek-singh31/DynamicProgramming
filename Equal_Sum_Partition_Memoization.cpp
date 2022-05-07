#include<bits/stdc++.h>
using namespace std;
int dp[105][10005];
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
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum&1){
        cout<<"Impossible\n";
    }
    else{
        memset(dp,-1,sizeof(dp));
        if(subsetSum(arr,sum/2,n-1)){
            cout<<"Possible\n";
        }
        else{
            cout<<"Impossible\n";
        }
    }
    return 0;
}