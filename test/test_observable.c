#include "unity.h"

#include "observable.h"

void setUp(void)
{
}

void tearDown(void)
{
}

typedef struct {
    Observable super;
    int data;
} ObservableData;

static void ObservableDataLogger(ObservableData *subject)
{
    printf("data received: %d", subject->data);
}

void test_Observable_attach_ShouldCallObserver_WhenNotify(void)
{
    ObservableData subject;
    Observable_init(&subject.super, 10);
    
    Observable_attach(subject, ObservableDataLogger);

    subject.data = 256;
    Observable_notify(subject);
}

void test_Observable_attach_ShouldFailAppend_WhenFull(void)
{
    ObservableData subject;
    int max_observer = 10;
    Observable_init(&subject.super, max_observer);
    
    int res;
    while (max_observer--)
    {
        res = Observable_attach(subject, ObservableDataLogger);
        TEST_ASSERT_EQUAL(res, 0);
    }

    res = Observable_attach(subject, ObservableDataLogger);
    TEST_ASSERT_TRUE(res < 0);
}


void test_Observable_deinit_ShouldMemSetAll0(void)
{
    ObservableData subject;
    int max_observer = 10;
    Observable_init(&subject.super, max_observer);
    
    int res;
    while (max_observer--)
    {
        res = Observable_attach(subject, ObservableDataLogger);
        TEST_ASSERT_EQUAL(res, 0);
    }

    Observable_deinit(&subject.super);
    TEST_ASSERT_EQUAL_MEMORY(&subject, &(Observable){0}, sizeof(Observable));
}