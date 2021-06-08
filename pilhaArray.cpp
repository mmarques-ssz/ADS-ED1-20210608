#include <iostream>
using namespace std;

#define MAX 10

struct Pilha {
	int qtde;
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
}

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	if (podeEmpilhar) {
		p->elementos[p->qtde++] = v;
	}
	return podeEmpilhar;
}

float pop(Pilha *p) {
	int podeDesempilhar = (p->qtde > 0);
	float v;
	if (podeDesempilhar) {
		v = p->elementos[p->qtde-1];
		p->qtde--;
	}
	else
	{
		v = -1;
	}
	return v;	
}


int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

int count(Pilha *p) {
	return (p->qtde);
}

void freePilha(Pilha *p) {
	free(p);
}

void print(Pilha *p) {
	cout << "Qtde de elementos na pilha: " << p->qtde << endl;
	for(int i=p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "--------------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = new Pilha;
	pilhaFloat = init();
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	
	cout << "Empilhado valor: " << (push(pilhaFloat, 15)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 30)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 45)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 115)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 130)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 145)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 215)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 230)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 245)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 315)?"SIM":"NAO") << endl;
	cout << "Empilhado valor: " << (push(pilhaFloat, 330)?"SIM":"NAO") << endl;
	
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	
	print(pilhaFloat);
	
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	cout << "Valor desempilhado: " << pop(pilhaFloat) << endl;
	
	print(pilhaFloat);
	
	freePilha(pilhaFloat);
	
	return 0;
}