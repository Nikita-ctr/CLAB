
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // Radius of the 3 given circles declared as double.
    double r1, r2, r3;

    // Taking r1, r2, r3 as input
    r1 = 10;
    r2 = 10;
    r3 = 10;

    // Calculation of r4 using formula given above
    double r4 = (r1 * r2 * r3)
                / (r1 * r2 + r2 * r3 + r1 * r3
                   + 2.0 * sqrt(r1 * r2 * r3 * (r1 + r2 + r3)));
    cout << fixed << setprecision(6) << r4 << '\n';
    return 0;
}