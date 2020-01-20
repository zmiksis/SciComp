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
  std::cout << "You have " << num_pennies << ((num_pennies > 1)?" pennies\n":" penny\n");
  std::cout << "You have " << num_nickels << ((num_nickels > 1)?" nickels\n":" nickel\n");
  std::cout << "You have " << num_dimes << ((num_dimes > 1)?" dimes\n":" dime\n");
  std::cout << "You have " << num_quarters << ((num_quarters > 1)?" quarters\n":" quarter\n");
  std::cout << "You have " << num_fifties << ((num_fifties > 1)?" half dollars\n":" half dollar\n");
  std::cout << "You have " << num_dollars << ((num_dollars > 1)?" dollar coins\n":" dollar coin\n");
  
  total = num_pennies + (5*num_nickels) + (10*num_dimes) + (25*num_quarters) + (50*num_fifties) + (100*num_dollars);
  std::cout << std::endl;

  std::cout << "The value of all your coins is $" << total/100 << "." << total%100 << std::endl;
  return 0;
}