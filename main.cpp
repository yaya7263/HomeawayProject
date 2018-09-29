/*
The following blockchain is built with help from
https://davenash.com/2017/10/build-a-blockchain-with-c/
https://medium.com/programmers-blockchain/create-simple-blockchain-java-tutorial-from-scratch-6eeed3cb03fa
*/

#include "Blockchain.h"

int main() {
	Blockchain newBlockChain; 
	std::vector<std::string> data; 
	data.push_back("Hi this is first block");
	Block genesisBlock(data);
	newBlockChain.AddBlock(genesisBlock); 
	
	std::vector<std::string> data2;
	data2.push_back("Hi this is second block");
	Block block2(data2, newBlockChain.getCurrentBlock().getHash());
	newBlockChain.AddBlock(block2);

	std::vector<std::string> data3;
	data3.push_back("Hi this is third block");
	Block block3(data3, newBlockChain.getCurrentBlock().getHash());
	newBlockChain.AddBlock(block3);

	std::cout << newBlockChain; 
	std::cin.get(); 

}