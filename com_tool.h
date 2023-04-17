#ifndef _COM_TOOL_H_ 
#define _COM_TOOL_H_

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <pthread.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <stdio.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/shm.h> 
#include <vector> 
#include <random> 
#include <cmath>
#include <functional>

//using std::string ;
using namespace std;

#define SERV_PORT 9780 
#define BUFF_SIZE 4000


static string file2string(string filepath){ 	
    std::fstream fs(filepath.data()); 	
    std::stringstream ss;
    ss << fs.rdbuf(); 	
    return ss.str(); 
}

static int string2file(string str , string filepath){ 	
    std::ofstream fs(filepath.data()); 	
    fs << str ; 	
    fs.close(); 	
    return 0 ; 
}

static string encode_groupsig(string str){
	char buff[2000] ;
	int str_len = str.length();
	int buff_len = 0;
	for (int i = 0; i < str_len; i++) {
		if(str[i]=='{' || str[i] == '}') buff[buff_len++]='A' ;
		else if(str[i] == '\n') buff[buff_len++] = '~';
		else if(str[i] == '"') buff[buff_len++] = '_';
		else if(str[i] == ':') buff[buff_len++] = '-';
		else if(str[i] == ',') buff[buff_len++] = '.';
		else if(str[i] == ' ') continue ;
		else buff[buff_len++] = str[i] ;
	}
	buff[buff_len++] = '\0';
	string result = buff ;
	return result ;
}

static string decode_groupsig(string str){
	char buff[2000] ;
	int str_len = str.length();
	int buff_len = 0;
	for (int i = 0; i < str_len; i++) {
		if(str[i] == '~') buff[buff_len++] = '\n';
		else if(str[i] == '_') buff[buff_len++] = '"';
		else if(str[i] == '-') buff[buff_len++] = ':';
		else if(str[i] == '.') buff[buff_len++] = ',';
		else if(str[i] == ' ') continue ;
		else buff[buff_len++] = str[i] ;
	}
	buff[0] = '{';
	buff[buff_len-2] = '}';
	buff[buff_len++] = '\0';
	string result = buff ;
	return result ;
}

static ssize_t readn(int fd, char *buf, int n){
    size_t nleft = n; //还需要读取的字节数
    char *bufptr = buf; //指向read函数当前存放数据的位置
    ssize_t  nread;
    while(nleft > 0){
        if((nread = read(fd, bufptr, n)) < 0){
            if(errno == EINTR){ //遇到中断
                continue;
            }
            else            // 其他错误
                return -1;
        }
        else if(nread == 0){ // 遇到EOF
            break;
        }
 
        nleft -= nread;
        bufptr += nread;
    }
    return (n - nleft);
}

static ssize_t writen(int fd, const char *vptr, size_t n) { 	
    size_t nleft; 	
    ssize_t nwritten; 	
    const char *ptr; 	
    ptr = vptr; 	
    nleft = n; 	
    while (nleft > 0){ 		
        if ( (nwritten = write(fd, ptr, nleft)) <= 0){ 			
            if (nwritten < 0 && errno == EINTR) 				
            nwritten = 0; // 			
            else  				return -1; // error 		
            } 		nleft -= nwritten; 		
            ptr += nwritten; 	
            } 	
            return n; 
} 

//用于发送和接收消息的函数
static string send_recv(string message){

	string gs_ip = file2string("./groupserverip.conf") ;
	if(gs_ip == ""){
		cout << "err gs_ip : " << gs_ip << endl ;
		return "" ;
	}
	int sockfd ;
	struct sockaddr_in server_addr ;
	int port = SERV_PORT ;
	bzero(&server_addr , sizeof(server_addr));
	server_addr.sin_family = AF_INET ;
	server_addr.sin_addr.s_addr = inet_addr(gs_ip.data());
	server_addr.sin_port = htons(port);

	sockfd = socket(AF_INET , SOCK_STREAM , 0 );
	connect(sockfd , (struct sockaddr *)&server_addr , sizeof(server_addr));
	char buff[BUFF_SIZE];
	memcpy(buff , message.data(), message.length());
	writen(sockfd , buff , BUFF_SIZE);
	bzero(buff , BUFF_SIZE);
	readn(sockfd , buff , BUFF_SIZE);
	close(sockfd);
	string result = buff ;
	return result ;
}

static bool is_prime(long long n) {     
    if (n < 2) {         
        return false;     
    }     
    if (n == 2) {         
        return true;     
    }     
    if (n % 2 == 0) {         
        return false;     
    }     
    long long d = n - 1;     
    int s = 0;     
    while (d % 2 == 0) 
    {         
        d /= 2;         
        s++;     
    }     
    for (int i = 0; i < 10; i++) {         
        long long a = rand() % (n - 2) + 2;         
        long long x = pow(a, d);         
        if (x % n == 1 || x % n == n - 1) {             
            continue;         
            }         
            for (int j = 0; j < s - 1; j++) {             
                x = (x * x) % n;             
                if (x % n == n - 1) {                 
                    break;             
                    }             
                    if (j == s - 2) {                
                         return false;             
                         }         
                }     
        }     
        return true; 
}

static long long hash_function(long long x) {     
    // hash<long long> hasher;     
    // long long hash_val = hasher(x);     
    // while (!is_prime(hash_val)) {         
    //     hash_val++;     
    // }    
    // return hash_val; 
}


#endif