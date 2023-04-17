#include <time.h>
#include "GroupSig.h"
#include "GroupSigFactory.h"
#include "devcore/statusCode.h"
#include "devcore/CommonFunc.h"
#include <iostream>
#include <vector>
#include <string>
using std::vector; 
using std::string;

using RetCode::CommonStatusCode::SUCCESS;
using GroupSigStatusCode::INTERNAL_PARAM_PARSE_FAILED;

using namespace dev::eth ;

#if defined(__cplusplus) 
namespace GroupSigApi 
{ 
#endif
const string GroupSigApi::PARAM_DELIM="*";

int parse_param(vector<string> &param_vec,
            std::string& group_name,
            const std::string& param, int param_num){

     param_vec = split(param, PARAM_DELIM);         
     if( (int)param_vec.size()!= param_num &&               
     (int)param_vec.size()!= param_num-1)         
     {             
        return INTERNAL_PARAM_PARSE_FAILED;         
        }          
        group_name = "";         
        if((int)param_vec.size() == param_num)             
        group_name = param_vec[param_num-1];         
        return SUCCESS;

}

int create_group(std::string& result,
        const std::string& algorithm_method,
        const std::string& pbc_param_info)
{

}

int create_group(std::string& result, std::string param,const std::string& pbc_param_info){
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

int group_member_join(std::string& gsk,
        const std::string& algorithm_method,
        const std::string& pbc_param_info,
        const std::string& gmsk_info, 
        const std::string &gpk_info,
        const std::string& gamma_info)
{

}

int group_member_getAttr(std::string& gsk,              
        const std::string &algorithm_method,             
        const std::string &pbc_param_info,             
        const std::string &gmsk_info,              
        const std::string &gpk_info,             
        const std::string &gamma_info)
{

}

int group_sig(std::string& sig, 
        const std::string& algorithm_method,
        const std::string& gpk_info,
        const std::string& gsk_info,
        const std::string& pbc_param_info,
        const std::string &message)
{

}

int group_verify(int& valid,
        const std::string& sig,
        const std::string& message,
        const std::string& algorithm_method,
        const std::string& gpk_info,
        const std::string& pbc_param_info)
{

}

int open_sig(std::string& cert, 
        const std::string& algorithm_method,
        const std::string& sig,
        const std::string& message,
        const std::string& gpk_info,
        const std::string& gmsk_info,
        const std::string& pbc_param_info)
{

}

int group_verify(int& valid,
        const std::string& sig,
        const std::string& message,
        const std::string& algorithm_method,
        const std::string& gpk_info,
        const std::string& pbc_param_info)
{

}

int group_verifylink(int& valid,
        const std::string& gpk_info,
        const std::string& pbc_param_info,    
        const std::string& message1,             
        const std::string& sig1,
        const std::string& message2,             
        const std::string& sig2,
        const std::string& mlk)
{

}





#if defined(__cplusplus) 
}
#endif