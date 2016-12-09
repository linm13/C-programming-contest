//班级：电31
//作者：林濛
//学号：2013010936
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct result{
	float c[7][7];
	float d[7][7];
};
enum name{加法,减法,数乘,乘法,求逆,乘方,转置,行列式,伴随,方程,求秩,QR,LU,相似};
FILE *fp;
int main()
{
	char get[20],judge[20][20]={{"加法"},{"减法"},{"数乘"},{"乘法"},{"求逆"},{"乘方"},{"转置"},{"行列式"},{"伴随"},{"方程"},{"求秩"},{"QR"},{"LU"},{"相似"}},filename[40]={},output[40]={};
	struct result ans;
	int N=0,i=0,j=0,n=0,p=0,m=0,x=0,y=0,choose=0,claim=0,go=1;
	float a[7][7]={0.0},b[7][7]={0.0};
	struct result multipl(float [7][7],float [7][7],int m,int N,int x,int y);//矩阵的乘法函数
	struct result power(float [7][7],int n,int N);//矩阵的乘方函数
	struct result add(float [7][7],float [7][7],int m,int N);//矩阵的加法函数
	struct result trans(float [7][7],int m,int N);//矩阵的转置函数
	float diterminant(float a[7][7],int N);//求矩阵的行列式函数
	struct result adjoint(float [7][7],int N);//求矩阵的伴随矩阵函数
	struct result inverse(float [7][7],int N);//求矩阵的逆函数
	struct result equation(float [7][7],float [7][7],int n);//求解线性方程组函数
	int rank(float [7][7],int m, int N);//求矩阵的秩函数
	float inner(float a[7][7],int j,float b[7][7],int k,int n);//求内积函数
	struct result QR_(float a[7][7],int N);//QR分解函数
	struct result LU_(float a[7][7],int N);//LU分解函数
	struct result multipl_num(float a[7][7],int m,int N,int n);//矩阵数乘函数
	struct result minus(float [7][7],float [7][7],int m,int N);//矩阵减法函数
	float tr(float a[7][7],int N);//矩阵的迹函数
	printf("                               矩阵计算器\n");
	printf("                                         ——Created by Linm\n");
	printf("           ------------------------------------------------------\n");
	printf("           |注意事项：1.程序中进行选择时请输入选项前的数字序号！|\n");
	printf("           |          2.运算前请先输入该运算的关键词！          |\n");
	printf("           |          3.键盘输入时请注意勿输入多余数据！        |\n");
	while(go==1)
	{
		printf("------------------------------------------------------------------------------\n");
		printf("请输入要进行运算的关键词：\n关键词：加法,减法,数乘,乘法,求逆,乘方,转置,行列式,伴随,方程,求秩,QR,LU,相似\n");
		scanf("%s",get);
		printf("------------------------------------------------------------------------------\n");
		for(i=0;i<20;i++)
		{
			if(strcmp(judge[i],get)==0)
			{
				p=i;
				break;
			}
		}
		switch (p)
		{
		case 相似:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的阶数：");
				scanf("%d",&N);
				printf("请输入第一个矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("请输入第二个矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&b[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵1文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d ",&m,&N);
				if(m!=N)
				{
					printf("该矩阵非方阵，输入有误！");
					exit(0);
				}
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
				printf("请输入矩阵2文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&x,&y);
				if(x!=m||y!=N)
				{
					printf("两矩阵阶数不同，有误！");
					exit(0);
				}
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&b[i][j]);
					}

				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			n=0;
			if(tr(a,N)!=tr(b,N)||diterminant(a,N)!=diterminant(a,N))
			{
				printf("--------------------------\n");
				printf("两矩阵不相似\n");
				n++;
			}
			else
			{
			    for(i=1;i<11;i++)
			    {
				    for(j=0;j<N;j++)
				   {
					    b[j][j]+=1.1;
					    a[j][j]+=1.1;
				    }
				    if(diterminant(a,N)!=diterminant(a,N))
				    {
					     printf("--------------------------\n");
					     printf("两矩阵不相似\n");
						 n++;
				    }
			     }
			}
			printf("--------------------------\n");
			if(n==0)
			    printf("两矩阵相似\n");

			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 减法:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的行数与列数：");
				scanf("%d%d",&m,&N);
				printf("请输入第一个矩阵的各个元素\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("请输入第二个矩阵的各个元素\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&b[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵1文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d ",&m,&N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
				printf("请输入矩阵2文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&x,&y);
				if(x!=m||y!=N)
				{
					printf("两矩阵行列式不同，有误！");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&b[i][j]);
					}

				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			ans=minus(a,b,m,N);
			printf("则矩阵1与矩阵2加法的结果为：\n");
			printf("-------------------------------------\n");
			for(i=0;i<m;i++)
			{	
				for(j=0;j<N;j++)
				{
					printf("%-10.3f",ans.c[i][j]);
				}
				printf("\n");
			}
			printf("-------------------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件的地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				fprintf(fp,"%d %d\n",m,N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N-1;j++)
					{
						fprintf(fp,"%-10.3f",ans.c[i][j]);
					}
					for(;j==N-1;)
					{
						fprintf(fp,"%-10.3f\n",ans.c[i][j]);
						break;
					}

				}
				fclose(fp);
			}
			else exit(0);
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 数乘:
			printf("请输入数乘的数：");
			scanf("%d",&n);
			printf("请选择矩阵输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{

				printf("请输入矩阵的行数与列数：");
				scanf("%d %d",&m,&N);
				printf("请输入矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}
				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			ans=multipl_num(a,m,N,n);
			printf("则该矩阵数乘%d后的结果为：\n",n);
			printf("-------------------------------------\n");
			for(i=0;i<N;i++)
			{	
				for(j=0;j<N;j++)
				{
					printf("%-10.3f",ans.c[i][j]);
				}
				printf("\n");
			}
			printf("-------------------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件的地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				fprintf(fp,"%d %d\n",m,N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N-1;j++)
					{
						fprintf(fp,"%-10.3f",ans.c[i][j]);
					}
					for(;j==N-1;)
					{
						fprintf(fp,"%-10.3f\n",ans.c[i][j]);
						break;
					}
				}
				fclose(fp);
			}
			else exit(0);
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;

		case 加法:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的行数与列数：");
				scanf("%d%d",&m,&N);
				printf("请输入第一个矩阵的各个元素\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("请输入第二个矩阵的各个元素\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&b[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵1文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d ",&m,&N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
				printf("请输入矩阵2文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&x,&y);
				if(x!=m||y!=N)
				{
					printf("两矩阵行列式不同，有误！");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&b[i][j]);
					}

				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			ans=add(a,b,m,N);
			printf("则矩阵1与矩阵2加法的结果为：\n");
			printf("-------------------------------------\n");
			for(i=0;i<m;i++)
			{	
				for(j=0;j<N;j++)
				{
					printf("%-10.3f",ans.c[i][j]);
				}
				printf("\n");
			}
			printf("-------------------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件的地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				fprintf(fp,"%d %d\n",m,N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N-1;j++)
					{
						fprintf(fp,"%-10.3f",ans.c[i][j]);
					}
					for(;j==N-1;)
					{
						fprintf(fp,"%-10.3f\n",ans.c[i][j]);
						break;
					}

				}
				fclose(fp);
			}
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 乘法:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵1的行数与列数：");
				scanf("%d %d",&m,&N);
				printf("请输入矩阵1的各个元素\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("请输入矩阵2的行数与列数：");
				scanf("%d %d",&x,&y);
				printf("请输入矩阵2的各个元素\n");
				for(i=0;i<x;i++)
				{
					for(j=0;j<y;j++)
					{
						scanf("%f",&b[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵1文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
				printf("请输入矩阵2文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&x,&y);
				for(i=0;i<x;i++)
				{
					for(j=0;j<y-1;j++)
					{
						fscanf(fp,"%f ",&b[i][j]);
					}
					for(;j=y-1;)
					{
						fscanf(fp,"%f",&b[i][j]);
						break;
					}
				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			if(x!=N)
			{
				printf("两矩阵无法求乘积，输入错误！\n");
				exit(0);
			}

			else 
			{
				ans=multipl(a,b,m,N,x,y);
				printf("则矩阵1与矩阵2乘法法的结果为：\n");
				printf("-------------------------------------\n");
				for(i=0;i<m;i++)
				{	
					for(j=0;j<y;j++)
					{
						printf("%-10.3f",ans.c[i][j]);
					}
					printf("\n");
				}
				printf("-------------------------------------\n");

				printf("请选择是否将此结果输出到文件（1.是 2.否）：");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("请输入结果输出文件的地址：");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("输出文件地址有误！\n");
						exit(0);
					}
					fprintf(fp,"%d %d\n",m,y);
					for(i=0;i<m;i++)
					{
						for(j=0;j<y-1;j++)
						{
							fprintf(fp,"%-10.3f",ans.c[i][j]);
						}
						for(;j=y-1;)
						{
							fprintf(fp,"%-10.3f\n",ans.c[i][j]);
							break;
						}
					}
					fclose(fp);
				}
				else ;
			}
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 求逆:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的阶数：");
				scanf("%d",&N);
				printf("请输入该矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("该矩阵非方阵，输入有误！");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}

				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			if(diterminant(a,N)==0.0)
			{
				printf("----------------------------\n");
				printf("该矩阵不存在逆矩阵！\n");
				exit(0);
			}
			else 
			{
				ans=inverse(a,N);
				printf("则该矩阵的逆矩阵为：\n");
				printf("-------------------------------------\n");
				for(i=0;i<N;i++)
				{	
					for(j=0;j<N;j++)
					{
						printf("%-10.3f",ans.c[i][j]);
					}
					printf("\n");
				}
				printf("-------------------------------------\n");
				printf("请选择是否将此结果输出到文件（1.是 2.否）：");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("请输入结果输出文件的地址：");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("输出文件地址有误！\n");
						exit(0);
					}
					m=N;
					fprintf(fp,"%d %d\n",m,N);
					for(i=0;i<m;i++)
					{
						for(j=0;j<N-1;j++)
						{
							fprintf(fp,"%-10.3f",ans.c[i][j]);
						}
						for(;j=N-1;)
						{
							fprintf(fp,"%-10.3f\n",ans.c[i][j]);
							break;
						}

					}
					fclose(fp);
				}
				else ;
			}
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 乘方:
			printf("请输入乘方数：");
			scanf("%d",&n);
			printf("请选择矩阵输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{

				printf("请输入矩阵的阶数：");
				scanf("%d",&N);

				printf("请输入矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵1文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("矩阵非方阵，有误！\n");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}
				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			ans=power(a,n,N);
			printf("则该矩阵%d次方的结果为：\n",n);
			printf("-------------------------------------\n");
			for(i=0;i<N;i++)
			{	
				for(j=0;j<N;j++)
				{
					printf("%-10.3f",ans.c[i][j]);
				}
				printf("\n");
			}
			printf("-------------------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件的地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				m=N;
				fprintf(fp,"%d %d\n",m,N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N-1;j++)
					{
						fprintf(fp,"%-10.3f",ans.c[i][j]);
					}
					for(;j==N-1;)
					{
						fprintf(fp,"%-10.3f\n",ans.c[i][j]);
						break;
					}
				}
				fclose(fp);
			}
			else ;
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 转置:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的行数与列数：");
				scanf("%d %d",&m,&N);
				printf("请输入矩阵的各个元素\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			ans=trans(a,m,N);
			printf("则矩阵转置的结果为：\n");
			printf("-------------------------------------\n");
			for(i=0;i<N;i++)
			{	
				for(j=0;j<m;j++)
				{
					printf("%-10.3f",ans.c[i][j]);
				}
				printf("\n");
			}
			printf("-------------------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件的地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				fprintf(fp,"%d %d\n",N,m);
				for(i=0;i<N;i++)
				{
					for(j=0;j<m-1;j++)
					{
						fprintf(fp,"%-10.3f",ans.c[i][j]);
					}
					for(;j=m-1;)
					{
						fprintf(fp,"%-10.3f\n",ans.c[i][j]);
						break;
					}
				}
				fclose(fp);
			}
			else ;
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 行列式:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的阶数：");
				scanf("%d",&N);
				printf("请输入矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("该矩阵非方阵，有误！\n");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			printf("--------------------------------\n");
			printf("矩阵行列式的值为：%.3f\n",diterminant(a,N));
			printf("--------------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件的地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				fprintf(fp,"该矩阵行列式的值为：%.3f\n",diterminant(a,N));

				fclose(fp);
			}
			else ;
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 伴随:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的阶数：");
				scanf("%d",&N);
				printf("请输入矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("该矩阵非方阵，有误！\n");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}
				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			ans=adjoint(a,N);
			printf("则矩阵的伴随矩阵为：\n");
			printf("-------------------------------------\n");
			for(i=0;i<N;i++)
			{	
				for(j=0;j<N;j++)
				{
					printf("%-10.3f",ans.c[i][j]);
				}
				printf("\n");
			}
			printf("-------------------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				m=N;
				fprintf(fp,"%d %d\n",m,N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fprintf(fp,"%-10.3f",ans.c[i][j]);
					}
					fprintf(fp,"\n");
				}
				fclose(fp);
			}
			else;
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 方程:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入未知数个数：");
				scanf("%d",&m);
				printf("请输入系数矩阵A：\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<m;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("请输入矩阵b：\n");
				for(j=0;j<m;j++)
				{
					scanf("%f",&b[0][j]);
				}
			}
			else if(choose==2)
			{
				printf("请输入系数矩阵A的文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("系数矩阵非方阵，本程序暂时无法求解：\n");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}
				}
				printf("请输入矩阵b的文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				for(j=0;j<m;j++)
				{
					fscanf(fp,"%f ",&b[0][j]);
				}

				fclose(fp);
			}
			else
			{
				printf("输入有误\n");
				exit(0);
			}

			if(diterminant(a,m)==0.0)
			{
				printf("方程无唯一解,本程序无法求解\n");
				exit(0);

			}
			else
			{
				ans=equation(a,b,m);
				printf("此方程的解为：/n");
				printf("-------------------------------------\n");
				for(i=0;i<m;i++)
				{
					printf("x%d=%.3f\n",i+1,ans.c[0][i]);
				}
				printf("-------------------------------------\n");
				printf("请选择是否将此结果输出到文件（1.是 2.否）：");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("请输入结果输出文件地址：");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("输出文件地址有误！\n");
						exit(0);
					}
					for(i=0;i<m;i++)
					{

						fprintf(fp,"x%d=%.3f\n",i+1,ans.c[0][i]);
					}
					fclose(fp);
				}
				else ;

			}
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case 求秩:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的行数与列数：");
				scanf("%d %d",&m,&N);
				printf("请输入矩阵的各个元素\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
			}
			else
			{
				printf("输入有误！\n");
				exit(0);
			}
			printf("-----------------------------\n");
			printf("该矩阵的秩为%d\n",rank(a,m,N));
			printf("-----------------------------\n");
			printf("请选择是否将此结果输出到文件（1.是 2.否）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入结果输出文件地址：");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("输出文件地址有误！\n");
					exit(0);
				}
				fprintf(fp,"该矩阵的秩为：%d",rank(a,m,N));
				fclose(fp);
			}
			else ;
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);

			break;
		case QR:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的阶数：");
				scanf("%d",&N);
				printf("请输入矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("该矩阵非方阵，无法QR分解！\n");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
			}
			if(diterminant(a,N)==0.0)
			{
				printf("该矩阵行列式为0，无法进行QR分解！\n");
				exit(0);
			}
			else
			{
				ans=QR_(a,N);
				printf("该矩阵QR分解后的Q矩阵为：\n");
				printf("-------------------------------------\n");
				for(i=0;i<N;i++)
				{	
					for(j=0;j<N;j++)
					{
						printf("%-10.3f",ans.c[i][j]);
					}
					printf("\n");
				}
				printf("-------------------------------------\n");
				printf("该矩阵QR分解后的R矩阵为：\n");
				printf("-------------------------------------\n");
				for(i=0;i<N;i++)
				{	
					for(j=0;j<N;j++)
					{
						printf("%-10.3f",ans.d[i][j]);
					}
					printf("\n");
				}
				printf("-------------------------------------\n");
				printf("请选择是否将此结果输出到文件（1.是 2.否）：");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("请输入结果输出文件地址：");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("输出文件地址有误！\n");
						exit(0);
					}
					m=N;
					fprintf(fp,"该矩阵QR分解后的Q矩阵为：\n");
					fprintf(fp,"%d %d\n",m,N);
					for(i=0;i<m;i++)
					{
						for(j=0;j<N;j++)
						{
							fprintf(fp,"%-10.3f",ans.c[i][j]);
						}
						fprintf(fp,"\n");
					}
					fprintf(fp,"该矩阵QR分解后的R矩阵为：\n");
					fprintf(fp,"%d %d\n",m,N);
					for(i=0;i<m;i++)
					{
						for(j=0;j<N;j++)
						{
							fprintf(fp,"%-10.3f",ans.d[i][j]);
						}
						fprintf(fp,"\n");
					}
					fclose(fp);
				}
				else ;
			}
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		case LU:
			printf("请选择输入方式（1.键盘输入 2.文件输入）：");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("请输入矩阵的阶数：");
				scanf("%d",&N);
				printf("请输入矩阵的各个元素\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
			}
			else if(choose==2)
			{
				printf("请输入矩阵文件地址：");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("输入文件地址有误！\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("该矩阵非方阵，无法LU分解！\n");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}

				}
				fclose(fp);
			}
			for(m=0;m<N;m++)
			{
				for(i=0;i<=m;i++)
				{
					for(j=0;j<=m;j++)
					{
						b[i][j]=a[i][j];
					}
				}

				if(diterminant(b,m+1)==0.0)
				{
					printf("该矩阵第%d个顺序主子式为0，无法进行LU分解！\n",m+1);
					exit(0);
				}
			}
			{
				ans=LU_(a,N);
				printf("该矩阵LU分解后的L矩阵为：\n");
				printf("-------------------------------------\n");
				for(i=0;i<N;i++)
				{	
					for(j=0;j<N;j++)
					{
						printf("%-10.3f",ans.d[i][j]);
					}
					printf("\n");
				}
				printf("-------------------------------------\n");
				printf("该矩阵LU分解后的U矩阵为：\n");
				printf("-------------------------------------\n");
				for(i=0;i<N;i++)
				{	
					for(j=0;j<N;j++)
					{
						printf("%-10.3f",ans.c[i][j]);
					}
					printf("\n");
				}
				printf("-------------------------------------\n");
				printf("请选择是否将此结果输出到文件（1.是 2.否）：");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("请输入结果输出文件地址：");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("输出文件地址有误！\n");
						exit(0);
					}
					m=N;
					fprintf(fp,"该矩阵LU分解后的L矩阵为：\n");
					fprintf(fp,"%d %d\n",m,N);
					for(i=0;i<m;i++)
					{
						for(j=0;j<N;j++)
						{
							fprintf(fp,"%-10.3f",ans.d[i][j]);
						}
						fprintf(fp,"\n");
					}
					fprintf(fp,"该矩阵LU分解后的U矩阵为：\n");
					fprintf(fp,"%d %d\n",m,N);
					for(i=0;i<m;i++)
					{
						for(j=0;j<N;j++)
						{
							fprintf(fp,"%-10.3f",ans.c[i][j]);
						}
						fprintf(fp,"\n");
					}
					fclose(fp);
				}
				else ;
			}
			printf("------------------------------------------------------------------------------\n");
			printf("是否继续进行其他运算（1.是  2.否）:");
			scanf("%d",&go);
			break;
		default:printf("名称有误\n");
		}
	}
}
struct result multipl(float a[7][7],float b[7][7],int m,int N,int x,int y)
{
	struct result c={{0}};
	int i,j,k;
	float q=0.0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<y;j++)
		{
			q=0.0;
			for(k=0;k<N;k++)
			{
				q+=a[i][k]*b[k][j];
			}
			c.c[i][j]=q;
		}
	}
	return c;
}
struct result power(float a[7][7],int n,int N)
{
	struct result c;
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		if(i==1)
		{
			for(j=0;j<N;j++)
			{
				for(k=0;k<N;k++)
				{
					c.c[j][k]=a[j][k];
				}
			}
		}
		else 
			c=multipl(c.c,a,N,N,N,N);
	}
	return c;
}
struct result add(float a[7][7],float b[7][7],int m,int N)
{
	struct result c;
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<N;j++)
		{
			c.c[i][j]=a[i][j]+b[i][j];
		}
	}
	return c;
}
struct result trans(float a[7][7],int m,int N)
{
	struct result c;
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<N;j++)
		{
			if(j==i);
			else c.c[i][j]=a[j][i];
		}
	}
	return c;
}
float diterminant(float a[7][7],int N)
{
	float d[7][7]={0.0};
	int i,j,k,m,n;
	float ans=0.0;
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
struct result adjoint(float a[7][7],int N)
{
	struct result d;
	float c[7][7];
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
			d.c[j][i]=n*diterminant(c,N-1);
		}
	}
	return d;
}
struct result inverse(float a[7][7],int N)
{
	struct result c;
	int i,j;
	if(N>=2)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				c.c[i][j]=adjoint(a,N).c[i][j]/diterminant(a,N);
			}
		}
	}
	else c.c[0][0]=1.0/a[0][0];
	return c;
}
struct result equation(float a[7][7],float b[7][7],int m)
{
	struct result c={0.0};
	c=multipl(inverse(a,m).c,b,m,1,m,m);
	return c;
}
int rank(float a[7][7],int m,int N)
{
	int i=0,j=0,k=-1,l=0,count=0,n=0;
	float mid=0;
	for(j=0;j<m;j++)
	{
		for(i=count;i<N;i++)
		{
			k=-1;
			if(a[i][j]!=0)
			{
				k=i;
				count++;
				break;
			}
		}
		if(k==-1)
			continue;
		else
		{
			for(l=0;l<N;l++)
			{
				mid=a[k][l];
				a[k][l]=a[count-1][l];
				a[count-1][l]=mid;
			}
			for(l=count;l<m;l++)
			{
				for(n=j+1;n<N;n++)
				{
					a[l][n]=a[l][n]-a[l][j]*a[count-1][n]/a[count-1][j];
				}
				a[count][j]=0.0;
			}
		}
	}
	return count;
}
float inner(float a[7][7],int j,float b[7][7],int k,int n)
{
	float x=0.0;
	int i;
	for(i=0;i<n;i++)
		x+=a[i][j]*b[i][k];
	return x;
}
struct result QR_(float a[7][7],int N)
{
	int i,j,k;
	struct result d={{0},{0}},e={{0},{0}},f={{0},{0}},g={{0},{0}};
	float b[7][7]={0},c[7][7]={0};
	for(j=0;j<N;j++)
	{	
		for(i=0;i<N;i++)
		{
			b[i][j]=a[i][j];
			for(k=0;k<j;k++)
				b[i][j]=b[i][j]-b[i][k]*inner(a,j,b,k,N)/inner(b,k,b,k,N);
		}
	}
	for(j=0;j<N;j++)
	{
		for(i=0;i<N;i++)
			f.c[i][j]=b[i][j]/sqrt(inner(b,j,b,j,N));
	}
	for(i=0;i<N;i++)
	{
		c[i][i]=sqrt(inner(b,i,b,i,N));
	}
	g=multipl(c,multipl(inverse(b,N).c,a,N,N,N,N).c,N,N,N,N);
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			f.d[i][j]=g.c[i][j];
	return f;
}
struct result LU_(float a[7][7],int N)
{
	int i=0,j=0,k=-1,l=0,n=0;
	float	mid=0.0;
	struct result c={0},b={0};
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			c.c[i][j]=a[i][j];
		}
	}
	for(j=0;j<N;j++)
	{
		for(k=j+1;k<N;k++)
		{
			for(i=j+1;i<N;i++)
			{
				c.c[k][i]-=c.c[k][j]*c.c[j][i]/c.c[j][j];
			}
			c.c[k][j]=0.0;
		}
	}
	b=multipl(a,inverse(c.c,N).c,N,N,N,N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			c.d[i][j]=b.c[i][j];
		}
	}
	return c;
}
struct result multipl_num(float a[7][7],int m,int N,int n)
{
	struct result c={0};
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<N;j++)
		{
			c.c[i][j]=n*a[i][j];
		}
	}
	return c;
}
struct result minus(float a[7][7],float b[7][7],int m,int N)
{
	struct result c;
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<N;j++)
		{
			c.c[i][j]=a[i][j]-b[i][j];
		}
	}
	return c;
}
float tr(float a[7][7],int N)
{
	float tr=0;
	int i;
	for(i=0;i<N;i++)
	{
		tr+=a[i][i];
	}
	return tr;
}