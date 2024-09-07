#include <iostream>
#include <vector>

std::vector<int> tribonacci(std::vector<int> signature, int n) {
    
    if (n == 0) {
        return {};
    }
    
    if (n <= 3) {
        return std::vector<int>(signature.begin(), signature.begin() + n);
    }
    
    std::vector<int> result = signature;
    
    for (int i = 3; i < n; i++) {
        int next_value = result[i - 1] + result[i - 2] + result[i - 3];
        result.push_back(next_value);
    }
    
    return result;
}

int main() {
    std::vector<int> signature = {0, 1, 1}; 
    int n = 10; 
    
    std::vector<int> result = tribonacci(signature, n);
    
    std::cout << "Secuencia Tribonacci de " << n << " elementos: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}