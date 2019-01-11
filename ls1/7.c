#include<string.h>
#include<stdio.h>

void swap(char *a,char *b){
	char temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	printf("1 : encode, (not 1) : decode, enter option : ");
	int opt;
	scanf(" %d",&opt);
	char str[100];
	fflush(stdin);
	//printf("Hello");
	scanf(" %[^\n]",str);
	//printf("hello2");
	strcat(str," ");
	int len = strlen(str),ind = 0;
	if(opt == 1){
		while(ind<len){
			str[ind] += 3;
			for(int k=0;k<2;k++){
				if(ind<len && str[++ind]==' '){
					ind++;
				}
			}
		}
		//printf(" converted : %s\n",str);
		int start=0,end=0;
		while(end<len){
			while(str[end+1]!=' '){
				end++;
			}
			for(int i=0;i<=(end-start)/2;i++){
				swap(&str[start+i],&str[end-i]);
			}
			end+=2;
			start=end;
		}
	}
	else{
		int start=0,end=0;
		while(end<len){
			while(str[end+1]!=' '){
				end++;
			}
			for(int i=0;i<=(end-start)/2;i++){
				swap(&str[start+i],&str[end-i]);
			}
			end+=2;
			start=end;
		}
		while(ind<len){
			str[ind] -= 3;
			for(int k=0;k<2;k++){
				if(ind<len && str[++ind]==' '){
					ind++;
				}
			}
		}
	}
	printf("%s\n",str);
	return 0;
}
