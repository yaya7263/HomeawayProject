#include "Blockchain.h"

std::ostream& operator<<(std::ostream& stream, Blockchain thisBlockchain) {
	for (int i = 0; i < thisBlockchain.thisBlockchain_.size(); i++)
		stream << thisBlockchain.thisBlockchain_[i] << std::endl;
	return stream;
}

Blockchain::Blockchain()
{
}

Blockchain::~Blockchain()
{
}

void Blockchain::AddBlock(Block newBlock) {
	thisBlockchain_.push_back(newBlock);
	if (!isChainValid()) {
		std::cout << "Cannot add new block" << std::endl;
	}
}

Block Blockchain::getCurrentBlock() {
	return thisBlockchain_.front(); 
}

bool Blockchain::isChainValid() {
	for (int i = 0; i < thisBlockchain_.size(); i++) {

		Block currentBlock = thisBlockchain_[i];

		if (!(currentBlock.getHash() == currentBlock.calculateHash())) {
			std::cout << "Current Hashes not equal" << std::endl;
			return false;
		}

		if (i == 0) break;
		else {
			Block previousBlock = thisBlockchain_[i - 1];
			if (!(previousBlock.getHash() == currentBlock.getPreviousHash())) {
				std::cout << "Previous Hashes not equal" << std::endl; 
				return false;
			}
		}
	}
	return true;
}




