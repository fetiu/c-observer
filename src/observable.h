#pragma once
#include <stddef.h>
#include "observer.h"

typedef struct Observable {
	Observer *observers;
	size_t max_observers;
	int (*attach)(struct Observable *subject, Observer callback);
	void (*notify)(struct Observable *subject);
} Observable;

int Observable_init(Observable *subject, size_t max_observers);
void Observable_deinit(Observable *subject);

#define Observable_attach(subject, callback) \
	((Observable *)&subject)->attach( \
	((Observable *)&subject), (Observer)callback)

#define Observable_notify(subject) \
	((Observable *)&subject)->notify((Observable *)&subject)