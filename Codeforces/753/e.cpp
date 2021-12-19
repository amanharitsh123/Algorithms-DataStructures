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

  
int n, m;

pair<int, int> get_move(char inp) {
  map< char, pair<int, int> > mp = {{'R', {0, 1}},{ 'L', {0, -1}}, {'U', {-1, 0}}, {'D', {1, 0}} };
  return mp[inp];
}

pair<int, int> get_correction(int x, int y) {
  if(x >= n) return {-1, 0};
  if(x < 0) return {1, 0};
  if(y >= m) return {0, -1};
  else return {0, 1};
}

bool valid(int x, int y) {
  return x >= 0 and x < n and y >= 0 and y < m;
}

void solve(int testcase) {
  cin >> n >> m;
  int startx = n/2, starty = m/2;
  int currentx = n/2, currenty = m/2;
  string commands;
  cin >> commands;
  int i = 0;
  int max_left = 0, max_right = 0, max_up = 0, max_down = 0;
  for( ; i < commands.size() and valid(startx, starty); i++) {
    max_left = max(max_left, starty-currenty);
    max_right = max(max_right, currenty-starty);
    max_up = max(max_up, startx-currentx);
    max_down = max(max_down, currentx-startx);
    auto [ox, oy] = get_move(commands[i]);
    currentx += ox;
    currenty += oy;
    if(!valid(currentx, currenty)) {
      auto [cx, cy] = get_correction(currentx, currenty);
      if(!valid(startx + cx, starty + cy)) {
        break;
      }
      currentx += cx;
      currenty += cy;
      startx += cx;
      starty += cy;
    }
  }

  cout << startx+1 << " " << starty+1 << endl;
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

