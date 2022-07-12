//朴素模式匹配算法的优化

#include<stdio.h>

#define MAXLEN 255

typedef struct{
	char ch[MAXLEN+1];
	int length;
}SString;

//NEXT数组
void Get_Next(SString T,int next[]){
	int i=1,j=0;
	next[1]=0;
	while(i<T.length){
		if(j==0||T.ch[i]==T.ch[j]){
			++i;
			++j;
			//若pi=pj则next[j+1]=next[j]+1
			next[i]=j; 
		}
		else
		//否则令j=next[j]，循环继续 
			j=next[j];
	}
}

//KMP算法 
int Index(SString S,SString T){
	int i=1,j=1;
	int next[T.length+1];
	Get_Next(T,next); 
	while(i<=S.length && j<=T.length){
		if(j==0 || S.ch[i]==T.ch[j]){
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>T.length)
		return i-T.length;//此处因为i在上面+1，故而不用再+1 
	else
		return 0;
}


int main(){
	
	return 0;
} 
