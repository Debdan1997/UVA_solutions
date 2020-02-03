#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace std;
using namespace __gnu_pbds;
 
 
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define f first
#define s second
#define resz resize
#define ini ll_MAX
#define inl LLONG_MAX
#define MOD 1000000007
#define sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define F0R(i, a) for (ll i = 0; i < (a); i++)
#define FORR(i, a, b) for (ll i = a; i >= (b); i--)
#define F0RR(i, a) for (ll i = a; i >= 0; i--)
#define trav(a, x) for (auto& a : x)
#define pbds tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
 
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
 
using pii = pair<ll, ll>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vpdd = vector<pdd>;
using vvpdd = vector<vpdd>;
 
ll mod(ll a,ll b)
{
    return (b+a%b)%b;
}
 
ll gcd(ll a,ll b)
{
    if(b==0)return a;
    else return gcd(b,a%b);
}
ll po(ll a,ll b)
{
    ll ans = 1;
    while(b--)
        ans*=a;
    return ans;
}
ll pom(ll a,ll b,ll mod)
{
    if(b==0)return 1;
    ll k = pom(a,b/2,mod);
    if(b%2==0)return (k*k)%mod;
    else return ((k*k)*mod*a)%mod;
}
 
ll sqdist(ll a,ll b,ll c,ll d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}
ll fact(ll n)
{
    if(n==0)return 1;
    ll ans = 1;
    FOR(i,1,n+1)ans*=i;
    return ans;
}
 
 
int check(int a,int b,int c,int d,int e)
{
    if(d<a&&e<b)return -1;
    else if(d>a&&e>b)return 1;
    else return c+1;
} 
 

int arr[1005][1005];
void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,n;
        cin>>a>>b>>n;
        FOR(i,0,a)
        {
            string str;
            cin>>str;
            FOR(j,0,b)
            {
                 if(str[j]=='R')arr[i][j]=0;
                 else if(str[j]=='S')arr[i][j]=1;
                 else arr[i][j]=2;
            }
         }

        int X[] = {0,0,1,-1};
        int Y[] = {1,-1,0,0};
        FOR(m,0,n){
            int ch[1005][1005];
            FOR(i,0,a)
            FOR(j,0,b)ch[i][j]=arr[i][j];
            FOR(i,0,a)
            {
                FOR(j,0,b)
                {
                    FOR(p,0,4)
                    {
                        int x = i+X[p];
                        int y = j+Y[p];
                        if(x>=0&&x<a&&y>=0&&y<b&&arr[x][y]==(arr[i][j]+1)%3)
                            ch[x][y]=arr[i][j];
                    }
                    FOR(p,0,4)
                    {
                        int x = i+X[p];
                        int y = j+Y[p];
                        if(x>=0&&x<a&&y>=0&&y<b&&arr[i][j]==(arr[x][y]+1)%3)
                            ch[i][j]=arr[x][y];
                    }
                }
            }
            FOR(i,0,a)
            FOR(j,0,b)arr[i][j]=ch[i][j];
        }
        FOR(i,0,a)
        {
            FOR(j,0,b)
            {
                if(arr[i][j]==0)cout<<"R";
                else if(arr[i][j]==1)cout<<"S";
                else cout<<"P";
            }
            cout<<endl;
        }
        if(t)
        cout<<endl;
    }
}
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    solve();
}