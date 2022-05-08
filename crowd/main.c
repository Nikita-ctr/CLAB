#include <stdio.h>

//5 7
//9 7 12 6 1 11 2 10 3 8 4 5
//
//2 3
//1 4 2 5 3


int main () {
    int n = 0;
    int m = 0;
    int p[200000] = {};

    int res = 0;

    int visited[200000];

    int ncnt = 0;
    int mcnt = 0;

    int ans = 0;

    res = scanf("%d", &n);
    res = scanf("%d", &m);
    for (int i = 0; i < n+m; i++) {
        res = scanf("%d", p+i);
        p[i]--;
    }

    //цикл до n+m длинны
    for (int i = 0; i < n+m; i++) {
        //если какой то элемент меньше или равен нулю,то=>
        if (visited[i] <= 0) {
            //создаются переменные(...)
            int idx = p[i];

            int cnt = 0;
            int is_ok = 0;
            //меняем vsited[i]=1
            visited[i] = 1;

            while (visited[idx] <= 0) {
                visited[idx] = 1;
                if ((p[idx] < n && idx >= n) || (p[idx] >= n && idx < n)) {
                    is_ok = 1;
                }
                idx = p[idx];
                cnt++;
            }
            ans += cnt;
            if (cnt > 0 && i < n) {
                ncnt += 1-is_ok;
            } else if (cnt > 0) {
                mcnt += 1-is_ok;
            }
        }
    }

    if (ncnt > mcnt) {
        ans += 2*ncnt;
    } else {
        ans += 2*mcnt;
    }


    printf("%d",ans);
    return 0;
}