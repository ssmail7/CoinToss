//**************************************************************
// Written by Steven Smail for COP3331
//
// cointoss.cpp (Project 1)
//
// This program simulates a coin toss and
// determines if it is realistic.
//**************************************************************

#include <iostream>
#include <cstdlib> //Contains prototypes for functions srand and rand
#include <ctime> //Needed for time functionusing namespace std;

//Function prototypes
int toss(void);
int realistic(int a, int b);

int main()
{
  //Seed random number generator with system clock
  srand(static_cast<unsigned int>(time(0)));

  int num, heads{0}, tails{0};

  //User input prompt for tosses
  cout << "Enter the number of times you want to toss the coin: ";
  cin >> num;

  while(num < 10)
  {
    cout << "The number of tosses must be greater than 10. Re-enter: ";
    cin >> num;
  }

  //Loop for tosses
  for(unsigned int counter{1}; counter <= num; counter++)
  {
    int i{toss()};

    if(i == 0)
    {
      cout << "Heads ";
      heads++;
    }
    else if(i == 1)
    {
      cout << "Tails ";
      tails++;
    }

    //Formatting 10 tosses per line
    if(counter % 10 == 0)
    {
      cout << endl;
    }
  }
  cout << endl;

  cout << "The total number of Heads was " << heads << endl;
  cout << "The total number of Tails was " << tails << endl;

  if(realistic(heads, num))
    cout << "This simulation was realistic." << endl;
  else
    cout << "This simulation was NOT realistic." << endl;
}

int toss(void)
{
  return (rand() % 2);
}

int realistic(int a, int b)
{
  double average{static_cast<double>(a) / b};

  if(average >= 0.45 && average <= 0.55)
    return 1;
  return 0;
}