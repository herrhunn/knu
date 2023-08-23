#include "Videoshop_header.h"

int main() // 메인 함수
{
	int num = 100;
	c1 = (struct customer*)malloc(sizeof(struct customer) * num);
	m1 = (struct movie*)malloc(sizeof(struct movie) * num);
	filein(); // 백업된 파일 불러오기
	login(); // 로그인 함수를 먼저 호출하고
	mainmenu(); // 로그인에 성공하면 메인메뉴로 이동
}
