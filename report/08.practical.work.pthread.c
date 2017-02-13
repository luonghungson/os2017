#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#define BUFFER_SIZE 10

typedef struct {
	char type; // 0=fried chicken, 1=French fries
	int amount; // pieces or weight
	char unit; // 0=piece, 1=gram
} item;
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
	// do nothing -- no free buffer item
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
	// do nothing -- nothing to consume
}
memcpy(i, &buffer[last], sizeof(item));
last = (last + 1) % BUFFER_SIZE;
return i;
}

void *threadFunctionPro(void *param) {
	item A, B, C;
	printf("A thread for producer:\n\n");
	A.type = '0';
	A.amount = 3;
	A.unit = '0';

	B.type = '1';
	B.amount = 30;
	B.unit = '1';

	C.type = '0';
	C.amount = 2;
	C.unit = '0';

	printf("item     type     amount     unit     first     last\n");
	printf("A        %c        %d          %c        %d         %d\n", A.type, A.amount, A.unit, first, last);
	printf("B        %c        %d         %c        %d         %d\n", B.type, B.amount, B.unit, first, last);
	printf("C        %c        %d          %c        %d         %d\n", C.type, C.amount, C.unit, first, last);

	printf("Produce 3 items\n");
	produce(&A);
	printf("produce A: first = %d   last = %d\n", first, last);
	produce(&B);
	printf("produce B: first = %d   last = %d\n", first, last);
	produce(&C);
	printf("produce C: first = %d   last = %d\n\n", first, last);
	return 0;
}

void *threadFunctionCon(void *param) {
	printf("A thread for consumer:\n\n");
	printf("Consume 2 items\n");
	consume();
	printf("consume an item     :   first = %d   last = %d\n", first, last);
	consume();
	printf("consume another item:   first = %d   last = %d\n", first, last);
	return 0;
}

int main(){
	pthread_t pro, con;
	
	pthread_create(&pro, NULL, threadFunctionPro, NULL);
	pthread_join(pro, NULL);

	pthread_create(&con, NULL, threadFunctionCon, NULL);
	pthread_join(con, NULL);

	return 0;
}
