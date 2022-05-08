#include <stdio.h>

int main() {
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

    for (int i = 0; i < n+m; i++) {
        if (visited[i] <= 0) {
            //создаются переменные(...)
            int idx = p[i];
            int cnt = 0;
            int is_ok = 0;
            //меняем vsited[i]=1
            visited[i] = 1;
    }


}
