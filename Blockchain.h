#pragma once
#include "Block.h"

class Blockchain
{
public:
	Blockchain();
	~Blockchain();

	void AddBlock(Block newBlock);
	bool isChainValid(); 

	Block getCurrentBlock();

	friend std::ostream& operator<<(std::ostream& stream, Blockchain thisBlockchain);

private:
	std::vector<Block> thisBlockchain_;
	

};

