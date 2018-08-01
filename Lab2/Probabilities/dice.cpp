#include <iostream>
#include <limits.h>
extern "C"{
  #include <stdlib.h>
  #include <time.h>
}

using namespace std;

int pRNG(int max, int min){
    int num = min + rand() / (RAND_MAX / (max - min + 1) + 1);
    return num;
}

void rollDice(int rollNumber){
  int rollArr[6] = {0, 0, 0, 0, 0, 0};
  int roll = 0;
  for(int x = 0; x < rollNumber; x++){
      roll = pRNG(6, 1);
      switch (roll) {
        case 1: rollArr[0]++; break;
        case 2: rollArr[1]++; break;
        case 3: rollArr[2]++; break;
        case 4: rollArr[3]++; break;
        case 5: rollArr[4]++; break;
        case 6: rollArr[5]++; break;
      }
  }
  cout << "--------------------------------------------------------" << endl;
  cout << "1: (a floating point number between 0 and 1) " << (float) rollArr[0]/rollNumber  << endl;
  cout << "2: (a floating point number between 0 and 1) " << (float) rollArr[1]/rollNumber << endl;
  cout << "3: (a floating point number between 0 and 1) " << (float) rollArr[2]/rollNumber << endl;
  cout << "4: (a floating point number between 0 and 1) " << (float) rollArr[3]/rollNumber << endl;
  cout << "5: (a floating point number between 0 and 1) " << (float) rollArr[4]/rollNumber << endl;
  cout << "6: (a floating point number between 0 and 1) " << (float) rollArr[5]/rollNumber << endl;
  cout << "--------------------------------------------------------" << endl;
}

void rollDiceHighLow(int rollNumber){
  int roll = 0;
  int high = 0;
  int low = 0;
  int same = 0;
  for(int x = 0; x < rollNumber; x++){
    for(int y = 0; y < 100; y++){
      roll = pRNG(6, 1);
      if(roll <=3){
        low++;
      }
      else if(roll >= 4){
        high++;
      }
    }
      if(high == low){
        same++;
      }
      high = 0;
      low = 0;
  }

  cout << "--------------------------------------------------------" << endl;
  cout << "Number of times high is equal to low: " << (float) same/(float) rollNumber << endl;
  cout << "--------------------------------------------------------" << endl;
}

void rollTwoDice(int rollNumber){
  int rollArr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int rollDieOne = 0;
  int rollDieTwo = 0;
  int rollTotal = 0;
  for(int x = 0; x < rollNumber; x++){
      rollDieOne = pRNG(6, 1);
      rollDieTwo = pRNG(6, 1);
      rollTotal = rollDieOne + rollDieTwo;
      switch (rollTotal) {
        case 2: rollArr[0]++; break;
        case 3: rollArr[1]++; break;
        case 4: rollArr[2]++; break;
        case 5: rollArr[3]++; break;
        case 6: rollArr[4]++; break;
        case 7: rollArr[5]++; break;
        case 8: rollArr[6]++; break;
        case 9: rollArr[7]++; break;
        case 10: rollArr[8]++; break;
        case 11: rollArr[9]++; break;
        case 12: rollArr[10]++; break;
      }
  }
  cout << "--------------------------------------------------------" << endl;
  cout << "2: (a floating point number between 0 and 1) " << (float) rollArr[0]/rollNumber  << endl;
  cout << "3: (a floating point number between 0 and 1) " << (float) rollArr[1]/rollNumber << endl;
  cout << "4: (a floating point number between 0 and 1) " << (float) rollArr[2]/rollNumber << endl;
  cout << "5: (a floating point number between 0 and 1) " << (float) rollArr[3]/rollNumber << endl;
  cout << "6: (a floating point number between 0 and 1) " << (float) rollArr[4]/rollNumber << endl;
  cout << "7: (a floating point number between 0 and 1) " << (float) rollArr[5]/rollNumber << endl;
  cout << "8: (a floating point number between 0 and 1) " << (float) rollArr[6]/rollNumber << endl;
  cout << "9: (a floating point number between 0 and 1) " << (float) rollArr[7]/rollNumber << endl;
  cout << "10: (a floating point number between 0 and 1) " << (float) rollArr[8]/rollNumber << endl;
  cout << "11: (a floating point number between 0 and 1) " << (float) rollArr[9]/rollNumber << endl;
  cout << "12: (a floating point number between 0 and 1) " << (float) rollArr[10]/rollNumber << endl;
  cout << "--------------------------------------------------------" << endl;
}

int main(){
  srand(time (NULL));

  //Question 1
  cout << "------------------------Question 1----------------------" << endl;
  cout << "Roll 10 Times" << endl;
  rollDice(10);
  cout << "Roll 1000 Times" << endl;
  rollDice(1000);
  cout << "Roll 100000 Times" << endl;
  rollDice(100000);
  cout << endl;

  //Question 2
  cout << "------------------------Question 2----------------------" << endl;
  cout << "Roll 100 Times, Repeat experiment 10000 Times" << endl;
  rollDiceHighLow(10000);
  cout << endl;

  //Question 3
  cout << "------------------------Question 3----------------------" << endl;
  cout << "Roll 2 Dice 10000 Times" << endl;
  rollTwoDice(10000);
  cout << endl;
}
