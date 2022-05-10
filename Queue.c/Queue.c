#include <stdio.h>
#define EMPTY 0 // ��ũ�� ��� 
#include <stdlib.h> // malloc �Լ��� ���� ���� ����

typedef struct node {
	int data;
	struct node* link;
}Queue;

Queue* GetNode()
{
	// �ּҸ� ������ ���� = (������ ������ �ڷ���)malloc(ũ��);
	// ���������
	// (������ ������ �ڷ���* ������;)

	Queue* tmp;

	tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = EMPTY; // tmp�� link�� ������(�����ʹ� ���� '0'=EMPTY)
	return tmp;
}

                       // ������ ������ �ڷ���* ������      data 10
void Enqueue(Queue** front, Queue** rear, int data)	
{
		if (*front == EMPTY)  // ù��° Enqueue
		{
			*front = GetNode();
			*rear = *front;
		}
		else
		{
			(*rear)->link = GetNode();
			*rear = (*rear)->link;
		}
		(*rear)->data = data;
}

void Dequeue(Queue** front)
{
	Queue* tmp;

	if (*front == EMPTY)
	{
		printf("Queue in Empty!!\n");
		return;
	}

	tmp = *front;
	printf("%d\n", (*front)->data);
	*front = (*front)->link;
	free(tmp);
}

int main()
{
	// front, rear ����
	// ������ ������ �ڷ���* ������;
	Queue* front = EMPTY; // EMPTY(0) �����
	Queue* rear = EMPTY;

	Enqueue(&front, &rear, 10); //Heap�� ������ ���� �ּ� ����
											// 10 �� �Է��� ������ ������ ����
	Enqueue(&front, &rear, 20); // �߰�������
	Enqueue(&front, &rear, 30); // �߰�������

	Dequeue(&front);
	Dequeue(&front);
	Dequeue(&front);
	Dequeue(&front);


	return 0; 

}











