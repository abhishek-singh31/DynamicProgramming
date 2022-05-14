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
    int diff;
    cin>>diff;
    int req=(diff+sum);
    if(req&1){
        cout<<0<<endl;
    }
    else{
        int dp[n+1][req/2+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)dp[i][j]=0;
                if(j==0)dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=req/2;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] + dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout<<dp[n][req/2]<<endl;
    }  
    return 0;
}