#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli compute(stack<lli> &st,lli ele) {
    
    lli count = 0;
    if(st.size() and st.top() > ele)
    {
        while(st.size() and st.top() > ele)
        {
            lli top = st.top();
            while(st.size() and st.top() == top)
                {
                    st.pop();
                }
            ++count;
        }
    }
    if(!st.size() or st.top()<ele)
        st.push(ele);

    return count;
}

void solve() {
    lli n;
    cin>>n;
    vector<lli> arr(n);
    stack<lli> st;
    lli ans = 0;
    
    for(lli i=0; i<n; i++)
    {
        cin>>arr[i];
        lli t = compute(st,arr[i]);
        ans += t;
    }
    
    cout<<ans+st.size()-1<<endl;
}

int main() {
    /*
    1-Start from biggest possible number and reduce that to immediate smaller number on left.
    2-Keep doing this.
    */
   lli t;
   cin>>t;
   while(t--) {
       solve();
   }
   
   return 0;
}

// 2
// 5
// 5 9 8 3 12
// 2
// 19 19
