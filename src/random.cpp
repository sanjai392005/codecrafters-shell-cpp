
// // ------------------ DEALING WITH OUTPUT OF 'PATH' ----------------------

// #include <iostream>
// #include <cstdlib>
// #include <vector>
// #include <string>
// #include <filesystem>

// namespace fs = std::filesystem;

// std::vector<std::string> path_dealer(){
//     std::vector<std::string> paths;
//     std::string env_path = std::getenv("PATH");

//     std::string seperate_path = "";

//     for(char i: env_path){
//         if(i!=':'){
//            seperate_path.push_back(i) ;
//         }
//         else{
//             paths.push_back(seperate_path);
//             seperate_path = "";
//         }
//     }
//     if(!seperate_path.empty()){
//         paths.push_back(seperate_path);
//     }

//     for(const std::string &i: paths){
//         std::cout<<i<<" ";
//     }

//     return paths;
// }


// // ------------- SEARCHING FOR EXISTENCE OF A PROGRAM IN A GIVEN PATH --------------------

// std::string program_existence(std::vector<std::string> paths, std::string target){
//     int isPresent = 0;

//     for(std::string i: paths){
//         fs::path current_path = i;

//         for(const auto &entry: fs::directory_iterator(current_path)){
//             if(entry.path().filename() == target){
//                 isPresent = 1;
//                 return target+" is "+(std::string)entry.path()+"\n";
//             }
//         }
//     }

//     if(isPresent==0){
//         return target+": not found"+"\n";
//     }
// }

// int main(){
//     std::vector<std::string> paths = path_dealer();
//     std::string target = "ls";
//     std::cout<<program_existence(paths, target); 
// }