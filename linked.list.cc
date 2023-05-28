#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

bool is_balanced(const std::string &s)
{

    std::stack<char> stack;

    std::unordered_map<char, char> map = {
        {')', '('},
        {'}', '{'},
        {']', '['}};

    for (char c : s)
    {

        if (map.find(c) == map.end())
        {

            stack.push(c);
        }
        else
        {

            if (stack.empty() || stack.top() != map[c])
            {

                return false;
            }

            stack.pop();
        }
    }

    return stack.empty();
}

int main()
{

    std::string input;

    std::cout << "String: ";

    std::cin >> input;

    bool balanced = is_balanced(input);

    if (balanced)
    {

        std::cout << "The string is balanced." << std::endl;
    }
    else
    {

        std::cout << "The string is not balanced." << std::endl;
    }

    return 0;
}
