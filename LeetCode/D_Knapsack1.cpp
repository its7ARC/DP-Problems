//
//  main.cpp
//  knapsack1
//
//  Created by Anshuman Raj Chauhan_1 on 04/12/20.
//  Copyright © 2020 Anshuman Raj Chauhan_1. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#define ll long long
using namespace std;

struct Item{
    ll wt;
    ll val;
};


ll value(vector<Item> v, ll n, ll W){
    
    vector<vector<ll>> dp(n+1);
    for(ll i = 1; i <= n; i++){
        for(ll j = 0; j <= W; j++){
            dp[i].push_back(0);
        }
    }
    
    dp[1][v[1].wt] = v[1].val;
    for(ll i = 2; i <= n; i++){
        for(ll j = 1; j <= W; j++){
            if(j >= v[i].wt){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-v[i].wt] + v[i].val);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    ll ans = 0;
    for(ll i = 1; i <= W; i++){
        ans = max(ans, dp[n][i]);
    }
    
    return ans;
}

int main(){
    
    ll n, w;
    cin >> n >> w;
    vector<Item> v(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> v[i].wt >> v[i].val;
    }
    
    cout << value(v,n,w) << "\n";
    
    return 0;
}
