//===============================================
#include "GSetting.h"
#include "GOptions.h"
#include "GProcess.h"
#include "GConfig.h"
//===============================================
using namespace std;
//===============================================
int main(int argc, char** argv) {
    GSetting::Instance()->load("data/config/config.txt");
    GOptions::Instance()->args(argc, argv);
    GProcess::Instance()->run(argc, argv);
    return 0;
}
//===============================================
