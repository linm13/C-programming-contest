//班级：电31
//作者：林濛
//学号：2013010936
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int choose=1;
	int diterminant(int a[15][15],int N);//求矩阵的行列式函数
	void adjoint(int a[15][15],int b[15][15],int N);//求伴随矩阵函数
	void decode(char *inputFilename,char* KeyName,char* outputFileName);//解密函数
	char filename1[40]={'/0'},filename2[40]={'/0'},filename3[40]={'/0'};
	printf("                           希尔密码解密程序\n");
	printf("                                        ——Created by LinM\n");
	while(choose==1)
	{
		printf("  ---------------------------------------------------------------------------\n");
		printf("请输入密匙矩阵文件地址：");
		scanf("%s",filename1);
		printf("请输入密文文件地址：");
		scanf("%s",filename2);
		printf("请输入结果输出文件的地址：");
		scanf("%s",filename3);
		decode(filename2,filename1,filename3);
		printf("解密成功！\n");
		printf("-----------------------------------------------------------------------------\n");
		printf("是否继续进行解密(请输如数字序号)？(1.是 2.否):");
		scanf("%d",&choose);
	}
	return 0;
}
int diterminant(int a[15][15],int N)
{
	int d[15][15]={0};
	int i,j,k,m,n,ans=0;
	if(N==1)
		ans=a[0][0];
	else 
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				for(k=0;k<N;k++)
				{
					d[j][k]=a[j+1][k];
				}
			}
			for(j=i;j<N;j++)
			{
				for(k=0;k<N;k++)
				{
					d[k][j]=d[k][j+1];
				}
			}
			m=i%2;
			n=m==0?1:-1;
			ans+=n*a[0][i]*diterminant(d,N-1);
		}
	}
	return ans;
}
void adjoint(int a[15][15],int b[15][15],int N)
{
	int c[15][15];
	int i,j,k,m,n,l,q;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			for (l=0;l<N;l++)
			{
				for(q=0;q<N;q++)
				{
					c[l][q]=a[l][q];
				}
			}
			for(k=i;k<N;k++)
			{
				for(l=0;l<N;l++)
				{
					c[k][l]=c[k+1][l];
				}
			}
			for(k=j;k<N;k++)
			{
				for(l=0;l<N;l++)
				{
					c[l][k]=c[l][k+1];
				}
			}
			m=(i+j)%2;
			n=m==0?1:-1;
			b[j][i]=n*diterminant(c,N-1);
		}
	}
}
void multipl(int a[15][15],int b[15][15],int e[15][15],int m,int N,int x,int y)
{
	int i,j,k,q=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<y;j++)
		{
			q=0;
			for(k=0;k<N;k++)
			{
				q+=a[i][k]*b[k][j];
			}
			e[i][j]=q;
		}
	}
}
void decode(char *inputFilename,char* KeyName,char* outputFileName)
{
	FILE *fp;
	int shift[500][15]={0},i=0,j=0,k=0,n=0,l=0,N,s=0,b[15][15]={0},d[15][15]={0},a[15][15]={0},c[15][15]={0},e[15][15]={0};
	char shift_[500][15]={},m=0,miwen[8000]={'\0'},yuanwen[8000]={'\0'};
	if((fp=fopen(KeyName,"r"))==NULL)
	{
		printf("加密矩阵输入文件地址有误！\n");
		exit(0);
	}
	fscanf(fp,"%d",&N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			fscanf(fp,"%d ",&a[i][j]);
		}
	}
	fclose(fp);
	if((diterminant(a,N)%61)==0)
	{
		printf("该加密矩阵不符合加密要求，有误！\n");
		exit(0);
	}
	if((fp=fopen(inputFilename,"r"))==NULL)
	{
		printf("密文输入文件地址有误！\n");
		exit(0);
	}
	for(i=0;i<8000;i++)
	{
		if(!feof(fp))
			miwen[i]=fgetc(fp);
		else break;
	}
	fclose(fp);
	for(n=0;n<500;n++)
	{
		for(j=0;j<N;j++)
		{
			shift_[n][j]=miwen[N*n+j];
		}
	}
	for(i=0;i<500;i++)
	{
		for(j=0;j<N;j++)
		{
			m=shift_[i][j];
			if(m>='A'&&m<='Z')
				shift[i][j]=m-'A'+1;
			if(m>='a'&&m<='z')
				shift[i][j]=m-'a'+27;
			if(m==' ')
				shift[i][j]=53;
			if(m=='.')
				shift[i][j]=54; 
			if(m==',')
				shift[i][j]=55;
			if(m==':')
				shift[i][j]=56;
			if(m=='!')
				shift[i][j]=57;
			if(m=='?')
				shift[i][j]=58;
			if(m=='"')
				shift[i][j]=59;
			if(m=='\n')
				shift[i][j]=60;
			if(m=='=')
				shift[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		if(shift[i][0]!=0)
			k=i+1;
	}
	if(diterminant(a,N)>0)
	{
		for(m=0;;m++)
		{
			if((m*diterminant(a,N))%61==1)
				break;
		}
	}
	else
	{
		for(m=0;;m++)
		{
			if((m*diterminant(a,N))%61==-60)
				break;
		}
	}

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			adjoint(a,c,N);
			d[i][j]=c[i][j]*m;
		}
	}
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			if(d[i][j]<=0)
			{
				while(d[i][j]<0)
					d[i][j]+=61;
			}
			else if(d[i][j]>=61)
			{
				while(d[i][j]>=61)
					d[i][j]-=61;
			}
			else continue;
		}
	}
	for(i=0;i<500;i++)
	{
		for(j=0;j<N;j++)
			b[j][0]=shift[i][j];
		multipl(d,b,e,N,N,N,1);
		for(j=0;j<N;j++)
			shift[i][j]=e[j][0]%61;
	}
	for(i=0;i<500;i++)
	{
		for(j=0;j<N;j++)
		{
			m=shift[i][j];
			if(m>=1&&m<=26)
				shift_[i][j]=m-1+'A';
			if(m>=27&&m<=52)
				shift_[i][j]=m-27+'a';
			if(m==53)
				shift_[i][j]=' ';
			if(m==54)
				shift_[i][j]='.'; 
			if(m==55)
				shift_[i][j]=',';
			if(m==56)
				shift_[i][j]=':';
			if(m==57)
				shift_[i][j]='!';
			if(m==58)
				shift_[i][j]='?';
			if(m==59)
				shift_[i][j]='"';
			if(m==60)
				shift_[i][j]='\n';
			if(m==0)
				shift_[i][j]=0;
		}
	}
	for(n=0;n<500;n++)
	{
		for(j=0;j<N;j++)
		{
			yuanwen[N*n+j]=shift_[n][j];
		}
	}
	if((fp=fopen(outputFileName,"w"))==NULL)
	{
		printf("原文输出文件地址有误！\n");
		exit(0);
	}
	for(i=0;i<8000;i++)
	{
		if(miwen[i]!=0)
			s=i;
	}
	for(i=0;i<=s;i++)
	{
		fputc(yuanwen[i],fp);
	}
	fclose(fp);
}