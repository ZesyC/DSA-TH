#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 4)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        vector<pair<int, int>> diem(n);
        map<pair<int, int>, bool> co;

        for (int i = 0; i < n; i++)
        {
            cin >> diem[i].first >> diem[i].second;
            co[diem[i]] = true;
        }

        int dem = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                int x1 = diem[i].first;
                int y1 = diem[i].second;
                int x2 = diem[j].first;
                int y2 = diem[j].second;

                if ((x1 + x2) % 2 != 0 || (y1 + y2) % 2 != 0)
                {
                    continue;
                }

                int tamX = (x1 + x2) / 2;
                int tamY = (y1 + y2) / 2;

                int dx = x1 - tamX;
                int dy = y1 - tamY;

                int x3 = tamX - dy;
                int y3 = tamY + dx;
                int x4 = tamX + dy;
                int y4 = tamY - dx;

                if (co[{x3, y3}] && co[{x4, y4}])
                {
                    dem++;
                }
            }
        }

        cout << dem / 2 << endl;
    }
    return 0;
}