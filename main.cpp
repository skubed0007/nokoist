#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
using namespace std;
namespace fs = std::filesystem;

int main()
{
    std::cout << "Welcome To Todoist!" << std::endl;
    std::cout << "Loading Todo-List Lists..." << std::endl;

    bool tdlse = fs::exists("./tdls");
    if (tdlse)
    {
        system("clear");
        std::cout << "CURRENT To-Do Lists :- " << std::endl;
        int indx = 0;
        for (const auto &i : fs::directory_iterator("./tdls/"))
        {
            std::cout << indx << ".) " << i.path().string() << std::endl;
            indx += 1;
        }

        std::cout << "Please type in the number corresponding to the todo-list > ";
        std::string chc = "";
        std::cin >> chc;
        int chcc = std::stoi(chc);

        while (chcc > indx - 1)
        {
            std::cout << "Please choose correctly!" << std::endl;
            std::cout << "Please type in the number corresponding to the todo-list > ";
            std::cin >> chcc;
        }

        int togi = 0;
        for (const auto &curtdl : fs::directory_iterator("./tdls"))
        {
            if (togi != chcc)
            {
                togi += 1;
                continue;
            }
            else
            {
                bool kr = true;
                while (kr)
                {
                    system("clear");
                    std::ifstream tdf(curtdl.path() / "ls.txt");
                    if (!tdf.is_open())
                    {
                        std::cerr << "Failed to open the file!" << std::endl;
                        std::cerr << "Press Enter to continue..." << std::endl;
                        cin.get();
                        return 1;
                    }

                    std::vector<std::string> cntns;
                    std::string curcntn;

                    // Read lines into the vector
                    while (std::getline(tdf, curcntn))
                    {
                        cntns.push_back(curcntn);
                    }

                    // Print the contents of the vector
                    int itemcount = 1;
                    for (const std::string &i : cntns)
                    {
                        std::cout << itemcount << ".) " << i << std::endl;
                        itemcount += 1;
                    }
                    int barmaker = 20;
                    int barmkrcount = 0;
                    while (barmkrcount <= barmaker)
                    {
                        cout << "*";
                        barmkrcount += 1;
                    }
                    cout << endl;
                    cout << "Type in a command\npossible commands are : {put index number to remove it} , add , exit" << endl;
                    cout << "> ";
                    string cmd = "";
                    cin >> cmd;
                    if (cmd == "exit")
                    {
                        kr = false;
                    }
                    else if (cmd == "add")
                    {
                        std::cout << "Enter the item to add: ";
                        std::string newItem;
                        std::cin.ignore();
                        std::getline(std::cin, newItem);
                        cntns.push_back(newItem);
                    }
                    else
                    {
                        try
                        {
                            int index = std::stoi(cmd);
                            if (index > 0 && index <= cntns.size())
                            {
                                cntns.erase(cntns.begin() + index - 1);
                            }
                            else
                            {
                                std::cerr << "Invalid index!" << std::endl;
                                std::cerr << "Press Enter to continue..." << std::endl;
                                char buf = 'b';
                                cin.get(buf);
                            }
                        }
                        catch (std::invalid_argument &)
                        {
                            std::cerr << "Invalid command!" << std::endl;
                            std::cerr << "Press Enter to continue..." << std::endl;
                            char buf = 'b';
                            cin.get(buf);
                            cin.get(buf);
                        }
                    }

                    // Write the updated list back to the file
                    std::ofstream wtf(curtdl.path() / "ls.txt");
                    for (const std::string &ii : cntns)
                    {
                        wtf << ii << std::endl;
                    }
                }
            }
        }
        return 0;
    }
    else
    {
        std::cout << "No Todo-List Lists found, let's create one!";
        std::cout << "*PRESS ENTER TO CONTINUE OR CTRL+C TO EXIT*" << std::endl;
        std::cin.ignore(); // To wait for enter key
        std::cin.get();
        system("clear");

        fs::create_directories("./tdls");
        std::cout << "New To-Do list name: ";
        std::string tdlnm = "";
        std::cin >> tdlnm;
        fs::create_directories("./tdls/" + tdlnm);

        std::ofstream outfile("./tdls/" + tdlnm + "/ls.txt");
        outfile.close();

        system("clear");
        std::cout << "CURRENT To-Do Lists :- " << std::endl;
        int indx = 0;
        for (const auto &i : fs::directory_iterator("./tdls/"))
        {
            std::cout << indx << ".) " << i.path().string() << std::endl;
            indx += 1;
        }
        return 0;
    }
}
