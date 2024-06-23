#include <iostream>
#include <stack>
#include <vector>

std::vector<int> write_to_notepad()
{
    int number_of_commands_left;
    std::cin >> number_of_commands_left;

    std::string command, type;
    int id;
    std::stack<int> deep_stack, shallow_stack;
    std::vector<int> notepad;
    while (number_of_commands_left-- > 0)
    {
        std::cin >> command >> type;
        if (command == "dziekuje")
        {
            std::cin >> id;
            if (type == "gleboki")
            {
                deep_stack.push(id);
            }
            else if (type == "plytki")
            {
                shallow_stack.push(id);
            }
        }
        else if (command == "prosze")
        {
            if (type == "gleboki")
            {
                notepad.push_back(deep_stack.top());
                deep_stack.pop();
            }
            if (type == "plytki")
            {
                notepad.push_back(shallow_stack.top());
                shallow_stack.pop();
            }
        }
    }

    return notepad;
}

void print_results(std::vector<int> notepad)
{
    for (auto i : notepad)
    {
        std::cout << i << "\n";
    }
}


int main()
{
    print_results(
        write_to_notepad()
    );

    return 0;
}