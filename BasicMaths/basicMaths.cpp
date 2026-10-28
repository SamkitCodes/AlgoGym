#include <iostream>
#include <vector>
using namespace std;

// Problem: Count number of digits in a number
// Time: O(1) using log_10 formula or else O(log_10 n) - Number is divided by 10 in loop
// Space: O(1)
int numDigits(int n) {
    // Case: number is 0
    if (n == 0) {
        return 1;
    }

    int input;
    int numberOfDigits = 0;


    // Handling negatives
    if (n < 0) {
        input = n * -1;
    } else {
        input = n;
    }

    return static_cast<int>(log10(input) + 1);

    // while (input > 0) {
    //     cout << (input % 10) << "\n";
    //
    //     numberOfDigits++;
    //     input = input / 10;
    // }
    // return numberOfDigits;
}

// Problem: Armstrong Number
// Time: O(log_10(n)) - Number is divided by 10 in loop till it reaches 0
// Space: O(1)
bool armstrongCheck(int n) {
    // Case: number is 0
    if (n == 0) {
        return true;
    }

    int input = n;
    int sum = 0;
    int power = static_cast<int>(log10(n) + 1);

    while (input > 0) {
        int base = input % 10;


        sum += static_cast<int>(pow(base, power));

        input /= 10;
    }

    if (sum == n) {
        return true;
    }

    return false;
}

// Problem: Sorted divisors of a number
// Time: O(sqrt(n)log(n)) - Loop take O(sqrt(n)) and sort function takes O(sqrt(n)*log(sqrt(n))
// but log(sqrt(n)) = (1/2)*log(n).
// Space: O(sqrt(n)) - Upper Bound or O(d(n)) where d(n) is number of divisors
vector<int> divisors(int n) {
    vector<int> divisors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);

            if (i * i != n) {
                divisors.push_back((n / i));
            }
        }
    }

    sort(divisors.begin(), divisors.end());
    return divisors;
}

// Problem: GCD
// Time: O(log_Φ(min(a,b)) - log phi as sometimes we divide by b sometimes by a
// Space: O(1)
int gcd(int a, int b) {

    // Can use recursion here if needed
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }

    if (a == 0) {
        return b;
    }
    return a;
}


// Problem: Print all prime factors of a number n
// Time: O(sqrt(n)) - when n is prime
// Space: O(1)
void printPrimeFactors(int n) {
    int duplicate = n;

    for (int i = 2; i * i <= duplicate; i++) {
        if (duplicate % i == 0) {
            cout << i << "\n";

            while (duplicate % i == 0) {
                duplicate /= i;
            }
        }
    }

    if (duplicate != 1) {
        cout << duplicate;
    }
}


// Problem: Print all prime numbers up to n using the Sieve of Eratosthenes.
// Time: O(n log log n): primes mark about n/2 + n/3 + n/5 + ... multiples;
// the reciprocal sum 1/2 + 1/3 + 1/5 + ... grows like log log n.
// Space: O(n)
void sieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= n / i; i++) {
        if (prime[i]) {
            for (long long j = 1LL * i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << "\n";
        }
    }
}

// Problem: Count primes in range l to r for q queries. Numbers can be till 10^6
// Time: O(n log log n)
// Space: O(1) - It is constant do not grow
void primeCount(int q, vector<pair<int, int> > &range) {
    const int MAX_INPUT_NUMBER = static_cast<int>(pow(10, 6));

    vector<int> sieve(MAX_INPUT_NUMBER+1, 1);
    sieve[0] = sieve[1] = 0;

    for (int i = 2; i * i <= MAX_INPUT_NUMBER; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAX_INPUT_NUMBER; j += i) {
                sieve[j] = 0;
            }
        }
    }


    for (int i = 2; i <= MAX_INPUT_NUMBER; i++) {
        sieve[i] += sieve[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l = range.at(i).first;
        if (l == 0) {
            l = 1;
        }
        int r = range.at(i).second;

        cout << sieve[r] - sieve[l - 1] << "\n";
    }
}

// Problem: LCM between 2 numbers
// Time: O(log_Φ(min(a,b)) - From GCD algorithm
// Space: O(1)
int lcm(int a, int b) {

    int gcdNum = gcd(a, b);

    return (a/gcdNum) * b;
}


int main() {
    // int digits = numDigits(-123);
    // cout << "Digits: " << digits;

    // bool armSt = armstrongCheck(1634);
    // cout << armSt;

    // vector<int> divisor = divisors(36);
    // for (int num : divisor) {
    //     cout << num << "\n";
    // }

    //cout << gcd(8, 36);

    //printPrimeFactors(10);

    //sieveOfEratosthenes(30);

    // vector<pair<int, int>> ranges = {
    //     {1, 10},         // 4: 2, 3, 5, 7
    //     {3, 7},          // 3: 3, 5, 7
    //     {10, 20},        // 4: 11, 13, 17, 19
    //     {2, 2},          // 1: 2
    //     {4, 4},          // 0
    //     {0, 1},          // 0
    //     {0, 2},          // 1: 2
    //     {999990, 1000000} // 0
    // };
    //
    // primeCount(static_cast<int>(ranges.size()), ranges);

    // int lcmNum = lcm(500001,5);
    // cout << lcmNum;

    return 0;
}
