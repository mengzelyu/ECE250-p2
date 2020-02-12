#include <iostream>
#include "chain.cpp"
#include <string>
int main(){
	long long size;
	std::string command;
	long long key;
	std::string caller;
	hash chain;
	while(std::cin >> command){
		if(command=="n"){
			std::cin >> size;
			chain.hash(size);
			std::cout << "success" << std::endl;
		}else if(command=="i"){
			std::cin >> key;
			std::cin >> caller;
			try{
				std::cout << chain.insert(key,caller);
			}
			catch(std::string error){
				std::cerr << error;
			}
		}else if(command=="s"){
			std::cin >> key;
			try{
				chain.search(key);
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
			chain.print();
		}
	}
	return 0;
}
