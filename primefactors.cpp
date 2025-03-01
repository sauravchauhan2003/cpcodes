vector<int> primeFactors(int n) {
    vector<int> factors;
    
    // Check for number of twos
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    
    // Check for odd factors
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    
    // If n is still a prime number greater than 2
    if (n > 2)
        factors.push_back(n);
    
    return factors;
}
