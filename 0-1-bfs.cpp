#include <bits/stdc++.h>
using namespace std;
using lli = long long;

#define loop(i,n) for(int i=0; i<n; i++)
#define debarr(a,n) cout<<#a<<" : ";for(int i=0;i<n;i++) cerr<<a[i]<<" "; cerr<<endl;
#define debmat(mat,row,col) cout<<#mat<<" :\n";for(int i=0;i<row;i++) {for(int j=0;j<col;j++) cerr<<mat[i][j]<<" ";cerr<<endl;}
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const unordered_set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const unordered_map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const multiset<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}

#define MULTICASE
#define INF 1e9

vector<vector<pair<int,int>>> g;
vector<int> dist;

void bfs()
{
    deque <pair<int,int>> dq;
    dq.push_front({0,1});

    while(!dq.empty())
    {
        pair<int,int> p = dq.front(); dq.pop_front();
        if(p.first>dist[p.second]) continue;

        for(auto v: g[p.second]){
            if(v.second+p.first<dist[v.first])
            {
                dist[v.first]=v.second+p.first;
                if(v.second==0) dq.push_front({dist[v.first],v.first});
                else dq.push_back({dist[v.first],v.first});
            }
        }
    }
}

void solver()
{
    int n,m; cin >> n >> m;
    g.resize(n+1);
    dist.assign(n+1,INF);

    loop(i,m){
        int x,y; cin >> x >> y;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }

    bfs();
    if(dist[n]!=INF)cout << dist[n] << "\n";
    else cout << "-1\n";
    g.clear();
}


int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

#ifdef MULTICASE
    int t;
    cin>>t;
    while(t--)
#endif
    solver();
    return 0;
}
