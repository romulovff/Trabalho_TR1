#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <iterator>
#include "../include/enlace.hpp"
#include "../include/fisica.hpp"

#define TAM_QUADRO 8

using namespace std;
long int size = 0;
int posicaoTotal = 0;
char mem[1000];
char quadro[8];
char hamming[12];

void pegarDadosEnvio(){
	FILE *file;
	file = fopen("../assets/text.bin", "rb");
	fread(mem, sizeof(mem), 1, file);
	fseek(file, 0L, SEEK_END);
	size = ftell(file);
}

void montarQuadro(){
	int j = 0;
	for(int i = posicaoTotal; i < (posicaoTotal+8); i++){
		quadro[j] = mem[i];
		j++;
	}
	j = 0; posicaoTotal += 9;
	printf("Quadro: %s\n", quadro);
}

void bitParidade(){
	bool paridadeBool = false;
	for(int i = 0; i < TAM_QUADRO; i++){
		if(quadro[i] == '1'){
			paridadeBool = !paridadeBool;
		}
	}
	printf("Bit paridade par: %d\n", paridadeBool);
	printf("Bit paridade impar: %d\n", !paridadeBool);
}

// void codigoDeHamming(){
// 	int j = 0;
// 	int potencias[] = {1,2,4,8};
// 	for(int i = 1; i <= 12; i++){
// 		bool exists = find(begin(potencias), end(potencias), i) != end(potencias);
// 		if(!exists){
// 			hamming[i] = quadro[j];
// 			j++;
// 		}
// 	}
// 	printf("Hamming: %s\n", hamming);
// }

int main(int argc, char const *argv[]) {
	pegarDadosEnvio();
	while(size != 0){
		montarQuadro();
		bitParidade();
		//codigoDeHamming();
		size -= 9;
	}
    return 0;
}
