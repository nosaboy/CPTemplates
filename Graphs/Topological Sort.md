## Normal
```cpp
vi aj[200005];
int vis[200005];
vi sorted; // topologically sorted array
void dfs(int n){
    vis[n] = 1;
    rep(i,0,aj[n].size()){
        if(!vis[aj[n][i]]){ // not yet discovered
            dfs(aj[n][i]); // visit and process it
        }
    }
    // after processing every neighbour node, we push current to the back
    sorted.pb(n); // this way we process all neighbours before current
}
void solve(){
    int n,m; cin>>n>>m;
    // reset()
    rep(i,0,n+1){
        vis[i]=0;
        aj[i].clear();
    }
    sorted.clear();

    rep(i,0,m){
        int a,b;cin>>a>>b;
        aj[a].pb(b); // course a points to course b
    }
    rep(i,1,n+1){
        if(!vis[i]){ // go through every node with indegree 0
            dfs(i);
        }
    }
    reverse(sorted.begin(),sorted.end()); // end up in order
    int idx[n+1];
    rep(i,0,sorted.size()){ // get index for each node inr sorted arr
        idx[sorted[i]] = i;
    }
    // check if there contains a cycle
    rep(i,1,n+1){
        rep(j,0,aj[i].size()){
            if(idx[aj[i][j]] <= idx[i]){ 
            // index of neighbour it points to is in front of than curr node
            // this means there is a cycle
                cout<<"IMPOSSIBLE\n";
                return;

            }
        }
    } 
    rep(i,0,sorted.size()){
        cout<<sorted[i]<<" ";
    }
    cout<<endl;
}
```

## Get DAG

```cpp
vi aj[200005];
int vis[200005];
stack <int> st; // current path
bool instack[200005]; // is current node in stack
vi cycle; // answer
void dfs(int n){
    vis[n] = 1;
    st.push(n); instack[n]=1;
    rep(i,0,aj[n].size()){
        if(cycle.size() == 0 && instack[aj[n][i]]){ // found a cycle
            // we didnt find a cycle yet
            int start = aj[n][i];
            cycle.pb(start);
            while(!st.empty() && st.top() != start){ // backtrack path
                cycle.pb(st.top()); 
                st.pop();
            }
            cycle.pb(start);

        }
        if(!vis[aj[n][i]]){ // not yet discovered
            dfs(aj[n][i]); // visit and process it
        }
        
    }
    instack[n] = 0; // we are finished processing all neighbours
    if(!st.empty()){ // not doing this will cause RTE 
        // while storing cycle we mightve popped more elements from stack
        st.pop(); // we pop current node from stack
    }
    
}
void solve(){
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int a,b;cin>>a>>b;
        aj[a].pb(b); // course a points to course b
    }
    rep(i,1,n+1){
        if(!vis[i]){ // go through every node with indegree 0
            dfs(i);
        }
    }
    if(cycle.size() == 0){ // no nodes in cycle, didnt find cycle
        cout<<"IMPOSSIBLE\n";
        return;
    }
    reverse(cycle.begin(),cycle.end());
    cout<<cycle.size()<<endl;
    rep(i,0,cycle.size()){
        cout<<cycle[i]<<" ";
    }
    cout<<endl;
}

```
