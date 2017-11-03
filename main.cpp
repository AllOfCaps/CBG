#include <iostream>
#include <string>
#include #FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame;

int main()
{
  bool bPlayAgain = false;
  do{
      PrintIntro();
      PlayGame();
      bPlayAgain = AskToPlayAgain();
  }
  while (bPlayAgain);
  
  return 0;
}


void PrintIntro()
{
  constexpr int WORD_LENGTH = 9;
  std::cout << "Welcome to blah blah\n";
  std::cout << "It's got " << WORD_LENGTH;
  std::cout << " Letters in it so good luck\n";
  std::cout << std::endl;
  
  return;
}

void PlayGame()
{
  BCGame.Reset();
  int MaxTries = BCGame.GetMaxTries();
  
  for (int i = 1; i <= MaxTries; i++) {
    std::string Guess = GetGuess();
    std::cout << "You guessed " << Guess << std::endl;
    std::cout << std::endl;
  }
}

std::string GetGuess()
{
  int CurrentTry = BCGame.GetCurrentTry();
  std::string Guess = "";
  
  std::cout << "Try " << CurrentTry << ". Enter your guess: ";
  std::getline(std::cin, Guess);
  return Guess;
}

bool AskToPlayAgain()
{
  std::string Response = "";
  std::cout << "Do you want to play again (y/n)? ";
  std::getline(std::cin, Response);
  return (Response[0] == 'y') || (Response[0] == 'Y');
}
