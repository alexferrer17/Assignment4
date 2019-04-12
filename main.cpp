#include "Register.h"

using namespace std;

int main(int argc, char const *argv[]) {

    std::cout << "hello from main!" << '\n';
    Register programme = Register();
    programme.RunSimulation(argv[1]);
    return 0;


}
