#include<bits/stdc++.h>
using namespace std;

int * partition(int arr[],int l,int r)
{
    int p=arr[l];
    int i = l + 1, j = r, count = 0;
    int *c=new int[2];
    do
    {
        while(arr[i]<=p)
        {
            if((i+1)>r)
             break;
             i++;
             count++;
        }
        while(arr[j]>p)
        {
            j--;
            count++;
        }
        
        count++;

        swap(arr[i],arr[j]);
    }while(i<j && i<=r);
    swap(arr[i],arr[j]);
    swap(arr[l],arr[j]);
    c[0]=j;
    c[1]=count;
    return c;

}

int quickSort(int arr[],int l,int r)
{
    if(r<=l || r<0 || l<0)
        return 0;
    
    int c1=0,c2=0,count=0,p;
    int *c;
    c=partition(arr,l,r);
    p=c[0];
    count=c[1];
    c1=quickSort(arr,l,p-1);
    c2=quickSort(arr,p+1,r);
    return c1+c2+count;


}
int main()
{

    int size,arr[100],t1=0,t2=0,t3=0,ln,opt;
    while(1)
    {
        cout<<"Enter the option\n1.correctness\n2.time complexity\n";
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
                quickSort(arr,0,size-1);
                cout<<"Array after sorting\n";
                for(int i=0;i<size;i++)
                {
                    cout<<arr[i]<<" ";
                }
                break;
            }
            case 2:
            {
                cout<<"Enter the size for analysis of next 5 multiples\n";
                cin>>size;
                cout<<"size\tascending\tn*n\tdescending\tn*n\trandom\tcnlog(n)\n";
                for(int i=0;i<5;i++)
                {
                    ln=3*size*log(size)/log(2);
                    for(int j=0;j<size;j++)
                    {
                        arr[j]=j;
                    }
                    t1=quickSort(arr,0,size-1);
                    for (int j = 0; j < size; j++)
                    {
                        arr[j] = size-j;
                    }
                    t2 = quickSort(arr, 0, size - 1);
                    for (int j = 0; j < size; j++)
                    {
                        arr[j] =rand()%100;
                    }
                    t3 = quickSort(arr, 0, size - 1);
                    cout<<size<<"\t\t"<<t1<<"\t"<<size*size<<"\t"<<t2<<"\t\t"<<size*size<<"\t"<<t3<<"\t"<<ln<<"\n";
                    size*=2;
                }
                break;
            }

        }
    }

    return 0;
}