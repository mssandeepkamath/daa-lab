#include<bits/stdc++.h>
using namespace std;
#define MAX 500

int table[MAX];

void tableFunction(string pattern)
{
    int m=pattern.length();

    for(int i=0;i<MAX;i++)
    {
        table[i]=m;
    }

    for(int i=0;i<m-1;i++)
    {
        table[pattern[i]]=m-i-1;
    }
}

int horsePool(string sentence,string pattern)
{
    int n=sentence.length();
    int m=pattern.length();
    int i=m-1;
    int k;
    while(i<n)
    {
        k=0;
        while(k<m && (sentence[i-k]==pattern[m-1-k]))
        {
            k++;
        }

        if(k==m)
        {
            return i-m+1;
        }
        else
        {
            i+=table[sentence[i]];
        }
    }

    return -1;

}

int main()
{
    string sentence,pattern;
    cout<<"Enter the sentence\n";
    getline(cin,sentence);
    cout<<"Enter the pattern\n";
    getline(cin,pattern);
    tableFunction(pattern);
    int pos= horsePool(sentence,pattern);
    if(pos>0)
    {
        cout<<"The pattern "<<"\""<<pattern<<"\""<<" is found in the sentence "<<"\""<<sentence<<"\""<<" at the position "<<pos<<" from the start\n";
    }
    else
    {
        cout<<"The pattern not found in the sentence\n";
    }
    return 0;

}