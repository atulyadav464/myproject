#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int>makeLps(string s )
{
    vector<int>ans(s.size(),0);
    int n = s.size();
    int i=0;
    int j=1;
    while(j<n)
    {
        if(s[i]==s[j])
        {
            i++;
            ans[j]=i;
            j++;
        }
        else
        {
            if(i!=0)
            {
                i=ans[i-1];
            }
            else{
               ans[j]=0;
               j++;
            }
        }
        
    }
    return ans;
}
int isPresent(string s,string part)
{
    vector<int>lps = makeLps(part);
    int n = part.size();
    int m= s.size();
    int i=0;
    int j=0;
    while(i<m)
    {
        if(s[i]==part[j])
        {
            i++;
            j++;
        }
        if(j==n)
        {
            return i-j;
        }
        else if (i < m && s[i] != part[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }          
    }
    return -1;
}
string removeOccurrences(string &s, string part) {
    while(isPresent(s,part)!=-1)
    {
        int index = isPresent(s,part);
        s.erase(index,part.size());

    }
    return s;
}
int main()
{
   string s ="daabcbaabcbc";
   string part ="abc";
   cout<<removeOccurrences(s,part);
   cout<<isPresent(s,part);
}