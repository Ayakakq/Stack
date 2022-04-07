#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#define STACK_INIT_SIZE 100		//��ʼ�洢�ռ�
#define STACKINCREMENT 10		//�ռ�������С
using namespace std;

typedef struct
{
	char* base;					//ջ��ָ��
	char* top;					//ջ��ָ��
	int stacksize;				//ջ�����������
}SqStack;

//��ʼ��һ��ջ
void IntStack(SqStack &S)
{
	S.base = (char*)malloc(STACK_INIT_SIZE * sizeof(char));
	if (!S.base)
	{  
		printf("\nStack Overflow.\n");
		return;
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	printf("\nStack Initialization Succeeded\n");
}

//��ջ  e
void Push(SqStack &S, char e)			//eΪ��ջ��Ԫ��			eg:  Push(S,11);
{
	if (S.top - S.base == S.stacksize)
	{
		char *newBase;
		newBase = (char*)realloc((S.base), (S.stacksize + STACKINCREMENT) * sizeof(char));
		if (!newBase)
		{
			printf("\nNewbase Crease Fail\n");
			return;
		}
		S.base = newBase;
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top = e;
	S.top++;
	//printf("\nNewbase Crease Succeeded\n");
}

//��ջ
char Pop(SqStack &S)
{
	/*
	if (S.top == S.base)
	{
		printf("\nջΪ�գ�ɾ��ʧ�ܡ�\n");
		return '0';
	}	
	*/
	--S.top;
	char e = *(S.top);
	//printf("\n�ѳɹ�ɾ��ջ��Ԫ�� %c\n", e);
	return e;
}

//ȡջ��Ԫ��
char GetTop(SqStack &S)
{
	char e;
	if (S.top == S.base)
	{
		printf("\nջΪ�գ�ȡֵʧ�ܡ�\n");
		return false;
	}
	e = *(S.top-1);
	return e;
}

//����ջ����
int StackLength(SqStack S)
{
	return S.top - S.base;
}

//�����Ƿ�Ϊ��ջ
bool StackEmpty(SqStack S)
{
	if (StackLength(S) == 0)
		return true;
	else
		return false;
}

//����&���ջ
int OutPut(SqStack* S) {
	char* p;

	if (S->top == S->base) {
		printf("Stack is NULL.\n");
		return 0;
	}
	p = S->top;
	// ��ջ���������±���
	while (p > S->base) {
		p--;
		printf("%c ", *p);
	}
	printf("\n");
	return 1;
}

//UI����
void UI(SqStack &S)
{
	int commend;
	printf("��ѡ�������Ҫ���еĲ�����\n");
	printf("----------------------\n");
	printf("1����Ԫ��ѹջ\n");
	printf("2����ջ\n");
	printf("3��ȡջ��Ԫ��\n");
	printf("4���鿴ջ����\n");
	printf("5�����ջ�Ƿ�Ϊ��\n");
	printf("6������&���ջ��Ԫ��\n");
	printf("0���˳��ó���\n");
	commend = (int)getch() - 48;
	system("cls");

	switch (commend)
	{
	case 1: {
		printf("������ѹջԪ�ظ�����");
		int cout = (int)getch() - 48;
		printf("%d\n", cout);
		for (int i = 0;i < cout;i++)
		{
			printf("\n�������%d��Ԫ�أ�", i + 1);
			char temp = getch();
			printf("%c\n", temp);
			Push(S, temp);
		}
		printf("\nѹջ����ɣ�����������ء�\n");
	}
		  break;
	case 2: {
		S.top != S.base?printf("Ԫ��%c�ѳ�ջ\n\n�����������", Pop(S)):printf("ջΪ�գ�ɾ��ʧ�ܡ�\n\n�����������");
	}
		  break;
	case 3: {
		printf("\nջ��Ԫ��Ϊ��%c\n", GetTop(S));
	}
		  break;
	case 4: {
		printf("\nջ�ĳ���Ϊ��%d\n", StackLength(S));
	}
		  break;
	case 5: {
		cout <<endl<< "ջ�Ƿ�Ϊ��:" << boolalpha << StackEmpty(S) << endl;
	}
		  break;
	case 6: {
		OutPut(&S);
	}
		  break;
	case 0:exit(1);
		break;
	default: {
		printf("\n�������ָ����������������0~6֮�������");
	}
		break;
	}
	getch();
}

int main()
{
	int commend;
	char e;
	SqStack S;
	IntStack(S);
	printf("˳��ջ�ѳ�ʼ��\n");
	cout << "ջ�Ƿ�Ϊ��:" << boolalpha << StackEmpty(S) << endl;
	while (1)
	{
		system("cls");
		UI(S);
	}
}