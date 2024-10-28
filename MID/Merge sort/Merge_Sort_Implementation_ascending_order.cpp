#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int ar[N];
void merge(int l, int r, int mid)
{
    int Lsize = mid - l + 1;
    int L[Lsize + 1];

    int Rsize = r - (mid + 1) + 1;
    int R[Rsize + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
    {
        L[j] = ar[i];
    }

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
    {
        R[j] = ar[i];
    }

    L[Lsize] = INT_MAX;
    R[Rsize] = INT_MAX;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] <= R[rp])
        {
            ar[i] = L[lp];
            lp++;
        }
        else
        {
            ar[i] = R[rp];
            rp++;
        }
    }
}
void mergesort(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) / 2;
    mergesort(l, mid);
    mergesort(mid + 1, r);
    merge(l, r, mid);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    mergesort(0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }

    return 0;
}