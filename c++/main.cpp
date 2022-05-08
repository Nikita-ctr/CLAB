#include <iostream>
using namespace std;
int n;
int m;

int main() {
    cin >> m;
    cin >> n;
    int p[n+m];

    for(int i=0; i<n+m; i++) cin >> p[i];

    int counter=0;
    for(int u=0; u<n+m;u++) {
        for(int j=1; j<((n+m)-u); j++) {
            if((p[j]<p[j-1])) {

                int prev;
                prev = p[j-1];
                p[j-1] = p[j];
                p[j] = prev;
                counter++;
            }
        }
    }
    cout << counter;
    return 0;
}