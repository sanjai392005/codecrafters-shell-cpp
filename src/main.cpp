#include <iostream>
using namespace std;

int main(){
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;
    std::cout << "$ ";

    string input;
    cin>>input;
    cout<<input << ": command not found" << endl;
    cout<<"$ exit 0";
    main();
}