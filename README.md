# Cost of Marshalling and Unmarshalling Protobufs

This is a simple benchmark which measures the *minimum* cost of marshalling and
then unmarshalling a proto containing a collection of `int32`'s. I claim this
is the minimal cost because all the data being touched should be cached by the
CPU if it fits in the CPU cache, since we're touching the same string and
protobuf over and over again.

By running with the following loop, we can measure the cost for a variety of
sizes.

```
for i in {100..100000..100}; do echo -n "$i," && ./Benchmark $i; done 
```
