#include "px.h"

void px_ks(vector<int> &obj, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r, x = obj[l];
        while (i < j)
        {
            while (i < j && obj[j] >= x)
            {
                j--;
            }
            if (i < j)
            {
                obj[i++] = obj[j];
            }

            while (i < j && obj[i] < x)
            {
                i++;
            }
            if (i < j)
            {
                obj[j--] = obj[i];
            }
        }
        obj[i] = x;
        px_ks(obj, l, i - 1);
        px_ks(obj, i + 1, r);
    }
}

void px_cr(vector<int> obj)
{
    int n;
    n = obj.size();
    vector<int> obj1;
    obj1.push_back(0);
    for (int i = 0; i < n; i++)
    {
        obj1.push_back(obj[i]);
        int a = 0;
        int b = obj1.size() - 1;
        while (b - a > 1)
        {
            if (obj[i] >= obj1[(a + b) / 2])
            {
                a = (a + b) / 2;
            }
            else
            {
                b = (a + b) / 2;
            }
        }
        for (int k = obj1.size() - 1; k > b; k--)
        {
            obj1[k] = obj1[k - 1];
        }
        obj1[b] = obj[i];
    }
}

void px_mp(vector<int> obj)
{
    int n;
    n = obj.size();
    for (int i = 0; i < n - 1; i++)
    {
        int pd = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (obj[j] > obj[j + 1])
            {
                int temp = obj[j];
                obj[j] = obj[j + 1];
                obj[j + 1] = temp;
                pd++;
            }
        }
        if (pd == 0)
            break;
    }
}