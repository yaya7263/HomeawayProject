#pragma once
#include <cstdint>
#include <iostream>
#include <vector>
#include <numeric> 
#include <string>


class Block
{
public:
	Block(std::vector<std::string> data);
	Block(std::vector<std::string> data, std::string previousHash);
	~Block(); 

	std::string calculateHash(); 
	std::string getHash() { return hash_; }
	std::string getPreviousHash() { return previousHash_; }

	
	friend std::ostream& operator<<(std::ostream& stream, Block currentBlock);
	

private:
	std::string hash_;
	std::string previousHash_;
	std::vector<std::string> data_;
	long timeStamp_; 
};

