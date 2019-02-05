#include<stdio.h>
#include<string.h>

int n;

int cmpstr(char *str, char *p, int striked[]) {
	/*
	int j=0,flag = 0;
	for(int i=0;i<strlen(p);i++) {
		for(;j<strlen(str);j++) {
			if(str[j] == p[i] && striked[j] != 1) {
				j++;
				break; //element found
			}
			if(j == strlen(str)-1 && i<strlen(p)) {
				flag = 1;
			}
		}
	}
	return !flag;
	*/
	int count = 0;
	for(int i=0;i<strlen(str);i++) {
		if(str[i] == p[count] && striked[i]!=1) {
			count++;
		}
	}
	if(count == strlen(p)) {
		return 1;
	}
	return 0;
}

int main() {
	
	char str[1000];
	char p[1000];
	memset(str, 0, sizeof(str));
	memset(p, 0, sizeof(p));
	scanf(" %s",str);
	scanf(" %s",p);
	scanf(" %d",&n);
	int arr[n],striked[n];
	memset(striked, 0, sizeof(striked));
	for(int i=0;i<n;i++) {
		scanf(" %d",&arr[i]);
		arr[i]--;
	}
	int count = 0,i=0;
	while(cmpstr(str,p,striked) == 1) {
		striked[arr[i++]] = 1;
		count++;
	}
	printf(" strike times : %d\n",count-1);

	return 0;
}
