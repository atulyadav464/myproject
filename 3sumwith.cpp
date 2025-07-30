#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int threeSumMulti(vector<int>& arr, int target) {
    vector<int>count_num(101,0);
    sort(arr.begin(),arr.end());
    int ans = 0;
   for(int i=0;i<arr.size();i++)
   {
    count_num[arr[i]]++;
    }
    for(int i=0;i<101;i++)
    {
       int start = i;
       int end = 100;
        while(start<=end)
    {
        int sum = i+start+end;
        if(sum==target)
        {
            if(i==start&&start==end)
            {
                if(count_num[i]>=3)
                {
                    int x =count_num[i];
                    ans+=((x*(x-1)*(x-2))/6);
                    
                }   
            }
            else if(i!=start&&start==end)
            {
                if(count_num[start]>1)
                {
                    int n = count_num[start];
                    int x = n*(n-1)/2;
                    ans+=(count_num[i]*x);                          
                }
            }
            else if(i==start&& start!=end)
            {
                if(count_num[i]>1)
                {
                    int n = count_num[i];
                    int x = n*(n-1)/2;
                    ans+=(count_num[end]*x);
                }                                                 
            }
            else if(i!=start&&start!=end)
            {
                
                ans += (count_num[i]*count_num[start]*count_num[end]);
            }
            end--;
        }
        else if(sum>target)
        {
            end--;
        }
        else{
             start++;
         }
                }
            }
            return ans;
        }
    
    int main(){
        vector<int>ans = {1,2,3};
        int target = 6;
        cout<<threeSumMulti(ans,target);
        
    }
   