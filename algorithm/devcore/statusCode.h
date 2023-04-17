#ifndef _STATUS_CODE_H_ 
#define _STATUS_CODE_H_

#pragma once 
#include <string>

namespace RetCode{
    namespace CommonStatusCode{
        const static int SUCCESS=0;   
        const static int UNKOWN_RET=1;
    }
}

namespace GroupSigStatusCode{
        const static int INTERNAL_PARAM_PARSE_FAILED=10005;
        const static int INTERNAL_PARAM_INIT_FAILED=10006;     
        const static int INTERNAL_GPK_INIT_FAILED=10007;     
        const static int INTERNAL_GMSK_INIT_FAILED=10008;     
        const static int INTERNAL_GSK_INIT_FAILED=10009;
        const static int INTERNAL_GPK_FREE_FAILED=10010;
        const static int INTERNAL_GSK_FREE_FAILED=10012;
}

#endif