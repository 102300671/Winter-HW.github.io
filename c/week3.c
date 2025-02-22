#include <stdio.h>

typedef struct {
    char number[20];
    char name[20];
    float price;
} Book;

void inverse1(double num[], int n) {
    for(int i = 0; i < n/2; i++) {
        int t=num[i];
        num[i]=num[n-i-1];
        num[n-i-1]=t;
    }
}

void inverse2(double *num, int n) {
    for(int i = 0; i < n/2; i++) {
        int t=*(num+i);
        *(num+i)=*(num+n-i-1);
        *(num+n-i-1)=t;
    }
}

void swap1(int a, int b) {
    int t=a;
    a=b;
    b=t;
}

void swap2(int *a, int *b) {
    int t=*a;
    *a=*b;
    *b=t;
}

void comperbookprice(Book *book1, Book *book2) {
    if(book1->price>book2->price) {
        printf("%s %s %.2f",book1->number,book1->name,book1->price);
    }
    else {
        printf("%s %s %.2f",book2->number,book2->name,book2->price);
    }
}

int main() {
    int n,way,number;
    printf("请输入操作编号 (1: 数组逆序, 2: 交换整数, 3: 比较书籍价格): ");
    scanf("%d",&number);
    if(number==1) {
        printf("请输入数组的长度: ");
        scanf("%d",&n);
        double num[n];
        printf("请输入数组的元素: ");
        for(int i=0; i<n; i++) {
            scanf("%lf",&num[i]);
        }
        printf("请输入逆序方式 (1: inverse1, 2: inverse2): ");
        scanf("%d",&way);
        if(way==1) inverse1(num,n);
        else inverse2(num,n);
        printf("逆序后的数组: ");
        for(int i=0; i<n; i++) {
            printf("%.2lf ",num[i]);
        }
    }
    else if(number==2) {
        int a,b;
        printf("请输入两个整数: ");
        scanf("%d %d",&a,&b);
        printf("交换前的结果: %d %d\n",a,b);
        printf("请输入交换方式 (1: swap1, 2: swap2): ");
        scanf("%d",&way);
        if(way==1) swap1(a,b);
        else swap2(&a,&b);
        printf("交换后的结果: %d %d",a,b);
    }
    else if(number==3) {
        Book book1,book2;
        printf("请输入第一本书的信息 (编号 名称 价格): ");
        scanf("%s %s %f",book1.number,book1.name,&book1.price);
        printf("请输入第二本书的信息 (编号 名称 价格): ");
        scanf("%s %s %f",book2.number,book2.name,&book2.price);
        printf("价格较高的书籍信息: ");
        comperbookprice(&book1,&book2);
    }
    
    return 0;
}