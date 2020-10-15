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

void solve() {
  bool possible=true;
  int n;
  cin >> n;
  vector<int> arr(n);
  lli sum=0;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
    sum+=arr[i];
  }
  possible=possible and (sum%n==0);
  lli target=(sum/n);
  vector< vector<lli> > ans;
  vector<pl> remaining;
  for(int i=1; i<n; i++) {
    lli x=arr[i]/(i+1);
    if(1) {
      remaining.pb({i+1-arr[i]%(i+1), i});
      continue;
    }
    ans.pb({i+1, 1LL, x});
    arr[i]-=x*(i+1);
    arr[0]+=x*(i+1);
  }
  sortall(remaining);
  //cout << "ans size till now " << ans.size() << endl;
  for(auto item:remaining) {
    output(arr);
    cout << "requirement is " << item.first << endl;
    if(arr[0]<item.first) {
      possible=false;
      cout << "here" << endl;
      break;
    }
    ans.pb({1LL, item.second+1, item.first});
    ans.pb({item.second+1, 1LL, (arr[item.second]+item.first)/(item.second+1)});
    arr[0]+=arr[item.second];
    arr[item.second]=0;
  }
  cout << "target is " << target<<space<<possible << endl;
  output(arr);
  for(lli i=1; i<n; i++) {
    lli diff=target-arr[i];
    if(diff<0 or arr[0]<diff) {
      possible=false;
      //cout << "possible error" << endl;
    }
    ans.pb({1LL, i+1, diff});
    arr[i]+=diff;
    arr[0]-=diff;
  }
  //output(arr);
  if(!possible) {
    cout << -1 << endl;
    return;
  }
  cout << ans.size() << endl;
  for(auto x:ans)
    output(x);
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  while(testcases--) {
    solve();
  }
}

