#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    int dp[n+1][sum+1];

    // Step 1: Initialization 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }

    // Step 2: Iterative
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][sum]){
        cout<<"Subset Present\n";
    }
    else{
        cout<<"Subset Not Present\n";
    }
    return 0;
}