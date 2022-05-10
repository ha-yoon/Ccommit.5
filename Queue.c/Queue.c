#include <stdio.h>
#define EMPTY 0 // 매크로 기능 
#include <stdlib.h> // malloc 함수를 쓰기 위한 선언

typedef struct node {
	int data;
	struct node* link;
}Queue;

Queue* GetNode()
{
	// 주소를 저장할 변수 = (저장할 변수의 자료형)malloc(크기);
	// ↓↓↓↓↓↓↓↓
	// (저장할 공간의 자료형* 변수명;)

	Queue* tmp;

	tmp = (Queue*)malloc(sizeof(Queue));
	tmp->link = EMPTY; // tmp를 link에 연결함(데이터는 아직 '0'=EMPTY)
	return tmp;
}

                       // 저장할 공간의 자료형* 변수명      data 10
void Enqueue(Queue** front, Queue** rear, int data)	
{
		if (*front == EMPTY)  // 첫번째 Enqueue
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
	// front, rear 선언
	// 저장할 공간의 자료형* 변수명;
	Queue* front = EMPTY; // EMPTY(0) 선언★
	Queue* rear = EMPTY;

	Enqueue(&front, &rear, 10); //Heap에 연결을 위해 주소 연결
											// 10 은 입력할 데이터 기입한 것임
	Enqueue(&front, &rear, 20); // 추가데이터
	Enqueue(&front, &rear, 30); // 추가데이터

	Dequeue(&front);
	Dequeue(&front);
	Dequeue(&front);
	Dequeue(&front);


	return 0; 

}











