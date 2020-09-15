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

vector<int> pre={0, 0, 0, 2};

bool valid(vector<int> &arr) {
  lli sum=0;
  lli cursum=0;
  for(auto x:arr)
    sum+=x;
  for(auto x:arr) {
    cursum+=x;
    if(2*cursum==sum)
      return true;
  }
  return false;
}

lli brute(int n) {
  vector<int> arr;
  for(int i=1; i<=n; i++)
    arr.pb(i);
  lli ans=0;
  for(int i=0; i<n; i++) {
    for(int j=i+1; j<n; j++) {
      swap(arr[i], arr[j]);
      if(valid(arr))
        ans++;
      swap(arr[i], arr[j]);
    }
  }
  return ans;
}
bool stop=false;
void solve() {
  lli n;
  cin >> n;
  if(n<=3) {
    cout << pre[n] << endl;
    return;
  }
  lli ans=0;
  lli m=0;
  lli lo=1, hi=n-1;
  lli sum=(n*(n+1))/2;
  while(lo<hi) {
    lli mid=(lo+hi)/2;
    lli temp=sum-(mid*(mid+1));
    if(temp<0)
      hi=mid-1;
    else if(temp<2*n)
      hi=mid;
    else
      lo=mid+1;
  }

  vector<lli> ofs;
  while(sum-(lo*(lo+1))<2*n and sum-(lo*(lo+1))>=0) {
    lli s1=lo*(lo+1)/2;
    lli s2=sum-s1;
    if((s2-s1)%2) {
      ++lo;
      continue;
    }
    lli offset=(s2-s1)/2;
    if(offset==0) {
      ans+=((lo)*(lo-1))/2;
      ans+=((n-lo)*(n-lo-1))/2;
      ++lo;
      continue;
    }
    ofs.pb(offset);
    // offset calculation
    hi=min(lo+offset, n);;
    lli lp=max(lo+1, 1+offset);
    ans+=hi-lp+1;
    //cout << "lo is "<<lo<<endl;
    lo++;
  }
  cout << ans << endl;
  /*if(ans!=brute(n)) {
    cout << "offsets ";
    output(ofs);
    cout << "Wrong answer " <<n<<endl;
    cout << "Correct answer " << brute(n) << endl;
    cout << "Your answer " << ans << endl;
    stop=true;
  } else {
    cout << "correct" << endl;
  }*/
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases;
  cin>>testcases;
  while(testcases-- and !stop) {
    solve();
  }
}

