#include <iostream>
#include <time.h>
#include <fstream>
#include "px.h"
using namespace std;

int main()
{
    // srand((unsigned int)time(NULL));
    // ofstream fout("data.txt");
    // for (int i = 0; i < 100000000; i++)
    // {
    //     fout << rand() << " ";
    // }
    // fout.close();
    // return 0;

    ifstream fin("data1.txt");
    int n;
    cout << "请输入数据量大小：";
    cin >> n;
    vector<int> shujuku(n);
    for (int i = 0; i < shujuku.size(); i++)
    {
        fin >> shujuku[i];
    }
    fin.close();

    double ti[3] = {0};
    clock_t start, end;

    if (n < 200000)
    {
        start = clock();
        px_mp(shujuku);
        end = clock();
        ti[0] = double(end - start) / CLK_TCK;
        cout << "冒泡排序用时：" << ti[0] << "s" << endl;
    }

    if (n < 2000000)
    {
        start = clock();
        px_cr(shujuku);
        end = clock();
        ti[1] = double(end - start) / CLK_TCK;
        cout << "插入排序用时：" << ti[1] << "s" << endl;
    }

    start = clock();
    px_ks(shujuku, 0, n - 1);
    end = clock();
    ti[2] = double(end - start) / CLK_TCK;
    cout << "快速排序用时：" << ti[2] << "s" << endl;

    system("pause");
    return 0;
}