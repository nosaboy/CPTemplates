#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <ostream>
#include <ratio>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using orderedMultiset = tree<T ,null_type,std::less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define pb push_back
#define rep(i, a, b) for(int i = a; i < (b); ++i) 
#define all(x) (x).begin(), (x).end()
ll MOD = 1e9+7;
mt19937 RNG((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

ll add(ll x, ll y)
{
    x += y;
    while(x >= MOD) x -= MOD;
    while(x < 0) x += MOD;
    return x;
}  
 
ll mult(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}
ll lpow(ll x, ll y)
{
    if(y<0){
        return 0;
    }
    if(y == 0){
        return 1;
    }
    ll z = 1;
    while(y)
    {
        if(y & 1) z = mult(z, x);
        x = mult(x, x);
        y >>= 1;
    }
    return z;
}
bool prime(int x)
{
    for(int i = 2; i * 1ll * i <= x; i++)
        if(x % i == 0)
            return false;
    return true;    
}
 
ll inv(ll x) {
	return lpow(x, MOD - 2);
}
ll qexp(ll a, ll b, ll m) {
    ll res = 1;
    while (b) {
        if (b % 2) res = res * a % m;
        a = a * a % m;
        b /= 2;
    }
    return res;
}
ll divide(ll x, ll y)
{
    return mult(x, inv(y));
}
vector<ll> fact, invf;
 
void precompute(int n) {
    fact.assign(n + 1, 1); 
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    invf.assign(n + 1, 1);
    invf[n] = qexp(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i > 0; i--) invf[i] = invf[i + 1] * (i + 1) % MOD;
}
 
ll nCk(ll n,ll k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invf[k] % MOD * invf[n - k] % MOD;
    // return fact[n] * qexp(fact[k], MOD - 2, MOD) % MOD * qexp(fact[n - k], MOD - 2, MOD) % MOD;
}
 
 

int ask(int a,int b){
    cout<<"? "<<a<<" "<<b<<endl;
    int d;cin>>d;
    return d;
}

long long rng() { // output a random long long number
	static std::mt19937 gen(
	    std::chrono::steady_clock::now().time_since_epoch().count());
	return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}

/*
=======================================================================

========================================================================
*/



void solve(){

}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}; 
