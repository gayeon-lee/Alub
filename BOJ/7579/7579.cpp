/**
* 메모리: 2180 KB, 시간: 0 ms
* 2022.04.29
* by Alub
*/
#include <bits/stdc++.h>

#define MEM_MAX 1000000001
#define COST_MAX 10001
using namespace std;

struct AppInfo {
    int mem;
    int cost;
};

class App {
  public:
    void Solve();

  private:
    void Input();
    int N, M;
    vector<AppInfo> app_info;
    vector<int> mems;
};

void App::Solve() {
    Input();
    mems.resize(COST_MAX);

    for (int i = 0; i < N; i++) {
        int cost = app_info[i].cost;
        for (int j = mems.size() - 1; j >= cost; j--)
            mems[j] = max(mems[j], mems[j - cost] + app_info[i].mem);
    }

    for (int i = 0; i < mems.size(); i++) {
        if (mems[i] >= M) {
            cout << i;
            break;
        }
    }
}

void App::Input() {
    cin >> N >> M;

    app_info.resize(N + 1);
    for (int i = 0; i < N; i++)
        cin >> app_info[i].mem;

    for (int i = 0; i < N; i++)
        cin >> app_info[i].cost;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    App().Solve();
    return 0;
}