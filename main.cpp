/*
#########################################
Alan Neres
#########################################
*/

#include <iostream>
#include <locale>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>

#define MAX 100000

using namespace std::chrono;

void menu();
void volMenu();
void bubbleSort(int vetor[], int a);
void insertionSort(int vetor[], int a);
void selectionSort(int vetor[], int a);
int mergeSort(int vetor[], int in, int fim);
void intercala(int vetor[], int in, int fim, int meio);
void mergeVer();
void Quick(int vetor[], int inicio, int fim);
void quickVer();

int main() {
	*setlocale(LC_ALL,"");
	menu();
	return 0;
}

void menu(){	
	int menu;
	int i; 
	
	std::string line, linha;
	int vetor[MAX];
	
	std::ifstream myfile ("numero.txt");
	  
	if (myfile.is_open()){
			  
	int n=0;

	for(int i=0; i<=MAX; i++){
	getline (myfile,line);
	n=stof(line);
	vetor[i] = n;
	}
	myfile.close();
	  
	}else{
		std::cout<<"N�O FOI POSS�VEL ABRIR O ARQUIVO"; 
	}	
	
	std::cout<<"\n=========== MENU ===========";
	std::cout<<"\n(1) - ORDENA��O BUBBLESORT";
	std::cout<<"\n(2) - ORDENA��O INSER��O";
	std::cout<<"\n(3) - ORDENA��O SELE��O";
	std::cout<<"\n(4) - ORDENA��O MERGE";
	std::cout<<"\n(5) - ORDENA��O QUICKSORT";
	std::cout<<"\n(6) - SAIR ";
	std::cout<<"\n============================";	
	std::cout<<"\n### Digite op��o: ";
	std::cin>>menu;
	system("cls");
		
	switch(menu){
		case 1:{
			bubbleSort(vetor, MAX);
			system("pause");
			system("cls");
			volMenu();
			break;
		}
			
		case 2:{
			insertionSort(vetor, MAX);
			system("pause");
			system("cls");
			volMenu();
			break;
		}
			
		case 3:{
			selectionSort(vetor, MAX);
			system("pause");
			system("cls");
			volMenu();
			break;
		}
			
		case 4:{
			mergeVer();
			system("pause");
			system("cls");
			volMenu();
			break;
		}
			
		case 5:{
			quickVer();
			system("pause");
			system("cls");
			volMenu();
			break;
		}
			
		case 6:{
			system("pause");
			std::cout<<"\nSAINDO";
			Sleep(70);
			std::cout<<".";
			Sleep(70);
			std::cout<<".";
			Sleep(70);
			std::cout<<".";
			exit(0);
			break;
		}
			
		default:{
			std::cout<<"\nDIGITE UMA OP��O V�LIDA!\n";
			system("pause");
			std::cout<<"\nRETORNANDO AO MENU.";
			Sleep(150);
			std::cout<<".";
			Sleep(150);
			std::cout<<".";
			system("cls");		
			break;
		}
	}
	
}

void volMenu(){
	int opc;
	
	std::cout<<"\nVoc� deseja voltar ao menu?\n(1) SIM | (2) N�O ";
	std::cout<<"\n### Digite op��o: ";
	std::cin>>opc;
	if(opc == 1){
		std::cout<<"\nVOLTANDO AO MENU...\n";
		Sleep(200);
		system("cls");
		menu();
	}
	if(opc == 2){
		std::cout<<"\nSAINDO";
		Sleep(70);
		std::cout<<".";
		Sleep(70);
		std::cout<<".";
		Sleep(70);
		std::cout<<".";
		exit(0);
	}
	else{
		std::cout<<"\nVoc� digitou errado.\nVOLTANDO AO MENU...\n";
		Sleep(200);
		system("cls");
		menu();
	}
}

void bubbleSort(int vetor[], int a){
	int l, x, auxiliar;
	
	// ordenando do menor para o maior
	// quantidade elementos do vetor - 1
	
	for(int p=0; p<=MAX; p++){
			std::cout << vetor[p] << "\n";
	}
	std::cout << "\nVETOR CARREGADO!\nORDENANDO OS N�MEROS DE FORMA CRESCENTE.\n";
	Sleep(3000);
	
	high_resolution_clock::time_point t1 = 
	high_resolution_clock::now();
	
	for(l=1; l<=a; l++){
		
		for(x=a; x>=l; x--){
			
			if(vetor[x] < vetor[x-1]){
				auxiliar = vetor[x];
				vetor[x] = vetor[x-1];
				vetor[x-1] = auxiliar;
			}
		}
	}	
	
	high_resolution_clock::time_point t2 = 
	high_resolution_clock::now();
	
	// mostrando o vetor

	for(x=0; x<=a-1; x++){
		std::cout << x+1 << " O N�MERO: " << vetor[x] << "\n";
	}
    
	std::cout << "\nVETOR ORDENADO!";
	
	duration<double> time_span = 
	duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "\n\nTempo gasto: " << time_span.count() << " segundos.\n";
	std::cout << std::endl;
}

void insertionSort(int vetor[], int a){
	int l, x, eleito ;

	// ordenando de forma crescente
	// la�o com a quantidade de elementos do vetor - 1
	
	for(int p=0; p<=MAX; p++){
			std::cout << vetor[p] << "\n";
	}
	std::cout << "\nVETOR CARREGADO!\nORDENANDO OS N�MEROS DE FORMA CRESCENTE.\n";
	Sleep(3000);
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	for(x=1; x<=a; x++){
		
		eleito = vetor[x];
		l = x - 1;
		
		// la�o que percorre os elementos �
		// esquerda do n�mero eleito
		// ou at� encontrar a posi��o para
		// recoloca��o do n�mero eleito
		// respeitando a ordena��o procurada
		
		while (l >= 0 && vetor[l] > eleito){
			vetor[l+1] = vetor[l];
			l = l - 1;
		}
		vetor[l+1] = eleito;
	}	
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	
	// mostrando o vetor ordenado
	
	for(x=0; x<=a-1; x++){
		std::cout << "\n" << x+1 << " O N�MERO: " << vetor[x];
	}
	
	std::cout << "\n\nVETOR ORDENADO!";
	
	duration<double> time_span = 
	duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "\n\nTempo gasto: " << time_span.count() << " segundos.\n";
	std::cout << std::endl;
}

void selectionSort(int vetor[], int a){
	int x, l, eleito, menor, posic, ma;
	
	// ordenando de forma crescente
	// la�o que percorre da 1� posi��o
	// � pen�ltima posi��o do vetor
	// elegendo um n�mero para ser comparado
	
	for(int p=0; p<=MAX; p++){
			std::cout << vetor[p] << "\n";
	}
	std::cout << "\nVETOR CARREGADO!\nORDENANDO OS N�MEROS DE FORMA CRESCENTE.\n";
	Sleep(3000);
	
	high_resolution_clock::time_point t1 = 
	high_resolution_clock::now();
	
	for(x=0; x<=l-1; x++){
		eleito = vetor[x];
		
		// encontrando o menor n�mero � direita do eleito
		// com sua respectiva posi��o
		// posi��o do eleito = i
		// primeiro n�mero � direita do
		// eleito na posi��o = i + 1
		
		menor = vetor[x+1];
		posic = x + 1;
		
		// la�o que percorre os elementos
		// que est�o � direita do
		// n�mero eleito, retornando o
		// menor n�mero � direita
		// e sua posi��o
		
		for(l=x+1; l<=a; l++){
			if(vetor[l] < menor){
				menor = vetor[l];
				posic = l;
			}
		}
		
		// troca do n�mero eleito com o n�mero da posi��o pos
		// o n�mero da posi��o pos � o menor n�mero � direita
		// do n�mero eleito
		
		if(menor < eleito){
			vetor[x] = vetor[posic];
			vetor[posic] = eleito;
		}
	}
	
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	
		// mostrando o vetor ordenado
		for(x=0; x<=a-1; x++){
			std::cout << "\n" << x+1 << " O N�MERO: " << vetor[x];
		}
	
	std::cout << "\n\nVETOR ORDENADO!";
	
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "\n\nTempo gasto: " << time_span.count() << " segundos.\n";
	std::cout << std::endl;
}

void intercala(int vetor[], int in, int fim, int meio){
	int noPos, inVetor1, inVetor2, x;
	int auxiliar[MAX];

	inVetor1 = in;
	inVetor2 = meio + 1;
	noPos = in;
	
	while(inVetor1 <= meio && inVetor2 <= fim){
		if(vetor[inVetor1] <= vetor[inVetor2]){
			auxiliar[noPos] = vetor[inVetor1];
			inVetor1 = inVetor1 + 1;
		}
		else{
			auxiliar[noPos] = vetor[inVetor2];
			inVetor2 = inVetor2 + 1;
		}
	noPos = noPos + 1;
	}	
	
	// se ainda existem n�meros no primeiro vetor
	// que n�o foram intercalados
		
		for(x=inVetor1; x<=meio; x++){
			auxiliar[noPos] = vetor[x];
			noPos = noPos + 1;
		}
	
	// se ainda existem n�meros no segundo vetor
	// que n�o foram intercalados
		
		for(x=inVetor2; x<=fim; x++){
			auxiliar[noPos] = vetor[x];
			noPos = noPos + 1;
		}
		
	// retorna os valores do vetor aux para o vetor vet
	
	for(x=in; x<=fim; x++){
		vetor[x] = auxiliar[x];
	}

}

int mergeSort(int vetor[], int in, int fim){
	int meio, x;
	
	if(in < fim){
		meio = (in + fim)/2;
		mergeSort(vetor,in,meio);
		mergeSort(vetor,meio+1,fim);
		intercala(vetor,in,fim,meio);
	}
	
	return *vetor;
}

void mergeVer(){
	int x,d;
	std::string line, linha;
	int vetor[MAX];
	
	std::ifstream myfile ("numero.txt");
	  
	if (myfile.is_open()){
		  
	int x=0;
	
	for(int x=0; x<=MAX; x++){
	getline (myfile,line);
	d=stof(line);
	vetor[x] = d;
	}
	myfile.close();
	  
	}else{
		std::cout << "N�O FOI POSS�VEL ABRIR O ARQUIVO"; 
	}
	
	for(int p=0; p<=MAX; p++){
			std::cout << vetor[p] << "\n";
	}
	std::cout << "\nVETOR CARREGADO!\nORDENANDO OS N�MEROS DE FORMA CRESCENTE.\n";
	Sleep(3000);
	
	high_resolution_clock::time_point t1 = 
	high_resolution_clock::now();
		
	*vetor =  mergeSort(vetor,0,MAX);
	
	high_resolution_clock::time_point t2 = 
	high_resolution_clock::now();
	
	// mostrando o vetor ordenado
	
		for(x=0; x<=MAX-1; x++){
			std::cout << "\n" << x+1 << " O N�MERO: " << vetor[x];
	    }
	
	std::cout << "\n\nVETOR ORDENADO!\n\n";

	duration<double> time_span = 
	duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "Tempo gasto: " << time_span.count() << " segundos.\n";
	std::cout << std::endl;
}

void Quick(int vetor[MAX], int inicio, int fim){
   
   int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);   

}

void quickVer(){
	std::string line, linha;
	int vetor[MAX], n;
	
	std::ifstream myfile ("numero.txt");
	  
	if (myfile.is_open()){
	
	for(int x=0; x<=MAX; x++){
	getline (myfile,line);
	n=stof(line);
	vetor[x] = n;
	}
	myfile.close();
	  
	}else{
		std::cout << "N�O FOI POSS�VEL ABRIR O ARQUIVO"; 
	}
	
	for(int x=0; x<=MAX; x++){
		std::cout << vetor[x] << "\n";
	}
	std::cout << "\nVETOR CARREGADO!\nORDENANDO OS NUMEROS DE FORMA CRESCENTE.\n";
	Sleep(3000);
   
    high_resolution_clock::time_point t1 = 
    high_resolution_clock::now();
 
   Quick(vetor, 0, (MAX-1));
   
   high_resolution_clock::time_point t2 = 
   high_resolution_clock::now();
   
   for(int x=0; x<=MAX-1; x++){
			std::cout << "\n" << x+1 << " O N�MERO: " << vetor[x];
	    }
	
	std::cout << "\n\nVETOR ORDENADO!\n\n";

	duration<double> time_span = 
	duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "Tempo gasto: " << time_span.count() << " segundos.\n";
	std::cout << std::endl;
}

