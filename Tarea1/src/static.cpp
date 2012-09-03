#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

static int str2int (const string &str) {
  stringstream ss(str);
  int num;
  ss >> num;
  return num;
}
