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
	static float difference(time_point<steady_clock> init, time_point<steady_clock> current = Timer::now(), format f = MILLISECONDS) {
		float dif = static_cast<float>(duration_cast<milliseconds>(current - init).count());

		if (f == MILLISECONDS) return dif;
		dif /= 1000.0f;
		if (f == SECONDS) return dif;
		dif /= 60.0f;
		if (f == MINUTES) return dif;
		dif /= 60.0f;

		return dif;
	}

	static time_point<steady_clock> now() { return steady_clock::now(); }
};

#endif // !_TIMER_