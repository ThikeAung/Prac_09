#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename T>
void displayVector(const vector<T> &container);

vector<int> sieveOfEratosthenes(int limit);
bool isCircularPrime(const vector<int> &numbers, int n);
bool find(const vector<int> &numbers, int target);

void displayVector(const vector<int> &container)
{
    for (int num : container)
    {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> sieveOfEratosthenes(int limit)
{
    vector<bool> prime(limit + 1, true);
    vector<int> primeNumbers;

    for (int p = 2; p * p <= limit; ++p)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= limit; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= limit; ++p)
    {
        if (prime[p])
        {
            primeNumbers.push_back(p);
        }
    }

    return primeNumbers;
}

bool isCircularPrime(const vector<int> &numbers, int n)
{
    string s = to_string(n);

    for (int i = 0; i < s.size(); ++i)
    {
        rotate(s.begin(), s.begin() + 1, s.end()); 
        int rotatedNum = stoi(s);
        if (!binary_search(numbers.begin(), numbers.end(), rotatedNum))
        {
            return false;
        }
    }

    return true;
}

bool find(const vector<int> &numbers, int target)
{
    return binary_search(numbers.begin(), numbers.end(), target);
}

int main()
{
    int bigNumber = 100000000;
    vector<int> primeNumbers = sieveOfEratosthenes(bigNumber);
    vector<int> circularPrimeNumbers;

    for (int primeNumber : primeNumbers)
    {
        if (isCircularPrime(primeNumbers, primeNumber))
        {
            circularPrimeNumbers.push_back(primeNumber);
        }
    }

    // cout << "Circular Prime Numbers: " << endl;
    // displayVector(circularPrimeNumbers);
    cout << "Total Circular Primes below " << bigNumber << ": " << circularPrimeNumbers.size() << endl;

    return 0;
}
