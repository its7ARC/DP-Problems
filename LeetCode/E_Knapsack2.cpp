//
//  main.cpp
//  knapSack2_D
//
//  Created by Anshuman Raj Chauhan_1 on 04/12/20.
//  Copyright © 2020 Anshuman Raj Chauhan_1. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#define ll long long
using namespace std;
#define V 100000
#define BIG 100000000000000
struct Item{
    ll wt;
    ll val;
};


ll maxVal(vector<Item> v, ll n, ll W){
    
    vector<vector<ll>> dp(n+1);
    for(ll i = 1;i <= n; i++){
        for(ll j = 0; j <= V; j++){
            dp[i].push_back(BIG);
        }
    }
    
    dp[1][v[1].val] = v[1].wt;
    
    for(ll i = 2; i <= n; i++){
        dp[i][v[i].val] = min(dp[i-1][v[i].val],v[i].wt);
        for(ll j = 1; j <= V; j++){
            if(j-v[i].val >= 0){
                dp[i][j] = min(dp[i-1][j], dp[i][j]);
                dp[i][j] = min(dp[i][j],dp[i-1][j-v[i].val] + v[i].wt);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    ll ans = 0;
    for(ll i = V; i >= 0; i--){
        if(dp[n][i] <= W){
            ans = i;
            break;
        }
    }
    
    return ans;
    
}
 



int main(){
    
    ll n, W;
    cin >> n >> W;
    vector<Item> v(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> v[i].wt >> v[i].val;
    }
    cout << maxVal(v,n,W) << "\n";
    cout << maxVal2(v,n,W) << "\n";
    return 0;
    
}
