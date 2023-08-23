#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int total_customer = 0; // ������ ȸ���� �ѿ� �ʱ�ȭ
int total_movie = 0; // ���� �Ѱ��� �ʱ�ȭ
int customer_restore = 0;
int movie_restore = 0;


struct customer { // �� ����ü�� ����
	char name[20]; // ����
	char phonenumber[20]; // ��ȭ��ȣ
	char rentmovname[30]; // �뿩 �� ���� �̸�
	char rentmovworks[20]; // �뿩 �� ���� ���ۻ�
	int rentprice; // �뿩 �� ���� �뿩��
};
struct customer* c1; // �� ����ü �迭�� ����

struct movie { // ���� ����ü�� ������
	char moviename[30]; // ������
	char movieworks[20]; // ���� ���ۻ�
	int price; // ���� �뿩��
	int status; // ������ ���� ���� (�뿩 ���� : 1, �뿩�� : 0)
};
struct movie* m1; // ���� ����ü �迭�� ����

void login(); // �α��� �Լ�
void mainmenu(); // ���θ޴� �Լ�
void fileout(); // ���� �Լ�
void filein(); // �ҷ����� �Լ�
void add_size(); // �迭 Ȯ�� �Լ�

void moviesearch() // ���� �˻� �Լ�
{
	if (total_movie == 0) //���̳� ���� �߿� �ϳ��� ������ ���� ����
	{
		printf("���� ������ �ȵ����Ƿ� �޴��� ���ư��ϴ�.\n");
		return;
	}
	char findmvname[20]; // ���� �˻��� ���� �Էº��� ����
	int yon = 0; // ���� �˻� ���� ���θ� ������ ���� ����

	printf("***********************************************\n");
	printf("���� �˻� ȭ���Դϴ�. ã�⸦ ���ϴ� ������ �̸��� �Է��ϼ���.\n");
	printf("***********************************************\n");
	printf("������ : ");
	scanf("%s", &findmvname); // ã���� �ϴ� �������� �Է¹޴´�
	for (int i = 0; i < total_movie; i++) // ��� ����ü ����� �Էµ� Ű���带 ���ϱ� ���� �ݺ���
	{
		if (strcmp(findmvname, m1[i].moviename) == 0) // �Է¹��� ������� ����� ������ �����Ͱ� ���� ��
		{
			printf("-----------------------------------\n"); // ã�� ������ ������ ���
			printf("�˻� ����� �̷����ϴ� :\n");
			printf("���� �̸� : %s\n", m1[i].moviename);
			printf("���ۻ� : %s\n", m1[i].movieworks);
			printf("�뿩�� : %d\n", m1[i].price);
			if (m1[i].status == 1) // ������ �뿩������ ������ ���
			{
				printf("���� : �뿩����\n");
			}
			else if (m1[i].status == 0) // ������ �뿩���� ������ ���
			{
				printf("���� : �뿩��\n");
			}
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
			yon = 1; // ���� �˻��� ������
			return; // �ش� �ݺ����� Ż��
		}

	}
	if (yon == 0) // ���� �˻��� ���� ��
	{
		printf("-----------------------------------\n"); // ���Է¿� ���� ������
		printf("�˻����� ������ �����Ͱ� �����ϴ�.\n");
		printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
		printf("-----------------------------------\n");
	}
}

void customersearch() // �� �˻� �Լ�
{
	if (total_customer == 0) //���� �ϳ��� ������ ���� ����
	{
		printf("���� ������ �ȵ����Ƿ� �޴��� ���ư��ϴ�.\n");
		return;
	}
	char findcsname[20]; // �� �˻��� ���� �Էº��� ����
	int yon = 0; // ���� �˻� ���� ���θ� ������ ���� ����

	printf("***********************************************\n");
	printf("�� �˻� ȭ���Դϴ�. ã�⸦ ���ϴ� ���� ������ �Է��ϼ���.\n");
	printf("***********************************************\n");
	printf("������ : ");
	scanf("%s", &findcsname); // ã���� �ϴ� �������� �Է¹޴´�
	for (int i = 0; i < total_customer; i++) // ��� ����ü ����� �Էµ� Ű���带 ���ϱ� ���� �ݺ���
	{
		if (strcmp(findcsname, c1[i].name) == 0) // �Է¹��� ������� ����� ������ �����Ͱ� ���� ��
		{
			printf("-----------------------------------\n"); // ã�� ���� ������ ���
			printf("�˻� ����� �̷����ϴ� :\n");
			printf("�� ���� : %s\n", c1[i].name);
			printf("��ȭ��ȣ : %s\n", c1[i].phonenumber);
			printf("�뿩���� ������ : %s\n", c1[i].rentmovname);
			printf("�뿩���� ���� ���ۻ� : %s\n", c1[i].rentmovworks);
			printf("�뿩���� ���� �뿩�� : %d\n", c1[i].rentprice);
			printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
			printf("-----------------------------------\n");
			yon = 1; // ���� �˻��� ������
			return; // �ش� �ݺ����� Ż��
		}

	}
	if (yon == 0) // ���� �˻��� ���� ��
	{
		printf("-----------------------------------\n"); // ���Է¿� ���� ������
		printf("�˻����� ������ �����Ͱ� �����ϴ�.\n");
		printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
		printf("-----------------------------------\n");
	}
}
void rent() // �뿩 �Լ�
{
	if (total_movie == 0) // ������ ������ ���� ���
	{
		printf("���� ������ ������ �����ϴ�. ������ �԰�ó�����ּ���.\n");
		return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
	}
	if (total_customer == 0) // ������ ���� ���� ���
	{
		printf("���� ȸ�����Ե� ���� �����ϴ�. ȸ������ó���� ���ּ���.\n");
		return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
	}
	int rent_unable = 0; // �뿩���� ������ ī��Ʈ�ϱ� ���� ���� ����
	for (int i = 0; i < total_movie; i++) // ������ ������ �뿩���¸� ��� Ȯ���ϱ� ���� �ݺ���
	{
		if (m1[i].status == 0) // ������ �뿩���� ���
		{
			rent_unable++; // �ش� ������ 1 ������Ŵ
		}
	}
	if (rent_unable == total_movie) // ��� ������ �뿩���� ���
	{
		printf("��� ������ �뿩���̹Ƿ� �뿩�� �Ұ��մϴ�.");
		return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
	}
	int search_movie = 0; // �뿩ó���� ������ �˻��� �� ����ϴ� �Էº��� ����
	int success = 0; // �뿩ó���� �������� �˻��� �������� �� �������θ� ������ ���� ����
	char yesorno; // Y Ȥ�� N�� �Է¹��� �� �ʿ��� �Էº��� ����
	char findcsname_rent[20]; // �뿩 �� �������� ã�� ���� ���̴� �Էº��� ����
	char findcsphonenumber_rent[20]; // // �뿩 �� ����ȭ��ȣ�� ã�� ���� ���̴� �Էº��� ����
	char findmovname_rent[30]; // �뿩 �� �������� ã�� ���� ���̴� �Էº��� ����

	printf("***********************************************\n");
	printf("�뿩 ȭ���Դϴ�. �뿩�� ������ ���� ����� ��ȭ��ȣ�� �Է��ϼ���.\n");
	printf("***********************************************\n");
	for (;;) // �뿩 �� �� ������ �ùٸ��� �Է����� ������ ��� �� �κ����� ���ƿ�
	{
		printf("���� : ");
		scanf("%s", findcsname_rent); // �뿩 �� �������� �Է¹���
		for (int i = 0; i < total_customer; i++) // ��� ����ü ����� �Էµ� Ű���带 ���ϱ� ���� �ݺ��� 
		{
			if (strcmp(findcsname_rent, c1[i].name) == 0) // �Է¹��� ������� ����� ������ �����Ͱ� ���� ��
			{
				printf("��ȭ��ȣ : ");
				scanf("%s", findcsphonenumber_rent); // �뿩 �� ����ȭ��ȣ�� �Է¹���
				if (strcmp(findcsphonenumber_rent, c1[i].phonenumber) == 0) // �Է¹��� ����ȭ��ȣ�� ����� ����ȭ��ȣ �����Ͱ� ���� ��
				{

					printf("-----------------------------------\n"); // �뿩�� ������ ������ ���
					printf("�뿩�� ������ ���� ã�ҽ��ϴ�.\n");
					printf("���� : %s\n", c1[i].name);
					printf("��ȭ��ȣ : %s\n", c1[i].phonenumber);
					printf("�뿩�� �����մϴ�.\n");
					printf("-----------------------------------\n");
					for (;;) // ���� ������ �ùٸ��� �Է����� ������ ��� �� �κ����� ���ƿ�
					{
						printf("-----------------------------------\n");
						printf("�뿩ó���� ������ ���� �̸��� �Է��ϼ���.\n");
						printf("-----------------------------------\n");
						printf("������ : ");
						scanf("%s", findmovname_rent);  // �뿩 �� �뿩�� �������� �Է¹���
						for (int j = 0; j < total_movie; j++) // ��� ����ü ����� �Էµ� Ű���带 ���ϱ� ���� �ݺ���
						{
							if (strcmp(findmovname_rent, m1[j].moviename) == 0) // �Է¹��� ������� ����� ������ �����Ͱ� ���� ��
							{
								search_movie = j; // j�� ������ ã������ ����ϴ� ����ü ��� ���� ������ �ʱ�ȭ
								success = 1; // ������ ã�Ƴ��� ���� ������
								break; // �ش� �ݺ����� Ż���ϰ� ���� �������� �Ѿ
							}
						}
						if (success == 1 && m1[search_movie].status == 1 && strcmp(c1[i].rentmovname, "�뿩���� ���� ����") == 0)	// ������ ã�Ƴ��� ���� �����ϰ� �ش� ������ �뿩������ ������ ��
						{
							printf("-----------------------------------\n"); // �뿩 �� ���� ������ �ٽ� �ѹ� Ȯ�ν�����
							printf("�� ������ �뿩ó���Ͻðڽ��ϱ�? Y / N\n");
							printf("������ : %s\n", m1[search_movie].moviename);
							printf("���ۻ� : %s\n", m1[search_movie].movieworks);
							printf("�뿩�� : %d\n", m1[search_movie].price);
							printf("-----------------------------------\n");
							scanf(" %c", &yesorno); // Y Ȥ�� N�� �Է¹���
							if (yesorno == 'Y' || yesorno == 'y') // Y Ȥ�� y�� �Է¹��� ��
							{
								printf("-----------------------------------\n"); // �뿩����, �뿩�� ���� ������ ���� �뿩�� ������ ������ ���������� ���
								printf("�뿩ó���� �Ϸ�Ǿ����ϴ�.\n");
								printf("-�뿩������-\n");
								printf("���� : %s\n", c1[i].name);
								printf("��ȭ��ȣ : %s\n", c1[i].phonenumber);
								printf("-�뿩��������-\n");
								strcpy(c1[i].rentmovname, m1[search_movie].moviename); //�� ����ü�� ���� ���� ���� ������ٰ� ����
								strcpy(c1[i].rentmovworks, m1[search_movie].movieworks);
								c1[i].rentprice = m1[search_movie].price;
								m1[search_movie].status = 0; // ������ '�뿩��' ���·� ��ȯ
								printf("������ : %s\n", c1[i].rentmovname);
								printf("���ۻ� : %s\n", c1[i].rentmovworks);
								printf("�뿩�� : %d\n", c1[i].rentprice);
								printf("-----------------------------------\n");
								add_size();
								fileout();
								return;	// �ش� ����� �����ϰ� ���θ޴��� ���ư�

							}
							else if (yesorno == 'N' || yesorno == 'n') // N Ȥ�� n�� �Է¹��� ��
							{
								printf("-----------------------------------\n");
								printf("�뿩�� ��ҵǾ����ϴ�.\n");
								printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
								printf("-----------------------------------\n");
								return;
							}
							else
							{
								printf("-----------------------------------\n"); // Y,y �� N,n�� �ƴ� �ٸ� ������ ������ �Է��Ͽ��� �� ��µǴ� ������
								printf("������ �Է��� �ƴմϴ�. Y / N ���� �Է����ּ���.\n");
								printf("�뿩�� ��ҵǾ����ϴ�.\n");
								printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
								printf("-----------------------------------\n");
								return;
							}
						}
						else if (success == 0) // ������ ã�Ƴ��� ���� �������� ���
						{
							printf("-----------------------------------\n");
							printf("�ش� ������ �������� �ʽ��ϴ�.\n");
							printf("-----------------------------------\n");
							continue; // �ش� �Լ� �ʱ�ȭ������ ���ư�
						}
						else if (m1[search_movie].status == 0 && strcmp(c1[i].rentmovname, "�뿩���� ���� ����") != 0) // (Ȯ���ʿ�) ������ �̹� �뿩���� ���
						{	//Ȯ���ʿ�
							printf("-----------------------------------\n");	//Ȯ���ʿ�
							printf("�ش� ������ �̹� �뿩���Դϴ�.\n");	//Ȯ���ʿ�
							printf("-----------------------------------\n");	//Ȯ���ʿ�
							continue;	//(Ȯ���ʿ�) �ش� �Լ� �ʱ�ȭ������ ���ư�
						}	//Ȯ���ʿ�
					}


				}
				else
				{
					printf("���� ��ȭ��ȣ�� �ùٸ��� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n"); // ���Է¿� ���� ������
					i--; // �ݺ��� ���������� ���� i �������� ���ҽ�Ŵ
					continue; // �ش� �Լ� �ʱ�ȭ������ ���ư�
				}
			}

		}
		printf("�ش� ���� ������ �������� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n");// ���Է¿� ���� ������
		continue; // �ش� �Լ� �ʱ�ȭ������ ���ư�
	}

}

void moviereturn() // �ݳ� �Լ�
{
	if (total_customer == 0 || total_movie == 0) //���̳� ���� �߿� �ϳ��� ������ ���� ����
	{
		printf("���� ������ �ȵ����Ƿ� �޴��� ���ư��ϴ�.\n");
		return;
	}
	char findmovname_return[30]; // �ݳ� �� �������� ã�� ���� ���̴� �Էº��� ����
	char yesorno;  // Y Ȥ�� N�� �Է¹��� �� �ʿ��� �Էº��� ����
	int search_movie = 0; // ������ ã������ ����ϴ� ����ü ��� ���� ���� ����
	int search_customer = 0; // ���� ����ü ����� �ε��� ���� �� ����ü ����� �ε��� ������ ��ȯ��ų �� ����ϴ� ���� ����
	int success = 0; // �ݳ�ó���� �������� �˻��� �������� �� �������θ� ������ ���� ����
	int index = 0; // �迭��ȣ ����

	for (;;) // ���� ������ �ùٸ��� �Է����� ������ ��� �� �κ����� ���ƿ�
	{
		printf("-----------------------------------\n");
		printf("�ݳ�ó���� ������ ���� �̸��� �Է��ϼ���.\n");
		printf("-----------------------------------\n");
		printf("������ : ");
		scanf("%s", findmovname_return); // �ݳ� �� �ݳ�ó���� �������� �Է¹���
		for (int i = 0; i < total_movie; i++) // ��� ����ü ����� �Էµ� Ű���带 ���ϱ� ���� �ݺ���
		{
			if (strcmp(findmovname_return, m1[i].moviename) == 0 && m1[i].status == 0) // �Է¹��� ������� ����� ������ �����Ͱ� ���� ��
			{
				search_movie = i; // ������ ã������ ����ϴ� ����ü ��� ���� ����
				success = 1; // ������ ã�Ƴ��� ���� ������
				break; // �ش� �ݺ����� Ż���ϰ� ���� �������� �Ѿ
			}

		}
		if (success == 1) // ������ ã�Ƴ��� ���� ������ ��
		{
			for (int i = 0; i < total_customer; i++) // ��� ����ü ���(���� �뿩�� ������)�� �Ǵٸ� ��� ����ü ���(������ ������)�� ���� ���ϱ� ���� �ݺ���
			{
				if (strcmp(c1[i].rentmovname, m1[search_movie].moviename) == 0) // ���� �뿩�� ������� ������ �������� ���� ���
				{
					search_customer = i; // ���� ����ü ����� �ε��� ���� �� ����ü ����� �ε��� ������ ��ȯ
				}
			}
			printf("-----------------------------------\n"); // �ݳ� �� ���� ������ �ٽ� �ѹ� Ȯ�ν�����
			printf("�� ������ �ݳ�ó���Ͻðڽ��ϱ�? Y / N\n");
			printf("-�뿩������-\n");
			printf("���� : %s\n", c1[search_customer].name);
			printf("��ȭ��ȣ : %s\n", c1[search_customer].phonenumber);
			printf("-�뿩��������-\n");
			printf("������ : %s\n", c1[search_customer].rentmovname);
			printf("���ۻ� : %s\n", c1[search_customer].rentmovworks);
			printf("�뿩�� : %d\n", c1[search_customer].rentprice);
			printf("-----------------------------------\n");
			scanf(" %c", &yesorno); // Y Ȥ�� N�� �Է¹���
			if (yesorno == 'Y' || yesorno == 'y') // Y Ȥ�� y�� �Է¹��� ��
			{
				strcpy(c1[search_customer].rentmovname, "�뿩���� ���� ����"); // �ݳ��Ǵ� ���� �̸��� �ʱⰪ���� ��������
				strcpy(c1[search_customer].rentmovworks, "�뿩���� ���� ����"); // �ݳ��Ǵ� ���� ���ۻ縦 �ʱⰪ���� ��������
				c1[search_customer].rentprice = 0; // �ݳ��Ǵ� ���� �뿩���� �ʱⰪ���� ��������

				m1[search_movie].status = 1; // �ش� ������ �ٽ� �뿩���ɻ���
				printf("-----------------------------------\n");
				printf("�ݳ�ó���� �Ϸ�Ǿ����ϴ�.\n");
				printf("-----------------------------------\n");
				add_size();
				fileout();
				return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
			}
			else if (yesorno == 'N' || yesorno == 'n') // N Ȥ�� n�� �Է¹��� ��
			{
				printf("-----------------------------------\n");
				printf("�ݳ��� ��ҵǾ����ϴ�.\n");
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
			}
			else
			{
				printf("-----------------------------------\n"); // Y,y �� N,n�� �ƴ� �ٸ� ������ ������ �Է��Ͽ��� �� ��µǴ� ������
				printf("������ �Է��� �ƴմϴ�. Y / N ���� �Է����ּ���.\n");
				printf("�ݳ��� ��ҵǾ����ϴ�.\n");
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
			}
		}
		else if (success == 0) // ������ �ݳ�ó���� �ʿ� ���� �̹� �뿩���ɻ����� ��
		{
			printf("-----------------------------------\n"); // ������ ���
			printf("�ش� ������ �߸� �Է��� �̸��̰ų� �ݳ�ó���� ���ʿ��� �����Դϴ�.\n");
			printf("-----------------------------------\n");
			continue; // �ش� �Լ� �ʱ�ȭ������ ���ư�
		}
	}
}
void noteall() // ��ȸ �Լ�
{
	if (total_customer == 0 || total_movie == 0) //���̳� ���� �߿� �ϳ��� ������ ���� ����
	{
		printf("���� ������ �ȵ����Ƿ� �޴��� ���ư��ϴ�.\n");
		return;
	}
	int selectitem; // ����ȸ �� ������ȸ �� �ϳ��� ���� �� ���� ����

	printf("***********************************************\n");
	printf("��ȸȭ���Դϴ�.\n");
	printf("1. ����ȸ\n");
	printf("2. ������ȸ\n");
	printf("***********************************************\n");
	scanf("%d", &selectitem); // 1�� Ȥ�� 2���� �Է¹���
	for (;;) // ��ȣ�� �ùٸ��� �Է����� ������ ��� �� �κ����� ���ƿ�
	{
		if (selectitem == 1) // 1���� �Է����� ���
		{
			if (total_customer == 0) // ���Ե� ���� �Ѹ� ���� ���
			{
				printf("���� ȸ�����Ե� ���� �����ϴ�. ȸ������ó���� ���ּ���.\n");
				return;
			}
			printf("-�������� ��� ǥ���մϴ�.-\n");
			for (int i = 0; i < total_customer; i++) // ����� ����ü ����� ��µ� �� �ְ� ��
			{
				printf("- - - - - - - - - -\n");
				printf("%d. \n", i + 1);
				printf("�̸� : %s\n", c1[i].name);
				printf("��ȭ��ȣ : %s\n", c1[i].phonenumber);
				printf("�뿩���� ������ : %s\n", c1[i].rentmovname);
				printf("�뿩���� ���� ���ۻ� : %s\n", c1[i].rentmovworks);
				printf("�뿩���� ���� �뿩�� : %d\n", c1[i].rentprice);
				printf("- - - - - - - - - -\n");
			}
			break;
		}
		else if (selectitem == 2) // 2���� �Է����� ���
		{
			if (total_movie == 0) // �԰�� ������ �ϳ��� ���� ���
			{
				printf("���� ������ ������ �����ϴ�. ������ �԰�ó�����ּ���.");
				return;
			}
			printf("-���������� ��� ǥ���մϴ�.-\n");
			for (int i = 0; i < total_movie; i++) // ����� ����ü ����� ��µ� �� �ְ� ��
			{
				printf("- - - - - - - - - -\n");
				printf("%d. \n", i + 1);
				printf("������ : %s\n", m1[i].moviename);
				printf("���ۻ� : %s\n", m1[i].movieworks);
				printf("�뿩�� : %d\n", m1[i].price);
				if (m1[i].status == 1) // ������ �뿩������ ������ ���
				{
					printf("���� : �뿩����\n");
					printf("- - - - - - - - - -\n");
				}
				else if (m1[i].status == 0) // ������ �뿩���� ������ ���
				{
					printf("���� : �뿩��\n");
					printf("- - - - - - - - - -\n");
				}
			}
			break; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
		}
		else
		{
			printf("-----------------------------------\n"); // ���Է¿� ���� ������
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			printf("-----------------------------------\n");
			return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
		}
	}
}
void join() // ȸ������ �Լ�
{
	char yesorno; // Y Ȥ�� N�� �Է¹��� �� �ʿ��� �Էº��� ����

	for (int i = total_customer; i < total_customer + 100; i++) // ȸ�������� �ѹ��� 100����� ������
	{
		printf("***********************************************\n");
		printf("ȸ�������� �մϴ�. ����Ͻ� ȸ���� ����� ��ȭ��ȣ�� ������� �Է��ϼ���.\n");
		printf("***********************************************\n");
		printf("���� : \n");
		scanf("%s", c1[i].name); // �������� �Է�
		if ((strcmp(c1[i].name, "") != 0)) // �������� ������ �ƴ� ���
		{
			printf("��ȭ��ȣ : \n");
			scanf("%s", c1[i].phonenumber);  // ����ȭ��ȣ�� �Է�
			if ((strcmp(c1[i].phonenumber, "") != 0)) // ����ȭ��ȣ�� ������ �ƴ� ���
			{
				strcpy(c1[i].rentmovname, "�뿩���� ���� ����"); // �뿩�� ���� ���� �ű԰��̹Ƿ� '�뿩�� ������' �� �ʱⰪ�� ����
				strcpy(c1[i].rentmovworks, "�뿩���� ���� ����"); // �뿩�� ���� ���� �ű԰��̹Ƿ� '�뿩�� ���� ���ۻ�' �� �ʱⰪ�� ����
				c1[i].rentprice = 0; // �뿩�� ���� ���� �ű԰��̹Ƿ� '�뿩�� ���� �뿩��' �� �ʱⰪ�� ����
				total_customer++; // �Ѱ����� ������Ŵ
				printf("-----------------------------------\n");
				printf("����� �Ϸ�Ǿ����ϴ�.\n");
				add_size();
				fileout();
				printf("ȸ������\n");
				printf("�̸� : %s\n", c1[i].name);
				printf("��ȭ��ȣ : %s\n", c1[i].phonenumber);
				printf("-----------------------------------\n");
				printf("ȸ���� �� ����Ͻðڽ��ϱ�? Y / N\n");
				printf("-----------------------------------\n");
				scanf(" %c", &yesorno); // Y Ȥ�� N�� �Է¹���
				if (yesorno == 'Y' || yesorno == 'y') // Y Ȥ�� y�� �Է¹��� ��
				{
					continue; // ȸ������ �߰� ����
				}
				else if (yesorno == 'N' || yesorno == 'n') // N Ȥ�� n�� �Է¹��� ��
				{
					printf("-----------------------------------\n");
					printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
					printf("-----------------------------------\n");
					return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
				}
				else
				{
					printf("-----------------------------------\n"); // ���Է¿� ���� ������
					printf("������ �Է��� �ƴմϴ�. Y / N ���� �Է����ּ���.\n");
					printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
					printf("-----------------------------------\n");
					return;
				}
			}
		}
	}
}
void control() // ���� ���� �Լ� (�԰�� ��� ��� ����)
{
	char findmvname[20]; // �������� ã�� �� ����ϴ� �Էº��� ����
	char yesorno; // Y Ȥ�� N�� �Է¹��� �� �ʿ��� �Էº��� ����
	int selectnumber; // �����԰�� ������� �� �ϳ��� ���� �� ���� ����
	int yon = 0; // ���� �˻� ���� ���θ� ������ ���� ����
	int index = 0; // ����ü ����� �迭��ȣ�� ������ ���� ����

	for (;;)
	{
		printf("***********************************************\n");
		printf("���� ����ȭ���Դϴ�.\n");
		printf("1. �����԰�\n");
		printf("2. �������\n");
		printf("***********************************************\n");
		scanf("%d", &selectnumber); // 1�� Ȥ�� 2���� �Է¹���
		for (int i = total_movie; i < total_movie + 100; i++) // ���� �԰�� �ѹ��� 100������ ������
		{
			if (selectnumber == 1) // 1���� �Է����� ���
			{
				printf("***********************************************\n");
				printf("������ �԰�ó���մϴ�. �԰��Ͻ� ������ ������� ���ۻ�, �뿩���� ������� �Է��ϼ���.\n");
				printf("***********************************************\n");
				printf("������ : \n");
				scanf("%s", m1[i].moviename); // �԰�ó���� �������� �Է�
				if (strcmp(m1[i].moviename, "") != 0) //�������� ������ �ƴ� ���
				{
					printf("���ۻ� : \n");
					scanf("%s", m1[i].movieworks); // �԰�ó���� ���� ���ۻ縦 �Է�
					if ((strcmp(m1[i].movieworks, "") != 0)) // ���� ���ۻ簡 ������ �ƴ� ���
					{
						printf("�뿩�� : \n");
						scanf("%d", &m1[i].price); // �԰�ó���� ������ �뿩���� �Է�
						if (m1[i].price != 0) // ���� �뿩���� 0���� �ƴ� ���
						{
							m1[i].status = 1;
							printf("-----------------------------------\n"); // �԰�ó���� ������ ������ Ȯ�� �� ���
							printf("����� �Ϸ�Ǿ����ϴ�.\n");
							printf("��������\n");
							printf("�̸� : %s\n", m1[i].moviename);
							printf("��ȭ��ȣ : %s\n", m1[i].movieworks);
							printf("��ȭ��ȣ : %d\n", m1[i].price);
							total_movie++;
							add_size();
							fileout();
							printf("-----------------------------------\n");
							printf("������ �� �԰��Ͻðڽ��ϱ�? Y / N\n");
							printf("-----------------------------------\n");
							scanf(" %c", &yesorno); // Y Ȥ�� N�� �Է¹���
						}
						if (yesorno == 'Y' || yesorno == 'y') // Y Ȥ�� y�� �Է¹��� ��
						{
							continue; // ���� �԰�ȭ������ ���ư� �߰��� �԰�ó���� �ϰ� ��
						}
						else if (yesorno == 'N' || yesorno == 'n')  // N Ȥ�� n�� �Է¹��� ��
						{
							printf("-----------------------------------\n");
							printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
							printf("-----------------------------------\n");
							return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
						}
						else
						{
							printf("-----------------------------------\n");
							printf("������ �Է��� �ƴմϴ�. Y / N ���� �Է����ּ���.\n");
							printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
							printf("-----------------------------------\n");
							return;
						}
					}
				}
			}
			else if (selectnumber == 2)
			{
				if (customer_restore == 0 || movie_restore == 0) //�� �����ͳ� ���� ������ �߿� �ϳ��� ������ �� �ƴٸ� ���� ����
				{
					printf("���� ������ �ȵ����Ƿ� �޴��� ���ư��ϴ�.\n");
					return;
				}
				if (total_movie == 0)
				{
					printf("�԰�� ������ �����ϴ�. �ʱ�ȭ������ ���ư��ϴ�.\n");
					return;
				}
				printf("***********************************************\n");
				printf("������ ����մϴ�. ��⸦ ���ϴ� �������� �Է����ּ���.\n");
				printf("***********************************************\n");
				scanf("%s", &findmvname); // ���ó���� �������� �Է¹���
				for (int i = 0; i < total_movie; i++) // ��� ����ü ����� �Էµ� Ű���带 ���ϱ� ���� �ݺ���
				{
					if (strcmp(findmvname, m1[i].moviename) == 0 && m1[i].status == 1)  // (Ȯ�� �ʿ�) // �Է¹��� ������� ����� ������ �����Ͱ� ���� ��
					{

						printf("-----------------------------------\n"); // ���ó���� ���� ������ Ȯ�� �� �����
						printf("�ش� ������ ���ó���Ͻðڽ��ϱ�? Y / N\n");
						printf("���� �̸� : %s\n", m1[i].moviename);
						printf("���ۻ� : %s\n", m1[i].movieworks);
						printf("�뿩�� : %d\n", m1[i].price);
						printf("-----------------------------------\n");
						yon = 1; // ���ó���� ������ �˻��ϴ� ���� ������
						scanf(" %c", &yesorno); // Y Ȥ�� N�� �Է¹���
						if (yesorno == 'Y' || yesorno == 'y') // Y Ȥ�� y�� �Է¹��� ��
						{
							for (int arrnum = i; arrnum < total_movie - 1; arrnum++) // �����Ͱ� �����ϴ� ����ü ������� �ݺ�
							{
								strcpy(m1[arrnum].moviename, m1[arrnum + 1].moviename); // ����ó���� �迭 ��� �ڿ� �ִ� ������� ������ ����� (������)
								strcpy(m1[arrnum].movieworks, m1[arrnum + 1].movieworks); // ����ó���� �迭 ��� �ڿ� �ִ� ������� ������ ����� (���ۻ�)
								m1[arrnum].price = m1[arrnum + 1].price; // ����ó���� �迭 ��� �ڿ� �ִ� ������� ������ ����� (�뿩��)

							}
							total_movie--; // ������ ���ó���Ǿ����� �� ���� ������ �ϳ� ���ҽ�Ŵ
							add_size();
							fileout();
							printf("-----------------------------------\n");
							printf("��Ⱑ ���������� ó���Ǿ����ϴ�.\n");
							printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
							printf("-----------------------------------\n");
							return; // �ش� ����� �����ϰ� ���θ޴��� ���ư�
						}
						else if (yesorno == 'N' || yesorno == 'n')  // N Ȥ�� n�� �Է¹��� ��
						{
							printf("-----------------------------------\n");
							printf("��⸦ ����߽��ϴ�.\n");
							printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
							printf("-----------------------------------\n");
							return;
						}
						else
						{
							printf("-----------------------------------\n"); // ���Է¿� ���� ������
							printf("������ �Է��� �ƴմϴ�. Y / N ���� �Է����ּ���.\n");
							printf("������ ���ó���� ��ҵǾ����ϴ�.\n");
							printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
							printf("-----------------------------------\n");
							break;
						}
					}
					else if (strcmp(findmvname, m1[i].moviename) == 0 && m1[i].status == 0) // ����Ϸ��� ������ ���� �뿩���� ���

						printf("-----------------------------------\n");
					printf("�ش� ������ ���� �뿩���� �����Դϴ�. �ݳ�ó�� �� ������ּ���.\n");
					printf("������ ���ó���� ��ҵǾ����ϴ�.\n");
					printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
					printf("-----------------------------------\n");
					return;
				}

			}
			if (yon == 0) // ���ó���� ���� �����Ͱ� ���� ��
			{
				printf("-----------------------------------\n"); // ���Է¿� ���� ������
				printf("�˻����� ������ �����Ͱ� �����ϴ�.\n");
				printf("�ʱ�ȭ������ ���ư��ϴ�.\n");
				printf("-----------------------------------\n");
				return;
			}

		}
	}

}
void customer_filein()
{
	FILE* fp;
	char temp1[20];
	char temp2[30];
	char temp;

	int temp3;
	//�� �ҷ�����
	fp = fopen("customer.txt", "r");
	while ((temp = fgetc(fp)) != EOF)
	{
		if (temp == '\n')
		{
			total_customer++;
		}
	}
	total_customer /= 5;
	fclose(fp);
	fp = fopen("customer.txt", "r");
	for (int i = 0; i < total_customer; i++)
	{
		fgets(temp1, 20, fp);
		temp1[strlen(temp1) - 1] = '\0';
		strcpy(c1[i].name, temp1);

		fgets(temp1, 20, fp);
		temp1[strlen(temp1) - 1] = '\0';
		strcpy(c1[i].phonenumber, temp1);

		fgets(temp2, 30, fp);
		temp2[strlen(temp2) - 1] = '\0';
		strcpy(c1[i].rentmovname, temp2);

		fgets(temp1, 20, fp);
		temp1[strlen(temp1) - 1] = '\0';
		strcpy(c1[i].rentmovworks, temp1);

		fgets(temp1, 20, fp);
		temp1[strlen(temp1) - 1] = '\0';
		temp3 = atoi(temp1);
		c1[i].rentprice = temp3;
	}
	fclose(fp);
	customer_restore = 1;
}
void movie_filein()
{
	FILE* fp;
	char temp1[20];
	char temp2[30];
	char temp;

	int temp3;
	//�� �ҷ�����
	fp = fopen("movie.txt", "r");
	while ((temp = fgetc(fp)) != EOF)
	{
		if (temp == '\n')
		{
			total_movie++;
		}
	}
	total_movie /= 4;
	fclose(fp);
	fp = fopen("movie.txt", "r");
	for (int i = 0; i < total_movie; i++)
	{
		fgets(temp2, 30, fp);
		temp2[strlen(temp2) - 1] = '\0';
		strcpy(m1[i].moviename, temp2);

		fgets(temp1, 20, fp);
		temp1[strlen(temp1) - 1] = '\0';
		strcpy(m1[i].movieworks, temp1);

		fgets(temp1, 20, fp);
		temp1[strlen(temp1) - 1] = '\0';
		temp3 = atoi(temp1);
		m1[i].price = temp3;

		fgets(temp1, 20, fp);
		temp1[strlen(temp1) - 1] = '\0';
		temp3 = atoi(temp1);
		m1[i].status = temp3;
	}
	fclose(fp);
	movie_restore = 1;
}

void customer_fileout()
{
	FILE* fp;
	fp = fopen("customer.txt", "w");
	for (int i = 0; i < total_customer; i++)
	{
		fprintf(fp, "%s\n", c1[i].name);
		fprintf(fp, "%s\n", c1[i].phonenumber);
		fprintf(fp, "%s\n", c1[i].rentmovname);
		fprintf(fp, "%s\n", c1[i].rentmovworks);
		fprintf(fp, "%d\n", c1[i].rentprice);
	}
	fclose(fp);
	customer_restore = 1;
	return;
}
void movie_fileout()
{
	FILE* fp;
	fp = fopen("movie.txt", "w");
	for (int i = 0; i < total_movie; i++)
	{
		fprintf(fp, "%s\n", m1[i].moviename);
		fprintf(fp, "%s\n", m1[i].movieworks);
		fprintf(fp, "%d\n", m1[i].price);
		fprintf(fp, "%d\n", m1[i].status);
	}
	fclose(fp);
	movie_restore = 1;
	return;
}

void filein() //�ҷ����� �Լ�
{
	FILE* fp1;
	FILE* fp2;

	fp1 = fopen("customer.txt", "r");
	fp2 = fopen("movie.txt", "r");

	if (fp1 == NULL && fp2 == NULL)
	{
		//printf("fail");
		return;
	}
	else if (fp1 != NULL && fp2 == NULL)
	{
		customer_filein();
		printf("");
		return;
	}
	else if (fp1 == NULL && fp2 != NULL)
	{
		movie_filein();
		printf("");
		return;
	}
	else if (fp1 != NULL && fp2 != NULL)
	{
		customer_filein();
		movie_filein();
		printf("");
		return;
	}
}
void fileout() //���� �Լ�
{
	if (total_customer == 0 && total_movie == 0)
	{
		printf("");
		return;
	}
	else if (total_customer != 0 && total_movie == 0)
	{
		customer_fileout();
		printf("");
		return;
	}
	else if (total_customer == 0 && total_movie != 0)
	{
		movie_fileout();
		printf("");
		return;
	}
	else if (total_customer != 0 && total_movie != 0)
	{
		customer_fileout();
		movie_fileout();
		printf("");
		return;
	}
}

void add_size() // ����ü �迭�� ũ�⸦ �ø��� �Լ�
{
	int add_total = 1000; // �ѹ� �ø� �� 1000���� �ø�
	if (total_customer > 90) // �Ѱ����� 90�� �Ѿ��� ���
	{
		realloc(c1, sizeof(struct customer) * add_total); // �� ����ü �迭�� 1000�� �ø�
	}
	if (total_movie > 90) // �Ѻ��������� 90�� �Ѿ��� ���
	{
		realloc(m1, sizeof(struct movie) * add_total); // ���� ����ü �迭�� 1000�� �ø�
	}
}


void mainmenu() // ���θ޴� �Լ�
{
	int num = 0; // �޴���ȣ�� �����ϱ� ���� �Էº��� ����
	for (;;) // �� ����� ������ �ٽ� ���ƿ� �ٸ� ��ɵ� �� �� �ְ� �ݺ�
	{
		printf("*********************************************\n");
		printf("���ƺ����� ���� ���� ȯ���մϴ�.\n");
		printf("���Ͻô� �޴��� �����ϼ���.\n");
		printf("1. �����˻�\n");
		printf("2. ���˻�\n");
		printf("3. ���� �뿩\n");
		printf("4. �ݳ�\n");
		printf("5. ��ȸ\n");
		printf("6. ȸ������\n");
		printf("7. ���� ����\n");
		printf("8. ����\n");
		printf("*********************************************\n");
		scanf("%d", &num); // �޴���ȣ�� �Է¹���
		switch (num) // �޴������� ���� switch��
		{
		case 1: // ���� �˻�
			moviesearch();
			continue;
		case 2: //  �� �˻�
			customersearch();
			continue;
		case 3: // ���� �뿩
			rent();
			continue;
		case 4: // ���� �ݳ�
			moviereturn();
			continue;
		case 5: // ��ȸ
			noteall();
			continue;
		case 6: // ȸ������
			join();
			continue;
		case 7: // ���� ����
			control();
			continue;
		case 8: // ����
			add_size();
			fileout();
			free(c1);
			free(m1);
			break;
		default: // �ٸ� ��ȣ�� �Է����� ��
			printf("�߸��� �Է��Դϴ�. �ùٸ� �޴���ȣ�� �Է����ּ���!\n");
			continue;
		}
		break; // �ݺ������� Ż�� �� ���α׷� ����
	}
}
void login() // �α��� �Լ�
{
	char ID[10]; // ������ID���� ����
	char PW[10]; // ��й�ȣ���� ����

	for (int i = 0; i < 1;) // �α��ο� �����ϸ� Ż���ϴ� �ݺ���
	{
		printf("������ �α����� ���ּ���.\n");
		printf("ID : ");
		scanf("%s", ID); // ������ID�� �Է¹���
		for (;;) // �ùٸ� �Է��� ���� ���� ��� �� �������� ��� ���ƿ�
		{
			if (strcmp(ID, "admin") == 0 || strcmp(ID, "ADMIN") == 0) // ������ID "admin" Ȥ�� "ADMIN"���� �ùٸ��� �Է����� ���
			{
				printf("��ȣ : ");
				scanf("%s", &PW); // ��й�ȣ�� �Է¹���
				if (strcmp(PW, "1234") == 0) // ��й�ȣ "1234"�� �ùٸ��� �Է����� ���
				{
					i++; // �ݺ��� Ż���� ���� i������ 1�� ������Ŵ
					printf("�α��ο� �����߽��ϴ�.\n");
					return; // �ش� ����� �����ϰ� �����Լ��� ���ư�
				}
				else
				{
					printf("��й�ȣ�� �ùٸ��� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n"); // ���Է¿� ���� ������
					continue;
				}
			}
			else
			{
				printf("ID�� �ùٸ��� �ʽ��ϴ�. �ٽ� �Է����ּ���.\n"); // ���Է¿� ���� ������
				break;
			}
		}
	}
}
