#include <string>

#include "PerfUtils/TimeTrace.h"
#include "PerfUtils/Cycles.h"

#include "TestObj.pb.h"

int main(){
    TestMessage msg;
    // Add various numbers of items
    msg.mutable_item()->Add(5);

    // Benchmark serialization
    std::string output;
    msg.SerializeToString(&output);

    google::protobuf::ShutdownProtobufLibrary();
}
