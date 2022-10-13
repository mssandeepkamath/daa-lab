#include <bits/stdc++.h>
using namespace std;

int heapify(int arr[], int n)
{
    int j, k, count = 0, v;
    bool flag;
    for (int i = n / 2; i >= 1; i--)
    {
        k = i;
        v = arr[k];
        flag = false;
        while (!flag && 2 * k <= n)
        {
            j = 2 * k;
            if (j < n)
            {
                if (arr[j] < arr[j + 1])
                    j = j + 1;
            }

            if (v >= arr[j])
            {
                flag = true;
            }
            else
            {
                arr[k] = arr[j];
                k = j;
                count++;
            }
        }

        arr[k] = v;
    }
    return count;
}

int main()
{
    int size, opt, arr[100], t1 = 0, t2 = 0, t3 = 0, ln = 0;
    while (1)
    {
        cout << "Enter the option\n1.Correctness\n2.Time complexity";
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            cout << "Enter the size of the array\n";
            cin >> size;
            cout << "Enter array elements\n";
            for (int i = 1; i <= size; i++)
            {
                cin >> arr[i];
            }
            heapify(arr, size);
            cout << "Array after sorting:\n";
            for (int i = size; i > 1; i--)
            {
                cout << arr[1] << " ";
                arr[1] = arr[i];
                heapify(arr, i - 1);
            }
            cout << arr[1] << "\n";
            break;
        }
        case 2:
        {
            cout << "Enter the size of the array for time complexity analysis for next 5 nultiples\n";
            cin >> size;
            cout << "size\tascending\tcnlog(n)\tdescending\tcnlog(n)\trandom\tcnlog(n)\n";
            for (int i = 0; i < 5; i++)
            {
                ln = size * log(size) / log(2);
                for (int j = 0; j < size; j++)
                {
                    arr[j] = j;
                }
                t1 = heapify(arr, size);
                for (int j = size; j > 1; j--)
                {
                    arr[1] = arr[j];
                    t1 += heapify(arr, j - 1);
                }
                for (int j = 0; j < size; j++)
                {
                    arr[j] = size - j;
                }
                t2 = heapify(arr, size);
                for (int j = size; j > 1; j--)
                {
                    arr[1] = arr[j];
                    t2 += heapify(arr, j - 1);
                }
                for (int j = 0; j < size; j++)
                {
                    arr[j] = rand() % 100;
                }
                t3 = heapify(arr, size);
                for (int j = size; j > 1; j--)
                {
                    arr[1] = arr[j];
                    t3 += heapify(arr, j - 1);
                }
                cout << size << "\t\t" << t1 << "\t\t" << ln << "\t\t" << t2 << "\t\t" << ln << "\t\t" << t3 << "\t\t" << ln << "\n";
                size *= 2;
            }
            break;
        }
        }
    }
    return 0;
}