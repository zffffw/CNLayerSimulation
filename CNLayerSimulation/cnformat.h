#ifndef cnformat_h
#define cnformat_h

#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int NumOfIP = 4;
const int NumOfMac = 6;
const int TTL = 255;

enum Layer {
    Mac,
    IP,
    TCP,
    Application,
};

struct Basic{
    string srcIP[NumOfIP];
    string desIP[NumOfIP];
    string srcMac[NumOfMac];
    string desMac[NumOfMac];
    int srcPort;
    int desPort;
    int TTL;
    Layer TransportLayer;
    Layer IPLayer;
    Layer DataLayer;
};

Basic basisInformation;

// interact with inferface
struct DataFormat {
    //
    Layer layer;
    int indexOfField;
    string valueOfField;
    string explainOfField;
};

struct Data {
    Layer layer;
    string head;
    string dataOfUpLayer;
    string tail;
};

#endif /* cnformat_h */