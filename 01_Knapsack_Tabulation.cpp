#include<bits/stdc++.h>
using namespace std;
int main(){
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
    int dp[n+1][W+1];

    // Step 1 : Initialization
    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }

    // Step 2 : Iterative
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][W]<<endl;
    return 0;
}