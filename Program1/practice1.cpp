#include<bits/stdc++.h>
using namespace std;

/*
Mistakes:

1. In the mergeSort function the base condition is the key
2. In the mergeArray function be careful while incrementing and decrementing.
3. Be careful in the case 2 of switch statement ie. outer loop as i so inner loops should have j.

*/

int mergeArray(int arr1[],int n1,int arr2[],int n2,int arr[])
{
    int count=0;
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
            arr[k++]=arr1[i++];
        else
            arr[k++]=arr2[j++];

        count++;
    }
    while(i<n1)
    {
        arr[k++]=arr1[i++];
        count++;
    }

    while(j<n2)
    {
        arr[k++]=arr2[j++];
        count++;
    }

    return count;
}

int mergeSort(int arr[],int n)
{
    if(n<=1)
    return 0;

    int c1=0,c2=0,c3=0,count=0;
    int arr1[100],arr2[100];
    for(int i=0;i<n/2;i++)
    {
        arr1[i] = arr[i];
        count++;
    }
       
    for(int i=n/2;i<n;i++)
    {
        arr2[i-(n/2)]=arr[i];
        count++;
    }

    c1=mergeSort(arr1,n/2);
    c2=mergeSort(arr2,(n-n/2));
    c3=mergeArray(arr1,n/2,arr2,n-(n/2),arr);
    return c1+c2+c3+count;

}

int main()
{
    int size,arr[100];
    int ln=0,t1=0,t2=0,t3=0;
    int opt;
    while(1)
    {
        cout<<"Enter the option\n1.Correctness\t2.Time complexity\n";
        cin>>opt;
        switch(opt)
        {
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
                cout<<"Array after sorting is:\n";
                for(int i=0;i<size;i++)
                {
                    cout<<arr[i]<<" ";
                }
                cout<<"\n";
                break;

            }
            case 2:
            {
               cout<<"Enter the size of the array to calculate time complexity for next 5 multiples\n";
               cin>>size;
               cout<<"Size\tAscending\tcnlog(n)\tDesending\tcnlog(n)\tRandom\tcnlog(n)\n";
               for(int i=0;i<5;i++)
               {
                ln=2*size*log(size)/log(2);
                for(int j=0;j<size;j++)
                {
                    arr[j]=j;
                }
                t1=mergeSort(arr,size);
                for(int j=0;j<size;j++)
                {
                    arr[j]=size-j;
                }
                t2=mergeSort(arr,size);
                for(int j=0;j<size;j++)
                {
                    arr[j]=rand()%100;
                }
                t3=mergeSort(arr,size);
                size*=2;
                cout << size <<"\t\t"<<t1<<"\t\t"<<ln<<"\t\t"<<t2<<"\t\t"<<ln<<"\t\t"<<t3<<"\t\t"<<ln<<"\n";
               }
               

                break;
            }
        }
        

    }
    return 0;
}
