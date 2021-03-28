#include <stdio.h>
#include <stdlib.h>
#include "grafo_header.h"


Grafo preencherGrafo(Grafo g, int peso){
    for(int i = 0;i<g->verticesInseridos;i++){
        for(int j = 0;j<g->verticesInseridos;j++){
            g->arestas[i][j] = peso;
        }
    }
}

Grafo inicializar(int n, bool ponderado) {
    int i,  j;
    Grafo g = malloc(sizeof *g); //alocando dinamicamente na memória
    g->ponderado = ponderado;
    g-> verticesInseridos = n; //inserindo no grafo a quantidade de verticies
    g->arestas = malloc(n * sizeof(int *)); //alocando dinamicamente na memoria um array para cada vertica (iniciando a construção da matriz de adjdacencia)
    for(i = 0;i<n;i++){
        g->arestas[i] = malloc(n * sizeof(int *)); //dizendo que cada posicao do array terá tamanho igual a quantidade de bits de um inteiro
    }
    if(ponderado == true){
        g = preencherGrafo(g, INT_MAX);
    }
    else {          
        g = preencherGrafo(g, 0);
    }

    return g;
}

int obterIndiceVertice(Grafo g, char* rotuloVertice) {
    for(int i = 0;i<g->verticesInseridos;i++){
        for(int j = 0;j<g->verticesInseridos;j++){
            if(g->rotuloVertices[i][j] == rotuloVertice){
                return i;
            }
        }
    }
}

void inserirAresta(Grafo g, char* rotuloVOrigem, char* rotuloVDestino, int peso) {
    int verticeOrigem  = obterIndiceVertice(g, rotuloVOrigem);
    int verticeDestino = obterIndiceVertice(g, rotuloVDestino);

    if(g->ponderado){
        g->arestas[verticeOrigem][verticeDestino] = peso;
        g->arestas[verticeDestino][verticeOrigem] = peso; 
    }
    else{
        peso = 1;
        g->arestas[verticeOrigem][verticeDestino] = peso;
        g->arestas[verticeDestino][verticeOrigem] = peso; 
    }
}

void inserirVertice(Grafo g, char* rotuloVertice) {

}

bool saoConectados(Grafo g, char* rotuloVOrigem, char* rotuloVDestino) {
    int verticeOrigem  = obterIndiceVertice(g, rotuloVOrigem);
    int verticeDestino = obterIndiceVertice(g, rotuloVDestino);

    if(g->ponderado){
        if(g->arestas[verticeOrigem][verticeDestino] != INT_MAX) {
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(g->arestas[verticeOrigem][verticeDestino] != 0) {
            return true;
        }
        else{
            return false;
        }
    }
}
