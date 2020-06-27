#include "observable.h"
#include <stdlib.h>

static int attach(Observable *subject, Observer callback)
{
    Observer *slot = subject->observers;
    
    while (*slot != NULL) {
        slot++;
    }
    
    if (slot == &subject->observers[subject->max_observers]) {
        return -1;
    }

    *slot = callback;
    return 0;
}

static void notify(Observable *subject)
{
    Observer *observer = subject->observers;
    while (*observer) {
        (*observer)(subject);
        observer++;
    }
}

int Observable_init(Observable *subject, size_t max_observers)
{
    // leave one more field at the end for null terminator
    subject->observers = calloc(max_observers + 1, sizeof(Observer));
    if (!subject->observers) {
        return -1;
    }
    subject->max_observers = max_observers;
    subject->attach = attach;
    subject->notify = notify;
    return 0;
}

void Observable_deinit(Observable *subject)
{
    free(subject->observers);
    *subject = (Observable){0};
}