#include <iostream>
#include <random>

int main() {
  using std::cin;
  using std::cout;

  int smallest_number = 0;
  int largest_number = 0;
  int guessed_number = 0;
  int no_of_guess = 0;
  // bool not_guessed = true;
  std::random_device random_device;
  std::mt19937 random_engine{random_device()};

  cout << "Welcome to the GUESSING GAME!" << std::endl
       << "I will generate a number and you will guess it!" << std::endl;
  cout << "Please provide the smallest number:" << std::endl;
  cin >> smallest_number;
  cout << "Please provide the largest number:" << std::endl;
  cin >> largest_number;
  std::uniform_int_distribution distribution{smallest_number, largest_number};
  const int generated_number = distribution(random_engine);
  cout << "I've generated a number. Try to guess it!" << std::endl;

  while (true) {
    cout << "Please provide the next guess:" ;
    cin >> guessed_number;
    no_of_guess++;
    if (guessed_number < generated_number) {
      cout << "Your number is too small.\nTry again!" << std::endl;
    } else if (guessed_number > generated_number) {
      cout << "Your number is too big.\nTry again!" << std::endl;
    } else {
      cout << "You've done it! You guessed the number " << guessed_number
           << " in " << no_of_guess << " guesses!" << std::endl;
      break;
    }
  }

  return 0;
}