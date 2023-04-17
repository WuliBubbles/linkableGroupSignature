#include <pbc.h>
#include <vector>
#include <string>

using namespace std;

namespace dev{
    namespace eth{
        class AttrBaseSig{
        public:
        
        struct sys_param
        {
            pairing_ptr pairing;
             element_t g1;     
             element_t g2;     
             element_t j1;     
             element_t j2;
             element_t w;
             element_t h;
             element_t u;
             element_t v;
             element_t U;
             element_t V;
            int signature_length;
        };

            struct sys_gpk
        {
            pairing_ptr pairing;
             element_t g1;     
             element_t g2;     
             element_t j1;     
             element_t j2;
             element_t w;
            int signature_length;
        };

        struct sys_gsk
        {
            pairing_ptr pairing;
             element_t xi1;     
             element_t xi2;     
            int signature_length;
        };
         
        typedef struct sys_param*  sys_param_ptr;
        typedef struct sys_gpk*  sys_gpk;
        typedef struct sys_gsk*  sys_gsk;


            //创建群
            int create_group(string& result,const std::string& param);

            //使用群签名算法签名消息
            int group_sig(string& result,const std::string& param);

            //群签名验证          
            int group_verify(int &valid, const std::string& param);

            //群签名链接验证          
            int group_verifylink(int &valid, const std::string& param);

            //打开群签名          
            int group_open(string& result, const std::string& param);

            //为成员颁发基本私钥          
            int gen_basegsk(string& result,const std::string& param);

            //为成员颁发属性私钥          
            int gen_attrgsk(string& result,const std::string& param);

            int init_gpk(sys_gpk gpk,pairing_ptr pairing,sys_param_ptr sys_param);

            int init_gsk(sys_param_ptr gsk,pairing_ptr pairing);

            int free_gsk(sys_gsk gsk);

            int free_gpk(sys_gpk gpk);

        private:

            //参数解析          
            int parse_param(vector<string>& param_vec,                  
            std::string& group_name,                  
            const std::string& param, 
            int param_num);

        //###*****群签名最常见的算法*****#######################
        //###生成群: 群公钥，群私钥, 群线pbc_param参数

            int create_group_key(std::string& result,                  
            std::string& pbc_param_str,                 
            const std::string& group_name);

            //初始化系统参数 线性对和系统参数
            int init_sig_param(sys_param_ptr sys_param, 
              pairing_ptr pairing, const string& group_name,
              string& pbc_param_str);

        public:
        const static std::string RL_DELIM; //撤销列表分割符，默认是#
        const static std::string RL_GONE_DELIM; //g1之间的分隔符,默认是#
        const static std::string PARAM_DELIM;   //参数之间分隔符(默认是*)
        const static std::string RET_DELIM;   //参数之间分隔符(默认是*)

        };
    }
}