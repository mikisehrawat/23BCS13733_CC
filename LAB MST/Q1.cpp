#include <bits/stdc++.h>
using namespace std;

using vi  = vector<int>;
using vvi = vector<vi>;

void rt(vvi energy){
    sort(energy.begin(), energy.end(),[](const vi &a, const vi &b) {
             return (b[1] - b[0]) < (a[1] - a[0]);
         });
    int curr = 0, ans = 0;
    for (auto &e : energy) {
        int cost = e[0];
        int need = e[1];
        if (curr < need) {
            ans += need - curr;
            curr = need;
        }
        curr -= cost;
    }
    cout<<ans<<'\n';
}

int main()
{
    vvi energy = {{1, 2}, {2, 4}, {4, 8}};
    rt(energy);
    energy={{1,3},{2,4},{8,9},{10,11},{10,12}};
    rt(energy);

    return 0;
}