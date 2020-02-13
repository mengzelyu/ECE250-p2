#include <iostream>
#include "chain.h"
#include <string>
#include <sstream>
int main(){
	long long size;
	std::string command;
	long long key;
	std::string caller;
	std::cin>>command;
	std::cin>>size;
	hash chain{size};
	long long index;
	std::string input;
	int pos;
	while(std::cin >> command){
		if(command=="i"){
			getline(std::cin,input);
			pos=input.find(";");
			caller=input.substr(pos+1);
			input=input.substr(0,pos-1);
			std::stringstream sin{input};
			sin>>key;
			try{
				chain.insert(key,caller);
			}
			catch(std::string error){
				std::cerr << error;
			}
		}else if(command=="s"){
			std::cin >> key;
			try{
				std::cout << chain.search(key);
			}
			catch(std::string error){
				std::cerr << error;
			}
		}else if(command=="d"){
			std::cin >> key;
			try{
				chain.delete_key(key);
			}
			catch(std::string error){
				std::cerr << error;
			}
		}else if(command=="p"){
			std::cin >> index;
			chain.print(index);
		}
	}
	return 0;
}
