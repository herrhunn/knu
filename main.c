#include "Videoshop_header.h"

int main() // ���� �Լ�
{
	int num = 100;
	c1 = (struct customer*)malloc(sizeof(struct customer) * num);
	m1 = (struct movie*)malloc(sizeof(struct movie) * num);
	filein(); // ����� ���� �ҷ�����
	login(); // �α��� �Լ��� ���� ȣ���ϰ�
	mainmenu(); // �α��ο� �����ϸ� ���θ޴��� �̵�
}
