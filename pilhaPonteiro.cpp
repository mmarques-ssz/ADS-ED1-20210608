#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Pilha {
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

void push(Pilha *p, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = p->topo;
	p->topo = no;
}

float pop(Pilha *p) {
	float ret;
	int podeDesempilhar = (p->topo != NULL);
	if (podeDesempilhar) {
	   No *no = p->topo;
	   ret = no->dado;
	   p->topo = p->topo->prox;
	   free(no);
	}
	else
	{
		ret = -1;
	}
	return ret;
}

void print(Pilha* p) {
	No* n;
	n = p->topo;
	while (n != NULL) {
		cout << n->dado << endl;
		n = n->prox;
	}
	cout << "--------------------" << endl;
}

int count(Pilha* p) {
	int i = 0;
	No* n;
	n = p->topo;
	while (n != NULL) {
		i++;
		n = n->prox;
	}
	return i;
}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

void freePilha(Pilha *p) {
	No *n = p->topo;
	while(n != NULL) {
		No *t = n->prox;
		free(n);
		n = t;
	}
	free(p);
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = init();
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	
	push(pilhaFloat, 15);
	push(pilhaFloat, 30);
	push(pilhaFloat, 45);
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	
	cout << "Qtde elementos na pilha: " << count(pilhaFloat) << endl;
	
	print(pilhaFloat);
	
	cout << "Desempilhado valor: " << pop(pilhaFloat) << endl;
	cout << "Desempilhado valor: " << pop(pilhaFloat) << endl;
	cout << "Desempilhado valor: " << pop(pilhaFloat) << endl;
	cout << "Desempilhado valor: " << pop(pilhaFloat) << endl;
	
	cout << "Qtde elementos na pilha: " << count(pilhaFloat) << endl;
	
	print(pilhaFloat);

	freePilha(pilhaFloat);
	
	return 0;
}