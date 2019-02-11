#include<stdio.h>
#include<string.h>

int bitNum;
int bitSum;
int bitString[35];

int abs(int x) {
	return (x>0)?x:-x;
}

int genBitString() {
	memset(bitString, 0, sizeof(bitString));
	bitSum = 0;
	int temp = bitNum--;
	for(int i=0;temp>0;i++) {
		bitString[i] = temp&1;
		bitSum += temp&1;
		temp = temp>>1;
	}
}

int main() {

	int n;
	scanf(" %d",&n);
	bitNum = (1<<n)-1;
	int config[n],cost[n],dominoes = 0,myconf[n];
	int fcost = 99999,ftowers,fheight;
	for(int i=0;i<n;i++) {
		scanf(" %d",&config[i]);
		dominoes += config[i];
	}
	for(int i=0;i<n;i++) {
		scanf(" %d",&cost[i]);
	}
	while(bitNum>0) {
		genBitString();
		if(dominoes%bitSum != 0)
			continue;
		int newCost = 0;
		int height = dominoes/bitSum;
		memset(myconf, 0, sizeof(myconf));
		for(int i=0;i<n;i++) {
			if(bitString[i] == 1) {
				myconf[i] = height;
			}
			newCost += abs(myconf[i]-config[i])*cost[i];
		}
		if(newCost < fcost) {
			fcost = newCost;
			ftowers = bitSum;
			fheight = height;
			for(int i=0;i<n;i++){
				printf("%d",bitString[i]);
			}printf("\n");
		}
	}
	printf("cost:%d, no of towers:%d, height:%d\n",fcost,ftowers,fheight);

	return 0;
}
