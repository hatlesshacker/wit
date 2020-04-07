#include <iostream>
#include <cli11.h>
using namespace std;

int main(int argc, char* argv[]) {

    std::string topline("wit client - version ");
    std::string add(PACKAGE_VERSION);
    topline.append(add);

    CLI::App app{topline};

    app.require_subcommand(1);

    //INITIALIZE REPO
    auto init = app.add_subcommand("init", "Initialize a wit project");
    std::vector<std::string> remote_loc;
    init->add_option("-r, --remote", remote_loc, "Initialize from remote location");

    init->callback([&]() {
    if(!remote_loc.empty()) {
            std::cout << "Initializing wit repo from ";
            for (auto i = remote_loc.begin(); i != remote_loc.end(); ++i){
                std::cout << *i << ' ';
            }
            std::cout << "..\n";
        } else {
            std::cout << "Initializing local wit repo..\n";
        }
    });

    //SHOW STATUS
    auto status = app.add_subcommand("status", "Print changes since last commit");
    status->callback([&]() {
        cout << "STATUS\n"; //TODO
    });

    CLI11_PARSE(app, argc, argv);     
    return 0; 
}
