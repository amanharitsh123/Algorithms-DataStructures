#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};
bool convert(string s,int index) {
    return s[index]=='T';
}
int solve(unordered_map< pair<int,int>, int, hash_pair> &dp,int start,int end, string s)
{
    if(dp.find(make_pair(start,end))!=dp.end())
        return dp[make_pair(start,end)];
    
    if(start+2 < s.size() and start+2==end)
        {
            bool verd;
            if(s[start+1]=='|')
                verd=convert(s,start)||convert(s,end);
            else if(s[start+1]=='&')
                verd=convert(s,start)&&convert(s,end);
            else
                verd=convert(s,start)^convert(s,end);
            if(verd)
                return 1;
            else
                return 0;
            
        }
    int ans=0;
    if(s[start+1]=='|')
        ans=solve(dp,start+2,end,s);
    else if(s[start+1]=='&' and convert(s,start))
        ans=solve(dp,start+2,end,s);
    else
        ans=convert(s,start)^solve(dp,start+2,end,s);
    
    if(s[end-1]=='|')
        ans+=convert(s,end)||solve(dp,start,end-2,s);
    else if(s[end-1]=='&')
        ans+=convert(s,end)&&solve(dp,start,end-2,s);
    else
        ans+=convert(s,end)^solve(dp,start,end-2,s);
    
    return dp[make_pair(start,end)]=ans;

}

int main() {
	int t,n,start,end;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string s;
        cin>>s;
        unordered_map< pair<int,int>, int, hash_pair> dp;
        start=0;
        end=s.size()-1;
        cout<< solve(dp,start,end,s)<<endl;

    }
	return 0;
}

// 2
// 7
// T|T&F^T
// 5
// T^F|F