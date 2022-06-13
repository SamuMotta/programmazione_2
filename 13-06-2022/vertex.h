#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>

using namespace std;

template <typename T>
class Vertex {
    T key;
    template <typename U>
    friend class Grafo;
    public:
        Vertex(T key) : key(key) {}
        Vertex() : Vertex(NULL) {}

        bool operator == (Vertex<T>& v) {
            return this->key == v.key;
        }
        friend ostream& operator << (ostream& out, Vertex<T>& v) {
            out << v.key;
            return out;
    }
};

template<typename T>
class Grafo {
    Vertex<T>** vertices;
    bool** adj;
    int max_size = 0;
    int nVertices = 0;

    public:

    Grafo(int max_size) : max_size(max_size) {
        vertices = new Vertex<T>[max_size];
        adj = new bool*[max_size];
        for (int i = 0; i < max_size; i++) {
            adj[i] = new bool[max_size];

            for(int j = 0; j < max_size; j++) {
                adj[i][j] = false;
            }
        }
    }

    void addVertex(T key) { 
        if(this->nVertices == this->max_size) {
            cerr << "Graph is full." << endl;
            return;
        }

        vertices[nVertices++] = new Vertex<T>(key);
    }

    void addEdge (T key1, T key2) {
        int i = this->search(key1);
        int j = this->search(key2);

        if (i != -1 && j != -1) {
            adj[i][j] = true;
        }
        else {
            if (i == -1) 
                cerr << "There is no vertex with key." << key1 << endl;
            else
                cerr << "There is no vertex with key." << key2 << endl;
        }
    }

    int search(T key) {
            if(this->nVertices == 0) {
                return -1;
            }

            for (int i = 0; i < this->nVertices; i++) {
                if(vertices[i]->key == key) {
                    return i;
                }
            }

            return -1;
        }

        friend ostream& out operator << (ostream& out, Grafo<T>& g) {

            for (int i = 0; i < g.nVertices; i++) {
                out << "v[" << i <<"] = " << g.vertices[i]->key << "\t";
            }

            out << endl;

            for (int i = 0; i < g.nVertices; i++) {
                for (int j = 0; j < g.nVertices; j++) {
                    if (g.adj[i,j]) {
                        out << "(" << i << ", " << j << ")" << endl;
                    }
                }
            }

            return out;
        }
};
#endif