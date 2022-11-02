#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>

using namespace std;

int main() {
	// Create the list of words
	vector<string> words;

	words.push_back("HOUSE");
	words.push_back("BUNCH");
	words.push_back("LUNGE");

	// Seed the random number generator and shuffle the words
	random_device rd;
	mt19937 generator(rd());

	shuffle(words.begin(), words.end(), generator);

	// Pick the first word of the list for the game
	string answer = words[0];
	char guess;

	// Populate the full guess string with -
	string full_guess = "";
	for (int i = 0; i < answer.length(); i++) {
		full_guess = full_guess + "-";
	}

	// Track the number of guesses made, max number of incorrect guesses and remaining incorrect guesses
	int num_guesses = 0;
	int max_guesses = answer.length();
	int remaining_guesses = answer.length();

	// Game Logic
	cout << "Welcome to the hangman game." << endl;

	// While the full word hasn't been found
	while (full_guess != answer) {
		cout << "\nPlease enter a letter: ";
		cin >> guess;

		// Handle correct guesses
		if (answer.find(toupper(guess)) != string::npos) {
			cout << "\nYou guessed correctly" << endl;
			
			full_guess[answer.find(toupper(guess))] = toupper(guess);

			cout << "The word so far is: " << full_guess << endl;

			cout << "The total number of incorrect guesses permitted is: " << max_guesses << endl;
			cout << "The number of incorrect guesses remaining is: " << remaining_guesses << endl;
		}
		// Handle incorrect guesses
		else {
			cout << "\nYou guessed incorrectly" << endl;

			remaining_guesses--;
			cout << "The word so far is: " << full_guess << endl;

			cout << "The total number of incorrect guesses permitted is: " << max_guesses << endl;
			cout << "The number of incorrect guesses remaining is: " << remaining_guesses << endl;
		}
		num_guesses++;

		// Lose condition
		if (remaining_guesses == 0) {
			cout << "\nYou have run out of guesses" << endl;
			return 0;
		}
	}

	// Win condition
	cout << "\nCongratulations! You have won the game." << endl;
	cout << "The word was " << full_guess;

	return 0;
}

