
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





-----------
  
Submit Code
#include<iostream>#include<limits.h>#include<vector>using namespace std;int m[100][100];int s[100][100];int mcm(int p[],int i,int j){ if(m[i][j]!=0){ return m[i][j]; }

if(i==j){ return 0; } m[i][j]=INT_MAX; for(int k=i;k<j;k++){ int h=min(m[i][j],mcm(p,i,k)+mcm(p,k+1,j)+p[i-1]*p[k]*p[j]); if(h<m[i][j]){ s[i-1][j-1]=k; m[i][j]=h; } } 
return m[i][j];}int main(){ int n; cin>>n; int a[n]; for(int i=0;i<n;i++){ cin>>a[i]; } int c=mcm(a,1,n-1); for(int i=1;i<n-1;i++){ for(int j=i+1;j<n;j++){ cout<<m[i][j]<<" "; } cout<<endl; } for(int i=0;i<n-2;i++){ for(int j=i+1;j<n-1;j++){ cout<<s[i][j]<<" "; } cout<<endl; } cout<<c<<endl; }









void printParenthesis(int i, int j, int n, string names[]) {
    if (i == j) {
        cout << names[i];
        return;
    }
    cout << "(";
    printParenthesis(i, s[i][j], n, names);
    printParenthesis(s[i][j] + 1, j, n, names);
    cout << ")";
}

void printParenthesis(int i, int j, int n, char &name){
    if (i == j) {
        cout << name++;
        return;
    }
    cout << "(";
    printParenthesis(i, s[i][j], n, name);
    printParenthesis(s[i][j] + 1, j, n, name);
    cout << ")";
}


#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int m[100][100];
int s[100][100];
int mcm(int p[],int i,int j){
    if(m[i][j]!=0){
        return m[i][j];
    }
    if(i==j){
        return 0;
    }
    m[i][j]=INT_MIN;
    for(int k=i;k<j;k++){
        int h=max(m[i][j],mcm(p,i,k)+mcm(p,k+1,j)+p[i-1]*p[k]*p[j]);
        if(h>m[i][j]){
            s[i-1][j-1]=k;
            m[i][j]=h;
        }
    }
    return m[i][j];
}
void printer(vector<vector<int>>s, int i, int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        printer(s,i,s[i-1][j-1]);
        printer(s,s[i-1][j-1]+1,j);
        cout<<")";
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=mcm(a,1,n-1);
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>>s1;
    for(int i=0;i<n-1;i++){
        vector<int>s2;
        for(int j=0;j<n-1;j++){
            s2.push_back(0);
        }
        s1.push_back(s2);
    }
    for(int i=0;i<n-2;i++){
        vector<int>s2;
        for(int j=i+1;j<n-1;j++){
            cout<<s[i][j]<<" ";
            s1[i][j]=s[i][j];
        }
        cout<<endl;
    }
    cout<<c<<endl;
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-1;j++){
    //         cout<<s1[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    printer(s1,1,n-1);
}








#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int m[100][100];
int s[100][100];
int mcm(int p[],int i,int j){
    if(m[i][j]!=0){
        return m[i][j];
    }
    if(i==j){
        return 0;
    }
    m[i][j]=INT_MAX;
    for(int k=i;k<j;k++){
        int h=min(m[i][j],mcm(p,i,k)+mcm(p,k+1,j)+p[i-1]*p[k]*p[j]);
        if(h<m[i][j]){
            s[i-1][j-1]=k;
            m[i][j]=h;
        }
    }
    return m[i][j];
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=mcm(a,1,n-1);
    for(int i=1;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<c<<endl;
    
}






#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int mcm(int p[],int i,int j){
    if(i==j){
        return 0;
    }
    int q=INT_MAX;
    for(int k=i;k<j;k++){
        q=min(q,mcm(p,i,k)+mcm(p,k+1,j)+p[i-1]*p[k]*p[j]);
    }
    return q;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=mcm(a,1,n-1);
    cout<<c;
}





#include<iostream>
using namespace std;
int p_count(int n){
    if(n<=1){
        return 1;
    }
    int q=0;
    for(int i=1;i<n;i++){
        q=q+p_count(i)*p_count(n-i);
    }
    return q;
}
int main(){
    int n;
    cin>>n;
    int a=p_count(n);
    cout<<a;
}
