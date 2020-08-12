#include "map.h"
#include <iostream>

using namespace std;

map::map()
{
  for(int row = 0; row<totalRows; row++)
  {
    for(int col = 0; col<totalCols; col++)
    {
      area[row][col] = " ";
    }
  }
  constructBoundaries();
}

void map::constructBoundaries()
{
  int row = 0;
  int col = 0;

  for(col = 0; col<totalCols; col++)
  {
    area[row][col] = "\u25A0";
  }

  row = totalRows - 1;
  for(col = 0; col<totalCols; col++)
  {
    area[row][col] = "\u25A0";
  }

  col = 0;
  for(row = 1; row<totalRows-1; row++)
  {
    area[row][col] = "\u25A0";
  }

  col = totalCols - 1;
  for(row = 1; row<totalRows-1; row++)
  {
    area[row][col] = "\u25A0";
  }
}

void map::displayMap()
{
  for(int row = 0; row<totalRows; row++)
  {
    for(int col = 0; col<totalCols; col++)
    {
      cout<<area[row][col];
    }
    cout<<endl;
  }
}

string** map::getMap()
{
    string** temp;
    temp = new string*[totalRows];

    for (int i = 0; i < totalCols; i++)
    {
          temp[i] = new string[totalCols];
    }
    for(int i = 0; i< totalRows; i++)
    {
      for(int j = 0; j<totalCols; j++)
      {
        temp[i][j] = area[i][j];
      }
    }
 return temp;
}
