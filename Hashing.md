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
## Faster map using hashtable
#### Single map
```cpp
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
gp_hash_table<long long, int, custom_hash> mp;
```
#### Pairs
```cpp
struct hashPi{
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(pair<uint64_t,uint64_t> x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x.first + FIXED_RANDOM)^(splitmix64(x.second + FIXED_RANDOM) >> 1);
	}
};
gp_hash_table<pi,int,hashPi> mp; // is there an edge between the two nodes?
```

