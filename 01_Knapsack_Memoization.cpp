#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapsack(int wt[], int val[], int W,int n){
    if(n==0 || W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    if(wt[n-1]<=W){
        return dp[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else{
        return dp[n][W]=knapsack(wt,val,W,n-1);
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int val[n];
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(wt,val,W,n);
    return 0;
}