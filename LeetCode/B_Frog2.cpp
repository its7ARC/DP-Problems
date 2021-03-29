
//Frog2
#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll cost(vector<ll> h, ll k, ll n){
    
    vector<ll> dp(n+1);
    
    dp[1] = 0;
    for(ll i = 2; i <= n; i++){
        ll cost = LLONG_MAX;
        for(ll j = i-1; j >= i-k && j > 0; j--){
            cost = min(cost,dp[j] + abs(h[j] - h[i]));
        }
        dp[i] = cost;
    
    }
    return dp[n];
    
}

int main(){
    
    ll n,k;
    cin >> n >> k;
    vector<ll> h(n+1);
    for(ll i = 1; i <= n; i++){
        cin >> h[i];
    }
    cout << cost(h,k,n) << "\n";
    
    return 0;
    
}
