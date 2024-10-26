## Krushal
Greedily add edges
```cpp
void solve(){
    int n,m;cin>>n>>m;
    vector <tuple<int,int,int>> edges;
    // reset dsu
    rep(i,1,n+1){
        rdsu[i]=0;
        pdsu[i]=i;
    }
    rep(i,0,m){
        int a,b,w;cin>>a>>b>>w;
        edges.pb({w,a,b});
    }
    sort(edges.begin(),edges.end()); // sort by weight
    ll ans = 0;
    rep(i,0,m){ // process edges  
        int weight = get<0>(edges[i]);
        int a = get<1>(edges[i]);  
        int b = get<2>(edges[i]);  
        if(get(a) == get(b)){ // same connected component
            continue; // we skip
        }
        ans += weight;
        unite(a,b);
    }
    // check if IMPOSSIBLE
    // check if node 1 is in every nodes connected component
    rep(i,2,n+1){
        if(get(1) != get(i)){ // not in same cc
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    cout<<ans<<endl;
}   
```

## Prims
Go through each node, Dijkstra-like process

```cpp
void solve(){
    int n,m;cin>>n>>m;
    vector <pi> aj[n+1];
    int vis[n+1]={0};
    rep(i,0,m){
        int a,b,w;cin>>a>>b>>w;
        aj[a].pb({b,w});
        aj[b].pb({a,w});
    }
    ll ans = 0;
    int start = 1; // random node
    // pq that sorts smallest weight to largest
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start}); // 0 weight to add edge
    while (!pq.empty()) {
        pair<ll,int> x = pq.top(); // minimum weight node
        ll weight = x.first; 
        int node = x.second;
        pq.pop();
        if (vis[node]) { continue; } // we already processed node
        vis[node]=1; 
        ans += weight;
        rep(i,0,aj[node].size()){ // push every neighbour into pq 
        // hope that the weight is minimum
            pi y = aj[node][i]; // {node, weight}
            if(!vis[y.first]){ // neighbour not in tree
                pq.push({y.second, y.first}); // sort node by weight
            }
        }
    }
    // check IMPOSSIBLE
    // if all nodes were visited(processed), the belong in same tree
    rep(i,1,n+1){
        if(!vis[i]){ // node wasnt visited
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }
    cout<<ans<<endl;
} 
```
