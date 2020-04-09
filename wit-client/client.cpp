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


            //STEP 1: Create the .wit/ directory and the subsequent structures
            if (mkdir(".wit", 0777) == -1) {
                cout << "Not able to create .wit/ . Check perms maybe?\n";
                exit(-1);
            }
            if (mkdir(".wit/changes", 0777) == -1) {
                cout << "Not able to create .wit/changes/ . Check perms maybe?\n";
                exit(-1);
            }

            //STEP 2: Ask user for credentials to remote repo

            //STEP 3: Obtain the information from remote repo and
            //        Populate local repo

        } else {
            std::cout << "Initializing local wit repo..\n";

            //STEP 1: Create the .wit/ directory and the subsequent structures
            if (mkdir(".wit", 0777) == -1) {
                cout << "Not able to create .wit/ . Check perms maybe?\n";
                exit(-1);
            }
            if (mkdir(".wit/changes", 0777) == -1) {
                cout << "Not able to create .wit/changes/ . Check perms maybe?\n";
                exit(-1);
            }

            fstream auth_json;      auth_json.open(".wit/auth.json", ios::out); 
            fstream versions_json;  versions_json.open(".wit/versions.json", ios::out);
            fstream description;    description.open(".wit/description", ios::out);

            cout << "Empty wit repo made in .wit/\n";


            //STEP 2: create the initial version from the current structure
            //        and ask the user for a commit message.

            //STEP 3: Store the version info.
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
