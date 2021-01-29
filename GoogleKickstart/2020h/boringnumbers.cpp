#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<cstring>
#include<numeric>
#include<sstream>

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
#define kick(t) cout << "Case #" << t+1 << ":" << " ";

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

string closest(string x) {
  int ln=x.size();
  string ans;
  while(ln--) {
    ans.push_back('9');
  }
  return ans;
}

string plusone(string x) {
  int ln=x.size();
  string ans="1";
  while(ln--) ans.push_back('0');
  return ans;
}

vector<char> numbers[] = {{'1', '3', '5', '7', '9'}, {'0', '2', '4', '6', '8'}};

lli total(int x, int total) {
  lli n=total-x;
  return power(5, n);
}

int to_int(string x) {
  stringstream ss;
  ss << x;
  int ans;
  ss >> ans;
  return ans;
}

bool good(int i) {
  stringstream ss;
  ss << i;
  string ans;
  ss >> ans;
  for(int i=0; i<ans.size(); i++) {
    if((i%2+1)%2 != ((ans[i]-'0')%2))
      return false;
  }
  return true;
}

lli brute(string x, string y) {
  int l=to_int(x);
  int r=to_int(y);
  int ans=0;
  for(int i=l; i<=r; i++) {
      if(good(i)) {++ans;} 
  }
  return ans;
}

lli foo(string x, string y, int pos) {
  lli ans=0;
  if(pos>=x.size()) return 1;
  for(auto c:numbers[pos%2]) {
    if(c<x[pos])
      continue;
    if(c>y[pos])
      continue;
    if(c==y[pos] and c==x[pos]) {
      ans+=foo(x, y, pos+1);
    } else if(c==y[pos]) {
      string backup;
      for(int i=pos+1; i<x.size(); i++) {
        backup.push_back(x[i]);
        x[i]='0';
      }
      ans+=foo(x, y, pos+1);
      x=x.substr(0, pos+1)+backup;
    } else if (c==x[pos]) {
      string backup;
      for(int i=pos+1; i<x.size(); i++) {
        backup.push_back(y[i]);
        y[i]='9';
      }
      ans+=foo(x, y, pos+1);
      y=y.substr(0, pos+1)+backup;
    } else {
      ans+=total(pos+1, x.size());
    }
  }
  return ans;
}

void solve(int testcase) {
  string x, y, tx, ty;
  cin >> x >> y;
  tx=x;
  ty=y;
  lli ans=0;
  while(x.size()!=y.size()) {
    string next=closest(x);
    ans+=foo(x, next, 0);
    x=plusone(next);
  }
  ans+=foo(x, y, 0);
  kick(testcase);
  cout << ans << endl;
  cout << "brute ans " << brute(tx, ty) << endl;
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

