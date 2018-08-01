#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class user{ //main class of a user used to store everything about a person and their relations
  public:
    int userNum;
    vector <int> content;
    vector <int> friends;
    vector <int> likes;
};

//get all subsets of the users
vector <vector <user>> getAllSubsets(vector <user> set)
{
    vector <vector <user>> subset;
    vector <user> empty;
    subset.push_back(empty);

    for(int i = 0; i < set.size(); i++)
    {
        vector <vector<user>> subsetTemp = subset;

        for (int j = 0; j < subsetTemp.size(); j++)
            subsetTemp[j].push_back( set[i] );

        for (int j = 0; j < subsetTemp.size(); j++)
            subset.push_back( subsetTemp[j] );
    }
    return subset;
}

int main(){
  string inputLine;
  int firstNum;
  int secondNum;

  int noOfUsers = 0;
  int noOfContent = 0;

  char letter = '0';

  vector <user> users;

  while(getline(cin, inputLine)){
    if(inputLine == "#U"){
      getline(cin, inputLine);
      noOfUsers = stoi(inputLine);
      for(int x = 1; x <=noOfUsers; x++){
        user emptyUser;
        emptyUser.userNum = x;
        users.push_back(emptyUser);
      }
    }
    if(inputLine == "#C"){ //get the content number
      getline(cin, inputLine);
      noOfContent = stoi(inputLine);
    }
    if(inputLine == "#F"){
      //add friends to each other
      while((inputLine != "#W")){
        getline(cin, inputLine);
        if(inputLine == "#W"){
          break;
        }
        stringstream stream(inputLine);
        stream >> firstNum;
        stream >> secondNum;
        users[(firstNum-1)].friends.push_back(secondNum);
        users[(secondNum-1)].friends.push_back(firstNum);
        }
      }
      if(inputLine == "#W"){ //piece of content that is owned is added
        while((inputLine != "#L")){
          getline(cin, inputLine);
          if(inputLine == "#L"){
            break;
          }
          stringstream stream(inputLine);
          stream >> firstNum;
          stream >> secondNum;
          users[(firstNum-1)].content.push_back(secondNum);
          }
      }
      if(inputLine == "#L"){ //a person likes something
        while(getline(cin, inputLine)){
          stringstream stream(inputLine);
          stream >> firstNum;
          stream >> secondNum;
          users[(firstNum-1)].likes.push_back(secondNum);
        }
      }
    }

    //make each user friends with themselves
    for(int x = 0; x < noOfUsers; x++){
      if(!count(users[x].friends.begin(), users[x].friends.end(), (x+1))){
          users[x].friends.push_back(users[x].userNum);
      }
    }

    //if you are friends with someone, you like everything they own
    for(int x = 0; x < users.size(); x++){
      for(int y = 0; y < users[x].friends.size(); y++){
        for(int z = 0; z <= users[((users[x].friends[y])-1)].content.size(); z++){
          if(!count(users[x].likes.begin(), users[x].likes.end(), users[((users[x].friends[y])-1)].content[z])){
            users[x].likes.push_back(users[((users[x].friends[y])-1)].content[z]);
          }
        }
      }
    }

    //find the power sets of users
    vector <vector <user>> powerSetUsers;
    powerSetUsers = getAllSubsets(users);
    //remove first element since it is the empty set
    powerSetUsers.erase(powerSetUsers.begin());

    //find dissimilar sets of users and print them
    bool dis = true;

    for(int a = 0; a < powerSetUsers.size(); a++){ //yeet
      for(int b = 0; b < powerSetUsers.size(); b++){
        for(int c = 0; c < powerSetUsers[a].size(); c++){
          for(int d = 0; d < powerSetUsers[b].size(); d++){
            for(int e = 0; e < powerSetUsers[b][d].likes.size(); e++){
              if(count(powerSetUsers[a][c].content.begin(), powerSetUsers[a][c].content.end(), powerSetUsers[b][d].likes[e])){
                dis = false;
              }
            }
          }
        }
        if(dis == true){ //print out this fucking shit
          cout << "{";
          for(int y = 0; y <powerSetUsers[b].size(); y++){
              cout << powerSetUsers[b][y].userNum;
              if((y+1) >= powerSetUsers[b].size())
                cout <<"";
              else
                cout << ",";
          }
          cout << "} ";
          cout << "{";
          for(int y = 0; y <powerSetUsers[a].size(); y++){
              cout << powerSetUsers[a][y].userNum;
              if((y+1) >= powerSetUsers[a].size())
                cout <<"";
              else
                cout << ",";
          }
          cout << "} " << endl;
        }
        dis = true;
      }
    }
    return 0;
}
