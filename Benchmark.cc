#include "TestObj.pb.h"
#include <string>

int main(){
    TestMessage msg;
    // Add various numbers of items
    msg.mutable_item()->Add(5);

    // Benchmark serialization
    std::string output;
    msg.SerializeToString(&output);

    google::protobuf::ShutdownProtobufLibrary();
}
