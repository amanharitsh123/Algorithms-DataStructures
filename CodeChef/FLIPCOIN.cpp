#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<map>
#include<cmath>
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
#define N 450000

int tree[N];
int lazy[N];

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

int update(int node, int arr_x, int arr_y, int q_x, int q_y) {
  
  if(arr_x > arr_y)
    return 0;

  if(q_x > arr_y || q_y < arr_x) // Case of Out of range
    return tree[node];

  if(arr_x >= q_x and q_y >= arr_y) { // Completely overlapping range

    tree[node] = arr_y - arr_x + 1 - tree[node]; // Updating value to N-num_of_heads
    lazy[node] = lazy[node] ^ 1; // toggling lazy flag, no need to update children now if already set lazy flag.
    return tree[node];

  } else {
    // partial overlapping range
    int left = 2*node + 1;
    int right = 2*node + 2;
    int mid = (arr_x + arr_y)/2;
    if(lazy[node]==1) {

      lazy[node] = 0; // setting lazy bit to 0
      update(left, arr_x, mid, arr_x, mid); // Passing updates onto left child.
      update(right, mid+1, arr_y, mid+1, arr_y); // Passing updates onto right child.

    }

    int left_val = update(left, arr_x, mid, q_x, q_y);
    int right_val = update(right, mid+1, arr_y, q_x, q_y);
    tree[node] = left_val + right_val;
  }

  return tree[node];
}

int query(int node, int arr_x, int arr_y, int q_x, int q_y) {

  if(arr_x > arr_y)
    return 0;

  if(q_x > arr_y || q_y < arr_x) // Case of Out of range
    return 0;
  
  if(arr_x >= q_x and q_y >= arr_y) { // Completely overlapping range

    return tree[node]; // return 

  } else {
    // partial overlapping range
    int left = 2*node + 1;
    int right = 2*node + 2;
    int mid = (arr_x + arr_y)/2;
    if(lazy[node]==1) {

      lazy[node] = 0; // setting lazy bit to 0
      update(left, arr_x, mid, arr_x, mid); // Passing updates onto left child.
      update(right, mid+1, arr_y, mid+1, arr_y); // Passing updates onto right child.

    }

    int left_val = query(left, arr_x, mid, q_x, q_y);
    int right_val = query(right, mid+1, arr_y, q_x, q_y);
    return left_val + right_val;
  }

}


int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  int size_tree = 1 << (int) ceil(log(n)/log(2));
  memset(tree, 0, sizeof(tree));
  memset(lazy, 0, sizeof(lazy));
  while(q--) {
    lli t, x, y;
    cin >> t >> x >> y;
    if(t==1) {
      cout << query(0, 0, n-1, x, y) << endl;
    } else {
      update(0 ,0 ,n-1 ,x ,y);
    }
  }
}

