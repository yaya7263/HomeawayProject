#include "Block.h"
#include "sha256.h"
#include <sstream>
#include <time.h>

std::ostream& operator<<(std::ostream& stream, const std::vector<std::string> data) {
	std::string concatenatedString = std::accumulate(data.begin(), data.end(), std::string(""));
	stream << concatenatedString;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Block currentBlock) {
	stream << currentBlock.data_;
	return stream;
}

Block::Block(std::vector<std::string> data)	// constructor for genesis block
{
	previousHash_ = "0"; 
	data_ = data;
	timeStamp_ = time(nullptr);
	hash_ = calculateHash();
}

Block::Block(std::vector<std::string> data, std::string previousHash)
{
	data_ = data; 
	this->previousHash_ = previousHash; 
	timeStamp_ = time(nullptr); 
	hash_ = calculateHash(); 
}


Block::~Block()
{
}


std::string Block::calculateHash() {
	std::stringstream ss;
	ss << previousHash_ << timeStamp_ << data_;
	return sha256(ss.str());
}