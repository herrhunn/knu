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
			printf("등록 화면입니다. 등록하실 이름과 번호를 순서대로 입력하세요.\n");
			printf("***********************************************\n");
			scanf("%s %s", p1[i].name, &(p1[i].phonenumber));
			if ((strcmp(p1[i].name, "") == 0) || (strcmp(p1[i].phonenumber, "") == 0))
			{
				printf("-----------------------------------\n");
				printf("잘못된 입력입니다. 초기화면으로 돌아갑니다.\n");
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
		printf("등록이 완료되었습니다.\n");
		printf("-----------------------------------\n");
		if (i < 99) {

			printf("-----------------------------------\n");
			printf("전화번호를 더 등록하시겠습니까? Y / N\n");
			printf("-----------------------------------\n");
			scanf("%s", &yesorno);
			if (yesorno[0] == 'Y')
			{

				continue;
			}
			else if (yesorno[0] == 'N')
			{
				printf("-----------------------------------\n");
				printf("초기화면으로 돌아갑니다.\n");
				printf("-----------------------------------\n");
				break;
			}
			else
			{
				printf("-----------------------------------\n");
				printf("적합한 입력이 아닙니다. Y / N 으로 입력해주세요.\n");
				printf("초기화면으로 돌아갑니다.\n");
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
	printf("수정 화면입니다. 수정을 원하는 데이터의 번호를 입력하세요.\n");
	printf("번호 이외의 값을 입력하면 데이터를 조회할 수 없으므로 번호만 입력해주시기 바랍니다.\n");
	printf("***********************************************\n");
	for (int i = 0; i < total; i++)
	{

		printf("- - - - - - - - - -\n");
		printf("%d. \n", i + 1);
		printf("이름 : %s\n", p1[i].name);
		printf("전화번호 : %s\n", p1[i].phonenumber);
		printf("- - - - - - - - - -\n");
	}
	for (;;)
	{
		scanf("%d", &index);
		if (total < index)
		{
			printf("-----------------------------------\n");
			printf("해당 데이터가 존재하지 않습니다.\n");
			printf("초기화면으로 돌아갑니다.\n");
			printf("-----------------------------------\n");
			break;
		}
		printf("-----------------------------------\n");
		printf("수정할 이름과 전화번호를 다시 입력하세요.\n");
		printf("-----------------------------------\n");
		scanf("%s %s", p1[index - 1].name, &(p1[index - 1].phonenumber));
			if ((strcmp(p1[index - 1].name, "")) == 0 || ((strcmp(p1[index - 1].phonenumber, "")) == 0))
			{
				printf("-----------------------------------\n");
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");
				printf("-----------------------------------\n");
				continue;
			}
			else
		{
				printf("-----------------------------------\n");
				printf("수정이 성공적으로 처리되었습니다.\n");
				printf("초기화면으로 돌아갑니다.\n");
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
	printf("삭제 화면입니다. 삭제를 원하는 데이터의 번호를 입력하세요.\n");
	printf("번호 이외의 값을 입력하면 데이터를 조회할 수 없으므로 번호만 입력해주시기 바랍니다.\n");
	printf("***********************************************\n");
	for (int i = 0; i < total; i++)
	{

		printf("- - - - - - - - - -\n");
		printf("%d. \n", i + 1);
		printf("이름 : %s\n", p1[i].name);
		printf("전화번호 : %s\n", p1[i].phonenumber);
		printf("- - - - - - - - - -\n");

	}
	for (;;)
	{
		scanf("%d", &index);
		if (total < index)
		{
			printf("-----------------------------------\n");
			printf("해당 데이터가 존재하지 않습니다.\n");
			printf("초기화면으로 돌아갑니다.\n");
			printf("-----------------------------------\n");
			break;
		}
		printf("-----------------------------------\n");
		printf("이 번호를 삭제하시겠습니까? Y / N\n");
		printf("이름 : %s\n", p1[index - 1].name);
		printf("전화번호 : %s\n", p1[index - 1].phonenumber);
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
			printf("삭제가 성공적으로 처리되었습니다.\n");
			printf("초기화면으로 돌아갑니다.\n");
			printf("-----------------------------------\n");
			break;
		}
		else if (yesorno[0] == 'N')
		{
			printf("-----------------------------------\n");
			printf("삭제를 취소했습니다.\n");
			printf("초기화면으로 돌아갑니다.\n");
			printf("-----------------------------------\n");
			break;
		}
		else
		{
			printf("-----------------------------------\n");
			printf("적합한 입력이 아닙니다. Y / N 으로 입력해주세요.\n");
			printf("데이터는 삭제되지 않았습니다.\n");
			printf("초기화면으로 돌아갑니다.\n");
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
	printf("검색 화면입니다. 1. 전화번호로 검색 2. 이름으로 검색\n");
	printf("***********************************************\n");
	scanf("%d", &selectnumber);
	if (selectnumber == 1)
	{
		printf("-----------------------------------\n");
		printf("찾기를 원하는 전화번호를 입력하세요.\n");
		printf("-----------------------------------\n");
		scanf("%s", &findnumber);
		for (int i = 0; i < total ; i++)
		{
			if (strcmp(findnumber, p1[i].phonenumber) == 0)
			{
				printf("-----------------------------------\n");
				printf("검색 결과는 이렇습니다 :\n");
				printf("이름 : %s\n", p1[i].name);
				printf("전화번호 : %s\n", p1[i].phonenumber);
				printf("초기화면으로 돌아갑니다.\n");
				printf("-----------------------------------\n");
				yon = 1;
				break;
			}
		}
		if (yon == 0)
		{
			printf("-----------------------------------\n");
			printf("검색값에 적합한 데이터가 없습니다.\n");
			printf("초기화면으로 돌아갑니다.\n");
			printf("-----------------------------------\n");
		}
							
	}
	else if (selectnumber == 2)
	{
		printf("-----------------------------------\n");
		printf("찾기를 원하는 이름을 입력하세요.\n");
		printf("-----------------------------------\n");
		scanf("%s", &findname);
		for (int i = 0; i < total + 1; i++)
		{
			if (strcmp(findname, p1[i].name) == 0)
			{
				printf("-----------------------------------\n");
				printf("검색 결과는 이렇습니다 :\n");
				printf("이름 : %s\n", p1[i].name);
				printf("전화번호 : %s\n", p1[i].phonenumber);
				printf("초기화면으로 돌아갑니다.\n");
				printf("-----------------------------------\n");
				yon = 1;
				break;
			}
		}
		if (yon == 0)
		{
			printf("-----------------------------------\n");
			printf("검색값에 적합한 데이터가 없습니다.\n");
			printf("초기화면으로 돌아갑니다.\n");
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
		printf("전화번호부 프로그램입니다. 원하는 메뉴를 선택하세요.\n");
		printf("메뉴번호 이외의 문자를 입력하면 프로그램이 종료됩니다.\n");
		printf("1. 등록\n");
		printf("2. 수정\n");
		printf("3. 삭제\n");
		printf("4. 검색\n");
		printf("5. 종료\n");
		printf("***********************************************\n");
		scanf("%d", &num);
			switch (num)
			{
			case 1: // 등록
				reg();
				continue;
			case 2: // 수정
				edit();
				continue;
			case 3: // 삭제
				del();
				continue;
			case 4: // 검색
				search();
				continue;
			case 5: // 종료
				break;



			}
			break;
	}
	return 0;
	}

