#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
#include<numeric>

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
#define kick(t) cout << "Case #" << t+1 << ":" << endl;

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

int compute(vector<pi> &left, vector<pi> &right, vector<int> &value, int l, int r) {
  pi left_interval, right_interval;
  if(l>=0) left_interval=left[l];
  else left_interval={0, 0};
  if(r<right.size()) right_interval=right[r];
  else right_interval={0, 0};
  int v=l>=0?value[l]:0;
  //cout << "left interval " << left_interval.first << " " << left_interval.second << endl;
  //cout << "right interval " << right_interval.first << " " << right_interval.second << endl;
  //cout << "value " << value[l] << endl;
  int ma=max(left_interval.first, right_interval.first+v);
  int mi=min(left_interval.second, right_interval.second+v);
  return ma-mi+1;
}

void solve(int testcase) {
  int n, m;
  cin >> n >> m;
  string inp;
  cin >> inp;
  vector<pi> prefix(n);
  vector<pi> suffix(n);
  vector<int> value(n);
  int ma=0, mi=0;
  int cur=0;
  for(int i=0; i<n; i++) {
    if(inp[i]=='+') ++cur;
    else --cur;
    ma=max(ma, cur);
    mi=min(mi, cur);
    value[i]=cur;
    prefix[i]={ma, mi};
  }
  ma=0;
  mi=0;
  cur=0;
  for(int i=n-1; i>=0; i--) {
    if(inp[i]=='-') ++cur;
    else --cur;
    ma=max(ma, cur);
    mi=min(mi, cur);
    suffix[i]={ma-cur, mi-cur};
  }
  for(int i=0; i<m; i++) {
    int l, r;
    cin >> l >> r, l--, r--;
    cout << compute(prefix, suffix, value, l-1, r+1) << endl;
  }
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  for(int testcase=0; testcase<testcases; testcase++) {
    solve(testcase);
  }
}

