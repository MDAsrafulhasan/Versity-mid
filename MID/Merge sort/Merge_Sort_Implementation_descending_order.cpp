#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
int a[N];

void merge(int l, int r, int mid)
{
    int Lsize = mid - l + 1;
    int L[Lsize + 1];

    int Rsize = r - (mid + 1) + 1;
    int R[Rsize + 1];

    for (int i = l, j = 0; i <= mid; i++, j++)
        L[j] = a[i];

    for (int i = mid + 1, j = 0; i <= r; i++, j++)
        R[j] = a[i];
    L[Lsize] = INT_MIN;
    R[Rsize] = INT_MIN;
    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] >= R[rp])
        {
            a[i] = L[lp];
            lp++;
        }
        else
        {
            a[i] = R[rp];
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
        cin >> a[i];
    }

    mergesort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}