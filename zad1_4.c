#include <stdio.h>
#include <stdlib.h>

/*************** Lista skladowych wewnetrznych ***************/
struct list {
	struct arrow * strzalka;
	struct list *next;
};

/*************** KRAWEDZ ***************/
struct arrow {
	struct arrow *twin;
	struct top *start;
	struct wall *f;
	struct arrow *next;
	struct arrow *prev;
	int name;
};

/*************** WIERZCHOLEK ***************/
struct top{
	int nr;
	struct arrow *edge;
};

struct wall {
	struct list *sw;
	struct arrow *sz;
};

int main(void){
	/*************** INICJALIZACJA ***************/
	struct top *v1 = (struct top *)malloc(sizeof(struct top));
	struct top *v2 = (struct top *)malloc(sizeof(struct top));
	struct top *v3 = (struct top *)malloc(sizeof(struct top));
	struct top *v4 = (struct top *)malloc(sizeof(struct top));

	struct arrow *e11 = (struct arrow *)malloc(sizeof(struct arrow));
	struct arrow *e12 = (struct arrow *)malloc(sizeof(struct arrow));
	struct arrow *e21 = (struct arrow *)malloc(sizeof(struct arrow));
	struct arrow *e22 = (struct arrow *)malloc(sizeof(struct arrow));
	struct arrow *e31 = (struct arrow *)malloc(sizeof(struct arrow));
	struct arrow *e32 = (struct arrow *)malloc(sizeof(struct arrow));
	struct arrow *e41 = (struct arrow *)malloc(sizeof(struct arrow));
	struct arrow *e42 = (struct arrow *)malloc(sizeof(struct arrow));

	struct wall *f1 = (struct wall *)malloc(sizeof(struct wall));
	struct wall *f2 = (struct wall *)malloc(sizeof(struct wall));
	
	struct arrow *jumper = (struct arrow *)malloc(sizeof(struct arrow));

	struct list * listaF1 = (struct list *)malloc(sizeof(struct list));

	struct list * tmp = (struct list *)malloc(sizeof(struct list));	

	v1->edge = e11;
	v1->nr = 1;
	v2->edge = e42;
	v2->nr = 2;
	v3->edge = e21;
	v3->nr = 3;
	v4->edge = e22;
	v4->nr = 4;
	e11->twin = e12;
	e12->twin = e11;
	e21->twin = e22;
	e22->twin = e21;
	e31->twin = e32;
	e32->twin = e31;
	e41->twin = e42;
	e42->twin = e41;
	e11->start = v1;
	e12->start = v2;
	e21->start = v3;
	e22->start = v4;
	e31->start = v3;
	e32->start = v1;
	e41->start = v3;
	e42->start = v2;
	e11->f = f1;
	e12->f = f2;
	e21->f = f1;
	e22->f = f1;
	e31->f = f1;
	e32->f = f2;
	e41->f = f2;
	e42->f = f1;
	e11->name = 11;
	e12->name = 12;
	e21->name = 21;
	e22->name = 22;
	e31->name = 31;
	e32->name = 32;
	e41->name = 41;
	e42->name = 42;
	e11->next = e42;
	e12->next = e32;
	e21->next = e22;
	e22->next = e31;
	e31->next = e11;
	e32->next = e41;
	e41->next = e12;
	e42->next = e21;
	e11->prev = e31;
	e12->prev = e41;
	e21->prev = e42;
	e22->prev = e21;
	e31->prev = e22;
	e32->prev = e12;
	e41->prev = e32;
	e42->prev = e11;

	f1->sz = NULL;
	listaF1->strzalka = e42;
	listaF1->next = NULL;
	f1->sw = listaF1;

	f2->sz = e41;
	f2->sw = NULL;
	
	/*************** USTAWIENIA ***************/
	struct wall *krawedzieSciany = f2;
	struct top *wierzcholek = v3;

	/*************** A ***************/
	printf("Sąsiedzi wierzchołka: ");
	jumper = wierzcholek->edge;
	do {
		printf("%i ", jumper->twin->start->nr);
		jumper = jumper->twin->next;
	} while(jumper != wierzcholek->edge);

	printf("\n");

	/*************** B ***************/
	printf("Krawędzie wewnetrzne sciany f: ");
	
	for(tmp = krawedzieSciany->sw; tmp != NULL; tmp = tmp->next){
		jumper = tmp->strzalka;
		do {
			printf("e%i ", jumper->name);
			jumper = jumper->next;
		} while(jumper != krawedzieSciany->sw->strzalka);
	
		printf("\n");
	}

	printf("\nKrawędzie zewnetrzne sciany f: ");
	
	if(krawedzieSciany->sz != NULL){
		jumper = krawedzieSciany->sz;
		do {
			printf("e%i ", jumper->name);
			jumper = jumper->next;
		} while(jumper != krawedzieSciany->sz);
	} else {
		printf("Sciana jest nieskonczona");
	}

	printf("\n");

	/*************** SPRZATANIE ***************/
	free(v1);
	free(v2);
	free(v3);
	free(v4);
	free(e11);
	free(e12);
	free(e21);
	free(e22);
	free(e31);
	free(e32);
	free(e41);
	free(e42);
	free(f1);
	free(f2);
	free(wierzcholek);
	free(krawedzieSciany);
	return 0;
}