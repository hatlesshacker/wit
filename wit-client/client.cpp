#include <iostream>
#include <cli11.h>
using namespace std;

int main(int argc, char* argv[]) {

    std::string topline("wit client - version ");
    std::string add(PACKAGE_VERSION);
    topline.append(add);

    cout << topline << endl;
    CLI::App app{topline};

    string init_loc = "."; //Default
    app.add_option("-i,--init", init_loc, "Initialize a wit repository");

    CLI11_PARSE(app, argc, argv);     
    return 0; 
}
