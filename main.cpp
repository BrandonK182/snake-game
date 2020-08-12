#include <iostream>
#include "player.h"
#include "map.h"

using namespace std;

const int NUM_SECONDS = 1;

int main()
{
  char choice;
  bool endGame = false;
  int numMoves = 0;
  int apples = 0;
  player aPlayer;
  while(endGame==false)
  {
    cout<<aPlayer;
    if(aPlayer.lose())
    {
      cout<<"GAME OVER!!!"<<endl;
      cout<<"play again? (y) (n)"<<endl;
      cin>>choice;
      switch(choice)
      {
        case 'y':
          endGame = false;
          aPlayer.reset();
          break;
        case 'n':
          endGame = true;
          break;
        default:
          cout<<"invalid entry"<<endl;
      }
    }
    else
    {
      cin>>choice;
      switch(choice)
      {
        case 'w' :
          aPlayer.movePlayerUp();
          break;
        case 'a' :
          aPlayer.movePlayerLeft();
          break;
        case 'd' :
          aPlayer.movePlayerRight();
          break;
        case 's' :
          aPlayer.movePlayerDown();
          break;
        default :
          cout<<"invalid move"<<endl;
          break;
      }
      if(aPlayer.overGoal())
      {
        apples++;
        aPlayer.changeGoal();
      }
      if(apples==aPlayer.getCapacity())
      {
        cout<<"you win. play again? (y) (n)"<<endl;
        cin>>choice;
        switch(choice)
        {
          case 'y':
            endGame = false;
            aPlayer.reset();
            break;
          case 'n':
            endGame = true;
            break;
          default:
            cout<<"invalid entry"<<endl;
        }
      }
    }
    

  }
  
}