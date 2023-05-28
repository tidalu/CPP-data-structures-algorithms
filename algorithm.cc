#include <iostream>
#include <vector>
using namespace std;

void process(vector<int>& xs, vector<int>& result, int i) {
    if (i >= xs.size()) return;
    result.push_back(xs[i]);
    if (i + 1 < xs.size()) {
        result.push_back(xs[i + 1]);
    }
    process(xs, result, i + 2);
}

int main() {
    vector<int> xs;
    int n;
    while (cin >> n) {
        xs.push_back(n);
    }
    
    vector<int> result;
    process(xs, result, 0);
    
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}