//���η��������˷�
//��Ҫ��0 ����λ������??
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

    //��д�������캯��������ǳ����
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
int AlignArray(Bign& a,Bign& b);  //����λ�� ���ز����λ������


 Bign multiplyT(Bign a,Bign b){  //b��10^n
     int count=0;
     Bign t;
     t.len=a.len;
     t.zheng=a.zheng;
     for(int i=0;i<b.len-1;i++){  //��0����ǰ��Ŷ�  0�ĸ���
         t.len++;
     }
     for(int j=0,i=b.len-1;i<t.len;i++,j++){
         t.val[i]=a.val[j];
     }
     return t;
 }

 //�޸���һ��2�ı���
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
    if(s[0]=='-'){ //�ж��Ƿ��Ǹ���
        strcpy(s,s+1);
        res.zheng=false;
    }
    res.len=strlen(s);
    for(int i=0;i<res.len;i++){  //����val����һ���ɵ�λ����λ������
        res.val[i]=s[res.len-i-1]-'0';
    }

    return res;
}

//�������ļӷ�
Bign add(Bign a,Bign b){
    bool resZheng=true; ////���������
    Bign t1=a;  //��ʱ����
    Bign t2=b;
    //�����һ����������  �ڶ��������Ǹ�
    if(t1.zheng && !t2.zheng){
        t2.zheng=true;
        return sub(t1,t2);
    }
    //�����һ�������Ǹ� �ڶ�����������
    else if(!t1.zheng && t2.zheng){
        t1.zheng=true;
        return sub(t2,t1);
    }
    else if(!t1.zheng && !t2.zheng){
       // t1.zheng=true;  t2.zheng=true;  �����������ν
        resZheng = false;
    }
    //����������
    Bign res;
    int carry=0;
    for(int i=0;i<t1.len||i<t2.len;i++){  //�������д��
        int temp=t1.val[i]+t2.val[i]+carry;
        res.val[res.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)  res.val[res.len++]=carry;
    res.zheng=resZheng;
    return res;
}
//�Ƚ���������ֵ  ����
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
//�������ļ���
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
                if(t1.val[i]<t2.val[i]){  //�������ͽ�λ
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
        else {  //��ȵ����
           res.len=1;
           res.val[0]=0;  //0��������
           res.zero=true;
           res.zheng=true;
           return res;
        }

}

Bign multiply(Bign a,Bign b){
    //����һλ���
    bool resZ=true;
    if((a.zheng && !b.zheng) || (!a.zheng && b.zheng)){
        resZ=false;
    }
    int len=a.len;  //��������϶����ǲ����
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
    //�ֳ��ĸ���ʼ��
    //��λ����λ  a�ĵ�λ      ��λ����λ a = b1 a1
    for(int i=0;i<a.len/2;i++ ){
        b1.val[b1.len++]=a.val[i];
    }

    for(int i=a.len/2;i<a.len;i++ ){  //��λ����λ  a�ĸ�λ
        a1.val[a1.len++]=a.val[i];
    }

    //��λ����λ  b�ĵ�λ    ��λ����λ b = d1 c1
    for(int i=0;i<b.len/2;i++ ){
        d1.val[d1.len++]=b.val[i];
    }
    for(int i=a.len/2;i<b.len;i++ ){  //��λ����λ   b�ĸ�λ
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

    //10��n/2
    Bign ten1;
    for(int i=0;i<a.len/2;i++){
        ten1.val[ten1.len++]=0;
    }
    ten1.val[ten1.len++]=1; //
    //AlignArray(t5,ten1);
    Bign t7 = multiplyT(t5,ten1);

    //10��n
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

//��ӡ�������ķ���
void print(Bign a){
    if(!a.zheng)  printf("-");
    //ȥ�������0
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
