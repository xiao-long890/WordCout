#include <stdio.h>
#include <string.h>
//ͳ���ַ���
void CharCount()
{
    FILE *fp;
    int charCount = 0;
    char ch;//��ȡ�ļ����ص��ֽ�
    if((fp = fopen("E:/test.txt","r")) == NULL)
    {
        printf("�ļ���ʧ��.");
    }
    ch = fgetc(fp);
    while(ch != EOF)
    {
            charCount++;
            ch = fgetc(fp);
    }
    printf("�ַ���Ϊ��%d��.\n",charCount);
    fclose(fp);
}


//ͳ�Ƶ�����
void WordCount() 
{
    FILE *fp;
    int wordCount = 0,flag=0;
    char ch;//��ȡ�ļ����ص��ֽ�
    if((fp = fopen("E:/test.txt","r")) == NULL){
        printf("�ļ���ʧ��.");
    }
    ch = fgetc(fp);
    while(ch != EOF){
        if (ch==' '){
			flag=0;
            ch = fgetc(fp);  
        }
        else {   
			if(flag==0){
				wordCount ++;	
				flag=1;
			}
            ch = fgetc(fp);
        }
    }
    printf("������Ϊ��%d��.\n",wordCount);
    fclose(fp);
}

int main(int argc,char *argv[])
{
	//ͳ���ַ���
    if ((strcmp(argv[1], "-c") == 0) && (strcmp(argv[2], "test.txt") == 0))
    {
        CharCount();
    }
    //ͳ�Ƶ�����
    if ((strcmp(argv[1], "-w") == 0) && (strcmp(argv[2], "test.txt") == 0))
    {
        WordCount();
    }
    
    return 0;
}
