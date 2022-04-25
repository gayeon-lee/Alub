#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;
struct Structure {
    int time = 0;
    int count;
    vector<int> next;
};

class Craft {
  public:
    void Solve();

  private:
    void Input();
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<Structure> vec;
    vector<int> ans;
    int N;
};

void Craft::Solve() {
    Input();
    int total_time = 0;
    int t, idx;

    while (!pq.empty()) {
        tie(t, idx) = pq.top();
        pq.pop();

        ans[idx] = t;

        if (total_time < t)
            total_time = t;

        for (auto &next_idx : vec[idx].next) {
            if (!--vec[next_idx].count)
                pq.push({vec[next_idx].time + total_time, next_idx});
        }
    }

    for (int i = 1; i <= N; i++)
        cout << ans[i] << '\n';
}

void Craft::Input() {
    int pre;

    cin >> N;
    vec.resize(N + 1);
    ans.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i].time;

        do {
            cin >> pre;
            if (pre == -1)
                break;

            vec[pre].next.push_back(i);
            vec[i].count++;
        } while (pre != -1);

        if (!vec[i].count)
            pq.push({vec[i].time, i});
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    Craft().Solve();
    return 0;
}
