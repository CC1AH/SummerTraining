#include<stdio.h>

void sort(int a[],int n){
	int i,j;
	for(i =0;i<n;i++){
		for(j = 0;j<n-1;j++){
			if(a[j]<a[j+1]){
				int tmp =a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}
}

int main(){
	int stu[3][6];
	int i =0, j =0;
	int sum[5] ={0};
	int average[5] ={0};
	for(;i<3;i++){
		printf("请输入学号：") ;
		scanf("%d",&stu[i][0]);
		printf("请输入高数成绩：");
		scanf("%d",&stu[i][1]);
		printf("请输入计算机成绩：");
		scanf("%d",&stu[i][2]);
		printf("请输入英语成绩：");
		scanf("%d",&stu[i][3]);
		printf("请输入经济学成绩："); 
		scanf("%d",&stu[i][4]);
		printf("请输入思修成绩："); 
		scanf("%d",&stu[i][5]);
		printf("\n"); 
	}
	for(i =0;i<3;i++){
		for(j =1;j<=5;j++){
			sum[i]+=stu[i][j]; 
		}
	}
	for(i =0;i<3;i++){
		average[i] = sum[i]/5;
	}
	printf("学号\t高数\t计算机\t英语\t经济学\t思修\t总分\t平均分\n");
	for(i =0;i<3;i++){
		for(j =0;j<6;j++){
			printf("%d\t",stu[i][j]);
		}
		printf("%d\t",sum[i]);
		printf("%d\t",average[i]);
		printf("\n");
		} 
	int math[3]={stu[0][1],stu[1][1],stu[2][1]};
	int comp[3]={stu[0][2],stu[1][2],stu[2][2]};
	int engl[3]={stu[0][3],stu[1][3],stu[2][3]};
	int econ[3]={stu[0][4],stu[1][4],stu[2][4]};
	int sixi[3]={stu[0][5],stu[1][5],stu[2][5]};
	sort(math,3);
	sort(comp,3);
	sort(engl,3);
	sort(econ,3);
	sort(sixi,3);
	int  max[5] ={math[0],comp[0],engl[0],econ[0],sixi[0]};
	int  min[5] ={math[2],comp[2],engl[2],econ[2],sixi[2]};
	for(i =0;i<5;i++){
		sum[3]+=max[i];
		sum[4]+=min[i];
	}
	for(i =0;i<5;i++){
		average[3] = sum[3]/5;
		average[4] = sum[4]/5;
	}
	
	printf("最大值：");
	for(i =0;i<5;i++){
		printf("%d\t",max[i]);
	} 
	printf("%d\t",sum[3]);
	printf("%d\t",average[3]);
	printf("\n");
	
	printf("最小值：");
	for(i =0;i<5;i++){
		printf("%d\t",min[i]);
	} 
	printf("%d\t",sum[4]);
	printf("%d\t",average[4]);
	
	return 0;
}
