/*
     this is max a visual assistant
      _ __ ___   __ ___  __
     | '_ ` _ \ / _` \ \/ /
     | | | | | | (_| |>  < 
     |_| |_| |_|\__,_/_/\_\
     designed to help the people that need its help.
*/

#include <iostream>
#include <stdlib.h>
#include <string>

int main(){
    std::string request;
    std::string cmdTypes[2] = {"!cmd", "!s"};
    std::string endCmd;
    
    system("clear");
    
    while(true){
	    std::getline(std::cin, request);
    
        if(request.find(cmdTypes[0]) != std::string::npos){                                                     // if [command]
            endCmd = request.substr(5, request.length() - 5);
            std::cout << "\033[1;33m==================== " << endCmd << " ====================\033[0m\n";
	    
            system((" " + endCmd).c_str());
            
            std::cout << "\033[1;33m========================================\033[0m";
            for(int i=0; i<=endCmd.length() + 2; i++){
                if(i < endCmd.length() + 1) std::cout << "\033[1;33m=\033[0m";
                if(i == endCmd.length() + 2) std::cout << "\033[1;33m=\033[0m\n";
            }
        }
   
        if(request.find(cmdTypes[1]) != std::string::npos){                                                     // if [search]
	        endCmd = request.substr(3, request.length() - 3);	
            std::cout << "\033[1;33m==================== " << endCmd << " ====================\033[0m\n";
	       	
            system(("lynx https://en.wikipedia.org/wiki/" + endCmd).c_str());
            
            std::cout << "\033[1;33m========================================\033[0m";
            for(int i=0; i<=endCmd.length() + 2; i++){
                if(i < endCmd.length() + 1) std::cout << "\033[1;33m=\033[0m";
                if(i == endCmd.length() + 2) std::cout << "\033[1;33m=\033[0m\n";
            }
        }
	
        if(request.find(cmdTypes[0]) != std::string::npos && request.find(cmdTypes[1]) != std::string::npos){   // error handling
            std::cerr << "ERROR: you can not use 2 commands at the same time\n";
        }

    }
}