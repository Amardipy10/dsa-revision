class Fancy {
    vector<long long> seq;
    long long a = 1;
    long long b = 0;
    const int mod = 1e9 + 7;

    long long power(long long x, long long y) {
        long long res = 1;
        x %= mod;
        while (y > 0) {
            if (y % 2 == 1) res = (res * x) % mod;
            x = (x * x) % mod;
            y /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, mod - 2);
    }

public:
    Fancy() {}

    void append(int val) {
        long long inv_a = modInverse(a);
        long long v = ((val - b + mod) % mod * inv_a) % mod;
        seq.push_back(v);
    }

    void addAll(int inc) {
        b = (b + inc) % mod;
    }

    void multAll(int m) {
        a = (a * m) % mod;
        b = (b * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= seq.size()) return -1;
        return (seq[idx] * a + b) % mod;
    }
};