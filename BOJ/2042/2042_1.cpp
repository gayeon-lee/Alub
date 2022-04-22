/**
* 메모리: 18408 KB, 시간: 152 ms
* 풀이 시간: 00:00:00
* 2022.04.22
* by Alub
*/
#include <bits/stdc++.h>
using namespace std;

#define UPDATE 1
#define SUM 2

struct Section {
    int left;
    int right;
};

class SectionSum {
  public:
    void Solve();

  private:
    void Update(int index, long long num);
    long long Sum(int index, Section current, Section input);
    long long Init(int index);
    void Input();

    vector<long long> tree;
    int s = 1;
};

void SectionSum::Update(int index, long long diff) {
    if (index < 1)
        return;

    tree[index] -= diff;

    Update(index / 2, diff);
}

long long SectionSum::Sum(int index, Section current, Section input) {
    if (index >= s * 2)
        return 0;

    if (current.left > current.right)
        return 0;

    if (current.right < input.left)
        return 0;

    if (input.right < current.left)
        return 0;

    if (current.left == current.right)
        return tree[index];

    if (input.left <= current.left && current.right <= input.right)
        return tree[index];

    int mid = (current.left + current.right) / 2;

    return Sum(index * 2, {current.left, mid}, input) + Sum(index * 2 + 1, {mid + 1, current.right}, input);
}

long long SectionSum::Init(int index) {
    if (index >= s * 2)
        return 0;

    if (index < s)
        tree[index] = Init(index * 2) + Init(index * 2 + 1);

    return tree[index];
}

void SectionSum::Input() {
    long long a, b, c;
    long long diff;
    cin >> a >> b >> c;

    switch (a) {
    case UPDATE:
        diff = tree[b + s - 1] - c;
        Update(b + s - 1, diff);
        break;

    case SUM:
        cout << Sum(1, {s, s + s - 1}, {(int)b + s - 1, (int)c + s - 1}) << '\n';
        break;
    }
}

void SectionSum::Solve() {
    int N, M, K;
    cin >> N >> M >> K;

    while (s <= N)
        s *= 2;

    tree.resize(s * 2);

    for (int i = 0; i < N; i++)
        cin >> tree[i + s];

    Init(1);

    for (int i = 0; i < M + K; i++)
        Input();
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    SectionSum().Solve();
    return 0;
}