# C Observer

basic implementation of Observer Patter in C.

## How to run

```sh
gem install ceedling
ceedling test:observer
```

## How to use

To add Observer property to certain object,
place `Observer` type as the first field of the sturct.

Now that will make your object can be updated with
`Observable_attach` and then `Observable_notify`.

See `test/test_observable.c` for example.