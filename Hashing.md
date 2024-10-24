# String Hashing
**One string:**
```cpp
mt19937 RNG((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll M = (1LL << 61) - 1; // large prime for mod
const ll P = uniform_int_distribution<ll>(0, M - 1)(RNG); // random base
ll hsh[200005]={0}; // LENGTH OF STRING 
vector <ll> pw = {1LL};
__int128 mul(ll a, ll b) { return (__int128)a * b; }
ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
void calchash(string s){
    // precalc pow
    while (pw.size() < s.size()) {
        pw.push_back(mod_mul(pw.back(), P) % M);
    }
    hsh[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			hsh[i + 1] = (mul(hsh[i], P) + s[i]) % M;
		}
}
long long gethash(int start, int end) { // inclusive: string [start...end]
	ll raw_val =
		    hsh[end + 1] - mod_mul(hsh[start], pw[end - start + 1]);
		return (raw_val + M) % M;
}
```
**Multi string:**
```cpp
mt19937 RNG((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const ll M = (1LL << 61) - 1; // large prime for mod
const ll P = uniform_int_distribution<ll>(0, M - 1)(RNG); // random base
ll hsh[20][10005]={0};
vector <ll> pw = {1LL};
__int128 mul(ll a, ll b) { return (__int128)a * b; }
ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
void calchash(int osa,string s){
    
    hsh[osa][0] = 0;
		for (int i = 0; i < s.size(); i++) {
			hsh[osa][i + 1] = (mul(hsh[osa][i], P) + s[i]) % M;
		}
}
long long gethash(int osa, int start, int end) {
	ll raw_val =
		    hsh[osa][end + 1] - mod_mul(hsh[osa][start], pw[end - start + 1]);
		return (raw_val + M) % M;
}
void solve(){
    // precalc pow
    while (pw.size() < 10005) {
        pw.push_back(mod_mul(pw.back(), P) % M);
    }
}
```
### Faster map using hashtable
```cpp

```

