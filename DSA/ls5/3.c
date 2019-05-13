#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int arr[1000], len = 0;

int cmp(const void *a,const void *b) {
    return (*(int *)a)-(*(int *)b);
}

void print() {
    for(int i=0;i<len;i++) {
        printf(" %d",arr[i]);
    }printf("\n");
}

int swap(int a, int b) {
    for(int i=0;i<len;i++)
        if(arr[i] == a) {a=i;break;}
    for(int i=0;i<len;i++)
        if(arr[i] == b) {b=i;break;}
    //printf("a=%d b=%d arr[a]=%d arr[b]=%d\n",a, b, arr[a], arr[b]);
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    //printf("a=%d b=%d arr[a]=%d arr[b]=%d\n",a, b, arr[a], arr[b]);
    print();
}

int insert(int x) {
    int i,temp;
    for(i=0;i<len;i++) {
        if(arr[i]>x)
            break;
    }
    len++;
    for(int j=len-1;j!=i;j--) {
        arr[j] = arr[j-1];
    }
    arr[i] = x;
    print();
}

int delete(int x) {
    int i,temp;
    for(i=0;i<len;i++) {
        if(arr[i]==x)
            break;
    }
    for(int j=i;j<len-1;j++) {
        arr[j] = arr[j+1];
    }
    len--;
    print();
}

int sort() {
    qsort(arr,len,sizeof(int),cmp);
    print();
}

int main() {

    char c;
    do {
        scanf("%d%c",&arr[len++],&c);
    }while(c!='\n');
    int n,x,y;
    scanf("%d",&n);
    char str[3];
    while(n--) {
        scanf(" %s",&str);
        if(strlen(str)-1) {
            //sw so
            switch (str[1])
            {
                case 'w':
                    scanf(" %d %d",&x,&y);
                    swap(x,y);
                    break;

                case 'o':
                    sort();
                    break;
                default :
                    printf("Improper operator\n");
            }
        }
        else {
            scanf(" %d",&x);
            switch (str[0])
            {
                case 'i':
                    insert(x);
                    break;

                case 'd':
                    delete(x);
                    break;
                default :
                    printf("Improper operator\n");
            }
        }
    }

    return 0;
}