//�༶����31
//���ߣ��֝�
//ѧ�ţ�2013010936
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct result{
	float c[7][7];
	float d[7][7];
};
enum name{�ӷ�,����,����,�˷�,����,�˷�,ת��,����ʽ,����,����,����,QR,LU,����};
FILE *fp;
int main()
{
	char get[20],judge[20][20]={{"�ӷ�"},{"����"},{"����"},{"�˷�"},{"����"},{"�˷�"},{"ת��"},{"����ʽ"},{"����"},{"����"},{"����"},{"QR"},{"LU"},{"����"}},filename[40]={},output[40]={};
	struct result ans;
	int N=0,i=0,j=0,n=0,p=0,m=0,x=0,y=0,choose=0,claim=0,go=1;
	float a[7][7]={0.0},b[7][7]={0.0};
	struct result multipl(float [7][7],float [7][7],int m,int N,int x,int y);//����ĳ˷�����
	struct result power(float [7][7],int n,int N);//����ĳ˷�����
	struct result add(float [7][7],float [7][7],int m,int N);//����ļӷ�����
	struct result trans(float [7][7],int m,int N);//�����ת�ú���
	float diterminant(float a[7][7],int N);//����������ʽ����
	struct result adjoint(float [7][7],int N);//�����İ��������
	struct result inverse(float [7][7],int N);//�������溯��
	struct result equation(float [7][7],float [7][7],int n);//������Է����麯��
	int rank(float [7][7],int m, int N);//�������Ⱥ���
	float inner(float a[7][7],int j,float b[7][7],int k,int n);//���ڻ�����
	struct result QR_(float a[7][7],int N);//QR�ֽ⺯��
	struct result LU_(float a[7][7],int N);//LU�ֽ⺯��
	struct result multipl_num(float a[7][7],int m,int N,int n);//�������˺���
	struct result minus(float [7][7],float [7][7],int m,int N);//�����������
	float tr(float a[7][7],int N);//����ļ�����
	printf("                               ���������\n");
	printf("                                         ����Created by Linm\n");
	printf("           ------------------------------------------------------\n");
	printf("           |ע�����1.�����н���ѡ��ʱ������ѡ��ǰ��������ţ�|\n");
	printf("           |          2.����ǰ�������������Ĺؼ��ʣ�          |\n");
	printf("           |          3.��������ʱ��ע��������������ݣ�        |\n");
	while(go==1)
	{
		printf("------------------------------------------------------------------------------\n");
		printf("������Ҫ��������Ĺؼ��ʣ�\n�ؼ��ʣ��ӷ�,����,����,�˷�,����,�˷�,ת��,����ʽ,����,����,����,QR,LU,����\n");
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
		case ����:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("���������Ľ�����");
				scanf("%d",&N);
				printf("�������һ������ĸ���Ԫ��\n");
				for(i=0;i<N;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("������ڶ�������ĸ���Ԫ��\n");
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
				printf("���������1�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d ",&m,&N);
				if(m!=N)
				{
					printf("�þ���Ƿ�����������");
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
				printf("���������2�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&x,&y);
				if(x!=m||y!=N)
				{
					printf("�����������ͬ������");
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
				printf("��������\n");
				exit(0);
			}
			n=0;
			if(tr(a,N)!=tr(b,N)||diterminant(a,N)!=diterminant(a,N))
			{
				printf("--------------------------\n");
				printf("����������\n");
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
					     printf("����������\n");
						 n++;
				    }
			     }
			}
			printf("--------------------------\n");
			if(n==0)
			    printf("����������\n");

			printf("------------------------------------------------------------------------------\n");
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ����:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("����������������������");
				scanf("%d%d",&m,&N);
				printf("�������һ������ĸ���Ԫ��\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("������ڶ�������ĸ���Ԫ��\n");
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
				printf("���������1�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("���������2�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&x,&y);
				if(x!=m||y!=N)
				{
					printf("����������ʽ��ͬ������");
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
				printf("��������\n");
				exit(0);
			}
			ans=minus(a,b,m,N);
			printf("�����1�����2�ӷ��Ľ��Ϊ��\n");
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
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ��ĵ�ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ����:
			printf("���������˵�����");
			scanf("%d",&n);
			printf("��ѡ��������뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{

				printf("����������������������");
				scanf("%d %d",&m,&N);
				printf("���������ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("��������\n");
				exit(0);
			}
			ans=multipl_num(a,m,N,n);
			printf("��þ�������%d��Ľ��Ϊ��\n",n);
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
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ��ĵ�ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;

		case �ӷ�:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("����������������������");
				scanf("%d%d",&m,&N);
				printf("�������һ������ĸ���Ԫ��\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("������ڶ�������ĸ���Ԫ��\n");
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
				printf("���������1�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("���������2�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&x,&y);
				if(x!=m||y!=N)
				{
					printf("����������ʽ��ͬ������");
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
				printf("��������\n");
				exit(0);
			}
			ans=add(a,b,m,N);
			printf("�����1�����2�ӷ��Ľ��Ϊ��\n");
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
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ��ĵ�ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case �˷�:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("���������1��������������");
				scanf("%d %d",&m,&N);
				printf("���������1�ĸ���Ԫ��\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("���������2��������������");
				scanf("%d %d",&x,&y);
				printf("���������2�ĸ���Ԫ��\n");
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
				printf("���������1�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("���������2�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("��������\n");
				exit(0);
			}
			if(x!=N)
			{
				printf("�������޷���˻����������\n");
				exit(0);
			}

			else 
			{
				ans=multipl(a,b,m,N,x,y);
				printf("�����1�����2�˷����Ľ��Ϊ��\n");
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

				printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("������������ļ��ĵ�ַ��");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ����:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("���������Ľ�����");
				scanf("%d",&N);
				printf("������þ���ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("�þ���Ƿ�����������");
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
				printf("��������\n");
				exit(0);
			}
			if(diterminant(a,N)==0.0)
			{
				printf("----------------------------\n");
				printf("�þ��󲻴��������\n");
				exit(0);
			}
			else 
			{
				ans=inverse(a,N);
				printf("��þ���������Ϊ��\n");
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
				printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("������������ļ��ĵ�ַ��");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case �˷�:
			printf("������˷�����");
			scanf("%d",&n);
			printf("��ѡ��������뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{

				printf("���������Ľ�����");
				scanf("%d",&N);

				printf("���������ĸ���Ԫ��\n");
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
				printf("���������1�ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("����Ƿ�������\n");
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
				printf("��������\n");
				exit(0);
			}
			ans=power(a,n,N);
			printf("��þ���%d�η��Ľ��Ϊ��\n",n);
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
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ��ĵ�ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ת��:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("����������������������");
				scanf("%d %d",&m,&N);
				printf("���������ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("��������\n");
				exit(0);
			}
			ans=trans(a,m,N);
			printf("�����ת�õĽ��Ϊ��\n");
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
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ��ĵ�ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ����ʽ:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("���������Ľ�����");
				scanf("%d",&N);
				printf("���������ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("�þ���Ƿ�������\n");
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
				printf("��������\n");
				exit(0);
			}
			printf("--------------------------------\n");
			printf("��������ʽ��ֵΪ��%.3f\n",diterminant(a,N));
			printf("--------------------------------\n");
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ��ĵ�ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
					exit(0);
				}
				fprintf(fp,"�þ�������ʽ��ֵΪ��%.3f\n",diterminant(a,N));

				fclose(fp);
			}
			else ;
			printf("------------------------------------------------------------------------------\n");
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ����:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("���������Ľ�����");
				scanf("%d",&N);
				printf("���������ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("�þ���Ƿ�������\n");
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
				printf("��������\n");
				exit(0);
			}
			ans=adjoint(a,N);
			printf("�����İ������Ϊ��\n");
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
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ���ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ����:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������δ֪��������");
				scanf("%d",&m);
				printf("������ϵ������A��\n");
				for(i=0;i<m;i++)
				{
					for(j=0;j<m;j++)
					{
						scanf("%f",&a[i][j]);
					}
				}
				printf("���������b��\n");
				for(j=0;j<m;j++)
				{
					scanf("%f",&b[0][j]);
				}
			}
			else if(choose==2)
			{
				printf("������ϵ������A���ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("ϵ������Ƿ��󣬱�������ʱ�޷���⣺\n");
					exit(0);
				}
				for(i=0;i<m;i++)
				{
					for(j=0;j<N;j++)
					{
						fscanf(fp,"%f ",&a[i][j]);
					}
				}
				printf("���������b���ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("��������\n");
				exit(0);
			}

			if(diterminant(a,m)==0.0)
			{
				printf("������Ψһ��,�������޷����\n");
				exit(0);

			}
			else
			{
				ans=equation(a,b,m);
				printf("�˷��̵Ľ�Ϊ��/n");
				printf("-------------------------------------\n");
				for(i=0;i<m;i++)
				{
					printf("x%d=%.3f\n",i+1,ans.c[0][i]);
				}
				printf("-------------------------------------\n");
				printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("������������ļ���ַ��");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("����ļ���ַ����\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case ����:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("����������������������");
				scanf("%d %d",&m,&N);
				printf("���������ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
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
				printf("��������\n");
				exit(0);
			}
			printf("-----------------------------\n");
			printf("�þ������Ϊ%d\n",rank(a,m,N));
			printf("-----------------------------\n");
			printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("������������ļ���ַ��");
				scanf("%s",output);
				if((fp=fopen(output,"w"))==NULL)
				{
					printf("����ļ���ַ����\n");
					exit(0);
				}
				fprintf(fp,"�þ������Ϊ��%d",rank(a,m,N));
				fclose(fp);
			}
			else ;
			printf("------------------------------------------------------------------------------\n");
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);

			break;
		case QR:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("���������Ľ�����");
				scanf("%d",&N);
				printf("���������ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("�þ���Ƿ����޷�QR�ֽ⣡\n");
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
				printf("�þ�������ʽΪ0���޷�����QR�ֽ⣡\n");
				exit(0);
			}
			else
			{
				ans=QR_(a,N);
				printf("�þ���QR�ֽ���Q����Ϊ��\n");
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
				printf("�þ���QR�ֽ���R����Ϊ��\n");
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
				printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("������������ļ���ַ��");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("����ļ���ַ����\n");
						exit(0);
					}
					m=N;
					fprintf(fp,"�þ���QR�ֽ���Q����Ϊ��\n");
					fprintf(fp,"%d %d\n",m,N);
					for(i=0;i<m;i++)
					{
						for(j=0;j<N;j++)
						{
							fprintf(fp,"%-10.3f",ans.c[i][j]);
						}
						fprintf(fp,"\n");
					}
					fprintf(fp,"�þ���QR�ֽ���R����Ϊ��\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		case LU:
			printf("��ѡ�����뷽ʽ��1.�������� 2.�ļ����룩��");
			scanf("%d",&choose);
			if(choose==1)
			{
				printf("���������Ľ�����");
				scanf("%d",&N);
				printf("���������ĸ���Ԫ��\n");
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
				printf("����������ļ���ַ��");
				scanf("%s",filename);
				if((fp=fopen(filename,"r"))==NULL)
				{
					printf("�����ļ���ַ����\n");
					exit(0);
				}
				fscanf(fp,"%d %d",&m,&N);
				if(m!=N)
				{
					printf("�þ���Ƿ����޷�LU�ֽ⣡\n");
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
					printf("�þ����%d��˳������ʽΪ0���޷�����LU�ֽ⣡\n",m+1);
					exit(0);
				}
			}
			{
				ans=LU_(a,N);
				printf("�þ���LU�ֽ���L����Ϊ��\n");
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
				printf("�þ���LU�ֽ���U����Ϊ��\n");
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
				printf("��ѡ���Ƿ񽫴˽��������ļ���1.�� 2.�񣩣�");
				scanf("%d",&choose);
				if(choose==1)
				{
					printf("������������ļ���ַ��");
					scanf("%s",output);
					if((fp=fopen(output,"w"))==NULL)
					{
						printf("����ļ���ַ����\n");
						exit(0);
					}
					m=N;
					fprintf(fp,"�þ���LU�ֽ���L����Ϊ��\n");
					fprintf(fp,"%d %d\n",m,N);
					for(i=0;i<m;i++)
					{
						for(j=0;j<N;j++)
						{
							fprintf(fp,"%-10.3f",ans.d[i][j]);
						}
						fprintf(fp,"\n");
					}
					fprintf(fp,"�þ���LU�ֽ���U����Ϊ��\n");
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
			printf("�Ƿ���������������㣨1.��  2.��:");
			scanf("%d",&go);
			break;
		default:printf("��������\n");
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