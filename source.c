#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int total = 0;

struct person {
	char name[20];
	char phonenumber[20];
};
struct person p1[100];

void reg()
{
	char yesorno[2];
	for (int i=0; i<100; i++)
	{
		for (;;)
		{
			printf("***********************************************\n");
			printf("��� ȭ���Դϴ�. ����Ͻ� �̸��� ��ȣ�� ������� �Է��ϼ���.\n");
			printf("***********************************************\n");
			scanf("%s %s", p1[i].name, &(p1[i].phonenumber));
			if ((strcmp(p1[i].name, "") == 0) || (strcmp(p1[i].phonenumber, "") == 0))
			{
				printf("-----------------------------------\n");
				printf("�߸��� �Է��Դϴ�. �ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				return;
			}
			else if ((strcmp(p1[i].name, "") != 0) || (strcmp(p1[i].phonenumber, "") != 0))
			{
				total++;
				break;
			}
			//scanf("%s %ld", p1[i].name, &(p1[i].phonenumber));
			
		}
		printf("-----------------------------------\n");
		printf("����� �Ϸ�Ǿ����ϴ�.\n");
		printf("-----------------------------------\n");
		if (i < 99) {

			printf("-----------------------------------\n");
			printf("��ȭ��ȣ�� �� ����Ͻðڽ��ϱ�? Y / N\n");
			printf("-----------------------------------\n");
			scanf("%s", &yesorno);
			if (yesorno[0] == 'Y')
			{

				continue;
			}
			else if (yesorno[0] == 'N')
			{
				printf("-----------------------------------\n");
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				break;
			}
			else
			{
				printf("-----------------------------------\n");
				printf("������ �Է��� �ƴմϴ�. Y / N ���� �Է����ּ���.\n");
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				break;
			}
			
		}
	}
}
void edit()
{
	int index;
	printf("***********************************************\n");
	printf("���� ȭ���Դϴ�. ������ ���ϴ� �������� ��ȣ�� �Է��ϼ���.\n");
	printf("��ȣ �̿��� ���� �Է��ϸ� �����͸� ��ȸ�� �� �����Ƿ� ��ȣ�� �Է����ֽñ� �ٶ��ϴ�.\n");
	printf("***********************************************\n");
	for (int i = 0; i < total; i++)
	{

		printf("- - - - - - - - - -\n");
		printf("%d. \n", i + 1);
		printf("�̸� : %s\n", p1[i].name);
		printf("��ȭ��ȣ : %s\n", p1[i].phonenumber);
		printf("- - - - - - - - - -\n");
	}
	for (;;)
	{
		scanf("%d", &index);
		if (total < index)
		{
			printf("-----------------------------------\n");
			printf("�ش� �����Ͱ� �������� �ʽ��ϴ�.\n");
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
			break;
		}
		printf("-----------------------------------\n");
		printf("������ �̸��� ��ȭ��ȣ�� �ٽ� �Է��ϼ���.\n");
		printf("-----------------------------------\n");
		scanf("%s %s", p1[index - 1].name, &(p1[index - 1].phonenumber));
			if ((strcmp(p1[index - 1].name, "")) == 0 || ((strcmp(p1[index - 1].phonenumber, "")) == 0))
			{
				printf("-----------------------------------\n");
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				printf("-----------------------------------\n");
				continue;
			}
			else
		{
				printf("-----------------------------------\n");
				printf("������ ���������� ó���Ǿ����ϴ�.\n");
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				break;
		}
	}
}
void del()
{
	int index;
	char yesorno[2];

	printf("***********************************************\n");
	printf("���� ȭ���Դϴ�. ������ ���ϴ� �������� ��ȣ�� �Է��ϼ���.\n");
	printf("��ȣ �̿��� ���� �Է��ϸ� �����͸� ��ȸ�� �� �����Ƿ� ��ȣ�� �Է����ֽñ� �ٶ��ϴ�.\n");
	printf("***********************************************\n");
	for (int i = 0; i < total; i++)
	{

		printf("- - - - - - - - - -\n");
		printf("%d. \n", i + 1);
		printf("�̸� : %s\n", p1[i].name);
		printf("��ȭ��ȣ : %s\n", p1[i].phonenumber);
		printf("- - - - - - - - - -\n");

	}
	for (;;)
	{
		scanf("%d", &index);
		if (total < index)
		{
			printf("-----------------------------------\n");
			printf("�ش� �����Ͱ� �������� �ʽ��ϴ�.\n");
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
			break;
		}
		printf("-----------------------------------\n");
		printf("�� ��ȣ�� �����Ͻðڽ��ϱ�? Y / N\n");
		printf("�̸� : %s\n", p1[index - 1].name);
		printf("��ȭ��ȣ : %s\n", p1[index - 1].phonenumber);
		printf("-----------------------------------\n");
		scanf("%s", &yesorno);
		if (yesorno[0] == 'Y')
		{
			for (int arrnum = index - 1; arrnum < total - 1; arrnum++)
			{
				strcpy(p1[arrnum].name, p1[arrnum + 1].name);
				strcpy(p1[arrnum].phonenumber, p1[arrnum + 1].phonenumber);
			}
			strcpy(p1[total - 1].name, "");
			strcpy(p1[total - 1].phonenumber, "");
			total--;

			printf("-----------------------------------\n");
			printf("������ ���������� ó���Ǿ����ϴ�.\n");
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
			break;
		}
		else if (yesorno[0] == 'N')
		{
			printf("-----------------------------------\n");
			printf("������ ����߽��ϴ�.\n");
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
			break;
		}
		else
		{
			printf("-----------------------------------\n");
			printf("������ �Է��� �ƴմϴ�. Y / N ���� �Է����ּ���.\n");
			printf("�����ʹ� �������� �ʾҽ��ϴ�.\n");
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
			break;
		}
	}
}
void search()
{
	int index = 0;
	int selectnumber;
	char findnumber[20];
	char findname[20];
	int yon = 0;

	printf("***********************************************\n");
	printf("�˻� ȭ���Դϴ�. 1. ��ȭ��ȣ�� �˻� 2. �̸����� �˻�\n");
	printf("***********************************************\n");
	scanf("%d", &selectnumber);
	if (selectnumber == 1)
	{
		printf("-----------------------------------\n");
		printf("ã�⸦ ���ϴ� ��ȭ��ȣ�� �Է��ϼ���.\n");
		printf("-----------------------------------\n");
		scanf("%s", &findnumber);
		for (int i = 0; i < total ; i++)
		{
			if (strcmp(findnumber, p1[i].phonenumber) == 0)
			{
				printf("-----------------------------------\n");
				printf("�˻� ����� �̷����ϴ� :\n");
				printf("�̸� : %s\n", p1[i].name);
				printf("��ȭ��ȣ : %s\n", p1[i].phonenumber);
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				yon = 1;
				break;
			}
		}
		if (yon == 0)
		{
			printf("-----------------------------------\n");
			printf("�˻����� ������ �����Ͱ� �����ϴ�.\n");
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
		}
							
	}
	else if (selectnumber == 2)
	{
		printf("-----------------------------------\n");
		printf("ã�⸦ ���ϴ� �̸��� �Է��ϼ���.\n");
		printf("-----------------------------------\n");
		scanf("%s", &findname);
		for (int i = 0; i < total + 1; i++)
		{
			if (strcmp(findname, p1[i].name) == 0)
			{
				printf("-----------------------------------\n");
				printf("�˻� ����� �̷����ϴ� :\n");
				printf("�̸� : %s\n", p1[i].name);
				printf("��ȭ��ȣ : %s\n", p1[i].phonenumber);
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				yon = 1;
				break;
			}
		}
		if (yon == 0)
		{
			printf("-----------------------------------\n");
			printf("�˻����� ������ �����Ͱ� �����ϴ�.\n");
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
		}
	}
}
int main()
{
	int num=0;
	for(;;)
	{
		printf("***********************************************\n");
		printf("��ȭ��ȣ�� ���α׷��Դϴ�. ���ϴ� �޴��� �����ϼ���.\n");
		printf("�޴���ȣ �̿��� ���ڸ� �Է��ϸ� ���α׷��� ����˴ϴ�.\n");
		printf("1. ���\n");
		printf("2. ����\n");
		printf("3. ����\n");
		printf("4. �˻�\n");
		printf("5. ����\n");
		printf("***********************************************\n");
		scanf("%d", &num);
			switch (num)
			{
			case 1: // ���
				reg();
				continue;
			case 2: // ����
				edit();
				continue;
			case 3: // ����
				del();
				continue;
			case 4: // �˻�
				search();
				continue;
			case 5: // ����
				break;



			}
			break;
	}
	return 0;
	}

