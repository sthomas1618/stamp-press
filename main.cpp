// Stephen Thomas
// Project 3
// CSCI 511

#include <iostream>
#include "stampstream.h"
#include "row.cpp"
using namespace std;

int main()
{
  stampstream s(30,10);
  s << "hi th#re planetoid humans" << endrow
  << " how's all the fish" << row(5) << "one more";
  s << row(4) << " two more" << 3.1415;

  return 0; 
}