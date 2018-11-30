#include <string>
#include <stdlib.h>
#include <stdio.h>


#include "PerfUtils/TimeTrace.h"
#include "PerfUtils/Cycles.h"

#include "TestObj.pb.h"

#define NUM_TRIALS 1000000
#define UNMARSHAL 1

using PerfUtils::Cycles;

/**
  * Pass in a the number of 4-byte integers to add to the message.
  */
int main(int argc, char** argv){
    int count = 1;
    if (argc > 1) {
        count = atoi(argv[1]);
    }

    srand(time(NULL));

    TestMessage msg;

    // Add various numbers of items
    for (int i = 0; i < count; i++) {
        msg.mutable_item()->Add(rand());
    }

    // Benchmark serialization
    std::string output;
    uint64_t startTime = Cycles::rdtsc();
    for (int i = 0; i < NUM_TRIALS; i++) {
        bool success = msg.SerializeToString(&output);
        if (!success) {
            fprintf(stderr, "Serialization failed\n");
        }
        #if UNMARSHAL
        success = msg.ParseFromString(output);
        if (!success) {
            fprintf(stderr, "Deserialization failed\n");
        }
        #endif
    }
    uint64_t endTime = Cycles::rdtsc();
    printf("%lu ns\n", Cycles::toNanoseconds(endTime - startTime) / NUM_TRIALS);

    google::protobuf::ShutdownProtobufLibrary();
}
