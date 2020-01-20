// Third program
#include <iostream>

int main()
{
  int num_pennies, num_nickels, num_dimes, num_quarters, num_fifties, num_dollars, total;
  std::cout << "Let's find the total value of all your coins! \n" << std::endl;
  std::cout << "How many pennies (1-cent coins) do you have? \n";
  std::cin >> num_pennies;
  std::cout << "How many nickels (5-cent coins) do you have? \n";
  std::cin >> num_nickels;
  std::cout << "How many dimes (10-cent coins) do you have? \n";
  std::cin >> num_dimes;
  std::cout << "How many quarters (25-cent coins) do you have? \n";
  std::cin >> num_quarters;
  std::cout << "How many half-dollar coins do you have? \n";
  std::cin >> num_fifties;
  std::cout << "How many one-dollar coins do you have? \n";
  std::cin >> num_dollars;  
  std::cout << std::endl;
  std::cout << "You have " << num_pennies << " pennies\n";
  std::cout << "You have " << num_nickels << " nickels\n";
  std::cout << "You have " << num_dimes << " dimes\n";
  std::cout << "You have " << num_quarters << " quarters\n";
  std::cout << "You have " << num_fifties << " half dollars\n";
  std::cout << "You have " << num_dollars << " dollar coins\n";  
  std::cout << std::endl;
  total = num_pennies + (5*num_nickels) + (10*num_dimes) + (25*num_quarters) + (50*num_fifties) + (100 * num_dollars);
  std::cout << "The value of all your coins is " << total << " cents." << std::endl;
  return 0;
}