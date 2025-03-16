vector<int> getFactors(int n) {
    vector<int> factors;
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);  // Store the divisor
            if (i != n / i) {      // Avoid duplicate factors for perfect squares
                factors.push_back(n / i);
            }
        }
    }
    
    sort(factors.begin(), factors.end()); // Sort factors in ascending order
    return factors;
}
