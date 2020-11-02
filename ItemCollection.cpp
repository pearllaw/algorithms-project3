#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include "ItemCollection.hpp"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

// function to return the hash value based on the first digit
unsigned int hashfct1(unsigned int barcode) {
  int pos = 7;
  int digit = (barcode / (int)pow(10, pos - 1)) % 10;
  return digit;
}

// function to return the hash value based on the second digit
unsigned int hashfct2(unsigned int barcode) {
  int pos = 6;
  int digit = (barcode / (int)pow(10, pos - 1)) % 10;
  return digit;
}

// function to return the hash value based on the third digit
unsigned int hashfct3(unsigned int barcode) {
  int pos = 5;
  int digit = (barcode / (int)pow(10, pos - 1)) % 10;
  return digit;
}

// function to return the hash value based on the fourth digit
unsigned int hashfct4(unsigned int barcode) {
  int pos = 4;
  int digit = (barcode / (int)pow(10, pos - 1)) % 10;
  return digit;
}

// function to return the hash value based on the fifth digit
unsigned int hashfct5(unsigned int barcode) {
  int pos = 3;
  int digit = (barcode / (int)pow(10, pos - 1)) % 10;
  return digit;
}

// function to return the hash value based on the sixth digit
unsigned int hashfct6(unsigned int barcode) {
  int pos = 2;
  int digit = (barcode / (int)pow(10, pos - 1)) % 10;
  return digit;
}

// function to return the hash value based on the seventh digit
unsigned int hashfct7(unsigned int barcode) {
  int pos = 1;
  int digit = (barcode / (int)pow(10, pos - 1)) % 10;
  return digit;
}

// Constructor for struct Item
Item::Item(string itemColor, string itemShape, string itemBrand,
		 unsigned int barcode):itemColor_(itemColor),itemShape_(itemShape), itemBrand_(itemBrand),
				       barcode_(barcode)
{};

// Load information from a text file with the given filename
// THIS FUNCTION IS COMPLETE
void ItemCollection::readTextfile(string filename) {
  ifstream myfile(filename);

  if (myfile.is_open()) {
    cout << "Successfully opened file " << filename << endl;
    string itemColor;
    string itemShape;
    string itemBrand;
    unsigned int barcode;
    while (myfile >> itemColor >> itemShape >> itemBrand >> barcode) {
			if (itemColor.size() > 0)
      	addItem(itemColor, itemShape, itemBrand, barcode);
    }
    myfile.close();
  }
  else
    throw std::invalid_argument("Could not open file " + filename);
}

void ItemCollection::addItem(string itemColor, string itemShape, string itemBrand, unsigned int barcode) {
  // create item object
  Item item{itemColor, itemShape, itemBrand, barcode};
  
  // insert item into table
  int key = item.barcode_;
  hT1.insert({key, item});
  hT2.insert({key, item});
  hT3.insert({key, item});
  hT4.insert({key, item});
  hT5.insert({key, item});
  hT6.insert({key, item});
  hT7.insert({key, item});
}

bool ItemCollection::removeItem(unsigned int barcode) {
  // if product key is in hash table, remove item and return true; otherwise return false 
  if (hT1.find(barcode) != hT1.end() || hT2.find(barcode) != hT2.end() || 
    hT3.find(barcode) != hT3.end() || hT4.find(barcode) != hT4.end() || 
    hT5.find(barcode) != hT5.end() || hT6.find(barcode) != hT6.end() || 
    hT7.find(barcode) != hT7.end())
  {
    hT1.erase(barcode);
    hT2.erase(barcode);
    hT3.erase(barcode);
    hT4.erase(barcode);
    hT5.erase(barcode);
    hT6.erase(barcode);
    hT7.erase(barcode);
    return true;
  }
  return false;
}

unsigned int ItemCollection::bestHashing() {
  // TO BE COMPLETED
  // function that decides the best has function, i.e. the ones among
  // fct1-fct7 that creates the most balanced hash table for the current
  // ItemCollection data member allItems

	// Hints:
	// Calculate the balance of each hashtable, one by one.
	/*
	 for (unsigned i=0; i<10; ++i) {
    cout << hT1.bucket_size(i); // Call bucket_size() to get the size of each bucket
  }
	*/
	// Then, calculate the lowest balance

    unsigned int balance[8];
    balance[0] = 0;

    unsigned int min_loc, max_loc;
    
    return min_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
