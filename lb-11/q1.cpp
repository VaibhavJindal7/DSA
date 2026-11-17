#include <iostream>
#include <vector>
using namespace std;

void heap(vector<int>& a, int n, int i) {
    int larg = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && a[l] > a[larg]) larg = l;
    if (r < n && a[r] > a[larg]) larg  = r;

    if (larg != i) {
        swap(a[i], a[larg]);
        heap(a, n, larg);
    }
}

void heapSort(vector<int>& a) {
    int n = a.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        heap(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);   
        heap(a, i, 0);   
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter " << n << " integers: ";
    for (int& x : a) cin >> x;

    heapSort(a);

    cout << "Sorted array: ";
    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}