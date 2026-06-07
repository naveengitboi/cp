#include <bits/stdc++.h>
#include <climits>
using namespace std;

#define mod 1000000007
#define int long long
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vs vector<string>
#define vvs vector<vector<string>>
#define mii map<int, int>
#define si set<int>
#define mll map<long long, long long>
#define pb push_back
#define f first
#define s second
#define b begin
#define e end
#define rb rbegin
#define re rend
#define gcd(a, b) __gcd(a,b)
#define lcm(a,b) (a/(gcd(a, b)*b))
#define bug(x) cout<<#x<<" "<<x<<endl

// functions
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
bool isPrime(int n){
    if(n < 2) return false;
    for(int i =2; i <= round(sqrt(n)); i++){
        if(n%i == 0) return false;
    }
    return true;
}
void _sort(vi& a,bool rev=false){
    if(rev){sort(a.rb(), a.re()); return;}
    sort(a.b(), a.e()); return;
}
void _input(vi& a, int s, int  e){
    for(int i = s; i <= e; i++){
        cin>>a[i];
    }
}






void solve(map<int, vi>& graph, vi& visited, int node, int end, int dist, mii& mp){
    if(node == end){
        // cout<<"Distance "<<node<<" "<<dist<<endl;
        mp[dist] = (mp[dist]+1)%mod;
        return;
    }
    visited[node] = true;
    for(auto n:graph[node]){
        if(visited[n] == false){
            solve(graph, visited, n, end, dist+1, mp);
        }
    }
    visited[node] = false;
}

int32_t main_atmp1() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    map<int, vi> graph;
    mii mp;
    while(m--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vi visited(n+1, false);
    solve(graph,visited, 1, n, 0, mp);
    int minDist = INT_MAX;
    int ans = 0;
    for(auto d:mp){
        // cout<<d.first<<" "<<d.second<<endl;
        if(d.first < minDist){
            minDist = d.first;
            ans = d.second;
        }
    }
    cout<<ans<<endl;
    return 0;
}



int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m;
    map<int, vi> graph;
    mii mp;
    while(m--){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    vi dist(n+1, 1e18);
    vi paths(n+1, 0);
    dist[1] = 0;
    paths[1] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: graph[u]){
            if(dist[v] == 1e18){
                dist[v] = dist[u] + 1;
                paths[v] = paths[u];
                q.push(v);
            }
            else{
                //already seen
                if(dist[v] == dist[u] + 1){
                    paths[v] = (paths[v] + paths[u])%mod;
                }
            }
        }
    }

    cout<<paths[n]<<endl;
    return 0;
}