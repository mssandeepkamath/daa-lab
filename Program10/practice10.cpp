#include<bits/stdc++.h>
using namespace std;

int w[100],x[100],d;

void sumOfSubset(int s,int k,int r)
{
    static int b=1;
    x[k]=1;
    if(s+w[k]==d)
    {
        cout<<"Subset: "<<b++<<"\n";
        for(int i=1;i<=k;i++)
        {
            if(x[i]==1)
                cout<<w[i]<<" ";
        }
        cout<<"\n";
    }
    else if(s+w[k]+w[k+1]<=d)
    {
        sumOfSubset(s+w[k],k+1,r-w[k]);
    }

    if((s+r-w[k]>=d) && (s+w[k+1]<=d))
    {
        x[k]=0;
        sumOfSubset(s,k+1,r-w[k]);
    }

}

int main()
{
    int n,sum=0;
    cout<<"Enter number of elements in the set\n";
    cin>>n;
    cout<<"Enter the elements\n";
    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        sum+=w[i];
    }
    cout<<"Enter the target\n";
    cin>>d;
    if(sum<d || w[1]>d)
    {
        cout<<"Solution doesn't exists\n";
        exit(0);
    }
    sumOfSubset(0,1,sum);
    return 0;
}