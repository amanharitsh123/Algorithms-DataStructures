#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<string.h>
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
#define kick(t,a) cout<<"Case #"<<t<<": "<<a<<endl;
#define N 8000000

int tree[N];


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

// Point Update
int update(int node, int arr_x, int arr_y, int target) {
  
  
  if(arr_x > arr_y)
    return 0;

  //test;
  //if(node>=N)
    //cout<<"Error"<<node<<endl;

  if(target >  arr_y || target < arr_x)
    return tree[node];

  if(arr_x == arr_y) {
    if(target == arr_x)
      ++tree[node];
    return tree[node];
  }

  int left = 2*node+1;
  int right = 2*node+2;

  int mid = (arr_x + arr_y)/2; 

  string space = " ";
  cout << node << space << arr_x << space << arr_y << space << target << endl;;

  tree[node] = update(left, arr_x, mid, target) + update(right, mid+1, arr_y, target);

  return tree[node];
}

int query(int node, int arr_x, int arr_y, int q_x, int q_y) {
  
  if(arr_x > arr_y) // Invalid range
    return 0;

  if(q_y < arr_x || q_x > arr_y) // Out of range
    return 0;
  
  if(arr_x >= q_x and arr_y <= q_y) // completely overlapping range
    return tree[node];

  int mid = (arr_x + arr_y)/2;
  int left = 2*node + 1;
  int right = 2*node + 2;
  return query(left, arr_x, mid, q_x, q_y) + query(right, mid+1, arr_y, q_x, q_y);
}

struct point {
  lli x,y;
  bool operator<(const point o) const{
    return x<o.x;
  }
};

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  memset(tree, 0, sizeof(tree));
  lli size = 2000001;
  //cout<<query(0,0,size-1,0,size-1)<<endl;
  cout<<update(0, 0, size-1, 1)<<endl;
  //cout<<query(0,0,size-1,0,size-1)<<endl;
  return 0;
  lli testcases, x, y, n, q;
  cin >> testcases;
  while(testcases--) {
    cin >> n >> q;
    memset(tree, 0, sizeof(int)*(4*n+1));
    vector<point> queries;
    vector<point> points;
    for(lli i=0;i<q;i++) {
      cin >> x >> y, x *= 2, y *= 2; // scaling vertices to handle halves
      points.push_back({x, y});
    }

    // Offline query processing
    for(lli i = 0; i < q; i++) {
      cin >> x >> y, x *= 2, y *= 2;
      queries.push_back({x, y});
    }

    sort(all(queries));
    sort(all(points));
    lli j = 0;
    for(auto qq:queries) {
      lli cap = ( qq.x + :qq.y ) / 2;
      while()
    }

  }
}

