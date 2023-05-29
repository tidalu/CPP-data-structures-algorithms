#include <iostream>
#include <queue>

std::queue<int> mergeQueues(std::queue<int>& a, std::queue<int>& b) {
    std::queue<int> c;
    
    if (a.empty())
        return b;
    if (b.empty())
        return a;
    
    if (a.front() <= b.front()) {
        c.push(a.front());
        a.pop();
        c = mergeQueues(a, b);
    } else {
        c.push(b.front());
        b.pop();
        c = mergeQueues(a, b);
    }
    
    c.push(a.front());
    a.pop();
    
    return c;
}

std::queue<int> mergeAllQueues(std::queue<std::queue<int>>& xs) {
    while (xs.size() > 1) {
        std::queue<int> a = xs.front();
        xs.pop();
        std::queue<int> b = xs.front();
        xs.pop();
        
        std::queue<int> c;
        while (!a.empty() || !b.empty()) {
            if (a.empty()) {
                c.push(b.front());
                b.pop();
            } else if (b.empty()) {
                c.push(a.front());
                a.pop();
            } else if (a.front() <= b.front()) {
                c.push(a.front());
                a.pop();
            } else {
                c.push(b.front());
                b.pop();
            }
        }
        
        xs.push(c);
    }
    
    return xs.front();
}

int main() {
    std::queue<std::queue<int>> xs;
    int n;
    
    while (std::cin >> n) {
        std::queue<int> x;
        x.push(n);
        xs.push(x);
    }
    
    std::queue<int> result = mergeAllQueues(xs);
    
    while (!result.empty()) {
        std::cout << result.front() << " ";
        result.pop();
    }
    
    std::cout << std::endl;
    
    return 0;
}


