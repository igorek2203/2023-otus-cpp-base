#include <iostream>
#include <iomanip>
#include "statistics.hpp"
#include "min_statistics.hpp"
#include "max_statistics.hpp"
#include "mean_statistics.hpp"
#include "std_statistics.hpp"

int main() {
	const size_t statistics_count = 4;
	IStatistics *statistics[statistics_count];

	statistics[0] = new stat::Min{};
	statistics[1] = new stat::Max{};
	statistics[2] = new stat::Mean{};
	statistics[3] = new stat::Std{};

	double val = 0;
	while (std::cin >> val) {
		for (size_t i = 0; i < statistics_count; ++i) {
			statistics[i]->update(val);
		}
	}

	// Handle invalid input data
	if (!std::cin.eof() && !std::cin.good()) {
		std::cerr << "Invalid input data\n";
		return 1;
	}

	// Print results if any
	for (size_t i = 0; i < statistics_count; ++i) {
		std::cout << statistics[i]->name() << " = " << statistics[i]->eval() << std::endl;
	}

	// Clear memory - delete all objects created by new
	for (size_t i = 0; i < statistics_count; ++i) {
		delete statistics[i];
	}
	return 0;
}
