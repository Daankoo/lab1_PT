#include <iostream> 
#include <list>
#include <string>
#include "stranger.h" 

using namespace std;

template <typename T>
bool checkUnionRes(const Set<T>& result, const list<T>& expectedElements) {
    for (const T& item : expectedElements) {
        if (!result.SEARCH(item)) {
            return false;
        }
    }
    return true;
}

int main() {
    
    Set<int> setA;
    Set<int> setB;
    
    // Set A: {1, 2, 5, 7, 8, 10, 11, 12, 13, 19}
    setA.INSERT(1); setA.INSERT(5); setA.INSERT(10); setA.INSERT(12); setA.INSERT(13); 
    setA.INSERT(2); setA.INSERT(7); setA.INSERT(8); setA.INSERT(11); setA.INSERT(19);
    
    // Set B: {3, 6, 7, 9, 11, 13, 14, 15, 16, 17}
    setB.INSERT(3); setB.INSERT(14); setB.INSERT(17); setB.INSERT(13); setB.INSERT(11); 
    setB.INSERT(16); setB.INSERT(15); setB.INSERT(7); setB.INSERT(6); setB.INSERT(9); 
    
    Set<int> unionRes = setA.UNION(setB);
    
    list<int> expectedUnion = {1, 2, 5, 7, 8, 10, 11, 12, 13, 19, 3, 6, 9, 14, 15, 16, 17};

    bool test_passed = checkUnionRes(unionRes, expectedUnion);

    if (test_passed) {
        cout << "Test 1 Passed! UNION result is correct.\n";
        return 0; // Повертаємо 0 (Успіх)
    } else {
        cout << "Test 1 Failed! Expected the correct set, but got an incorrect one.\n";
        return 1; // Повертаємо 1 (Помилка)
    }
}
