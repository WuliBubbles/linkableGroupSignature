
#pragma once
#include "GroupSigFactory.h"
#include <string>

#if !defined(__cplusplus) 
extern "C" 
{ 
#endif

#if defined(__cplusplus) 
namespace GroupSigApi
{
#endif

        int create_group(std::string& result,
        const std::string& algorithm_method,
        const std::string& pbc_param_info);

        int group_member_join(std::string& gsk,              
        const std::string &algorithm_method,             
        const std::string &pbc_param_info,             
        const std::string &gmsk_info,              
        const std::string &gpk_info,             
        const std::string &gamma_info);

        int group_member_getAttr(std::string& gsk,              
        const std::string &algorithm_method,             
        const std::string &pbc_param_info,             
        const std::string &gmsk_info,              
        const std::string &gpk_info,             
        const std::string &gamma_info);

        int group_sig(std::string& result,              
        const std::string& algorithm_method,             
        const std::string& gpk_info,             
        const std::string& gsk_info,              
        const std::string& pbc_param_info,             
        const std::string &message); 

        int group_verify(int& ret,             
        const std::string& message,             
        const std::string& sig,             
        const std::string& algorithm_method,             
        const std::string& gpk_info,             
        const std::string& pbc_param_info); 

        int open_sig(std::string& cert,              
        const std::string& algorithm_method,             
        const std::string& sig,             
        const std::string& message,             
        const std::string& gpk_info,              
        const std::string& gmsk_info,             
        const std::string& pbc_param_info);

        int group_verifylink(
        int& valid,
        const std::string& gpk_info,
        const std::string& pbc_param_info,    
        const std::string& message1,             
        const std::string& sig1,
        const std::string& message2,             
        const std::string& sig2,
        const std::string& mlk);

#if defined(__cplusplus) 
}
#endif 

#if !defined(__cplusplus) 
} 
#endif