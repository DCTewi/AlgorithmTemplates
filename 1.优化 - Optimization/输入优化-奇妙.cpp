char ch,B[1<<20],*S=B,*T=B;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<20,stdin),S==T)?0:*S++)
#define isd(c) (c>='0'&&c<='9')
ll aa;ll F()
{ //positive only.
    while(ch=getc(),!isd(ch));aa=ch-'0';
    while(ch=getc(),isd(ch))aa=aa*10+ch-'0';
	return aa;
}

