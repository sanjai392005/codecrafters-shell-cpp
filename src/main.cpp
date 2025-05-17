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
        if(command=="exit 0") return 0;
        cout<<command<<": command not found" << endl;
    }

}