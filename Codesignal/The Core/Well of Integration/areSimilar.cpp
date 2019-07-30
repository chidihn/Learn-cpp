/**
 * Hai mảng được gọi là tương tự nhau nếu như ta có thể thu được mảng này bằng
 * cách hoán đổi tối đa một cặp phần tử trong mảng kia.
 */
#include <iostream>
#include <vector>
using namespace std;

bool areSimilar(vector<int> a, vector<int> b) {
    if(a == b)
        return true;

    // Tìm 2 phần tử khác nhau đầu tiên và hoán đổi
    int tmp[2], j = 0;
    for(int i = 0; i < a.size() && j < 2; ++i)
        if(a[i] != b[i])
            tmp[j++] = i;
    swap(a.at(tmp[0]), a.at(tmp[1]));

    return a == b;
}

bool areSimilar2(vector<int> a, vector<int> b) {
    if (a == b)
        return true;

    iter_swap(
        mismatch(a.begin(), a.end(), b.begin(), b.end()).first,
        mismatch(a.rbegin(), a.rend(), b.rbegin(), b.rend()).first
    );

    return a == b;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5};
    vector<int> b = {1, 2, 3, 4, 5};

    cout << boolalpha << areSimilar(a, b)<< endl;
    cout << boolalpha << areSimilar2(a, b)<< endl;

    return 0;
}