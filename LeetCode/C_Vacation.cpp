//
//  main.cpp
//  vacation
//
//  Created by Anshuman Raj Chauhan_1 on 04/12/20.
//  Copyright © 2020 Anshuman Raj Chauhan_1. All rights reserved.
//

#include <iostream>
#include <vector>
#define ll long long
using namespace std;

struct Act{
    ll a;
    ll b;
    ll c;
};

ll points(vector<Act> v, ll n){
    
    vector<Act> dp(n+1);
    
    dp[1].a = v[1].a;
    dp[1].b = v[1].b;
    dp[1].c = v[1].c;
    
    for(ll i = 2; i <= n; i++){
        dp[i].a = max(dp[i-1].b + v[i].a, dp[i-1].c + v[i].a);
        dp[i].b = max(dp[i-1].c + v[i].b, dp[i-1].a + v[i].b);
        dp[i].c = max(dp[i-1].a + v[i].c, dp[i-1].b + v[i].c);
    }
    ll ans = max(dp[n].a, dp[n].b);
    ans = max(dp[n].c,ans);
    
    return ans;
}

int main(){
    
    ll n;
    cin >> n;
    vector<Act> v(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> v[i].a >> v[i].b >> v[i].c;
    }
    
    cout << points(v,n) << "\n";
    
    return 0;
}
