/**
* 메모리: 2156 KB, 시간: 0 ms
* 2022.05.01
* by Alub
*/
#include <bits/stdc++.h>

using namespace std;

class App {
  public:
    void Solve();

  private:
    void Input();
    void Rotate(int, int, int);
    void Check();

    int N, M, T;
    vector<vector<int>> arr;
};

void App::Check() {
    bool is_checked = false;
    vector<vector<int>> tmp(arr);
    int cnt = 0;
    int sum = 0;

    for (int j = 1; j <= M; j++) {
        arr[0][j] = 0;
        arr[N + 1][j] = 0;
    }

    for (int i = 1; i <= N; i++) {
        arr[i][0] = arr[i][M];
        arr[i][M + 1] = arr[i][1];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] != 0) {
                cnt++;
                sum += arr[i][j];
                if (arr[i][j] == arr[i - 1][j] || arr[i][j] == arr[i + 1][j] || arr[i][j] == arr[i][j - 1] ||
                    arr[i][j] == arr[i][j + 1]) {
                    tmp[i][j] = 0;
                    is_checked = true;
                }
            }
        }
    }

    if (is_checked) {
        arr = tmp;
        return;
    }

    if (cnt == 0)
        return;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (tmp[i][j] > 0) {
                if (tmp[i][j] * cnt > sum)
                    tmp[i][j]--;
                else if (tmp[i][j] * cnt < sum)
                    tmp[i][j]++;
            }
        }
    }

    arr = tmp;
}

void App::Rotate(int idx, int d, int k) {
    int tmp = 0;
    while (k--) {
        if (d == 0) { // +1
            arr[idx][0] = arr[idx][M];
            for (int i = M; i >= 1; i--) {
                arr[idx][i] = arr[idx][i - 1];
            }
            arr[idx][0] = 0;
        }

        else { // -1
            arr[idx][M + 1] = arr[idx][1];
            for (int i = 1; i <= M; i++) {
                arr[idx][i] = arr[idx][i + 1];
            }
            arr[idx][M + 1] = 0;
        }
    }
}

void App::Solve() {
    int x, d, k, ans = 0;
    Input();

    while (T--) {
        cin >> x >> d >> k;
        for (int i = 1; i <= N; i++) {
            if (i % x == 0) {
                Rotate(i, d, k);
            }
        }

        Check();
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            ans += arr[i][j];
        }
    }

    cout << ans;
}

void App::Input() {
    cin >> N >> M >> T;
    arr.resize(N + 2);
    for (auto &a : arr)
        a.resize(M + 2);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    App().Solve();
    return 0;
}