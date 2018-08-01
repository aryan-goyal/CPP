#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <random>
extern "C"{
  #include <stdlib.h>
}

using namespace std;

int pRNG(int max, int min){
    int num = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    return num;
}

class Deck{
  public:
    vector <int> deck;

    int remainingCards(){
      return deck.size();
    }

    int deal(){
      int size = deck.size();
      int lastElement = size-1;
      int x = deck[lastElement];
      deck.erase(deck.begin()+lastElement);
      return x;
    }

    void shuffle(){
      deck = {1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5,
        6, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 9, 10, 10, 10, 10,
        10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
      random_shuffle(deck.begin(), deck.end());
    }
};

int main(){
  Deck deckOne;
  deckOne.shuffle();

  //Question 4
  cout << "------------------------Question 4----------------------" << endl;
  float threshArray[11] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int threshCounter = 0;
  for(int thresh = 10; thresh <= 20; thresh++){
    for(int x = 0; x <10000; x++){
      int currentSum = 0;
      int numaces = 0;
      while(currentSum < thresh){
        if(deckOne.remainingCards() == 0){
          deckOne.shuffle();
        }
        else{
          int next = deckOne.deal();
          if(next == 1){
            numaces += 1;
            next = 11;
          }
          currentSum += next;
          if (currentSum > 21 && numaces > 0) {
            currentSum -= 10;
            numaces -= 1;
          }
        }
      }
      if(currentSum > 21){
        threshArray[threshCounter]++;
      }
    }
    threshCounter++;
  }

  for(int x = 0; x < 11; x++){
    cout << "For a threshold of " << x + 10 << ", the probability of busting is: "
    << (float) (threshArray[x]/10000) << endl;
  }
  cout << endl;

  //Question 5
  cout << "------------------------Question 5----------------------" << endl;
  Deck deckTwo;
  deckTwo.shuffle();

  float correct = 0;

  for(int repeat = 0; repeat < 10000; repeat++){
    int count = 0;
    int wager = 0;
    int dealerSum = 0;
    int playerSum = 0;
    int numacesDealer = 0;
    int numacesPlayer = 0;
    int next = 0;

    if(deckTwo.remainingCards() == 0){
      deckTwo.shuffle();
      count = 0;
    }

    //deal to dealer
    next = deckTwo.deal();
    if(next == 1){
      count -= 1;
      numacesDealer += 1;
      next = 11;
      dealerSum += next;
    }
    else if(next == 10){
      count -= 1;
      dealerSum += next;
    }
    else if(next == 2 || next == 3 || next == 4 || next == 5 || next == 6){
      count += 1;
      dealerSum += next;
    }
    else if(next == 7 || next == 8 || next == 9){
      dealerSum += next;
    }

    //deal to imaginary players
    for(int x = 0; x < 6; x++){
      if(deckTwo.remainingCards() == 0){
        deckTwo.shuffle();
        count = 0;
      }
      next = deckTwo.deal();
      if(next == 1 || next == 10){
        count -= 1;
      }
      else if(next == 2 || next == 3 || next == 4 || next == 5 || next == 6){
        count += 1;
      }
    }

    //deal to main player
    while(playerSum < 19){
      if(count>0){
        wager = 1;
      } else if(count = 0){
        wager = 0;
      } else if(count < 0){
        wager = -1;
      }
      if(deckTwo.remainingCards() == 0){
        deckTwo.shuffle();
        count = 0;
      }
      next = deckTwo.deal();
      if(next == 1){
        count -= 1;
        numacesPlayer += 1;
        next = 11;
        playerSum += next;
      }
      else if(next == 2 || next == 3 || next == 4 || next == 5 || next == 6){
        count += 1;
        playerSum += next;
      }
      else{
        playerSum += next;
      }
      if (playerSum > 21 && numacesPlayer > 0) {
        playerSum -= 10;
        numacesPlayer -= 1;
      }
    }

    //deal again to dealer
    while(dealerSum <= 16){
      if(deckTwo.remainingCards() == 0){
        deckTwo.shuffle();
        count = 0;
      }
      next = deckTwo.deal();
      if(next == 1){
        numacesDealer += 1;
        next = 11;
      }
      dealerSum += next;
      if (dealerSum > 21 && numacesDealer > 0) {
        dealerSum -= 10;
        numacesDealer -= 1;
      }
    }

    //determine win
    bool playerWin;
    if((dealerSum > 21) || (playerSum == 21) || ((playerSum > dealerSum) && playerSum < 22 && dealerSum < 22)){
      playerWin = true;
    }
    else if((playerSum > 21) || ((dealerSum > playerSum) && (dealerSum <22))){
      playerWin = false;
    }

    if(((wager>=0) && playerWin) || ((wager<0) && (playerWin == false))){
      correct += 1;
    }
  }

  cout << "Fraction of correct bets: " << (float) (correct/10000) << endl;
  cout << endl;

  return 0;
}
