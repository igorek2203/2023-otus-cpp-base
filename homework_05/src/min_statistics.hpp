#pragma once

#include <limits>
#include "statistics.hpp"

namespace stat {
	class Min : public IStatistics {
	public:
		explicit Min();
        ~Min() = default;

		void update(double next);
		double eval() const;
		const char * name() const;

	private:
		double m_min;
	};
} //stat
