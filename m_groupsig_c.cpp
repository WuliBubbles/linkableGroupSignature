//#include "m_groupsig_c.h"
//#include "com_tool.h"
//#include "algorithm/GroupSig.h"
//
//int m_mkdir(string filepath) { 	
//    mkdir(filepath.c_str() , S_IRUSR | S_IWUSR | S_IXUSR | S_IRWXG | S_IRWXO);        
//    return 0; }
//
//M_Groupsig_C::M_Groupsig_C(string key_dir){
//    this->m_key_dir = key_dir ; 	
//    m_mkdir(key_dir); 	
//    this->m_gamma = "" ; 	
//    this->m_gpk = "" ; 	
//    this->m_pbc_param = "" ; 	
//    this->m_gsk = "";	
//    this->m_gmsk = "" ;
//    this->m_mlk = ""; 
//}
//M_Groupsig_C::~M_Groupsig_C(){  
//
//}
//
////这段代码的作用是读取指定的密钥文件，并返回读取出来的密钥内容
//string M_Groupsig_C::load_key(string group_name , string file_name){ 	
//    string filepath = this->m_key_dir+"/"+group_name+"/"+file_name; 	
//    return file2string(filepath); 
//}
//
////将密钥存储到磁盘的功能
//void M_Groupsig_C::store_key(string group_name , string file_name, string str){ 
//    string filepath = this->m_key_dir+"/"+group_name+"/"+file_name; 	
//    string2file(str,filepath); 
//}
//
////加载密钥
//void M_Groupsig_C::load_key(string group_name){
//	this->m_gpk = this->load_key(group_name , "gpk");
//	this->m_gsk = this->load_key(group_name , "gsk");
//	this->m_gmsk = this->load_key(group_name , "gmsk");
//	this->m_gamma = this->load_key(group_name , "gamma");
//	this->m_pbc_param = this->load_key(group_name , "pbc_param");
//}
//
////存密钥
//void M_Groupsig_C::store_key(string group_name){
//	m_mkdir(this->m_key_dir+"/"+group_name);
//	this->store_key(group_name,"gpk",this->m_gpk);
//	this->store_key(group_name,"gsk",this->m_gsk);
//	this->store_key(group_name,"gmsk",this->m_gmsk);
//	this->store_key(group_name,"gamma",this->m_gamma);
//	this->store_key(group_name,"pbc_param",this->m_pbc_param);
//
//}
//
////
//void M_Groupsig_C::m_create_g(string group_name){
//	string result ;
//	GroupSigApi::create_group(result , algorithm_method , pbc_param_str);
//
//	int tmp_i1 = 0;
//	int tmp_i2 = result.find('*',tmp_i1) ;
//	string gpk = result.substr(tmp_i1 , tmp_i2 - tmp_i1);
//	tmp_i1 = tmp_i2+1 ;
//	tmp_i2 = result.find('*',tmp_i1);
//	string gmsk = result.substr(tmp_i1, tmp_i2 - tmp_i1);
//	tmp_i1 = tmp_i2+1 ;
//	tmp_i2 = result.find('*',tmp_i1);
//	string gamma = result.substr(tmp_i1, tmp_i2 - tmp_i1);
//	tmp_i1 = tmp_i2+1 ;
//	string pbc_param = result.substr(tmp_i1, result.length()-tmp_i1);
//
//	this->m_gpk = gpk ;
//	this->m_gmsk = gmsk ;
//	this->m_gamma = gamma ;
//    this->m_mlk = m_mlk;
//	this->m_pbc_param=pbc_param;
//	this->store_key(group_name);
//}
//
//
//string M_Groupsig_C::m_add_member(string group_name){
//	this->load_key(group_name);
//	cout << group_name << endl ;
//	string gsk;
//	GroupSigApi::group_member_join(gsk , algorithm_method , this->m_pbc_param 
//			, this->m_gmsk , this->m_gpk , this->m_gamma);
//	this->m_gsk = gsk ;
//	this->store_key(group_name);
//	return gsk+"*"+this->m_gpk+"*"+this->m_pbc_param+"*";
//}
//
//
