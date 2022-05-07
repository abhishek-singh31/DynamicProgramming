#include<bits/stdc++.h>
using namespace std;
bool subsetSum(int arr[],int sum,int n){
    if(n==0){
        return sum==0;
    }
    if(arr[n-1]<=sum){
        return subsetSum(arr,sum-arr[n-1],n-1) || subsetSum(arr,sum,n-1);
    }
    else{
        return subsetSum(arr,sum,n-1);
    }
}
int main(){
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