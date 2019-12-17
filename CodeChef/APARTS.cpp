#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
class pos{
    public:
    lli x,y,val;
};
bool cmp(pos p1,pos p2)
{
    return p1.val>p2.val;
}
int main() {
    lli t;
    cin>>t;
    while(t--) {
        lli n,m;
        cin>>n>>m;
        vector<pos> orders;
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
        // set<lli> s;
        unordered_map<int,int> floors;
        for(lli i=0;i<n;i++)
            for(lli j=0;j<m;j++)
            {
                lli temp;
                cin>>temp;
                pos p;
                p.x = i+1;
                p.y = j+1;
                p.val = temp;
                orders.push_back(p);
            }
        sort(orders.begin(),orders.end(),cmp);
        for(auto i:orders)
        {
            lli x = i.x, y = i.y, val = i.val;
            x = n-x+1;
            // mark clean
            --x;
            --y;
            // cout<<"here"<<x<<" "<<y<<" "<<val<<endl;
            ans[x][y] = 1;
            
            // Logic to check for safety of current block.
            for(auto it = floors.begin();it != floors.end();it++)
            {
                lli q = it->first;
                lli p = it->second;
                if((p-x)>=abs(q-y))
                {
                    ans[x][y] = 0;
                    break;
                }
            }
            // s.insert(y);
            if(floors.find(y)!=floors.end())
            {
                if(floors[y]<x)
                    floors[y] = x;
            }
            else
            {
                floors[y] = x;
            }
        }
        // return 0;
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<m;j++)
            {
                cout<<ans[i][j];
            }
            cout<<endl;
        }       
    }
}
