#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     string s1;
     string s2;
     cin>>s1>>s2;
     int n=s1.size();
     int m=s2.size();
     int lcs[n+1][m+1];
     char dir[n+1][m+1];
     for(int i=0;i<=n;i++)
     {
         lcs[i][0]=0;
     }
     for(int j=0;j<=m;j++)
     {
         lcs[0][j]=0;
     }

     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                lcs[i][j]=lcs[i-1][j-1]+1;
                dir[i][j]='D';

            }
            else
            {
                if(lcs[i-1][j]>=lcs[i][j-1])
                {
                    lcs[i][j]=lcs[i-1][j];
                    dir[i][j]='U';
                }else
                {
                    lcs[i][j]=lcs[i][j-1];
                    dir[i][j]='L';
                }
            }
        }
     }
     for(int i=0;i<=n;i++)
     {
         for(int j=0;j<=m;j++)
         {
             cout<<lcs[i][j]<<" ";
         }
          cout<<endl;
     }

     vector<char> v;
     int i=n;
     int j=m;
     while(i>0&&j>0)
     {
         if(dir[i][j]=='U')
         {
             i--;
         }
         else if(dir[i][j]=='L')
         {
             j--;
         }
         else if(dir[i][j]=='D')
         {
            v.push_back(s1[i]);
            i--;
            j--;
         }
     }
     reverse(v.begin(),v.end());
    cout<<"longest common Subsequence: ";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }



 }
