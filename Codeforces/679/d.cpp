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

bool verify(int n, vector<int> ops, vector<int> ans, vector<int> numbers) {
  set<int> s;
  int current=0;
  int cur2=0;
  for(auto x:ops) {
    if(x==1) {
      s.insert(ans[current]);
      ++current;
    } else {
      int num=numbers[cur2];
      cur2++;
      if(*s.begin()!=num)
        return false;
      s.erase(s.begin());
    }
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n, -1);
  set<int, greater<int> > values;
  set<pi> assigned;
  for(int i=1; i<=n; i++) values.insert(i);
  int current=0;
  bool pos=true;
  int last=INT_MIN;
  vector<int> ops;
  vector<int> numbers;
  for(int i=0; i<2*n; i++) {
    char x;
    cin >> x;
    if(x=='+') {
      ops.pb(1);
      if((current==n) or (values.size()==0)) {
        pos=false;
        break;
      }
      int top=*values.begin();
      values.erase(values.begin());
      ans[current]=top;
      assigned.insert({top, current});
      ++current;
      last=INT_MIN;
    } else {
      ops.pb(0);
      int num;
      cin >> num;
      numbers.pb(num);
      if(assigned.size()==0) {
        pos=false;
        break;
      }
      if(num<last) {
        pos=false;
        break;
      }
      last=num;
      if((*assigned.begin()).first==num) {
        assigned.erase(assigned.begin());
        continue;
      }
      if((values.size()==0) or (values.find(num)==values.end())) {
        pos=false;
        break;
      }
      auto itr=values.find(num);
      auto pp=*assigned.begin();
      assigned.erase(assigned.begin());
      ans[pp.second]=num;
      values.erase(itr);
      values.insert(pp.first);
      last=num;
    }
  }
  if(pos and verify(n, ops, ans, numbers)) {
    cout << "YES" << endl;
    output(ans);
  } else {
    cout << "NO" << endl;
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

