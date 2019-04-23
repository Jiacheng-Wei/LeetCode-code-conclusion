//分治法大整数乘法
//需要补0 补齐位数不用??
#include<bits/stdc++.h>
using namespace std;
struct Bign{
    int val[100];
    int len;
    bool zheng;
    bool zero;
    Bign(){
        memset(val,0, sizeof(val));
        len=0;
        zheng= true;
        zero=false;
    }

    //重写拷贝构造函数，避免浅拷贝
    Bign& operator=(const Bign&  Bigntmp){
        this->len=Bigntmp.len;
        this->zheng=Bigntmp.zheng;
        for(int i=0;i<Bigntmp.len;i++){
            this->val[i]=Bigntmp.val[i];
        }
        return *this;
    }

};

Bign change(char s[]);
Bign add(Bign a,Bign b);
Bign sub(Bign a,Bign b);
Bign multiply(Bign a,Bign b);
Bign multiplyT(Bign a,Bign b);
bool More(Bign a,Bign b);
bool Less(Bign a,Bign b);
int AlignArray(Bign& a,Bign& b);  //补齐位数 返回补齐的位数长度


 Bign multiplyT(Bign a,Bign b){  //b是10^n
     int count=0;
     Bign t;
     t.len=a.len;
     t.zheng=a.zheng;
     for(int i=0;i<b.len-1;i++){  //把0加在前面才对  0的个数
         t.len++;
     }
     for(int j=0,i=b.len-1;i<t.len;i++,j++){
         t.val[i]=a.val[j];
     }
     return t;
 }

 //修改了一下2的倍数
int AlignArray(Bign &a,Bign &b){
    if(a.len>b.len) b.len=a.len;
    else if(b.len>a.len) a.len=b.len;

    if(a.len%2!=0) {
        a.len++;
        b.len++;
    }
    return a.len;
}

Bign change(char s[]){
    Bign res;
    if(s[0]=='-'){ //判断是否是负数
        strcpy(s,s+1);
        res.zheng=false;
    }
    res.len=strlen(s);
    for(int i=0;i<res.len;i++){  //存在val里面一个由低位到高位的数组
        res.val[i]=s[res.len-i-1]-'0';
    }

    return res;
}

//大整数的加法
Bign add(Bign a,Bign b){
    bool resZheng=true; ////结果是正的
    Bign t1=a;  //临时变量
    Bign t2=b;
    //如果第一操作数是正  第二操作数是负
    if(t1.zheng && !t2.zheng){
        t2.zheng=true;
        return sub(t1,t2);
    }
    //如果第一操作数是负 第二操作数是正
    else if(!t1.zheng && t2.zheng){
        t1.zheng=true;
        return sub(t2,t1);
    }
    else if(!t1.zheng && !t2.zheng){
       // t1.zheng=true;  t2.zheng=true;  这个好像无所谓
        resZheng = false;
    }
    //两个都是正
    Bign res;
    int carry=0;
    for(int i=0;i<t1.len||i<t2.len;i++){  //这个条件写错
        int temp=t1.val[i]+t2.val[i]+carry;
        res.val[res.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)  res.val[res.len++]=carry;
    res.zheng=resZheng;
    return res;
}
//比较两个数的值  大于
bool More(Bign a,Bign b){
    if(a.len!=b.len) return a.len>b.len;
    else {
        for(int i=a.len-1;i>=0;i--){
            if(a.val[i]!=b.val[i]) return a.val[i]>b.val[i];
        }
        return false;
    }
}

bool Less(Bign a,Bign b){
    if(a.len!=b.len) return a.len<b.len;
    else {
        for(int i=a.len-1;i>=0;i--){
            if(a.val[i]!=b.val[i]) return a.val[i]<b.val[i];
        }
        return false;
    }
}
//大整数的减法
Bign sub(Bign a,Bign b){
    Bign t1=a;  Bign t2=b;
    Bign res;
    if(t1.zheng && !t2.zheng){
        t2.zheng= true;
        return add(t1,t2);
    }
    else if(!t1.zheng && t2.zheng){
        t1.zheng= true;
        Bign r=add(t1,t2);
        r.zheng= false;
        return r;
    }
    else if(!t1.zheng && !t2.zheng){
        t2.zheng= true;
        t1.zheng= true;
        return sub(t2,t1);
    }

        if(More(t1,t2)){
            for(int i=0;i<t1.len ||i<t2.len;i++){
                if(t1.val[i]<t2.val[i]){  //不够减就借位
                    t1.val[i+1]--;
                    t1.val[i]+=10;
                }
                res.val[res.len++]=t1.val[i]-t2.val[i];
            }

            while(res.len-1>=1 && res.val[res.len-1]==0){
                res.len--;
            }

            return res;
        }
        else if(Less(t1,t2)){
        res=sub(t2,t1);
        res.zheng = false;
        return res;
        }
        else {  //相等的情况
           res.len=1;
           res.val[0]=0;  //0当正数？
           res.zero=true;
           res.zheng=true;
           return res;
        }

}

Bign multiply(Bign a,Bign b){
    //处理一位相乘
    bool resZ=true;
    if((a.zheng && !b.zheng) || (!a.zheng && b.zheng)){
        resZ=false;
    }
    int len=a.len;  //进入的数肯定都是补齐的
    if(a.len==1){
        Bign r;
        int temp=a.val[0]*b.val[0];
        if(temp>9){
            r.val[1]=temp/10;
            r.val[0]=temp%10;
            r.len=2;
        }
        else {
            r.val[0]=temp;
            r.len=1;
        }
        r.zheng=resZ;
        return r;
    }
    else if(len==2){
        Bign r;
        r.len=4;
        int t1=a.val[0]*b.val[0];
        r.val[0]=t1%10;
        int t2=a.val[1]*b.val[0]+a.val[0]*b.val[1]+t1/10;
        r.val[1]=t2%10;
        int t3=a.val[1]*b.val[1]+t2/10;
        r.val[2]=t3%10;
        r.val[3]=t3/10;
        r.zheng=resZ;
        return r;
    }


    Bign a1;
    Bign c1;
    Bign b1;
    Bign d1;
    //分成四个初始化
    //低位到高位  a的低位      低位到高位 a = b1 a1
    for(int i=0;i<a.len/2;i++ ){
        b1.val[b1.len++]=a.val[i];
    }

    for(int i=a.len/2;i<a.len;i++ ){  //低位到高位  a的高位
        a1.val[a1.len++]=a.val[i];
    }

    //低位到高位  b的低位    低位到高位 b = d1 c1
    for(int i=0;i<b.len/2;i++ ){
        d1.val[d1.len++]=b.val[i];
    }
    for(int i=a.len/2;i<b.len;i++ ){  //低位到高位   b的高位
        c1.val[c1.len++]=b.val[i];
    }

    //
    AlignArray(a1,b1);
    AlignArray(c1,d1);
    Bign k0=multiply(a1,c1);
    Bign k2=multiply(b1,d1);

    Bign t1= add(a1,b1);
    Bign t2= add(c1,d1);
    AlignArray(t1,t2);
    Bign t3=multiply(t1,t2);  //

    Bign t4=add(k0,k2);
    Bign t5=sub(t3,t4);

    //10的n/2
    Bign ten1;
    for(int i=0;i<a.len/2;i++){
        ten1.val[ten1.len++]=0;
    }
    ten1.val[ten1.len++]=1; //
    //AlignArray(t5,ten1);
    Bign t7 = multiplyT(t5,ten1);

    //10的n
    Bign ten2;
    for(int i=0;i<a.len;i++){
        ten2.val[ten2.len++]=0;
    }
    ten2.val[ten2.len++]=1;
  //  AlignArray(k0,ten2);
    Bign t8=multiplyT(k0,ten2);

    Bign res;
    res=add(t8,add(t7,k2));
    res.zheng=resZ;
    return res;
}

//打印大整数的方法
void print(Bign a){
    if(!a.zheng)  printf("-");
    //去掉多余的0
    while(a.len-1>=1 && a.val[a.len-1]==0)  a.len--;
    for(int i=a.len-1;i>=0;i--) printf("%d",a.val[i]);
    printf("\n");
}
int main(){
    char str1[1000],str2[1000];
    scanf("%s%s",str1,str2);
    Bign a=change(str1);
    Bign b=change(str2);
    AlignArray(a,b);
   // printf("a.len %d   b.len %d\n",a.len,b.len);
   // Bign res=sub(a,b);
   print(multiply(a,b));
    return 0;
}
