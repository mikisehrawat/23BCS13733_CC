#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vi = vector<int>;

int rt(const vs &w)
{
    int n = w.size();
    vi mask(n, 0);

    for (int i = 0; i < n; ++i) {
        for (char ch : w[i])
            mask[i] |= 1 << (ch - 'a');
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((mask[i] & mask[j]) == 0)
                ans = max(ans,(int)w[i].size() * (int)w[j].size());
        }
    }
    return ans;
}

int main()
{
    vs words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout<<rt(words)<<'\n';
    words={"a","aa","aaa","aaaa"};
    cout<<rt(words)<<'\n';

    return 0;
}