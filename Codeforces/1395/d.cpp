#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>

using namespace std;
typedef long long int lli;

#define all(arr) arr.begin(),arr.end()
#define f first
#define s second
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
#define nl cout<<"\n";
#define pq priority_queue
#define inf 0x3f3f3f3f
#define test cout<<"abcd\n";
#define pi pair<int,int>
#define pii pair<int,pi>
#define pb push_back
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define space ' '
#define kick(t) cout << "Case #" << t << ":" << endl;

typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<" ";
  cout<<endl;
}


template <typename T>
void input_set(set<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.insert(temp);
}

lli mul(lli a, lli b) {
  return (a%MOD*b%MOD)%MOD;
}

lli power(lli a,lli b) {
  lli ans = 1;
  while(b > 0) {
    if(b&1)
      ans = mul(ans, a);
    a = mul(a,a);;
    b >>= 1;
  }
  return ans;
}
vector<lli> arr;
lli n, d, m;
lli remain=0;
lli foo(int ind) {
  if(ind==0)
    return arr[0];
  if(remain<=0) {
    return 0;
  }
  if(arr[ind]<=m) {
    remain--;
    return arr[ind]+foo(ind-1);
  }
  else {
    remain=remain-1-d;
    return arr[ind]+foo(ind-1);
  }
}

void solve() {
  cin >> n >> d >> m;
  input(arr, n);
  vector<lli> costly, free;
  for(auto x:arr)
    if(x<=m)
      free.pb(x);
    else
      costly.pb(x);
  lli ans=0;
  sort(all(costly));
  if(costly.size())
     ans=*costly.rbegin();
  int c=(int) costly.size()-2;
  int f=0;
  sort(all(free));
  while(c>=0 and f+d-1<free.size()) {
    lli sum=0;
    for(int i=f; i<f+d; i++)
      sum+=free[i];
    if(sum<=costly[c]) {
      ans+=costly[c];
      f+=d;
      c-=1;
    } else {
      while(f<free.size()) {
        ans+=free[f];
        ++f;
      }
      break;
    }
  }
  if(c!=0) {
    vector<lli> temp;
    for(int i=f; i<free.size(); i++)
      temp.pb(free[f]);
    for(int i=0; i<=c; i++)
      temp.pb(costly[i]);
    costly=temp;
    int f=0;
    while(f+d-1<c) {
    lli sum=0;
      for(int i=f; i<f+d; i++) {
        sum+=costly[i];
      }
      ans+=costly[c];
      f+=d;
      c-=1;
    }
  }
  while(f<free.size()) {
    ans+=free[f];
    ++f;
  }
  cout << ans << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

