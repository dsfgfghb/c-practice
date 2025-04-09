//最长不下降子序列
//时间复杂度O(n^2)
#include <iostream> 
#include <vector>
using namespace std;


int main(){
    int n,ans=-1;
    vector<int> a;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    vector<int> dp(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(a[i] >= a[j]&& dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans;
}
