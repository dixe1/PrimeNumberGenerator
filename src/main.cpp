#include "Includes.hpp"

// cpp 17

void printMenu();
uint64_t getUserInput();
void handleNumbers(std::vector<uint64_t>&, uint64_t, std::atomic<uint64_t>&);
bool isPrime(uint64_t);
void savePrimesToFile(const std::vector<uint64_t>&);
void loadingScreen(const std::atomic<uint64_t>&, uint64_t);

int main()
{
	std::vector<uint64_t> primes;		// Vector for storage prime Numbers
	std::vector<std::thread> threads;	// Vector for storage threads objects
	std::atomic<uint64_t> index{};

	printMenu();
	consoleTools::write("Please enter an integer\n",32,0,0);


	// Start generating
	const uint64_t userInput {getUserInput()};
	threads.emplace_back(handleNumbers, std::ref(primes), userInput, std::ref(index));
	threads.emplace_back(loadingScreen, std::ref(index), userInput);

	for (auto& thread : threads)
		thread.join();

	savePrimesToFile(primes);
	localTools::clearTerm();
	consoleTools::write("Prime numbers saved to primes.txt\n",32,0,0);
}

void printMenu()
{
	consoleTools::write("Prime numbers generator v2.0\n",32,0,0);
	consoleTools::write("============================\n",90,0,0);
}
uint64_t getUserInput()
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
		}
		else
		{
			// String can be converted
			const uint64_t inputNumber = std::stoll(input);
			if (inputNumber >= 150000000)
			{
				consoleTools::write("warning: number is very huge this may take a while:\n",31,0,0);
				consoleTools::write("press enter to continue\n",90,0,0);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin.get();
			}
			return inputNumber;
		}
	}
}
void handleNumbers(std::vector<uint64_t>& primes, const uint64_t limit, std::atomic<uint64_t>& index)
{
	if (limit >= 2)
		// Adding 2 because for is starting from 3
		primes.emplace_back(2);

	// Start from 3 and add 2 to skip even numbers
	for (index = 3; index < limit; index+=2)
	{
		// if number is prime add to vector
		if (isPrime(index))
			primes.emplace_back(index);
	}
}
bool isPrime(const uint64_t number)
{
	const double sq{ sqrt(number) };
	for (uint64_t i{2}; i <= sq; i++) {
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
		file << i << ".  " << primes.at(i) << '\n';
	}
}
void loadingScreen(const std::atomic<uint64_t>& index, const uint64_t userInput)
{
	while (index <= userInput)
	{
		localTools::clearTerm();
		consoleTools::write("calculating...\n",32,0,0);
		std::cout << index << " / " << userInput << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
// Template from: https://github.com/dixe1/cpp-project-template