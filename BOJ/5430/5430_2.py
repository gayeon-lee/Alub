'''
 메모리: 32624 KB, 시간: 712 ms
 2022.04.24
 by Alub
'''
import collections

def solve():
    lst = []
    ps = ""
    n = 0
    string_arr = ""
    is_reverse = False
    is_error = False

    ps = input()
    n = int(input())
    string_arr = input()

    tmp = 0

    for s in string_arr:
        if s == '[':
            continue
        elif s == ']' or s == ',':
            if n == 0:
                continue
            lst.append(tmp)
            tmp = 0
        else:
            tmp = tmp * 10 + int(s)

    deq = collections.deque(lst)

    for p in ps:
        if p == 'R':
            is_reverse = not is_reverse
        elif p == 'D':
            if not deq:
                is_error = True

            if is_error:
                continue

            if is_reverse:
                deq.pop()
            else:
                deq.popleft()

    if is_error:
        print("error")
        return

    print('[', end='')

    while deq:
        if is_reverse:
            print(deq.pop(), end='')
        else:
            print(deq.popleft(), end='')

        if deq:
            print(',', end='')

    print(']')


T = int(input())

for i in range(0, T):
    solve()
