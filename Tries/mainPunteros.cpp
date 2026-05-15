#include <bits/stdc++.h>
using namespace std;

// 1. Definición del Nodo
struct TrieNode {
    TrieNode* children[26]; // Arreglo de punteros a los nodos hijos
    bool isEnd;             // Bandera de fin de palabra

    // Constructor: Inicializa todo en nulo y falso
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// 2. La Clase Trie
class Trie {
private:
    TrieNode* root;

    // Función recursiva privada para liberar memoria (El "dolor de cabeza" de CP)
    void clearMemory(TrieNode* node) {
        if (node == nullptr) return;
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != nullptr) {
                clearMemory(node->children[i]);
            }
        }
        delete node; // Liberamos la memoria del nodo actual
    }

public:
    // Constructor del Trie
    Trie() {
        root = new TrieNode(); // La raíz siempre existe y está vacía
    }

    // Destructor: Se llama automáticamente para limpiar la memoria
    ~Trie() {
        clearMemory(root);
    }

    // Método para insertar
    void insert(const string& word) {
        TrieNode* node = root; // Empezamos en la raíz
        for (char c : word) {
            int index = c - 'a';
            // Si el puntero es nulo, la puerta está "cerrada". Creamos la habitación.
            if (node->children[index] == nullptr) {
                node->children[index] = new TrieNode();
            }
            // Saltamos al siguiente nodo
            node = node->children[index];
        }
        node->isEnd = true; // Marcamos el final
    }

    // Método para buscar palabra exacta
    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            // Si en algún punto el puntero es nulo, el camino no existe
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return node->isEnd; // Solo es true si llegamos a un final válido
    }

    // Método para buscar prefijo
    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == nullptr) {
                return false;
            }
            node = node->children[index];
        }
        return true; // Si terminamos el ciclo sin chocar con un nulo, el prefijo existe
    }
};

int main() {
    Trie* miDiccionario = new Trie();

    miDiccionario->insert("david");
    miDiccionario->insert("avalos");

    cout << "¿Existe 'david'? " << (miDiccionario->search("david") ? "Sí" : "No") << "\n";
    cout << "¿Empieza con 'ava'? " << (miDiccionario->startsWith("ava") ? "Sí" : "No") << "\n";

    // Al liberar el diccionario, se llama al destructor (~Trie) y se limpia todo
    delete miDiccionario; 

    return 0;
}