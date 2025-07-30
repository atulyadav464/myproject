#include<iostream>
using namespace std;
#include<vector>
vector<int> makelps(string s)
{
   int n = s.size();
    vector<int>ans(n,0);
    int i = 0;
     int j = 1;
     while(j<n){
        if(s[i]==s[j])
        {
            i++;
            ans[j]=i;
            j++;
        }
        else{
            if(i!=0)
            {
                i = ans[i-1];
            }
            else{
                ans[j]=0;
                j++;
            }
        }
     }
     return ans;
}
vector<int> makeLps(string s){
    int m= s.size();
    vector<int>ans(m,0);
    int i=0;
    int j=1;
    while(j<m)
    {
        if(s[i]==s[j])
        {
           
           i++;
           ans[j]=i;
           j++;
        }
        else{
           if(i!=0)
           {
             i=ans[i-1];
             
           }
           else{
            ans[j]=0;
            j++;
          }
       }
    }d
    return ans;
    
}
bool isreapeated(string s)
{
    int n = s.length();
    vector<int>lps = makelps(s);
    int k = n-lps[n-1];
    if(k<n&&n%k==0)
    {
        return 1;
    }
    else{
        return 0;
    }
}
int main()
{
    string s = "abcdefabc";
    cout<<isreapeated(s);
    cout<<"\n";
    vector<int>ans =makelps(s);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i];
}