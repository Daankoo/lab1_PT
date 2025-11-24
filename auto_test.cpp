#include <iostream> 
#include <list>
#include <string>
#include "stranger.h" 

using namespace std;

bool checkSetRes(const Set<int>& result, const list<int>& expectedElements) {
    for (const int& item : expectedElements) {
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

    // TEST 1: UNION
    Set<int> unionRes = setA.UNION(setB);
    list<int> expectedUnion = {1, 2, 5, 7, 8, 10, 11, 12, 13, 19, 3, 6, 9, 14, 15, 16, 17};
    bool union_passed = checkSetRes(unionRes, expectedUnion);

    if (union_passed) {
        cout << "Test 1: PASS\n";
    } else {
        cout << "Test 1: FAIL\n";
        return 1; 
    }

    // --- TEST 2: INTERSECTION ---
    Set<int> intersectionRes = setA.INTERSECTION(setB);
    list<int> expectedIntersection = {7, 11, 13}; 
    bool intersection_passed = checkSetRes(intersectionRes, expectedIntersection);
    
    if (intersection_passed) {
        cout << "Test 2: PASS\n";
    } else {
        cout << "Test 2: FAIL\n";
        return 1;
    }

    // TEST 3: DIFFERENCE A\B
    Set<int> differenceRes = setA.SETDIFFERENCE(setB);
    list<int> expectedDifference = {1, 2, 5, 8, 10, 12, 19}; 
    bool difference_passed = checkSetRes(differenceRes, expectedDifference);
    
    if (difference_passed) {
        cout << "Test 3: PASS\n";
    } else {
        cout << "Test 3: FAIL\n";
        return 1;
    }

    // TEST 4: SYM_DIFFERENCE
    Set<int> SymDiffRes = setA.SYM_DIFFERENCE(setB);
    list<int> expectedSymDiff = {1, 2, 5, 8, 10, 12, 19, 3, 6, 9, 14, 15, 16, 17};
    bool SymDiff_passed = checkSetRes(SymDiffRes, expectedSymDiff);
    
    if (SymDiff_passed) {
        cout << "Test 4: PASS\n";
    } else {
        cout << "Test 4: FAIL\n";
        return 1;
    }

    return 0;
}
