#pragma once
#include<chrono>

#ifndef _TIMER_
#define _TIMER_

using namespace std::chrono;

enum format {
	MILLISECONDS = 0,
	SECONDS = 1,
	MINUTES = 2,
	HOURS = 3
};

class Timer {
public:
	static int difference(time_point<steady_clock> init, format f = MILLISECONDS) {
		const time_point<steady_clock> current = steady_clock::now();
		int dif = duration_cast<milliseconds>(current - init).count();

		if (f == MILLISECONDS) return dif;
		dif /= 1000;
		if (f == SECONDS) return dif;
		dif /= 60;
		if (f == MINUTES) return dif;
		dif /= 60;

		return dif;
	}

	static time_point<steady_clock> now() { return steady_clock::now(); }
};

#endif // !_TIMER_