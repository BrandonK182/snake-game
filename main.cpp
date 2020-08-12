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
  
  /*************************
  * while loop to keep game running if player 
  * chooses to continue after winning/losing
  *****************************/
  while(endGame==false)
  {
    // displays content about the player and the world around them
    cout<<aPlayer;
    
    // CHECKS losing conditions
    if(aPlayer.lose())
    {
      cout<<"GAME OVER!!!"<<endl;
      cout<<"play again? (y) (n)"<<endl;
      
      // let's players restart the game
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
    
    // if the player has not lost the game yet
    else
    {
      //player changes directions using WASD keys
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
      
      // CHECKS if player has reached goal after movement
      if(aPlayer.overGoal())
      {
        apples++;
        aPlayer.changeGoal();
      }
      
      // CHECKS if player has reached maximum capacity
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
