## Dijkstra
rep(i,1,n+1){
	distance[i] = INF;
	vis[i] = 0;
}
distance[x] = 0;
// pq that sorts shortest path to longest
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

int start = 0;
dist[start] = 0;  // The shortest path from a node to itself is 0
pq.push({0, start}); // 0 dist
while (!pq.empty()) {
    pair<ll,int> x = pq.top(); // {curr min dist of node, curr node}
    ll cdist = x.first;  
    int node = x.second;
    pq.pop();
    if (vis[node]) { continue; } // we already processed node
    vis[node]=1; // visit node(otherwise TLE)
    rep(i,0,aj[node].size()){
    		pi y = aj[node][i]; // {node, weight}
    		// If we can reach a neighbouring node faster, we update its min dist
    		if (cdist + y.second < dist[y.first]) {
    			pq.push({dist[y.first] = cdist + y.second, y.first}); // push neighbour into pq
    		}
    }
}

## Floyd Warshall
Get all distance $a$ to $b$ in $O(n^3)$
```cpp

    int n,m,q;cin>>n>>m>>q;
    ll adj[n+1][n+1]={0}; //adjacency matrix
    rep(i,1,n+1){
	rep(j,1,n+1){
	    adj[i][j]=1000000000000000005;
        }
    }
    rep(i,0,m){
        ll a,b,w; cin>>a>>b>>w;
        adj[a][b]=min(adj[a][b],w); // account for multiple edges
        adj[b][a]=min(adj[a][b],w);
    }
    // process dist
    ll dist[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0; // dist(a,a) = 0
            else if (adj[i][j]!=1000000000000000005) dist[i][j] = adj[i][j]; // there is an edge between 2 nodes
            else dist[i][j] = 1000000000000000005; // else we set to INF
        }
    }
    
    
    for (int k = 1; k <= n; k++) { // for every round we pick node k as middle
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                // for every pair of nodes we see if k is in the path
                // if it was only constructed form nodes 1...k
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        if(dist[a][b]==1000000000000000005){ // = INF
            cout<<-1<<"\n";
        }
        else{
            cout<<dist[a][b]<<"\n";
        }
        
    }

```

When working with real number weights, use:
```cpp
if (d[i][k] + d[k][j] < d[i][j] - eps) // adjust comparison
    d[i][j] = d[i][k] + d[k][j]; 
```
