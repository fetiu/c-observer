#include "build/temp/_test_observable.c"
#include "src/observable.h"
#include "/usr/local/lib/ruby/gems/2.6.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"




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



    ((Observable *)&subject)->attach( ((Observable *)&subject), (Observer)ObservableDataLogger);



    subject.data = 256;

    ((Observable *)&subject)->notify((Observable *)&subject);

}



void test_Observable_attach_ShouldFailAppend_WhenFull(void)

{

    ObservableData subject;

    int max_observer = 10;

    Observable_init(&subject.super, max_observer);



    int res;

    while (max_observer--)

    {

        res = ((Observable *)&subject)->attach( ((Observable *)&subject), (Observer)ObservableDataLogger);

        UnityAssertEqualNumber((UNITY_INT)((res)), (UNITY_INT)((0)), (((void*)0)), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_INT);

    }



    res = ((Observable *)&subject)->attach( ((Observable *)&subject), (Observer)ObservableDataLogger);

    if ((res < 0)) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(48)));};

}





void test_Observable_deinit_ShouldMemSetAll0(void)

{

    ObservableData subject;

    int max_observer = 10;

    Observable_init(&subject.super, max_observer);



    int res;

    while (max_observer--)

    {

        res = ((Observable *)&subject)->attach( ((Observable *)&subject), (Observer)ObservableDataLogger);

        UnityAssertEqualNumber((UNITY_INT)((res)), (UNITY_INT)((0)), (((void*)0)), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_INT);

    }



    Observable_deinit(&subject.super);

    UnityAssertEqualMemory(( const void*)((&subject)), ( const void*)((&(Observable){0})), (UNITY_UINT32)((sizeof(Observable))), 1, (((void*)0)), (UNITY_UINT)(66), UNITY_ARRAY_TO_ARRAY);

}
