#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)dp[i][j]=0;
            if(j==0)dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    int ans=INT_MAX;
    for(int i=1;i<=sum/2;i++){
        if(dp[n][i])
            ans=min(ans,sum-2*i);
    }
    cout<<ans<<endl;
    return 0;
}