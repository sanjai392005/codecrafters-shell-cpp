#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

vector<std::string> path_dealer(){ //splits the PATH at occurence of ':' and stores the individual paths in a vector
    std::vector<std::string> paths;
    std::string env_path = std::getenv("PATH");

    std::string seperate_path = "";

    for(char i: env_path){
        if(i!=':'){
           seperate_path.push_back(i) ;
        }
        else{
            paths.push_back(seperate_path);
            seperate_path = "";
        }
    }
    if(!seperate_path.empty()){
        paths.push_back(seperate_path);
    }

    return paths;
}

std::string program_existence(std::vector<std::string> paths, std::string target){
    int isPresent = 0;

    for(std::string i: paths){
        fs::path current_path = i;

        for(const auto &entry: fs::directory_iterator(current_path)){
            if(entry.path().filename() == target){
                isPresent = 1;
                return target+" is "+(std::string)entry.path()+"\n";
            }
        }
    }

    return target+": not found"+"\n";
    
}

int main(){
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    set<string> shell_commands = {"type", "echo", "exit"};

    while(true){
        string command;
        cout<<"$ ";
        getline(cin, command);

        if(command=="exit 0" || command=="exit"){// INBUILT: exit
            return 0;
        }
        else if(command.substr(0, 4)=="echo"){// INBUILT: echo

            if(command.size()==4){continue;}
            else cout<<command.substr(5, command.size())<<endl;

        }
        else if(command.substr(0, 4)=="type"){// INBUILT: type
            if(command.size()==4){ continue; }
            else{
                string suffix = command.substr(5, command.size());

                if(shell_commands.find(suffix)!=shell_commands.end()) cout<<suffix<<" is a shell builtin"<<endl;
                //else if(shell_commands.find(suffix)==shell_commands.end()) cout<<suffix<<": not found" << endl;
                else{
                    vector<string> paths = path_dealer();
                    cout<<program_existence(paths, suffix);
                }

            }

        }

        else{
            cout<<command<<": command not found" << endl;
        }
    }

    return 0;
}