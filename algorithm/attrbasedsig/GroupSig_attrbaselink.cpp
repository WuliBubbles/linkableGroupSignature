#include "time.h"
#include <pbc.h>
//#include "/usr/local/include/pbc/pbc.h"
#include "GroupSig_attrbaselink.h"
#include "../devcore/statusCode.h"
#include<iostream>
using namespace std;
//using GroupSigStatusCode::INTERNAL_PARAM_INIT_FAILED;
using namespace GroupSigStatusCode;
using namespace RetCode::CommonStatusCode;



namespace dev{
    namespace eth{
        const string AttrBaseSig::RL_DELIM="#";     
        const string AttrBaseSig::RL_GONE_DELIM="#";//g1之间的分隔符,默认是#     
        const string AttrBaseSig::PARAM_DELIM="*";//参数之间分隔符(默认是*)     
        const string AttrBaseSig::RET_DELIM="*"; 


    //###创建群
    int AttrBaseSig::create_group(string& result,const std::string& param)
    {

    }

    int AttrBaseSig::parse_param(vector<string> &param_vec,
            std::string& group_name,
            const std::string& param, int param_num)
    {

    }

    //###使用群签名算法签名消息
    int AttrBaseSig::group_sig(string& result, const std::string& param)
    {

    }

    int AttrBaseSig::group_verify(int& valid, const std::string& param)
    {

    }

    int AttrBaseSig::group_verifylink(int& valid, const std::string& param)
    {

    }

    //###打开群签名
    int AttrBaseSig::group_open(string& result, const std::string& param)
    {

    }

    //###为成员颁发私钥
    int AttrBaseSig::gen_basegsk(string& gsk_info,const std::string& param)
    {

    }

    int AttrBaseSig::gen_attrgsk(string& gsk_info,const std::string& param)
    {

    }



    




   /* @function: 初始化群签名相关的数据结构，包括双线性对&&系统参数
     * @params: 1. sys_param:
     *          2. pairing:
     *          3. type:
     *          4. group_name:
     */
    int AttrBaseSig::init_sig_param(sys_param_ptr sys_param, 
            pairing_ptr pairing, const string& group_name,
            string& pbc_param_str){
         cout<<"begin init_sig_param";
         if(!sys_param ||!pairing)
             return INTERNAL_PARAM_INIT_FAILED;
        
        element_init_G1(sys_param->g1, pairing);
        element_init_G2(sys_param->g2, pairing);
        element_init_G1(sys_param->h, pairing);
        element_init_G1(sys_param->u, pairing);
        element_init_G1(sys_param->v, pairing);
        element_init_G1(sys_param->w, pairing);
 //mlk settings       
        element_t φ1, φ2;
        element_random(φ1); 
        element_random(φ2);

        element_pow_zn(sys_param->j1, sys_param->j1, φ1); 
        element_pow_zn(sys_param->j2, sys_param->j2, φ2);

        element_pow_zn(sys_param->U, sys_param->g2, φ1); 
        element_pow_zn(sys_param->V, sys_param->g2, φ2);
 //issuer settings
        element_t y;
        element_random(y);
        element_pow_zn(sys_param->w, sys_param->g2, y);
 //hashGen settings
 //gsk settings
        bool isEqual = false;
        element_t xi1, xi2;
        element_random(xi1); 
        element_random(xi2);

        element_t u_xi1, v_xi2;
        element_init_G1(u_xi1, pairing);     
        element_init_G1(v_xi2, pairing);

        element_pow_zn(u_xi1, sys_param->u, xi1); 
        element_pow_zn(v_xi2, sys_param->v, xi2);
        do{
            element_random(xi1); 
            element_random(xi2);
            element_pow_zn(u_xi1, sys_param->u, xi1); 
            element_pow_zn(v_xi2, sys_param->v, xi2);
            
            isEqual = element_cmp(u_xi1, v_xi2) == 0;

            if (!isEqual) {
        // 如果不相等，释放之前生成的资源，重新生成 xi1 和 xi2
            element_clear(xi1);
            element_clear(xi2);
            element_clear(u_xi1);
            element_clear(v_xi2);
        }

    }while (!isEqual);
    element_set(sys_param->h, u_xi1);
        
        cout<<"success sys_param";

    return SUCCESS;

    }

    

    int AttrBaseSig::init_gpk(sys_gpk gpk,pairing_ptr pairing,sys_param_ptr sys_param)
    {
                //assert(gpk && pairing);
        if( !gpk || !pairing || !sys_param)
            return INTERNAL_GPK_INIT_FAILED;

        element_init_G1(gpk->g1, pairing);
        element_init_G2(gpk->g2, pairing);
        element_init_G1(gpk->j1, pairing);
        element_init_G1(gpk->j2, pairing);
        element_init_G1(gpk->w, pairing);

        element_set(gpk->g1, sys_param->g1);     
        element_set(gpk->g2, sys_param->g2);     
        element_set(gpk->j1, sys_param->j1);     
        element_set(gpk->j2, sys_param->j2);     
        element_set(gpk->w, sys_param->w);

        cout<<"success gpk";

        return SUCCESS;

    }

    int AttrBaseSig::free_gpk(sys_gpk gpk)     
    {
                if(!gpk)             
                    return INTERNAL_GPK_FREE_FAILED;         
                element_clear(gpk->g1);         
                element_clear(gpk->g2);         
                element_clear(gpk->j1);         
                element_clear(gpk->j2);                
                element_clear(gpk->w);      
                return SUCCESS;
                     
    }

    int AttrBaseSig::init_gsk(sys_param_ptr gsk,pairing_ptr pairing)
    {

    }

    int AttrBaseSig::free_gsk(sys_gsk gsk)     
    {
            if(!gsk)             
                return INTERNAL_GSK_FREE_FAILED;         
            element_clear(gsk->xi1);         
            element_clear(gsk->xi2);         
            return SUCCESS;
                     
    }

        
    }
}