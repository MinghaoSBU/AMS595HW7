//
//  main.cpp
//  AMS595ASSI7
//
//  Created by 罅 on 2024/12/15.
//

#include <iostream>
#include <string>
using namespace std;

// Problem 1
void number_value() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    switch (n) {
        case -1:
            cout << "negative one" << endl;
            break;
        case 0:
            cout << "zero" << endl;
            break;
        case 1:
            cout << "positive one" << endl;
            break;
        default:
            cout << "other value" << endl;
            break;
    }
}

// Problem 2
void print_vector(std::vector<int> v) {
    // Your implementation
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << " ";
        }
    }
    cout << endl; // End after printing the vector
}

// Problem 3
void print_fibonacci(int limit) {
    int a = 1, b = 2;

    // Print the first term
    cout << a << endl;

    // While loop for generating and printing the Fibonacci terms
    while (b <= limit) {
        cout << b << endl;

        // Update terms for later
        int next = a + b;
        a = b;
        b = next;
    }
}

// function that determines if a number is prime
bool isprime(int n) {
    if (n <= 1) return false; // 0 and 1 not prime
    for (int i = 2; i * i <= n; ++i) { // Check divisors up to sqrt(n)
        if (n % i == 0) {
            return false; // Divisible by a number other than 1 and itself
        }
    }
    return true; // Prime
}

// Test for isprime
void test_isprime() {
    std::cout << "isprime(2) = " << isprime(2) << '\n';
    std::cout << "isprime(10) = " << isprime(10) << '\n';
    std::cout << "isprime(17) = " << isprime(17) << '\n';
}

// function that finds all the factors of a number:
vector<int> factorize(int n) {
    vector<int> answer;
    for (int i = 1; i <= n; ++i) { // Iterate through all numbers up to n
        if (n % i == 0) {
            answer.push_back(i); // Add factor to the vector
        }
    }
    return answer;
}

// Test for factorize
void test_factorize() {
    print_vector(factorize(2));
    print_vector(factorize(72));
    print_vector(factorize(196));
}

// function that finds the prime factorization of a number
vector<int> prime_factorize(int n) {
    vector<int> answer;
    for (int i = 2; i * i <= n; ++i) { // Start with the smallest prime
        while (n % i == 0) { // Check if i is a factor
            answer.push_back(i); // Add to prime factors
            n /= i; // Divide n by i
        }
    }
    if (n > 1) { // If n is still greater than 1, it's a prime factor
        answer.push_back(n);
    }
    return answer;
}

// Test for prime factorize
void test_prime_factorize() {
print_vector(prime_factorize(2));
print_vector(prime_factorize(72));
print_vector(prime_factorize(196));
}

// function that prints the first n rows of Pascal’s Triangle
void print_pascals_triangle(int n) {
    vector<vector<int>> triangle(n);

    for (int i = 0; i < n; ++i) {
        triangle[i].resize(i + 1); // Resize the row to fit the current level
        triangle[i][0] = triangle[i][i] = 1; // First and last elements are 1

        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        // Print the current row
        print_vector(triangle[i]);
    }
}

int main() {
    // Test Fibonacci sequence printing
    cout << "Fibonacci sequence up to 4,000,000:" << endl;
    print_fibonacci(4000000);

    // Run all test cases
    cout << "\nTesting isprime function:" << endl;
    test_isprime();

    cout << "\nTesting factorize function:" << endl;
    test_factorize();

    cout << "\nTesting prime_factorize function:" << endl;
    test_prime_factorize();

    // Test Pascal's Triangle
    cout << "\nPascal's Triangle with 10 rows:" << endl;
    print_pascals_triangle(10);

    // Test number value
    cout << "\nTesting number_value function:" << endl;
    number_value();

    return 0;
}
