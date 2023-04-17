#include "GroupSigFactory.h"
#include "devcore/statusCode.h"
#include <iostream>
#include <vector>
#include <string>
using std::vector; 
using std::string;

using RetCode::CommonStatusCode::SUCCESS;

namespace dev{
    namespace eth{
int parse_param(vector<string> &param_vec,
            std::string& group_name,
            const std::string& param, int param_num){

            }

int create_group(std::string& result, std::string param){
    //参数解析，各个参数之间用*号码隔开 		
    // param = {"linear_type":"f", "bit_len":256}   
    vector<string> param_vec;
    string group_name;
    string pbc_param_setting = "";
    if( "" != param )
        {
           int is_valid = parse_param(param_vec, group_name, param, 2);
           if(is_valid != SUCCESS)
               return is_valid;
           pbc_param_setting = param_vec[0];  // pbc_param_setting = {"linear_type":"f", "bit_len":256}
        }
        else
        {
            int is_valid = parse_param(param_vec, group_name, param, 1);
            if(is_valid != SUCCESS)
                return is_valid;

    }
}
}
}
