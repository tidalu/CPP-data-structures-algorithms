#include <iostream>
#include <list>

struct Customer {
    int priority;
    std::string name;

    Customer(int priority, std::string name) : priority(priority), name(name) {}
};

class PriorityQueue {
private:
    std::list<Customer> customerList;

public:
    void enqueue(Customer customer) {
        auto it = customerList.begin();
        while (it != customerList.end() && it->priority > customer.priority) {
            ++it;
        }
        customerList.insert(it, customer);
    }

    Customer dequeue() {
        if (customerList.empty()) {
            throw std::runtime_error("Queue is empty");
        }
        Customer front = customerList.front();
        customerList.pop_front();
        return front;
    }
};

int main() {
    PriorityQueue queue;
    queue.enqueue(Customer(1, "Ulugbek"));
    queue.enqueue(Customer(3, "Amal"));
    queue.enqueue(Customer(2, "Saidali"));
    queue.enqueue(Customer(4, "Mukhammadjon"));

    std::cout << queue.dequeue().name << std::endl; 
    std::cout << queue.dequeue().name << std::endl; 
    std::cout << queue.dequeue().name << std::endl; 
    std::cout << queue.dequeue().name << std::endl;

    return 0;
}
