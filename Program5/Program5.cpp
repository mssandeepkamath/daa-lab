#include<bits/stdc++.h>
using namespace std;

int heapify(int arr[],int n)
{
    int count=0;
    int k,v,flag,j;
    for(int i=n/2;i>=1;i--)
    {
        k=i;
        v=arr[k];
        flag=0;
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(arr[j]<arr[j+1])
                {
                    j=j+1;
                }
            }

            if(v>=arr[j])
            {
                flag=1;
            }else
            {
                arr[k]=arr[j];
                k=j;
                count++;
            }

        }
        arr[k]=v;
    }
    return count;
}

int main()
{
int size;
int arr[32000];
int opt;
while(1)
{
    cout<<"Enter the option\n1.Correctness\n2.Time complexity\n";
    cin>>opt;
    switch(opt)
    {
        case 1:
        {
            cout<<"Enter the size of the array\n";
            cin>>size;
            cout<<"Enter the array elements\n";
            for(int i=1;i<=size;i++)
            {
                cin>>arr[i];
            }
            heapify(arr,size);

            cout<<"Array after sorting\n";

            for(int i=size;i>1;i--)
            {
                cout<<arr[1]<<" ";
                arr[1]=arr[i];
                heapify(arr,i-1);
            }
            cout<<arr[1]<<" \n";
            break;
        }
        case 2:
        {
            cout<<"Enter the size of the array for time complexity analysis of next 5 multiples\n";
            cin>>size;
            float ln=0.0;
            int t1=0,t2=0,t3=0;
            cout<<"Size\tAscending\tcnlog(n)\tDescending\tcnlog()\tRandom\tcnlog(n)\n";
            for(int i=1;i<=5;i++)
            {
                ln=size*log(size)/log(2);
                for(int j=1;j<=size;j++)
                {
                    arr[j]=j;
                }
                t1=heapify(arr,size);
                for(int j=size;j>1;j--)
                {
                    arr[1]=arr[j];
                    t1+=heapify(arr,j-1);
                }
                for(int j=1;j<=size;j++)
                {
                    arr[j]=size-j;
                }
                t2=heapify(arr,size);
                for(int j=size;j>1;j--)
                {
                    arr[1]=arr[j];
                    t2+=heapify(arr,j-1);
                }
                for(int j=1;j<=size;j++)
                {
                    arr[j]=rand()%32000;
                }
                t3=heapify(arr,size);
                for(int j=size;j>1;j--)
                {
                    arr[1]=arr[j];
                    t3+=heapify(arr,j-1);
                }
                cout<<size<<"\t\t"<<t1<<"\t\t"<<ln<<"\t\t"<<t2<<"\t\t"<<ln<<"\t\t"<<t3<<"\t\t"<<ln<<"\n";
                size*=2;
            }
            break;
        }
        default:
            exit(0);

    }
}
    return 0;
}