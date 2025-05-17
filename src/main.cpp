#include <iostream>
#include <string>
using namespace std;

int main(){
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    while(true){
        string command;
        cout<<"$ ";
        getline(cin, command);

        if(command=="exit 0" || command=="exit"){
            return 0;
        }else if(command.substr(0, 4)=="echo"){
            if(command.size()==4) continue;
            else cout<<command.substr(5, command.size())<<endl;
        }else if(command.substr(0, 4)=="type"){
            if(command.size()==4){ continue; }
            else cout<<command.substr(5, command.size())<<" is a shell builtin"<<endl;
        }
        
        else{
            cout<<command<<": command not found" << endl;
        }
    }

}