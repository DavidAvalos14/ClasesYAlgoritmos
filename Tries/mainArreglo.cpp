#include <bits/stdc++.h>
using namespace std;

// Constantes globales para la competencia
const int MAX_NODES = 100005; // Ajustar según los límites del problema (suma total de caracteres a insertar)
const int ALPHABET_SIZE = 26; // Para letras minúsculas (a-z)

// Estructura estática del Trie
int trie[MAX_NODES][ALPHABET_SIZE];
bool isEnd[MAX_NODES];
int nodeCount = 1; // El nodo 0 siempre es la raíz

// Función para insertar una palabra
void insert(const string& word) {
    int node = 0; // Empezamos desde la raíz
    for (char c : word) {
        int index = c - 'a'; // Convertimos la letra a un índice (0 a 25)
        
        // Si no existe un camino para esta letra, creamos un nuevo nodo
        if (trie[node][index] == 0) {
            trie[node][index] = nodeCount++;
        }
        // Saltamos al siguiente nodo
        node = trie[node][index];
    }
    // Marcamos el último nodo como el final de una palabra válida
    isEnd[node] = true;
}

// Función para buscar si una palabra exacta existe en el Trie
bool search(const string& word) {
    int node = 0;
    for (char c : word) {
        int index = c - 'a';
        // Si en algún punto el camino se rompe, la palabra no existe
        if (trie[node][index] == 0) {
            return false;
        }
        node = trie[node][index];
    }
    // Retorna true solo si terminamos en un nodo marcado como fin de palabra
    return isEnd[node];
}

// Función para buscar si existe ALGUNA palabra que empiece con este prefijo
bool startsWith(const string& prefix) {
    int node = 0;
    for (char c : prefix) {
        int index = c - 'a';
        if (trie[node][index] == 0) {
            return false;
        }
        node = trie[node][index];
    }
    // Si logramos recorrer todo el prefijo sin que se rompa el camino, el prefijo existe
    return true;
}

// OBLIGATORIO PARA CP: Función para limpiar el Trie entre casos de prueba
void clearTrie() {
    // Solo limpiamos la memoria que realmente usamos, no todo el arreglo (para evitar TLE)
    for (int i = 0; i < nodeCount; i++) {
        memset(trie[i], 0, sizeof(trie[i]));
        isEnd[i] = false;
    }
    nodeCount = 1; // Reiniciamos el contador
}

int main() {
    // Optimizaciones de I/O para C++ (clásicas en CP)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    insert("flower");
    insert("flight");
    insert("flow");

    // Simulación de un nuevo caso de prueba
    clearTrie(); 

    return 0;
}