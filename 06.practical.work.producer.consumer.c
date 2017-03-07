#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int main(){
	item A, B;
	A.type = '0';
	A.amount = 3;
	A.unit = '0';

	B.type = '1';
	B.amount = 30;
	B.unit = '1';

	printf("item     type     amount     unit     first     last\n");
	printf("A        %c        %d          %c        %d         %d\n", A.type, A.amount, A.unit, first, last);
	printf("B        %c        %d         %c        %d         %d\n", B.type, B.amount, B.unit, first, last);
	
	produce(&A);
	printf("produce A: first = %d   last = %d\n", first, last);
	produce(&B);
	printf("produce B: first = %d   last = %d\n", first, last);
	
	consume();
	printf("consume:   first = %d   last = %d\n", first, last);
	return 0;
}

	


