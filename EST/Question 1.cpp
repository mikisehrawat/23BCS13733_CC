#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pi;
template <typename K, typename V>
using umap = unordered_map<K,V>;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define endl "\n"
#define REP(i,a,b) for (int i = a; i <= b; i++)

class DSU {
private:
    vector<int> parent, size;

public:
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (size[px] < size[py])
            swap(px, py);

        parent[py] = px;
        size[px] += size[py];
    }
};

void vin(vl& ht){
    for(ll& i : ht)cin>>i;
}
void thesort(vector<ll>& ht){
    sort(ht.begin(),ht.end());
}
void thesort(vector<int>& ht){
    sort(ht.begin(),ht.end());
}
void thesort(vector<pair<ll,ll>>& ht){
    sort(ht.begin(),ht.end());
}
void vtravel(vl &ht){
    for(ll i: ht)cout<<i<<" ";
    cout<<endl;
}
long long gcd(long long a, long long b) {
    return (b == 0) ? a : gcd(b, a % b);
}
bool is_s_sorted(vl ht){
    for(int i=0;i<ht.size()-1;i++){
        if(ht[i]>=ht[i+1])return false;
    }
    return true;
}

ll  bsearch(vl ht, ll t,ll l,ll h){
    if(l>h)return -1;
    ll m=(l+h)/2;
    if(ht[m]==t)return m;
    else if(ht[m]<t){
        return bsearch(ht,t,m+1,h);
    }
    return bsearch(ht,t,l,m-1);
}
bool isprime(int n) {
    if (n <= 1)return false;
    if (n <= 3)return true;
    if (n % 2 == 0 || n % 3 == 0)return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
vector<int> sieve(int N) {
    vector<int> lp(N+1);
    vector<int> pr;

    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }
    return pr;
}

vector<vector<int>> graphmaker(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> ht(n+1,vector<int>(1,0));
    while(e--){
        int x,y;
        cin>>x>>y;
        ht[x].PB(y);
    }
    return ht;
} 

void toposort(const vector<vector<int>>& ht){
    int n=ht.size();
    vector<int> ind(n,0);
    for(int i=1;i<n;i++){
        for(int j=0;j<ht[i].size();j++){
            ind[ht[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=1;i<n;i++)if(ind[i]==0)q.push(i);
    while(q.size()){
        int element=q.front();
        q.pop();
        cout<<element<<" ";
        for(int i : ht[element]){
            ind[i]--;
            if(ind[i]==0 and i!=0)q.push(i);
        }
    }
    cout<<endl;
    return;
}

ll modpow(ll x, ll n, ll m = 0) {
    if (n == 0) return (m == 0) ? 1 : 1 % m;
    ll u = modpow(x, n / 2, m);
    if (m == 0) {
        u = (u * u);
        return (n % 2 == 0) ? u : (u * x);
    } else {
        u = (u * u) % m;
        return (n % 2 == 0) ? u : (u * x) % m;
    }
}

vl primefactors(ll n){
    vl ans;
    while(n%2==0){
        ans.PB(2);
        n/=2;
    }
    for(int i=3;i*i<=n;i++){
        while(n%i==0){
            ans.PB(i);
            n=n/i;
        }
    }
    if(n>2)ans.PB(n);
    
    return ans;
}

ll cal(ll n,ll k){
    if(n<=k)return(n*(n+1)/2);
    n-=k;
    n=k-n-1;
    ll net=((k-1)*k)/2-(n*(n+1))/2;
    return (k*(k+1)/2)+net;
}

void solve(){
    ll m,n;
    cin>>m>>n;
    vector<vl> arr(m+1,vl(n+1,0));
    arr[0][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    cout<<arr[m][n]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        solve();
        
    }
    return 0;
}
 