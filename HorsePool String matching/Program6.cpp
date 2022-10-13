#include <bits/stdc++.h>
using namespace std;

int table[500];

void tableFunction(string pattern)
{

    int m = pattern.length();
    for (int i = 0; i < 500; i++)
    {
        table[i] = m;
    }

    for (int i = 0; i < m - 1; i++)
    {
        table[pattern[i]] = m - 1 - i;
    }
}

int horsePool(string sentence, string pattern)
{
    int m = pattern.length();
    int n = sentence.length();
    int i = m - 1;
    int k;
    while (i < n)
    {
        k = 0;
        while (k < m && sentence[i - k] == pattern[m - 1 - k])
            k++;

        if (k == m)
            return i - m + 1;
        else
            i += table[sentence[i]];
    }

    return -1;
}

int main()
{
    string sentence, pattern;
    cout << "Enter the sentence\n";
    getline(cin, sentence);
    cout << "Enter the pattern\n";
    getline(cin, pattern);
    tableFunction(pattern);
    int pos = horsePool(sentence, pattern);
    if (pos != -1)
        cout << "The pattern "
             << "\"" << pattern << "\""
             << " is found in the sentence"
             << "\"" << sentence << "\""
             << " at position " << pos << "\n";
    else
        cout << "Pattern not found in the sentence\n";
    return 0;
}