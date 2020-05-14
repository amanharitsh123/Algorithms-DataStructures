#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
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
#define MOD 1000000007
using namespace std;
typedef long long int lli;

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

lli power(lli num,lli base) {
  if(base==0)
    return 1;

  if(base%2)
    return (num%MOD*power(num,base-1)%MOD)%MOD;
  else {
    lli x=power(num,base/2);
    x=(x*x)%MOD;
    return x;
  }
}

void solve() {
  lli n, m, votes=0, votes_c=0;
  cin >> n >> m;
  map<string, string> chef_country;
  map<string, lli> votes_chef;
  map<string, lli> votes_country;
  string max_c;
  string chef, country;
  while(n--) {
    cin >> chef >> country;
    chef_country[chef] = country;
  }

  while(m--) {
    cin >> chef;
    votes_chef[chef]++;
    votes_country[chef_country[chef]]++;
    votes = max(votes, votes_chef[chef]);
    votes_c = max(votes_c, votes_country[chef_country[chef]]);
  }

  chef = " ";
  for(auto x:votes_chef) {
    if(x.second==votes) {
      if(chef==" " or chef>x.first)
        chef = x.first;
    }
  }
  
  country = " ";
  for(auto x:votes_country) {
    if(x.second==votes_c) {
      if(country==" " or country>x.first)
        country = x.first;
    }
  }
  cout << country << endl;
  cout << chef << endl;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  lli testcases=1;
  while(testcases--) {
    solve();
  }
}

