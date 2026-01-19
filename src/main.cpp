#include "Includes.hpp"

// cpp 17

void printMenu();
int64_t getUserInput();
void handleNumbers(std::vector<uint64_t>& primes, int64_t limit);
bool isPrime(int64_t number);
void savePrimesToFile(const std::vector<uint64_t>& primes);

int main()
{
	// Vector for storage prime Numbers
	std::vector<uint64_t> primes;

	printMenu();
	consoleTools::write("Please enter an integer\n",32,0,0);
	handleNumbers(primes,getUserInput());
	savePrimesToFile(primes);

	for (const auto& prime : primes)
		std::cout << prime << '\n';
}

void printMenu()
{
	consoleTools::write("Prime numbers generator v2.0\n",32,0,0);
	consoleTools::write("============================\n",90,0,0);
}
int64_t getUserInput()
{
	while (true)
	{
		consoleTools::write(">> ",90,0,0);
		std::string input;
		std::cin >> input;

		// Checking if user input can be converted to number
		if (input.empty() || !std::all_of(input.begin(), input.end(), ::isdigit))
		{
			// String can't be converted
			consoleTools::write("invalid input:\n",31,0,0);
			continue;
		}else
		{
			// String can be converted
			return std::stoll(input);
		}
	}
}
void handleNumbers(std::vector<uint64_t>& primes, const int64_t limit)
{
	if (limit >= 2)
		// Adding 2 because for is starting from 3
		primes.emplace_back(2);

	// Start from 3 and add 2 to skip even numbers
	for (int64_t i{3}; i < limit; i+=2)
	{
		// if number is prime add to vector
		if (isPrime(i))
			primes.emplace_back(i);
	}
}
bool isPrime(const int64_t number)
{
	double sq{ sqrt(number) };
	for (int64_t i = 2; i <= sq; i++) {
		if (number % i == 0) return false;
	}
	return true;
}
void savePrimesToFile(const std::vector<uint64_t>& primes)
{
	std::ofstream file("primes.txt", std::ios::trunc);

	if (!file.is_open())
	{
		consoleTools::write("Failed to open 'primes.txt'",32,0,0);
		return;
	}
	for (uint64_t i{}; i < primes.size(); i++)
	{
		file << i << ". " << primes.at(i) << '\n';
	}
}
// Template from: https://github.com/dixe1/cpp-project-template

/*
 * 90 -> gray
 *
 * to do
 * 1.change name generateNumbers
 */