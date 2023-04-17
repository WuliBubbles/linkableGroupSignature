#ifndef _COMMON_FUNC_H_ 
#define _COMMON_FUNC_H_  
#pragma once #include <string> 
#include <unistd.h> 
#include <exception> 
#include <vector> 
#include <iomanip> 
#include <time.h> 
#include <string.h>
//#include "boost/filesystem.hpp" 
#include "pbc/pbc.h"  
//#include "devcore/easylog.h" 
#define MAX_PATH_LEN 255  
using namespace std;

namespace dev{
    namespace eth{
    

    

//将一个字符串按照指定的分隔符分割成多个子字符串，并返回一个存储这些子字符串的 vector
static inline vector<string> split(const std::string& str, const string& delim)
{
    char *outer = NULL;
    char *result = strtok_r((char*)str.c_str(), delim.c_str(), &outer);
    vector<string> result_vec;
    while(result)
    {
        result_vec.push_back(std::string(result));
        result = strtok_r(NULL, delim.c_str(), &outer);
    }
    //LOG(DEBUG)<<"result string:"<<result_vec;
    return result_vec;
}


    }
}

enum GroupSigMethod {     
    BASIC=0x00,     
    TREE=0x01,         
    METHOD_UNKOWN 
};

#endif