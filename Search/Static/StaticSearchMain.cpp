#include <iostream>
#include "StaticSearch.hpp"
using namespace std;

int main()
{
    SET<int, int> a[] = {2, 4, 7, 8, 10, 12, 13, 15, 16, 19, 20};
    cout << seqSearch(a, 11, 13) << endl;
    cout << binarySearch(a, 11, 13) << endl;
    cout << binarySearchRec(a, 11, 13) << endl;

    cout << seqSearch(a, 11, -3) << endl;
    cout << binarySearch(a, 11, -3) << endl;
    cout << binarySearchRec(a, 11, -3) << endl;

    system("pause");
    return 0;
}