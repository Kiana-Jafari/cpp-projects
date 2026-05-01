#include <iostream>
#include "Set.hpp"

int main()
{
    // Test 1: Integer set
    Set<int> intSet1, intSet2;

    intSet1.insert(10);
    intSet1.insert(20);
    intSet1.insert(30);
    intSet1.insert(20);
    std::cout << "Set1 after inserts: ";
    intSet1.displaySet();

    std::cout << "\nIs 20 present? " << (intSet1.isPresent(20) ? "Yes" : "No") << '\n';
    std::cout << "Is 99 present? " << (intSet1.isPresent(99) ? "Yes" : "No") << '\n';

    intSet1.remove(20);
    std::cout << "Set1 after removing 20: ";
    intSet1.displaySet();

    intSet2.insert(30);
    intSet2.insert(40);
    intSet2.insert(50);
    Set<int> unionSet = intSet1 + intSet2;
    std::cout << "\nUnion of Set1 and Set2: ";
    unionSet.displaySet();

    Set<int> diffSet = intSet1 - intSet2;
    std::cout << "\nDifference (Set1 - Set2): ";
    diffSet.displaySet();

    Set<int> interSet = intSet1 * intSet2;
    std::cout << "\nIntersection: ";
    interSet.displaySet();

    intSet1.save();
    std::cout << "\nSet1 saved to numbers.txt\n";

    // Test 2: Double set
    Set<double> doubleSet;
    doubleSet.insert(1.5);
    doubleSet.insert(2.7);
    doubleSet.insert(3.14);
    doubleSet.insert(1.5);
    std::cout << "Double set: ";
    doubleSet.displaySet();

    // Test 3: Character set
    Set<char> charSet;
    charSet.insert('A');
    charSet.insert('B');
    charSet.insert('C');
    charSet.insert('A');
    std::cout << "Char set: ";
    charSet.displaySet();

    // Test 4:
    Set<int> emptySet;
    std::cout << "Empty set size: ";
    emptySet.displaySet();

    Set<int> fullSet;
    for (int i = 0; i < 100; ++i) {
        fullSet.insert(i);
    }
    std::cout << "\nAfter inserting 100 distinct elements: ";
    fullSet.displaySet();
    fullSet.insert(200);  // "Reached maximum size"
    std::cout << "\n";

    // Test 5: GetInput
    Set<double> inputSet;
    inputSet.getInput();
    std::cout << "Set from user input: ";
    inputSet.displaySet();
}
