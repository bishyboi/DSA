#include "avl.h"
#include <vector>
/* Note:
    1. You will have to comment main() when unit testing your code because catch uses its own main().
    2. You will submit this main.cpp file and any header files you have on Gradescope.
*/
bool isID(std::string s)
{
    if (s.length() != 8)
        return false;
    else
    {
        for (char c : s)
        {
            if (!isdigit(c))
                return false;
        }

        return true;
    }
}

bool isName(std::string s)
{
    if (s.front() == '\"' && s.back() == '\"')
        return true;
    else
        return false;
}
std::vector<std::string> separateString(std::string &line)
{
    std::vector<std::string> args;
    std::string input = "";
    int spaceIdx = 0;

    while (spaceIdx != -1)
    {
        spaceIdx = line.find(" ");

        input = line.substr(0, spaceIdx);
        line.erase(0, spaceIdx + 1);

        args.push_back(input);
    }

    return args;
}

bool determineValidCMD(std::vector<std::string> &args)
{
    if (args[0] == "insert")
    {
        if (isName(args[1]))
            return isID(args[2]);
        else
            return false;
    }

    else if (args[0] == "remove")
    {
        if (isID(args[1]))
            return true;
        else
            return false;
    }
    else if (args[0] == "search")
    {
        if (isID(args[1]) || isName(args[1]))
            return true;
        else
            return false;
    }
    else if (args[0] == "printInorder")
        return true;
    else if (args[0] == "printPreorder")
        return true;
    else if (args[0] == "printPostorder")
        return true;
    else if (args[0] == "printLevelCount")
        return true;
    else if (args[0] == "removeInOrder")
        return true;

    return false;
}

bool executeCMD(std::vector<std::string> args, AVLTree &avl)
{
    if (args[0] == "insert")
    {
        args[1].erase(0, 1);
        args[1].erase(args[1].length() - 1, 1);

        if (avl.insert(args[1], std::stoi(args[2])))
        {
            std::cout << "successful";
            return true;
        }
        else
            return false;
    }

    else if (args[0] == "remove")
    {
        args[1].erase(0, 1);
        args[1].erase(args[1].length() - 1, 1);

        if (avl.remove(std::stoi(args[1])))
        {
            std::cout << "successful";
            return true;
        }
        else
            return false;
    }
    else if (args[0] == "search")
    {
        std::string output = "";
        if (isID(args[1]))
            output = avl.search(std::stoi(args[1]));
        else
        {
            args[1].erase(0, 1);
            args[1].erase(args[1].length() - 1, 1);

            output = avl.inOrderSearch(args[1]);
        }
        if (output == "" || output == "unsuccessful")
            return false;
        else
            std::cout << output;
        return true;
    }
    else if (args[0] == "printInorder")
    {
        std::cout << avl.printInOrder();
        return true;
    }
    else if (args[0] == "printPreorder")
    {
        std::cout << avl.printPreOrder();
        return true;
    }
    else if (args[0] == "printPostorder")
    {
        std::cout << avl.printPostOrder();
        return true;
    }
    else if (args[0] == "printLevelCount")
    {
        std::cout << avl.getHeight();
        return true;
    }
    else if (args[0] == "removeInOrder")
    {
        return avl.removeInOrder(std::stoi(args[1]));
    }
    return false;
}

int main()
{
    int commandCount = 0;
    std::string line = "";
    std::vector<std::string> args;
    AVLTree avl = AVLTree();

    std::getline(std::cin, line);

    args = separateString(line);

    commandCount = std::stoi(args[0]);

    for (int i = 0; i < commandCount; i++)
    {
        std::getline(std::cin, line);
        args = separateString(line);

        if (determineValidCMD(args))
        {
            if (!executeCMD(args, avl))
                std::cout << "unsuccessful";
        }
        else
            std::cout << "unsuccessful";

        std::cout << "\n";
    }

    return 0;
}
