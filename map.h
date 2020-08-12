#include <string>

#ifndef MAP_H
#define MAP_H

using namespace std;

class map
{
  public:
  map();
  void displayMap();
  string** getMap();
  const static int totalRows = 10; //Rows iin the matrix
  const static int totalCols = 10; //Columns in the matrix

  private:
  void constructBoundaries();
  string area[totalRows][totalCols];
};

#endif 