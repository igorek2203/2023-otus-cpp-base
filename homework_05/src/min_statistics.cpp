#include "min_statistics.hpp"

namespace stat {
	Min::Min() : 
		m_min{std::numeric_limits<double>::max()} 
		{}

	void Min::update(double next) {
		if (next < Min::m_min) {
			Min::m_min = next;
		}
	}

	double Min::eval() const {
		return Min::m_min;
	}

	const char * Min::name() const {
		return "min";
	}
}
