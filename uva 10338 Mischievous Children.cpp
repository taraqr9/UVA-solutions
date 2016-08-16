/*
     gmail : nurshuvo51@gmail.com
     Nur Shuvo, ICE ,NSTU
*/
#include<bits/stdc++.h>
int main()
{
    char str[100];
    unsigned long long t,i,j,k,len,mot,vag,count,q=1;
    scanf("%lLu",&t);
    getchar();
    while(t--){
    gets(str);
    len=strlen(str);
    mot=1;
    for(i=2;i<=len;i++)
        mot*=i;

    for(i=65;i<=90;i++){
            count=0;
    for(j=0;j<len;j++){
        if(str[j]==i)
        count++;
    }
    vag=1;
    if(count>1){
        for(k=2;k<=count;k++)
            vag*=k;
    }
    mot=mot/vag;
//    printf("%lu\n",count);
    }
    printf("Data set %llu: %llu\n",q++,mot);
    }
    return 0;
}
