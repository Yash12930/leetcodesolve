class Solution {
private:
    typedef long long ll;
    static const int mod = 1e9+7;
    static const int MAXN = 100005;
    static ll fact[MAXN], invfact[MAXN];
    static bool computed;

    static ll mpow(ll base, ll exp) {
        ll result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
    }

    static void compute() {
        if (computed) return;
        computed = true;
        fact[0] = invfact[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            fact[i] = (fact[i-1] * i) % mod;
            invfact[i] = mpow(fact[i], mod-2);
        }
    }

    static ll nCk(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % mod * invfact[n-k] % mod;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        compute();
        ll ways = nCk(n-1, k);
        ways = ways * m % mod;
        ways = ways * mpow(m-1, n-k-1) % mod;
        return ways;
    }
};

long long Solution::fact[Solution::MAXN];
long long Solution::invfact[Solution::MAXN];
bool Solution::computed = false;
