#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>

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

bool possible(multiset<lli, greater<lli> > &s) {
  if(*s.begin()<4)
    return false;
  
  if(*s.begin()>=8)
    return true;
  
  int i=0;
  int res=*s.begin()-4;
  if(res<2)
    res=4;
  else
    res=2;
  auto x=s.begin();
  ++x;
  for(; x!=s.end() and res!=0; x++) {
    if(*x>=res)
      return true;
    if(*x>=2)
      res-=2;
    else
      return false;
  }
  return res==0;
}

void solve() {
  int n, x;
  char c;
  cin >> n;
  multiset<lli, greater<lli> > s;
  map<lli, lli> mp;
  for(int i=0; i<n; i++) {
    cin >> x;
    mp[x]++;
  }
  for(auto x:mp) {
    s.insert(x.second);
  }
  int ops;
  cin >> ops;
  for(int i=0; i<ops; i++) {
    cin >> c >> x;
    if(c=='+') {
      if(s.find(mp[x])!=s.end())
        s.erase(s.find(mp[x]));
      mp[x]+=1;
      s.insert(mp[x]);
    } else {
      if(s.find(mp[x])!=s.end())
        s.erase(s.find(mp[x]));
      mp[x]-=1;
      s.insert(mp[x]);
    }
    if(possible(s)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

