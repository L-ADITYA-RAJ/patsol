
Don't fuck with paste:- https://chrome.google.com/webstore/detail/dont-f-with-paste/nkgllhigpcljnhoakjkgaieabnkmgdkb
Switch tabs:- https://chrome.google.com/webstore/detail/switch-tabs/idiomkjpboogdmkpndeepnkldhbpnnpb?hl=en#:~:text=Switch%20Tabs%20is%20the%20only,Enjoy
Akways Active window:- https://chrome.google.com/webstore/detail/always-active-window-alwa/ehllkhjndgnlokhomdlhgbineffifcbj?hl=en

/*************************************************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <math.h> 
#include <limits.h>
#include <vector>
using namespace std; 
  
int MatrixChainOrder(int p[], int n) 
{ 
  
    int m[n][n]; 
  
    for (int i = 1; i < n; i++) 
        m[i][i] = 0; 

    for (int L = 2; L < n; L++) { 
        for (int i = 1; i < n - L + 1; i++) { 
            int j = i + L - 1; 
            m[i][j] = INT_MAX; 
            for (int k = i; k <= j - 1; k++) { 
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]; 
                if (q < m[i][j]) 
                    m[i][j] = q; 
            } 
        } 
    } 
  
    return m[1][n - 1]; 
} 

int main() 
{ 
    int n, k;
    cin >> n >> k;
    int p[n+1];
    p[0] = k;
    for(int i=1; i<=n; i++){
        p[i] = k;
    }
    cout << MatrixChainOrder(p, n+1); 
    return 0; 
}


/**********************************************************************************************************************************/
#include <iostream>
#include <cstring>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;

    int dp[n+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) {
        int sum = digitSum(i);
        if (sum % 2 == 0) dp[i] = sum;
        else dp[i] = sum + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}


/********************************************************************************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int calculatePrice(int x) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    if (sum % 2 == 0) {
        return sum;
    } else {
        return sum + 1;
    }
}

int maxRevenue(int n, int k) {
    if (k == 1) {
        return calculatePrice(n);
    }

    int maxRev = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        int rev = calculatePrice(i) + maxRevenue(n - i, k - 1);
        if (rev > maxRev) {
            maxRev = rev;
        }
    }

    return maxRev;
}

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int revenue = maxRevenue(n, k);
    cout << revenue << endl;
    return 0;
}