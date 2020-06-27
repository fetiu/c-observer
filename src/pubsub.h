#pragma once
#include "observable.h"

#define EVENT_INIT(subject, max_subscribers) \
    Observable_init((Observable *)&subject, max_subscribers);

#define EVENT_DEINIT(subject, max_subscribers) \
    Observable_deinit((Observable *)&subject);

#define EVENT_SUBSCRIBE(subject, callback) \
	((Observable *)&subject)->attach( \
		((Observable *)&subject), \
		(Observer)callback \
	)

#define EVENT_PUBPLISH(subject) \
	((Observable *)&subject)->notify((Observable *)&subject)