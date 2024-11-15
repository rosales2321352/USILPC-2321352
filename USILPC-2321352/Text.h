#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <sstream>
#include <string>
#include <map>

using namespace std;


struct BBox {
    double x1;
    double y1;
    double x2;
    double y2;
    double x_center;
    double y_center;
    string text;
};



// Estructura para representar un punto en 2D
struct Point {
    double x, y;
    Point(double x_val, double y_val) : x(x_val), y(y_val) {}
};

// Función para calcular la distancia euclidiana entre dos puntos
double euclidean_distance(const Point& p1, const Point& p2) {
    return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// Función para encontrar los vecinos de un punto dentro del radio eps
std::vector<int> region_query(const std::vector<Point>& points, int point_idx, double eps) {
    std::vector<int> neighbors;
    for (int i = 0; i < points.size(); ++i) {
        if (euclidean_distance(points[point_idx], points[i]) <= eps) {
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

// Función para expandir un grupo a partir de un punto
void expand_cluster(std::vector<int>& labels, const std::vector<Point>& points, int point_idx, int cluster_id, double eps, int min_samples) {
    labels[point_idx] = cluster_id;
    std::vector<int> seeds = region_query(points, point_idx, eps);
    seeds.erase(std::remove(seeds.begin(), seeds.end(), point_idx), seeds.end()); // Eliminar el propio punto

    for (int i = 0; i < seeds.size(); ++i) {
        int neighbor_idx = seeds[i];
        if (labels[neighbor_idx] == -1) { // Si el vecino es ruido
            labels[neighbor_idx] = cluster_id; // Convertir a miembro del grupo
        }
        if (labels[neighbor_idx] == 0) { // Si el vecino no está etiquetado aún
            labels[neighbor_idx] = cluster_id;
            std::vector<int> new_seeds = region_query(points, neighbor_idx, eps);
            if (new_seeds.size() >= min_samples) {
                seeds.insert(seeds.end(), new_seeds.begin(), new_seeds.end());
            }
        }
    }
}

// Función principal para aplicar DBSCAN
std::vector<int> dbscan(const std::vector<Point>& points, double eps, int min_samples) {
    std::vector<int> labels(points.size(), 0); // 0 significa sin grupo
    int cluster_id = 0;

    for (int i = 0; i < points.size(); ++i) {
        if (labels[i] != 0) continue; // Ya fue etiquetado

        std::vector<int> neighbors = region_query(points, i, eps);
        if (neighbors.size() < min_samples) {
            labels[i] = -1; // Etiquetar como ruido
        }
        else {
            ++cluster_id;
            expand_cluster(labels, points, i, cluster_id, eps, min_samples);
        }
    }

    return labels;
}

string GetOCR() {
    vector<BBox>* lista = new vector<BBox>;
    fstream stream;

    stream.open("data.csv", ios_base::in | ios_base::app);
    if (!stream.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return "";
    }
    string line;
    // Omitir encabezados
    if (getline(stream, line))
    {
        // Leer datos
        while (getline(stream, line))
        {
            try
            {
                std::stringstream ss(line);
                std::string item;
                BBox objeto;
                //Omitir indice
                getline(ss, item, ',');
                if (getline(ss, item, ','))
                    objeto.x1 = stold(item);
                if (getline(ss, item, ','))
                    objeto.y1 = stold(item);
                if (getline(ss, item, ','))
                    objeto.x2 = stold(item);
                if (getline(ss, item, ','))
                    objeto.y2 = stold(item);
                if (getline(ss, item, ','))
                    objeto.x_center = stold(item);
                if (getline(ss, item, ','))
                    objeto.y_center = stold(item);
                if (getline(ss, item, ','))
                    objeto.text = item;
                lista->push_back(objeto);
            }
            catch (const std::exception& e)
            {
                std::cerr << "Error al procesar la línea: " << line << "\n"
                    << e.what() << '\n';
            }
        }
    }
    stream.close();

    //// Ejemplo de puntos
    std::vector<Point> points;
    for (int i = 0; i < lista->size(); i++)
    {
        points.push_back(Point((*lista)[i].x_center, (*lista)[i].y_center));
    }

    //// Parámetros DBSCAN
    double eps = 50.0;  // Distancia máxima para ser considerado vecino
    int min_samples = 2; // Mínimo número de puntos para formar un grupo

    //// Aplicar DBSCAN
    std::vector<int> labels = dbscan(points, eps, min_samples);

    //// Imprimir los resultados
    map<int, vector<BBox>> mapa;
    for (int i = 0; i < labels.size(); ++i) {
        mapa[labels[i]].push_back((*lista)[i]);
        /*std::cout << "Punto " << i + 1 << " (" << points[i].x << ", " << points[i].y << ") -> Grupo " << labels[i] << std::endl;*/
    }
    string texto_completo = "";
    for (auto& item : mapa) {
        string texto = "";
        for (int i = 0; i < item.second.size(); i++) {
            texto += item.second[i].text + " ";
        }
        texto_completo += texto + "\n";
    }

    return texto_completo;
}