/**
* 메모리: 3076 KB, 시간: 36 ms
* 풀이 시간: 00:31:15
* 2022.04.24
* by Alub
*/
#include <bits/stdc++.h>

#define REVERSE 'R'
#define DELETE 'D'

using namespace std;

class AC {
  public:
    void Solve();

  private:
    void Input();
    void Output();
    void Execute();
    string p;
    int n;
    deque<int> x;
    bool is_error = false;
    bool is_reverse = false;
};

void AC::Output() {
    if (is_error) {
        cout << "error\n";
        return;
    }

    cout << "[";

    while (!x.empty()) {
        if (is_reverse) {
            cout << x.back();
            x.pop_back();
        } else {
            cout << x.front();
            x.pop_front();
        }
        if (!x.empty())
            cout << ',';
    }

    cout << "]\n";
}

void AC::Input() {
    string buffer;
    cin >> p >> n >> buffer;
    int temp = 0;
    for (auto c : buffer) {
        if (c == '[') {
            continue;
        } else if (c == ']' || c == ',') {
            if (n == 0)
                continue;
            x.push_back(temp);
            temp = 0;
        } else {
            temp = temp * 10 + (c - '0');
        }
    }
}

void AC::Execute() {
    for (auto job : p) {
        if (job == REVERSE) {
            is_reverse = !is_reverse;
        } else if (job == DELETE) {
            if (x.empty())
                is_error = true;

            if (is_error)
                continue;

            if (is_reverse)
                x.pop_back();
            else
                x.pop_front();
        }
    }
}

void AC::Solve() {
    Input();
    Execute();
    Output();
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
        AC().Solve();

    return 0;
}