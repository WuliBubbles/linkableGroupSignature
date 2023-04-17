#include<iostream>
//#include "/usr/local/include/pbc/pbc.h"
//#include "/usr/include/jsoncpp/json/json.h"
#include "jsoncpp/json/json.h"
//#include "jsoncpp/json/json.h"
#include<pbc.h>


using namespace std;
using namespace Json;

void parse_arg(int argc,char **args, string &cmd ,string &group_name,
    string &msg, string &sig) {
    if (argc < 3) {
        cout << "Usage :";
    }
    cmd = args[1];
    group_name = args[2];



}


int main(void) {    
    string group_name;
    string msg;
    string cmd;
    string sig;
    pairing_t pairing; 
    Value root;
    cout<<"json library success\n"; 
    return 0; 
} 
