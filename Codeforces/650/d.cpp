#include<bits/stdc++.h>

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
#define MOD 1000000007

template <typename T>
void input(vector<T> &arr,lli n) {
  T temp;
  for(lli i=0;i<n;i++) cin>>temp, arr.push_back(temp);
}

template <typename T>
void output(vector<T> arr) {
  for(auto x:arr) cout<<x<<"";
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

int possible(vector<char> &arr, char letter, int value, int i) {
  int pos = -1;
  int n = arr.size();
  //cout << "recieved  " << letter << " " << value << endl;
  //output(arr);
    int temp = 0;
   for(int j=0; j<i; j++) {
    if(arr[j]!='1' and arr[j] > letter)
      temp += i-j;
   }
    
  //cout << "temp1 is " << temp << endl;
  for(int j=i+1; j<n; j++)
    if(arr[j]!='1' and arr[j] > letter) {
      //cout << j << " " << i << endl;
      temp += j-i;
    }
  //cout << "temp is " << temp << endl;
  if(temp==value) {
    arr[i] = letter;
    pos = i;
  }

  return pos;
}

void solve() {
  int n;
  string letters;
  cin >> letters;
  n = letters.size();
  int m;
  cin >> m;
  vector<int> values;
  input(values, m);
  vector<bool> processed(m, false);
  vector<char> ans(m, '1');
  sort(all(letters));
  vector<pi> pairs;
  for(int i=0; i<m; i++)
    pairs.pb({values[i], i});

  sort(all(pairs));
  int hi = n-1;
  int val_ind = 0;
  int assign = 0;
  // if a assignment turns out to be impossible, this means that last assignment gone wrong, undo that 
  int last_assignment = -1;
  int last_processed = -1;
  while(assign < m) {
    //cout << assign << " " <<letter << endl;
    //cout << "sending " << letters[hi]<<" " << pairs[val_ind].first << endl;
    //output(ans);
    int pos = -1;
    int minimal = 100000;
    int a = -1;
    for(int i=0; i<m; i++) {
      if(!processed[i]) {
        pos = possible(ans, letters[hi], values[i], i);
        if(pos!=-1) {
          if(values[pos]<minimal) {
            a = i;
            last_processed = i;
            minimal = values[pos];
          }
        }
      }
    }

    pos = a;
    if(hi<0 or val_ind<0 or assign<0) {
      //cout << "error " << hi << " " <<val_ind << " "<<assign<< endl;
      cout << letters;
      break;
    }

    if(pos==-1) {
      //--hi;
      ans[last_assignment] = '1';
      processed[last_processed] = false;
      --assign;
      --val_ind;
    } else {
      processed[pos] = true;
      ans[pos]=letters[hi];
      last_assignment = pos;
      ++assign;
      --hi;
      ++val_ind;
    }
  }

  output(ans);
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

