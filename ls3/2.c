#include<stdio.h>
#include<string.h>

int main() {

	char str[100];
	//scanf(" %[^\n]s",str);
	scanf(" %s",str);
	int m;
	scanf(" %d",&m);
	int queries[m][3];
	for(int i=0;i<m;i++) {
		int f,r,k;
		scanf(" %d %d %d",&f,&r,&k);
		char temp[100];
		memset(temp, 0, sizeof(temp));
		f--;r--;
		strncpy(temp,str+f,r-f+1);
		printf("temp = %s\n",temp);
		int len=strlen(temp);
		int x = k%len;
		strcat(temp,temp);
		char final[100];
		memset(final, 0, sizeof(final));
		strncpy(final, str, f);
		strncat(final, temp+len-x, len);
		strncat(final, str+r+1, sizeof(str)-f-len);
		printf("%s\n",final);
		memset(str, 0, sizeof(str));
		strcpy(str, final);
	}

	return 0;
}
