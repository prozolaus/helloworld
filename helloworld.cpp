#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
  srand(static_cast<unsigned int>(time(0)));
  cout << "Rock Paper Scissors - game\n\n";
  int choise_comp, choise_player, count_comp = 0, count_player = 0, ties = 0;
  int count_player_temp = 0, count_comp_temp = 0;
  vector<string> words = {"rock", "paper", "scissors"};
  while (true)
  {
    choise_comp = rand() % 3 + 1;
    cout << "Make your choise (1 - Rock, 2 - Paper, 3 - Scissors, 4 - Statistics, 5 - Exit): ";
    cin >> choise_player;
    if (choise_player == 5)
      break;
    if (choise_player == 4)
    {
      cout << "Number of your wins: " << count_player << endl;
      cout << "Number of computer wins: " << count_comp << endl;
      cout << "Number of ties: " << ties << endl;
    }
    else if (choise_player != choise_comp)
    {
      if (choise_player == 1)
      {
        if (choise_comp == 2)
          count_comp++;
        else if (choise_comp == 3)
          count_player++;
      }
      else if (choise_player == 2)
      {
        if (choise_comp == 1)
          count_player++;
        else if (choise_comp == 3)
          count_comp++;
      }
      else if (choise_player == 3)
      {
        if (choise_comp == 1)
          count_comp++;
        else if (choise_comp == 2)
          count_player++;
      }
      cout << "Choise of computer is " << words[choise_comp - 1] << endl;
      if (count_comp > count_comp_temp)
        cout << "You lost this round!\n";
      else if (count_player > count_player_temp)
        cout << "You win this round!\n";
      count_player_temp = count_player;
      count_comp_temp = count_comp;
    }
    else
    {
      cout << "Tie!\n\n";
      ties++;
      continue;
    }
    cout << endl;
  }
}