#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum&1){
        cout<<"Impossible\n";
        return 0;
    }
    
    int dp[n+1][sum/2+1];
    
    // Step 1: Initialization 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum/2;j++){
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
        for(int j=1;j<=sum/2;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    if(dp[n][sum/2]){
        cout<<"Possible\n";
    }
    else{
        cout<<"Impossible\n";
    }
    return 0;
}