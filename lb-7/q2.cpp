#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

string clean(string s) {
    bool changed = true;
    while (changed) {
        changed = false;
        string t;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) j++;
            if (j - i >= 3) changed = true;
            else t += s.substr(i, j - i);
            i = j;
        }
        s = t;
    }
    return s;
}

int findMinStep(string board, string hand) {
    board = clean(board);
    if (board.empty()) return 0;

    sort(hand.begin(), hand.end());

    queue<pair<string, string>> q;
    unordered_set<string> seen;
    q.push({board, hand});
    seen.insert(board + "|" + hand);

    int steps = 0;

    while (!q.empty()) {
        int sz = q.size();
        steps++;

        while (sz--) {
            string b = q.front().first;
            string h = q.front().second;
            q.pop();

            set<char> tried;

            for (int i = 0; i < h.size(); i++) {
                char c = h[i];
                if (tried.count(c)) continue;
                tried.insert(c);

                string nh = h;
                nh.erase(nh.begin() + i);

                for (int pos = 0; pos <= b.size(); pos++) {
                    if (pos > 0 && pos < b.size() && b[pos-1] == c && b[pos] == c)
                        continue;

                    string nb = clean(b.substr(0, pos) + c + b.substr(pos));

                    if (nb.empty()) return steps;

                    string key = nb + "|" + nh;
                    if (!seen.count(key)) {
                        seen.insert(key);
                        q.push({nb, nh});
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    cout << findMinStep("WWRRBBWW", "WRBRW") << endl;
    cout << findMinStep("WRRBBW", "RBW") << endl;
}