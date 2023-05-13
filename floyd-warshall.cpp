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

lli dist[505][505];

#define INF 1e18

void floyd(int n)
{
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);   
}

void solver()
{
    int n,m,q; cin >> n >> m >> q;

    loop(i,n){
        loop(j,n)
            {
                if(i==j) dist[i+1][i+1]=0;
                else dist[i+1][j+1]=INF;
            }
    }

    loop(i,m){
        lli x,y,c; cin >> x >> y >> c;
        if(c<dist[x][y]){
            dist[x][y]=c;
            dist[y][x]=c;
        }
    }

    floyd(n);

    loop(k,q)
    {
        int a,b; cin >> a >> b;
        if(dist[a][b]!=INF) cout << dist[a][b] << "\n";
        else cout << "-1\n";
    }
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
