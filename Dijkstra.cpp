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
