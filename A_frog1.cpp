#include <iostream>
using namespace std;

int cost(int *arr, int n){
    int dp[n+1];
    dp[1] = dp[0] = 0;
    dp[2] = abs(arr[2] - arr[1]);
    for(int i = 3; i <= n; i++){
        dp[i] = min(dp[i-1] + abs(arr[i] - arr[i-1]), dp[i-2] + abs(arr[i] - arr[i-2]));
    }
    return dp[n];
    
}

int main(){
    
    int n;
    cin >> n;
    int *arr = new int[n+1];
    
    for(int i = 1;i <= n; i++){
        cin >> arr[i];
    }
    cout << cost(arr, n) << "\n";
    
    return 0;
}
