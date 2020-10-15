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
bool win(int a, int b) {
  if(a==0 and b==2)
    return true;
  if(a==1 and b==0)
    return true;
  if(a==2 and b==1)
    return true;
  return false;
}

void solve() {
  lli n, count;
  vector<pl> alice, bob;
  cin >> n;
  lli ma=-1e18, mi=1e18;
  for(int i=0; i<3; i++) {
    cin >> count;
    alice.pb({i, count});
  }
  for(int i=0; i<3; i++) {
    cin >> count;
    bob.pb({i, count});
  }
  swap(alice[1].second, alice[2].second);
  swap(bob[1].second, bob[2].second);
  do {
    sortall(bob);
    do {
      lli win_alice=0;
      int i=0, j=0;
      vector<pl> talice=alice, tbob=bob;
      while(i<3 and j<3) {
        lli offset=min(talice[i].second, tbob[j].second);
        if((talice[i].first!=tbob[j].first) and win(talice[i].first, tbob[j].first)) {
          win_alice+=offset;
        }
        talice[i].second-=offset;
        tbob[j].second-=offset;
        if(talice[i].second==0)
          ++i;
        if(tbob[j].second==0)
          ++j;
      }
      ma=max(ma, win_alice);
      mi=min(mi, win_alice);
    } while(next_permutation(all(bob)));
  } while(next_permutation(all(alice)));
  cout << mi << space << ma << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

