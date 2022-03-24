//----------------------Function：getenv获取环境变量----------------------------//
#include <stdlib.h>
#include "stdio.h"
int main(){
    printf("%s", getenv("path"));
}

//-------------------------------------------------------------------//


//---------------------Function：setjmp,longjmp实现跳转--------------------------//
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>
jmp_buf jmpbuffer;//必须要一个全局变量作为jmp_buf数据类型来保存当前状态（锚点）
void test1(){
    longjmp(jmpbuffer,1);//跳转，index为1
}
void test2(){
    longjmp(jmpbuffer,2);//跳转，index为2
}
int main(){
    int temp = setjmp(jmpbuffer);//设置锚点，temp赋0
    if(temp){
        if(temp == 1){
            printf("test1 has been jmp\n");
            test2();
        }
        if(temp == 2){
            printf("test2 has been jmp\n");
            exit(0);
        }
    }
    test1();
}
//---------------------------------------------------------------//





//-------------------Function:atexit------------------------------//
#include <stdio.h>
void exit_function(){
	printf("atexit has run!");
}
int main(){
	atexit(exit_function);
	printf("now,program will end later");
	return 0;
}
//-----------------------------------------------------------------//






//------------------shell主逻辑---------------------------------------//
#include <stdlib.h>
#include "stdio.h"
#define MAXSIZE 1000
#define TOK_ADD 2
char *tok_ptr;

int get_token(void){
    ...
}

void cmd_add(void){
    int token;
    token = get_token();
}

void Run_Line(char *ptr){
    int cmd;
    tok_ptr = ptr;
    while((cmd = get_token()) > 0){
        switch (cmd){
            case TOK_ADD:
                cmd_add();
                break;
        }
    }
}



int main(){
    char line[MAXSIZE];
    while(fgets(line,MAXSIZE,stdin)!= NULL){
        Run_Line(line);
    }
    exit(0);
}
//-----------------------------------------------//
