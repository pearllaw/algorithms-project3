#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cmath>
#include <algorithm>
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
  unsigned int balance[8];
  balance[0] = 0;

  unsigned int min_loc, max_loc, min_val;

  for (unsigned int i = 1; i < 8; ++i) {
    unsigned int bucket_vals[10];
	  //created a case for each of the 7 checks
    for (unsigned int j = 0; j < 10; ++j) {
      switch (i) {
        case 1:
          bucket_vals[j] = hT1.bucket_size(j);
          break;

        case 2:
          bucket_vals[j] = hT2.bucket_size(j);
          break;

        case 3:
          bucket_vals[j] = hT3.bucket_size(j);
          break;

        case 4:
          bucket_vals[j] = hT4.bucket_size(j);
          break;

        case 5:
          bucket_vals[j] = hT5.bucket_size(j);
          break;

        case 6:
          bucket_vals[j] = hT6.bucket_size(j);
          break;

        case 7:
          bucket_vals[j] = hT7.bucket_size(j);
          break;

        default:
          break;
      }
    }

    min_loc = *std::min_element(bucket_vals, bucket_vals + 10);
    max_loc = *std::max_element(bucket_vals, bucket_vals + 10);

    balance[i] = max_loc - min_loc;
  }

  min_val = balance[1];
  
  for (size_t i = 2; i < 8; i++) {
    if (min_val > balance[i]) {
      min_val = balance[i];
      min_loc = i;
    }
  }

  return min_loc;
}

// ALREADY COMPLETED
size_t ItemCollection::size() {
    if ((hT1.size() != hT2.size()) || (hT1.size() != hT3.size()) || (hT1.size() != hT4.size()) || (hT1.size() != hT5.size())|| (hT1.size() != hT6.size()) || (hT1.size() != hT7.size()))
  	throw std::length_error("Hash table sizes are not the same");
    
	return hT1.size();
}
