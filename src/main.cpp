#include <iostream>
#include <cstdlib>
#include <string>
#include <set>
#include <vector>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

fs::path command_path;

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

std::string program_existence(std::vector<std::string> paths, std::string target){ //checks if the program exists
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


bool bool_program_existence(std::vector<std::string> paths, std::string target){
    for(std::string i: paths){
        fs::path current_path = i;

        for(const auto &entry: fs::directory_iterator(current_path)){
            if(entry.path().filename() == target){
                //command_path=entry.path(); 
                command_path = entry.path().filename();// as per the constraints taht was given in the problem, command should be executed as is and not using its full path

                return true;
            }
        }
    }

    return false;
}



std::vector<std::string> command_argument_seperator(std::string input){// seperates the command from the arguments and stores everything in a vector
    std::vector<std::string> result;
    std::string word = "";
    for(char i: input){
        if(i!=' '){
            word+=i;
        }
        else{
            result.push_back(word);
            word = "";
        }
    }
    if(word!=""){
        result.push_back(word);
    }

    return result;
}



int main(){
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    set<string> shell_commands = {"type", "echo", "exit"};

    while(true){
        string command;
        cout<<"$ ";
        getline(cin, command);

        std::vector<std::string> commands_arguments = command_argument_seperator(command);
        vector<string> paths = path_dealer();


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
                    cout<<program_existence(paths, suffix);
                }

            }

        }

        else if(bool_program_existence(paths, commands_arguments[0])){
            string final_command_path = command_path.string();
            std:string space = " ";

            for(int i=1; i<commands_arguments.size(); i++){
                final_command_path += space + commands_arguments[i];
            }
            std::system(final_command_path.c_str());
            //std::cout<<final_command_path<<"\n"; just for checking
        }
        

        else{
            cout<<command<<": command not found" << endl;
        }
    }

    return 0;
}