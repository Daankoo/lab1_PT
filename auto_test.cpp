#include <iostream>
#include "count.h"

using namespace std;

int main() {
    
    int result = count(2026, 1, 1);
    
    if (result == 4) {
        cout << "Test 1 Passed! Result is 4.\n";
    } 
    else {
        cout << "Test 1 Failed! Expected 4, got " << result;
        return 1;    
    }

    return 0; 
}