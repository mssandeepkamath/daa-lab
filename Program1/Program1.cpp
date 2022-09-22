#include<bits/stdc++.h>
using namespace std;


int mergee(int b[],int n1,int c[], int n2, int a[])
{
    int i=0,j=0,k=0;
    int count=0;
    while(i<n1 && j<n2)
    {
        if(b[i]<=c[j])
        {
            a[k++]=b[i++];
        }
        else
        {
            a[k++]=c[j++];
        }
        count++;
    }

    while(i<n1)
    {
        a[k++]=b[i++];
        count++;
    }
    while(j<n2)
    {
        a[k++]=c[j++];
        count++;
    }


    return count;
}
int mergeSort(int a[],int n)
{
    if(n<=1)
        return 0;
    int count=0,c1=0,c2=0,c3=0;
    int b[100],c[100];
    for(int i=0;i<n/2;i++)
    {
        b[i]=a[i];
        count++;
    }
    for(int i=n/2;i<n;i++)
    {
        c[i-(n/2)]=a[i];
        count++;
    }
    c1= mergeSort(b,n/2);
    c2= mergeSort(c,n-(n/2));
    c3=mergee(b,n/2,c,n-(n/2),a);
    return count+c1+c2+c3;
}



int main()
{

    cout<<"Enter the option:\n1.Correctness\n2.Time complexity\n";
    int opt;
    int size,arr[100];
    float ln=0.0;
    int t1=0,t2=0,t3=0;
    cin>>opt;
    switch (opt) {
        case 1:
        {

            cout<<"Enter the size of the array\n";
            cin>>size;
            cout<<"Enter the array elements\n";
            for(int i=0;i<size;i++)
            {
                cin>>arr[i];
            }
            mergeSort(arr,size);
            cout<<"Array after sorting\n";
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            break;
        }

        case 2:
        {
            cout<<"Enter the size of the array for time complexity calculation of next 5 multiples\n";
            cin>>size;
            cout<<"size\tAscending\tcnlog(n)\tDescending\tcnlog(n)\tRandom\tcnlog(n)\n";
           for(int i=0;i<5;i++)
           {
               ln=2*size*log(size)/log(2);
               for(int j=0;j<size;j++)
               {
                   arr[j]=j;
               }
               t1= mergeSort(arr,size);
               for(int j=0;j<size;j++)
               {
                   arr[j]=size-j;
               }
               t2= mergeSort(arr,size);
               for(int j=0;j<size;j++)
               {
                   arr[j]=rand()%100;
               }
               t3= mergeSort(arr,size);
               cout<<size<<"\t\t"<<t1<<"\t\t"<<ln<<"\t\t"<<t2<<"\t\t"<<ln<<"\t\t"<<t3<<"\t\t"<<ln<<"\n";
                         size*=2;
           }

        }

    }

    return 0;
}