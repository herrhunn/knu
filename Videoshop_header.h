#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int total_customer = 0; // 가입한 회원의 총원 초기화
int total_movie = 0; // 비디오 총갯수 초기화
int customer_restore = 0;
int movie_restore = 0;


struct customer { // 고객 구조체를 선언
	char name[20]; // 성명
	char phonenumber[20]; // 전화번호
	char rentmovname[30]; // 대여 시 비디오 이름
	char rentmovworks[20]; // 대여 시 비디오 제작사
	int rentprice; // 대여 시 비디오 대여가
};
struct customer* c1; // 고객 구조체 배열을 선언

struct movie { // 비디오 구조체를 선언함
	char moviename[30]; // 비디오명
	char movieworks[20]; // 비디오 제작사
	int price; // 비디오 대여가
	int status; // 비디오의 상태 변수 (대여 가능 : 1, 대여중 : 0)
};
struct movie* m1; // 비디오 구조체 배열을 선언

void login(); // 로그인 함수
void mainmenu(); // 메인메뉴 함수
void fileout(); // 저장 함수
void filein(); // 불러오기 함수
void add_size(); // 배열 확장 함수

void moviesearch() // 비디오 검색 함수
{
	if (total_movie == 0) //고객이나 비디오 중에 하나라도 없으면 돌려 보냄
	{
		printf("파일 복원이 안됐으므로 메뉴로 돌아갑니다.\n");
		return;
	}
	char findmvname[20]; // 비디오 검색을 위한 입력변수 선언
	int yon = 0; // 비디오 검색 성공 여부를 가리는 변수 선언

	printf("***********************************************\n");
	printf("비디오 검색 화면입니다. 찾기를 원하는 비디오의 이름을 입력하세요.\n");
	printf("***********************************************\n");
	printf("비디오명 : ");
	scanf("%s", &findmvname); // 찾고자 하는 비디오명을 입력받는다
	for (int i = 0; i < total_movie; i++) // 모든 구조체 멤버와 입력된 키워드를 비교하기 위한 반복문
	{
		if (strcmp(findmvname, m1[i].moviename) == 0) // 입력받은 비디오명과 저장된 비디오명 데이터가 같을 시
		{
			printf("-----------------------------------\n"); // 찾던 비디오의 정보를 출력
			printf("검색 결과는 이렇습니다 :\n");
			printf("비디오 이름 : %s\n", m1[i].moviename);
			printf("제작사 : %s\n", m1[i].movieworks);
			printf("대여가 : %d\n", m1[i].price);
			if (m1[i].status == 1) // 비디오가 대여가능한 상태일 경우
			{
				printf("상태 : 대여가능\n");
			}
			else if (m1[i].status == 0) // 비디오가 대여중인 상태일 경우
			{
				printf("상태 : 대여중\n");
			}
			printf("초기화면으로 돌아갑니다.\n");
			printf("-----------------------------------\n");
			yon = 1; // 비디오 검색에 성공함
			return; // 해당 반복문을 탈출
		}

	}
	if (yon == 0) // 비디오 검색에 실패 시
	{
		printf("-----------------------------------\n"); // 오입력에 대한 오류문
		printf("검색값에 적합한 데이터가 없습니다.\n");
		printf("초기화면으로 돌아갑니다.\n");
		printf("-----------------------------------\n");
	}
}

void customersearch() // 고객 검색 함수
{
	if (total_customer == 0) //고객이 하나라도 없으면 돌려 보냄
	{
		printf("파일 복원이 안됐으므로 메뉴로 돌아갑니다.\n");
		return;
	}
	char findcsname[20]; // 고객 검색을 위한 입력변수 선언
	int yon = 0; // 비디오 검색 성공 여부를 가리는 변수 선언

	printf("***********************************************\n");
	printf("고객 검색 화면입니다. 찾기를 원하는 고객의 성명을 입력하세요.\n");
	printf("***********************************************\n");
	printf("고객성명 : ");
	scanf("%s", &findcsname); // 찾고자 하는 고객성명을 입력받는다
	for (int i = 0; i < total_customer; i++) // 모든 구조체 멤버와 입력된 키워드를 비교하기 위한 반복문
	{
		if (strcmp(findcsname, c1[i].name) == 0) // 입력받은 고객성명과 저장된 고객성명 데이터가 같을 시
		{
			printf("-----------------------------------\n"); // 찾던 고객의 정보를 출력
			printf("검색 결과는 이렇습니다 :\n");
			printf("고객 성명 : %s\n", c1[i].name);
			printf("전화번호 : %s\n", c1[i].phonenumber);
			printf("대여중인 비디오명 : %s\n", c1[i].rentmovname);
			printf("대여중인 비디오 제작사 : %s\n", c1[i].rentmovworks);
			printf("대여중인 비디오 대여가 : %d\n", c1[i].rentprice);
			printf("초기화면으로 돌아갑니다.\n");
			printf("-----------------------------------\n");
			yon = 1; // 비디오 검색에 성공함
			return; // 해당 반복문을 탈출
		}

	}
	if (yon == 0) // 비디오 검색에 실패 시
	{
		printf("-----------------------------------\n"); // 오입력에 대한 오류문
		printf("검색값에 적합한 데이터가 없습니다.\n");
		printf("초기화면으로 돌아갑니다.\n");
		printf("-----------------------------------\n");
	}
}
void rent() // 대여 함수
{
	if (total_movie == 0) // 보유한 비디오가 없을 경우
	{
		printf("아직 보유한 비디오가 없습니다. 비디오를 입고처리해주세요.\n");
		return; // 해당 기능을 종료하고 메인메뉴로 돌아감
	}
	if (total_customer == 0) // 가입한 고객이 없을 경우
	{
		printf("아직 회원가입된 고객이 없습니다. 회원가입처리를 해주세요.\n");
		return; // 해당 기능을 종료하고 메인메뉴로 돌아감
	}
	int rent_unable = 0; // 대여중인 비디오를 카운트하기 위한 변수 선언
	for (int i = 0; i < total_movie; i++) // 보유한 비디오의 대여상태를 모두 확인하기 위한 반복문
	{
		if (m1[i].status == 0) // 비디오가 대여중일 경우
		{
			rent_unable++; // 해당 변수를 1 증가시킴
		}
	}
	if (rent_unable == total_movie) // 모든 비디오가 대여중일 경우
	{
		printf("모든 비디오가 대여중이므로 대여가 불가합니다.");
		return; // 해당 기능을 종료하고 메인메뉴로 돌아감
	}
	int search_movie = 0; // 대여처리할 비디오를 검색할 때 사용하는 입력변수 선언
	int success = 0; // 대여처리할 비디오까지 검색에 성공했을 때 성공여부를 가리는 변수 선언
	char yesorno; // Y 혹은 N을 입력받을 때 필요한 입력변수 선언
	char findcsname_rent[20]; // 대여 시 고객성명을 찾는 데에 쓰이는 입력변수 선언
	char findcsphonenumber_rent[20]; // // 대여 시 고객전화번호를 찾는 데에 쓰이는 입력변수 선언
	char findmovname_rent[30]; // 대여 시 비디오명을 찾는 데에 쓰이는 입력변수 선언

	printf("***********************************************\n");
	printf("대여 화면입니다. 대여를 진행할 고객의 성명과 전화번호를 입력하세요.\n");
	printf("***********************************************\n");
	for (;;) // 대여 시 고객 정보를 올바르게 입력하지 않으면 계속 이 부분으로 돌아옴
	{
		printf("성명 : ");
		scanf("%s", findcsname_rent); // 대여 시 고객성명을 입력받음
		for (int i = 0; i < total_customer; i++) // 모든 구조체 멤버와 입력된 키워드를 비교하기 위한 반복문 
		{
			if (strcmp(findcsname_rent, c1[i].name) == 0) // 입력받은 고객성명과 저장된 고객성명 데이터가 같을 시
			{
				printf("전화번호 : ");
				scanf("%s", findcsphonenumber_rent); // 대여 시 고객전화번호를 입력받음
				if (strcmp(findcsphonenumber_rent, c1[i].phonenumber) == 0) // 입력받은 고객전화번호와 저장된 고객전화번호 데이터가 같을 시
				{

					printf("-----------------------------------\n"); // 대여를 진행할 고객정보 출력
					printf("대여를 진행할 고객을 찾았습니다.\n");
					printf("성명 : %s\n", c1[i].name);
					printf("전화번호 : %s\n", c1[i].phonenumber);
					printf("대여를 진행합니다.\n");
					printf("-----------------------------------\n");
					for (;;) // 비디오 정보를 올바르게 입력하지 않으면 계속 이 부분으로 돌아옴
					{
						printf("-----------------------------------\n");
						printf("대여처리를 진행할 비디오 이름을 입력하세요.\n");
						printf("-----------------------------------\n");
						printf("비디오명 : ");
						scanf("%s", findmovname_rent);  // 대여 시 대여할 비디오명을 입력받음
						for (int j = 0; j < total_movie; j++) // 모든 구조체 멤버와 입력된 키워드를 비교하기 위한 반복문
						{
							if (strcmp(findmovname_rent, m1[j].moviename) == 0) // 입력받은 비디오명과 저장된 비디오명 데이터가 같을 시
							{
								search_movie = j; // j를 비디오를 찾기위해 사용하는 구조체 멤버 순서 변수로 초기화
								success = 1; // 비디오를 찾아내는 데에 성공함
								break; // 해당 반복문을 탈출하고 다음 과정으로 넘어감
							}
						}
						if (success == 1 && m1[search_movie].status == 1 && strcmp(c1[i].rentmovname, "대여중인 비디오 없음") == 0)	// 비디오를 찾아내는 데에 성공하고 해당 비디오가 대여가능한 상태일 시
						{
							printf("-----------------------------------\n"); // 대여 전 비디오 정보를 다시 한번 확인시켜줌
							printf("이 비디오를 대여처리하시겠습니까? Y / N\n");
							printf("비디오명 : %s\n", m1[search_movie].moviename);
							printf("제작사 : %s\n", m1[search_movie].movieworks);
							printf("대여가 : %d\n", m1[search_movie].price);
							printf("-----------------------------------\n");
							scanf(" %c", &yesorno); // Y 혹은 N을 입력받음
							if (yesorno == 'Y' || yesorno == 'y') // Y 혹은 y를 입력받을 때
							{
								printf("-----------------------------------\n"); // 대여성공, 대여한 고객의 정보와 고객이 대여한 비디오의 정보를 마지막으로 출력
								printf("대여처리가 완료되었습니다.\n");
								printf("-대여고객정보-\n");
								printf("성명 : %s\n", c1[i].name);
								printf("전화번호 : %s\n", c1[i].phonenumber);
								printf("-대여비디오정보-\n");
								strcpy(c1[i].rentmovname, m1[search_movie].moviename); //고객 구조체의 빌린 비디오 정보 멤버에다가 저장
								strcpy(c1[i].rentmovworks, m1[search_movie].movieworks);
								c1[i].rentprice = m1[search_movie].price;
								m1[search_movie].status = 0; // 비디오를 '대여중' 상태로 전환
								printf("비디오명 : %s\n", c1[i].rentmovname);
								printf("제작사 : %s\n", c1[i].rentmovworks);
								printf("대여가 : %d\n", c1[i].rentprice);
								printf("-----------------------------------\n");
								add_size();
								fileout();
								return;	// 해당 기능을 종료하고 메인메뉴로 돌아감

							}
							else if (yesorno == 'N' || yesorno == 'n') // N 혹은 n을 입력받을 때
							{
								printf("-----------------------------------\n");
								printf("대여가 취소되었습니다.\n");
								printf("초기화면으로 돌아갑니다.\n");
								printf("-----------------------------------\n");
								return;
							}
							else
							{
								printf("-----------------------------------\n"); // Y,y 나 N,n이 아닌 다른 엉뚱한 변수를 입력하였을 때 출력되는 오류문
								printf("적합한 입력이 아닙니다. Y / N 으로 입력해주세요.\n");
								printf("대여가 취소되었습니다.\n");
								printf("초기화면으로 돌아갑니다.\n");
								printf("-----------------------------------\n");
								return;
							}
						}
						else if (success == 0) // 비디오를 찾아내는 데에 실패했을 경우
						{
							printf("-----------------------------------\n");
							printf("해당 비디오는 존재하지 않습니다.\n");
							printf("-----------------------------------\n");
							continue; // 해당 함수 초기화면으로 돌아감
						}
						else if (m1[search_movie].status == 0 && strcmp(c1[i].rentmovname, "대여중인 비디오 없음") != 0) // (확인필요) 비디오가 이미 대여중인 경우
						{	//확인필요
							printf("-----------------------------------\n");	//확인필요
							printf("해당 비디오는 이미 대여중입니다.\n");	//확인필요
							printf("-----------------------------------\n");	//확인필요
							continue;	//(확인필요) 해당 함수 초기화면으로 돌아감
						}	//확인필요
					}


				}
				else
				{
					printf("고객의 전화번호가 올바르지 않습니다. 다시 입력해주세요.\n"); // 오입력에 대한 오류문
					i--; // 반복문 형태유지를 위해 i 변수값을 감소시킴
					continue; // 해당 함수 초기화면으로 돌아감
				}
			}

		}
		printf("해당 고객의 정보가 존재하지 않습니다. 다시 입력해주세요.\n");// 오입력에 대한 오류문
		continue; // 해당 함수 초기화면으로 돌아감
	}

}

void moviereturn() // 반납 함수
{
	if (total_customer == 0 || total_movie == 0) //고객이나 비디오 중에 하나라도 없으면 돌려 보냄
	{
		printf("파일 복원이 안됐으므로 메뉴로 돌아갑니다.\n");
		return;
	}
	char findmovname_return[30]; // 반납 시 비디오명을 찾는 데에 쓰이는 입력변수 선언
	char yesorno;  // Y 혹은 N을 입력받을 때 필요한 입력변수 선언
	int search_movie = 0; // 비디오를 찾기위해 사용하는 구조체 멤버 순서 변수 선언
	int search_customer = 0; // 비디오 구조체 멤버의 인덱스 값을 고객 구조체 멤버의 인덱스 값으로 전환시킬 때 사용하는 변수 선언
	int success = 0; // 반납처리할 비디오까지 검색에 성공했을 때 성공여부를 가리는 변수 선언
	int index = 0; // 배열번호 선언

	for (;;) // 비디오 정보를 올바르게 입력하지 않으면 계속 이 부분으로 돌아옴
	{
		printf("-----------------------------------\n");
		printf("반납처리를 진행할 비디오 이름을 입력하세요.\n");
		printf("-----------------------------------\n");
		printf("비디오명 : ");
		scanf("%s", findmovname_return); // 반납 시 반납처리할 비디오명을 입력받음
		for (int i = 0; i < total_movie; i++) // 모든 구조체 멤버와 입력된 키워드를 비교하기 위한 반복문
		{
			if (strcmp(findmovname_return, m1[i].moviename) == 0 && m1[i].status == 0) // 입력받은 비디오명과 저장된 비디오명 데이터가 같을 시
			{
				search_movie = i; // 비디오를 찾기위해 사용하는 구조체 멤버 순서 변수
				success = 1; // 비디오를 찾아내는 데에 성공함
				break; // 해당 반복문을 탈출하고 다음 과정으로 넘어감
			}

		}
		if (success == 1) // 비디오를 찾아내는 데에 성공할 시
		{
			for (int i = 0; i < total_customer; i++) // 모든 구조체 멤버(고객이 대여한 비디오명)와 또다른 모든 구조체 멤버(보유한 비디오명)을 전부 비교하기 위한 반복문
			{
				if (strcmp(c1[i].rentmovname, m1[search_movie].moviename) == 0) // 고객이 대여한 비디오명과 보유한 비디오명이 같을 경우
				{
					search_customer = i; // 비디오 구조체 멤버의 인덱스 값을 고객 구조체 멤버의 인덱스 값으로 전환
				}
			}
			printf("-----------------------------------\n"); // 반납 전 비디오 정보를 다시 한번 확인시켜줌
			printf("이 비디오를 반납처리하시겠습니까? Y / N\n");
			printf("-대여고객정보-\n");
			printf("성명 : %s\n", c1[search_customer].name);
			printf("전화번호 : %s\n", c1[search_customer].phonenumber);
			printf("-대여비디오정보-\n");
			printf("비디오명 : %s\n", c1[search_customer].rentmovname);
			printf("제작사 : %s\n", c1[search_customer].rentmovworks);
			printf("대여가 : %d\n", c1[search_customer].rentprice);
			printf("-----------------------------------\n");
			scanf(" %c", &yesorno); // Y 혹은 N을 입력받음
			if (yesorno == 'Y' || yesorno == 'y') // Y 혹은 y를 입력받을 때
			{
				strcpy(c1[search_customer].rentmovname, "대여중인 비디오 없음"); // 반납되는 비디오 이름을 초기값으로 돌려놓음
				strcpy(c1[search_customer].rentmovworks, "대여중인 비디오 없음"); // 반납되는 비디오 제작사를 초기값으로 돌려놓음
				c1[search_customer].rentprice = 0; // 반납되는 비디오 대여가를 초기값으로 돌려놓음

				m1[search_movie].status = 1; // 해당 비디오는 다시 대여가능상태
				printf("-----------------------------------\n");
				printf("반납처리가 완료되었습니다.\n");
				printf("-----------------------------------\n");
				add_size();
				fileout();
				return; // 해당 기능을 종료하고 메인메뉴로 돌아감
			}
			else if (yesorno == 'N' || yesorno == 'n') // N 혹은 n을 입력받을 때
			{
				printf("-----------------------------------\n");
				printf("반납이 취소되었습니다.\n");
				printf("초기화면으로 돌아갑니다.\n");
				printf("-----------------------------------\n");
				return; // 해당 기능을 종료하고 메인메뉴로 돌아감
			}
			else
			{
				printf("-----------------------------------\n"); // Y,y 나 N,n이 아닌 다른 엉뚱한 변수를 입력하였을 때 출력되는 오류문
				printf("적합한 입력이 아닙니다. Y / N 으로 입력해주세요.\n");
				printf("반납이 취소되었습니다.\n");
				printf("초기화면으로 돌아갑니다.\n");
				printf("-----------------------------------\n");
				return; // 해당 기능을 종료하고 메인메뉴로 돌아감
			}
		}
		else if (success == 0) // 비디오가 반납처리가 필요 없이 이미 대여가능상태일 때
		{
			printf("-----------------------------------\n"); // 오류문 출력
			printf("해당 비디오는 잘못 입력한 이름이거나 반납처리가 불필요한 비디오입니다.\n");
			printf("-----------------------------------\n");
			continue; // 해당 함수 초기화면으로 돌아감
		}
	}
}
void noteall() // 조회 함수
{
	if (total_customer == 0 || total_movie == 0) //고객이나 비디오 중에 하나라도 없으면 돌려 보냄
	{
		printf("파일 복원이 안됐으므로 메뉴로 돌아갑니다.\n");
		return;
	}
	int selectitem; // 고객조회 와 비디오조회 중 하나를 고르게 할 변수 선언

	printf("***********************************************\n");
	printf("조회화면입니다.\n");
	printf("1. 고객조회\n");
	printf("2. 비디오조회\n");
	printf("***********************************************\n");
	scanf("%d", &selectitem); // 1번 혹은 2번을 입력받음
	for (;;) // 번호를 올바르게 입력하지 않으면 계속 이 부분으로 돌아옴
	{
		if (selectitem == 1) // 1번을 입력했을 경우
		{
			if (total_customer == 0) // 가입된 고객이 한명도 없을 경우
			{
				printf("아직 회원가입된 고객이 없습니다. 회원가입처리를 해주세요.\n");
				return;
			}
			printf("-고객정보를 모두 표기합니다.-\n");
			for (int i = 0; i < total_customer; i++) // 저장된 구조체 멤버만 출력될 수 있게 함
			{
				printf("- - - - - - - - - -\n");
				printf("%d. \n", i + 1);
				printf("이름 : %s\n", c1[i].name);
				printf("전화번호 : %s\n", c1[i].phonenumber);
				printf("대여중인 비디오명 : %s\n", c1[i].rentmovname);
				printf("대여중인 비디오 제작사 : %s\n", c1[i].rentmovworks);
				printf("대여중인 비디오 대여가 : %d\n", c1[i].rentprice);
				printf("- - - - - - - - - -\n");
			}
			break;
		}
		else if (selectitem == 2) // 2번을 입력했을 경우
		{
			if (total_movie == 0) // 입고된 비디오가 하나도 없을 경우
			{
				printf("아직 보유한 비디오가 없습니다. 비디오를 입고처리해주세요.");
				return;
			}
			printf("-비디오정보를 모두 표기합니다.-\n");
			for (int i = 0; i < total_movie; i++) // 저장된 구조체 멤버만 출력될 수 있게 함
			{
				printf("- - - - - - - - - -\n");
				printf("%d. \n", i + 1);
				printf("비디오명 : %s\n", m1[i].moviename);
				printf("제작사 : %s\n", m1[i].movieworks);
				printf("대여가 : %d\n", m1[i].price);
				if (m1[i].status == 1) // 비디오가 대여가능한 상태일 경우
				{
					printf("상태 : 대여가능\n");
					printf("- - - - - - - - - -\n");
				}
				else if (m1[i].status == 0) // 비디오가 대여중인 상태일 경우
				{
					printf("상태 : 대여중\n");
					printf("- - - - - - - - - -\n");
				}
			}
			break; // 해당 기능을 종료하고 메인메뉴로 돌아감
		}
		else
		{
			printf("-----------------------------------\n"); // 오입력에 대한 오류문
			printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			printf("-----------------------------------\n");
			return; // 해당 기능을 종료하고 메인메뉴로 돌아감
		}
	}
}
void join() // 회원가입 함수
{
	char yesorno; // Y 혹은 N을 입력받을 때 필요한 입력변수 선언

	for (int i = total_customer; i < total_customer + 100; i++) // 회원가입은 한번에 100명까지 가능함
	{
		printf("***********************************************\n");
		printf("회원가입을 합니다. 등록하실 회원의 성명과 전화번호를 순서대로 입력하세요.\n");
		printf("***********************************************\n");
		printf("성명 : \n");
		scanf("%s", c1[i].name); // 고객성명을 입력
		if ((strcmp(c1[i].name, "") != 0)) // 고객성명이 공백이 아닌 경우
		{
			printf("전화번호 : \n");
			scanf("%s", c1[i].phonenumber);  // 고객전화번호를 입력
			if ((strcmp(c1[i].phonenumber, "") != 0)) // 고객전화번호가 공백이 아닌 경우
			{
				strcpy(c1[i].rentmovname, "대여중인 비디오 없음"); // 대여를 아직 안한 신규고객이므로 '대여한 비디오명' 의 초기값을 설정
				strcpy(c1[i].rentmovworks, "대여중인 비디오 없음"); // 대여를 아직 안한 신규고객이므로 '대여한 비디오 제작사' 의 초기값을 설정
				c1[i].rentprice = 0; // 대여를 아직 안한 신규고객이므로 '대여한 비디오 대여가' 의 초기값을 설정
				total_customer++; // 총고객수를 증가시킴
				printf("-----------------------------------\n");
				printf("등록이 완료되었습니다.\n");
				add_size();
				fileout();
				printf("회원정보\n");
				printf("이름 : %s\n", c1[i].name);
				printf("전화번호 : %s\n", c1[i].phonenumber);
				printf("-----------------------------------\n");
				printf("회원을 더 등록하시겠습니까? Y / N\n");
				printf("-----------------------------------\n");
				scanf(" %c", &yesorno); // Y 혹은 N을 입력받음
				if (yesorno == 'Y' || yesorno == 'y') // Y 혹은 y를 입력받을 때
				{
					continue; // 회원가입 추가 진행
				}
				else if (yesorno == 'N' || yesorno == 'n') // N 혹은 n을 입력받을 때
				{
					printf("-----------------------------------\n");
					printf("초기화면으로 돌아갑니다.\n");
					printf("-----------------------------------\n");
					return; // 해당 기능을 종료하고 메인메뉴로 돌아감
				}
				else
				{
					printf("-----------------------------------\n"); // 오입력에 대한 오류문
					printf("적합한 입력이 아닙니다. Y / N 으로 입력해주세요.\n");
					printf("초기화면으로 돌아갑니다.\n");
					printf("-----------------------------------\n");
					return;
				}
			}
		}
	}
}
void control() // 비디오 관리 함수 (입고와 폐기 기능 보유)
{
	char findmvname[20]; // 비디오명을 찾을 때 사용하는 입력변수 선언
	char yesorno; // Y 혹은 N을 입력받을 때 필요한 입력변수 선언
	int selectnumber; // 비디오입고와 비디오폐기 중 하나를 고르게 할 변수 선언
	int yon = 0; // 비디오 검색 성공 여부를 가리는 변수 선언
	int index = 0; // 구조체 멤버의 배열번호를 정해줄 변수 선언

	for (;;)
	{
		printf("***********************************************\n");
		printf("비디오 관리화면입니다.\n");
		printf("1. 비디오입고\n");
		printf("2. 비디오폐기\n");
		printf("***********************************************\n");
		scanf("%d", &selectnumber); // 1번 혹은 2번을 입력받음
		for (int i = total_movie; i < total_movie + 100; i++) // 비디오 입고는 한번에 100개까지 가능함
		{
			if (selectnumber == 1) // 1번을 입력했을 경우
			{
				printf("***********************************************\n");
				printf("비디오를 입고처리합니다. 입고하실 비디오의 비디오명과 제작사, 대여가를 순서대로 입력하세요.\n");
				printf("***********************************************\n");
				printf("비디오명 : \n");
				scanf("%s", m1[i].moviename); // 입고처리할 비디오명을 입력
				if (strcmp(m1[i].moviename, "") != 0) //비디오명이 공백이 아닌 경우
				{
					printf("제작사 : \n");
					scanf("%s", m1[i].movieworks); // 입고처리할 비디오 제작사를 입력
					if ((strcmp(m1[i].movieworks, "") != 0)) // 비디오 제작사가 공백이 아닌 경우
					{
						printf("대여가 : \n");
						scanf("%d", &m1[i].price); // 입고처리할 비디오의 대여가를 입력
						if (m1[i].price != 0) // 비디오 대여가가 0원이 아닌 경우
						{
							m1[i].status = 1;
							printf("-----------------------------------\n"); // 입고처리한 비디오의 정보를 확인 차 출력
							printf("등록이 완료되었습니다.\n");
							printf("비디오정보\n");
							printf("이름 : %s\n", m1[i].moviename);
							printf("전화번호 : %s\n", m1[i].movieworks);
							printf("전화번호 : %d\n", m1[i].price);
							total_movie++;
							add_size();
							fileout();
							printf("-----------------------------------\n");
							printf("비디오를 더 입고하시겠습니까? Y / N\n");
							printf("-----------------------------------\n");
							scanf(" %c", &yesorno); // Y 혹은 N을 입력받음
						}
						if (yesorno == 'Y' || yesorno == 'y') // Y 혹은 y를 입력받을 때
						{
							continue; // 비디오 입고화면으로 돌아가 추가로 입고처리를 하게 함
						}
						else if (yesorno == 'N' || yesorno == 'n')  // N 혹은 n을 입력받을 때
						{
							printf("-----------------------------------\n");
							printf("초기화면으로 돌아갑니다.\n");
							printf("-----------------------------------\n");
							return; // 해당 기능을 종료하고 메인메뉴로 돌아감
						}
						else
						{
							printf("-----------------------------------\n");
							printf("적합한 입력이 아닙니다. Y / N 으로 입력해주세요.\n");
							printf("초기화면으로 돌아갑니다.\n");
							printf("-----------------------------------\n");
							return;
						}
					}
				}
			}
			else if (selectnumber == 2)
			{
				if (customer_restore == 0 || movie_restore == 0) //고객 데이터나 비디오 데이터 중에 하나라도 복원이 안 됐다면 돌려 보냄
				{
					printf("파일 복원이 안됐으므로 메뉴로 돌아갑니다.\n");
					return;
				}
				if (total_movie == 0)
				{
					printf("입고된 비디오가 없습니다. 초기화면으로 돌아갑니다.\n");
					return;
				}
				printf("***********************************************\n");
				printf("비디오를 폐기합니다. 폐기를 원하는 비디오명을 입력해주세요.\n");
				printf("***********************************************\n");
				scanf("%s", &findmvname); // 폐기처리할 비디오명을 입력받음
				for (int i = 0; i < total_movie; i++) // 모든 구조체 멤버와 입력된 키워드를 비교하기 위한 반복문
				{
					if (strcmp(findmvname, m1[i].moviename) == 0 && m1[i].status == 1)  // (확인 필요) // 입력받은 비디오명과 저장된 비디오명 데이터가 같을 시
					{

						printf("-----------------------------------\n"); // 폐기처리할 비디오 정보를 확인 차 출력함
						printf("해당 비디오를 폐기처리하시겠습니까? Y / N\n");
						printf("비디오 이름 : %s\n", m1[i].moviename);
						printf("제작사 : %s\n", m1[i].movieworks);
						printf("대여가 : %d\n", m1[i].price);
						printf("-----------------------------------\n");
						yon = 1; // 폐기처리할 비디오를 검색하는 데에 성공함
						scanf(" %c", &yesorno); // Y 혹은 N을 입력받음
						if (yesorno == 'Y' || yesorno == 'y') // Y 혹은 y를 입력받을 때
						{
							for (int arrnum = i; arrnum < total_movie - 1; arrnum++) // 데이터가 존재하는 구조체 멤버까지 반복
							{
								strcpy(m1[arrnum].moviename, m1[arrnum + 1].moviename); // 삭제처리될 배열 멤버 뒤에 있는 멤버들을 앞으로 끌어옴 (비디오명)
								strcpy(m1[arrnum].movieworks, m1[arrnum + 1].movieworks); // 삭제처리될 배열 멤버 뒤에 있는 멤버들을 앞으로 끌어옴 (제작사)
								m1[arrnum].price = m1[arrnum + 1].price; // 삭제처리될 배열 멤버 뒤에 있는 멤버들을 앞으로 끌어옴 (대여가)

							}
							total_movie--; // 비디오가 폐기처리되었으니 총 비디오 갯수를 하나 감소시킴
							add_size();
							fileout();
							printf("-----------------------------------\n");
							printf("폐기가 성공적으로 처리되었습니다.\n");
							printf("초기화면으로 돌아갑니다.\n");
							printf("-----------------------------------\n");
							return; // 해당 기능을 종료하고 메인메뉴로 돌아감
						}
						else if (yesorno == 'N' || yesorno == 'n')  // N 혹은 n을 입력받을 때
						{
							printf("-----------------------------------\n");
							printf("폐기를 취소했습니다.\n");
							printf("초기화면으로 돌아갑니다.\n");
							printf("-----------------------------------\n");
							return;
						}
						else
						{
							printf("-----------------------------------\n"); // 오입력에 대한 오류문
							printf("적합한 입력이 아닙니다. Y / N 으로 입력해주세요.\n");
							printf("비디오의 폐기처리가 취소되었습니다.\n");
							printf("초기화면으로 돌아갑니다.\n");
							printf("-----------------------------------\n");
							break;
						}
					}
					else if (strcmp(findmvname, m1[i].moviename) == 0 && m1[i].status == 0) // 폐기하려는 비디오가 현재 대여중일 경우

						printf("-----------------------------------\n");
					printf("해당 비디오는 현재 대여중인 비디오입니다. 반납처리 후 폐기해주세요.\n");
					printf("비디오의 폐기처리가 취소되었습니다.\n");
					printf("초기화면으로 돌아갑니다.\n");
					printf("-----------------------------------\n");
					return;
				}

			}
			if (yon == 0) // 폐기처리할 비디오 데이터가 없을 때
			{
				printf("-----------------------------------\n"); // 오입력에 대한 오류문
				printf("검색값에 적합한 데이터가 없습니다.\n");
				printf("초기화면으로 돌아갑니다.\n");
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
	//고객 불러오기
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
	//고객 불러오기
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

void filein() //불러오기 함수
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
void fileout() //저장 함수
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

void add_size() // 구조체 배열의 크기를 늘리는 함수
{
	int add_total = 1000; // 한번 늘릴 때 1000개를 늘림
	if (total_customer > 90) // 총고객수가 90을 넘었을 경우
	{
		realloc(c1, sizeof(struct customer) * add_total); // 고객 구조체 배열을 1000개 늘림
	}
	if (total_movie > 90) // 총비디오갯수가 90을 넘었을 경우
	{
		realloc(m1, sizeof(struct movie) * add_total); // 비디오 구조체 배열을 1000개 늘림
	}
}


void mainmenu() // 메인메뉴 함수
{
	int num = 0; // 메뉴번호를 선택하기 위한 입력변수 선언
	for (;;) // 각 기능이 끝나고 다시 돌아와 다른 기능도 쓸 수 있게 반복
	{
		printf("*********************************************\n");
		printf("지훈비디오에 오신 것을 환영합니다.\n");
		printf("원하시는 메뉴를 선택하세요.\n");
		printf("1. 비디오검색\n");
		printf("2. 고객검색\n");
		printf("3. 비디오 대여\n");
		printf("4. 반납\n");
		printf("5. 조회\n");
		printf("6. 회원가입\n");
		printf("7. 비디오 관리\n");
		printf("8. 종료\n");
		printf("*********************************************\n");
		scanf("%d", &num); // 메뉴번호를 입력받음
		switch (num) // 메뉴구성을 위한 switch문
		{
		case 1: // 비디오 검색
			moviesearch();
			continue;
		case 2: //  고객 검색
			customersearch();
			continue;
		case 3: // 비디오 대여
			rent();
			continue;
		case 4: // 비디오 반납
			moviereturn();
			continue;
		case 5: // 조회
			noteall();
			continue;
		case 6: // 회원가입
			join();
			continue;
		case 7: // 비디오 관리
			control();
			continue;
		case 8: // 종료
			add_size();
			fileout();
			free(c1);
			free(m1);
			break;
		default: // 다른 번호를 입력했을 때
			printf("잘못된 입력입니다. 올바른 메뉴번호를 입력해주세요!\n");
			continue;
		}
		break; // 반복문에서 탈출 시 프로그램 종료
	}
}
void login() // 로그인 함수
{
	char ID[10]; // 관리자ID변수 선언
	char PW[10]; // 비밀번호변수 선언

	for (int i = 0; i < 1;) // 로그인에 성공하면 탈출하는 반복문
	{
		printf("관리자 로그인을 해주세요.\n");
		printf("ID : ");
		scanf("%s", ID); // 관리자ID를 입력받음
		for (;;) // 올바른 입력을 하지 않을 경우 이 시점으로 계속 돌아옴
		{
			if (strcmp(ID, "admin") == 0 || strcmp(ID, "ADMIN") == 0) // 관리자ID "admin" 혹은 "ADMIN"으로 올바르게 입력했을 경우
			{
				printf("암호 : ");
				scanf("%s", &PW); // 비밀번호를 입력받음
				if (strcmp(PW, "1234") == 0) // 비밀번호 "1234"로 올바르게 입력했을 경우
				{
					i++; // 반복문 탈출을 위해 i변수에 1을 증가시킴
					printf("로그인에 성공했습니다.\n");
					return; // 해당 기능을 종료하고 메인함수로 돌아감
				}
				else
				{
					printf("비밀번호가 올바르지 않습니다. 다시 입력해주세요.\n"); // 오입력에 대한 오류문
					continue;
				}
			}
			else
			{
				printf("ID가 올바르지 않습니다. 다시 입력해주세요.\n"); // 오입력에 대한 오류문
				break;
			}
		}
	}
}
