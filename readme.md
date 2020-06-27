# C Observer

basic implementation of Observer Pattern in C.

## How to run

```sh
gem install ceedling
ceedling test:observer
```

## How to use

To add Observable property to certain object,
1. place `Observable` type as the first field of the sturct.
2. Call `Observable_init` to activate
3. If some module wants to be notified, register appropriate handler with `Observable_attach` 
4. Now that will make anything can be updated when `Observable_notify` called.

See `test/test_observable.c` for example.