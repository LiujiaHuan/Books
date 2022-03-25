//-------------------------------8.6 fork两次以免产生僵尸进程-----------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    if((pid = fork()) < 0){
    	err_sys("fork error");
    }else{
    	if((pid = fork()) < 0){
    		err_sys("error");
    	}else if(pid > 0){
    		exit(0);	//二次fork后子进程1的返回值为自身，故子线程exit了
    	}

    	sleep(2);	//休眠两秒，以免第二个子进程无法打印出他的父进程
    	printf("第二个子进程的父进程pid为：%d",(long)getppid());	//pid = 1 (init进程)
    	exit(0);	//子进程2结束
    
    }
    if(waitpid(pid,NULL,0) ！= pid){	//等待子进程1 exit，以免主进程exit了
    	err_sys("waitpid error");
    }
    exit(0);
}
//---------------------------------------------------------------------------------------------------------------//




//==========================================进程竞争演示=========================================================//
int main(){
	pid_t pid;
	if((pid = fork()) < 0){//父进程先运行
		err_sys("error");
	}else if(pid > 0){
		print_text("这是父进程的输出");
	}else if(pid == 0){
		print_text("这是子进程的输出");//父进程调用
	}
	exit(0);
}

print_text(char *mytext){
	char *temp;
	setbuf(stdout,NULL);	//不缓冲，所以每个字符输出一次都要调用write，这是演示竞争的核心！
	for(ptr = mytext;(ptr++)!=0; ){
		putc(c,stdout);
	}
}
//=====================================================================================================================//
