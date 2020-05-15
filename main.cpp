#include<iostream>
#include<string>

using namespace std; 


struct Lista {
	string num;
		
	Lista *prox, *ant;
}; 

struct Prioridade {
	string num;
		
	Prioridade *prox, *ant;
}; 

int Idade() {
	int idade;
	
	cout<<"\nIdade:"<<endl;
	cin>>idade;
	
	return idade;
}

string Cpf() {
	string cpf;
	
	cout<<"\nCPF:"<<endl;
	cin>>cpf;
	
	return cpf;
}
	
int Sexo() {
	int sexo, gravida, gra;
	
	    cout<<"\nSexo (1-feminino 2-masculino):"<<endl;
	    cin>>sexo;
	 while (sexo>2)  {	 	 	
	 	cout<<"\nSexo (1-feminino 2-masculino):"<<endl;
	 	cin>>sexo;}
	 if (sexo==1) {
	    cout<<"\nEsta gravida? (1-Sim 2-Nao):"<<endl;
	    cin>>gravida;
	 if (gravida==1) {
		return 3;}	 
	 }
	 
	 return sexo;     	   
}

int main() {
		
	Lista *inicio = NULL, *fim=NULL, *aux = NULL;
	
	Prioridade *prini = NULL, *prifi=NULL, *pri=NULL;
	
	int op=0, sexo, idade;
	string CPF;
	
	while(op != 4) {
		cout<<"\n\t 1-Registrar Atendimento";
		cout<<"\n\t 2-Proximo Atendimento";
		cout<<"\n\t 3-Fila";
		cout<<"\n\t 4-Sair";
		cout<<"\n\t Escolha Opcao:"<<endl;
		cin>>op;
	
        if (op==1){
        	
        	CPF=Cpf();
        	idade=Idade();
        	sexo=Sexo();
        	
        	if (idade>65 || sexo==3) {
        	
        	Prioridade *novo = new Prioridade;			
			novo->num = CPF;
			if (prini == NULL) {
				prini = novo;
				prifi = novo;				 
				cout<< "novo"<<novo;
				novo->prox = NULL;
				novo->ant = NULL;
				}
				
			else {
			   
				novo->prox = prini;
				cout<<"+1 prox "<<prini;
				prini->ant=novo;
				cout<<"+1 ant "<<prini;
				novo->ant=NULL;
				prini=novo;
			}
	        }       
            else {
            Lista *novo = new Lista;			
			novo->num = CPF;
			if (inicio == NULL) {
				inicio = novo;
				fim = novo;				 
				cout<< "novo"<<novo;
				novo->prox = NULL;
				novo->ant = NULL;
				}
				
			else {
			   
				novo->prox = inicio;
				cout<<"+1 prox "<<inicio;
				inicio->ant=novo;
				cout<<"+1 ant "<<inicio;
				novo->ant=NULL;
				inicio=novo;
			}
		    }
	    }
       

	   if(op==2) {
	   	
	   	    if(prifi != NULL) {
				pri = prifi;
				cout<<"\n\tProximo:"<< pri->num <<endl;
				prifi=prifi->ant;
				delete (pri);
				}	
	      
		    else { 
			  if(fim == NULL) {
				cout<<"\nLista Vazia"<<endl;
		      }else {
				aux = fim;
				cout<<"\n\tProximo:"<< aux->num <<endl;
				fim=fim->ant;
				delete (aux);
				}			 					
	    	}
	    } 
    
	   if (op==3) {
			if (inicio == NULL, prini==NULL) {
				cout<<"\nLista Vazia"<<endl;
			}else {
				aux = fim;
				pri=prifi;
				while (pri != NULL){
					cout<<"\n\tProximo:"<< pri->num <<endl;
					pri=pri->ant;
				}
				while (aux != NULL){
					cout<<"\n\tProximo:"<< aux->num <<endl;
					aux=aux->ant;
				}
			}
		}
	
	
	}
  
	return 0; 
}


