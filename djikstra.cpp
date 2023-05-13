#include <bits/stdc++.h>
using namespace std;
using lli=long long;

#define loop(i,n) for(int i=0; i<n; i++)
#define INF 1e18

const lli mod = 1e9+7;
vector<set<pair<lli,lli>>> adj;
vector<lli> dist;

void djikstra()
{
    priority_queue <pair<lli,lli>> pq;
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty())
    {
        lli x=pq.top().second;
        lli d = -pq.top().first;
        pq.pop();

        if(d > dist[x]) continue;
        
        for(auto p: adj[x])
        {
            lli wt = p.second;
            lli child = p.first;

            if(dist[x]+wt < dist[child])
            {
                dist[child] = dist[x]+wt;
                pq.push({-dist[child],child});
            }
        }
    }
}

void solver()
{
    lli n,m; cin >> n >> m;
    adj.resize(n+1);
    dist.resize(n+1,INF);

    loop(i,m)
    {
        lli x,y,z; cin >> x >> y >> z;
        adj[x].insert({y,z});
    }

    djikstra();
    for(int i=1; i<=n ;i++)
    {
        cout << dist[i] << " ";
    } cout << "\n";
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

#ifdef MULTICASE
    lli t;
    cin>>t;
    while(t--)
#endif
    solver();
    return 0;
}
