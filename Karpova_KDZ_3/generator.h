#ifndef KDZ_3_GENERATOR_H
#define KDZ_3_GENERATOR_H

#include <vector>

// Функция для генерации полного графа с n вершинами
std::vector<std::vector<int>> generateCompleteGraph(int n);

// Функция для генерации связного графа с n вершинами и коэффициентом плотности density
std::pair<int, std::vector<std::vector<int>>> generateConnectedGraph(int n, double density);

// Функция для генерации разреженного графа (дерева) с n вершинами
std::pair<int, std::vector<std::vector<int>>> generateSparseGraph(int n);

#endif //KDZ_3_GENERATOR_H