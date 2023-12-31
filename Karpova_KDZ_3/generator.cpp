#include "generator.h"
#include <iostream>
#include <vector>
#include <random>

// Функция для генерации полного графа с n вершинами
std::vector<std::vector<int>> generateCompleteGraph(int n) {

    // инициализируем полный граф
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // подготавливаем генераторы случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> weightDis(1, 10);

    // добавляем вершины в полный граф
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int weight = weightDis(gen);
            graph[i][j] = weight;
            graph[j][i] = weight;
        }
    }

    return graph;
}

// Функция для генерации связного графа с n вершинами и коэффициентом плотности density
std::pair<int, std::vector<std::vector<int>>> generateConnectedGraph(int n, double density) {

    // инициализируем свзной граф
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // подготавливаем генераторы случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, n * (n - 1) / 2);

    int numEdges = dis(gen);

    // убеждаемся в корректности сгенерированных весов и индексов
    std::uniform_int_distribution<> weightDis(1, 10);
    for (int k = 0; k < numEdges; ++k) {
        int i, j;

        do {
            i = std::uniform_int_distribution<>(0, n - 1)(gen);
            j = std::uniform_int_distribution<>(0, n - 1)(gen);
        } while (i == j || graph[i][j] != 0);

        int weight = weightDis(gen);
        graph[i][j] = weight;
        graph[j][i] = weight;
    }

    // заполняем граф
    std::uniform_real_distribution<> probDis(0.0, 1.0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (graph[i][j] == 0 && probDis(gen) < density) {
                int weight = weightDis(gen);
                graph[i][j] = weight;
                graph[j][i] = weight;
            }
        }
    }

    return std::make_pair(numEdges, graph);
}

// Функция для генерации разреженного графа (дерева) с n вершинами
std::pair<int, std::vector<std::vector<int>>> generateSparseGraph(int n) {

    // инициализируем разреженный граф
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));

    // подготавливаем генераторы случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> numEdgesDis(1, n - 1);

    int numEdges = numEdgesDis(gen);

    for (int i = 0; i < numEdges; ++i) {
        int u = std::uniform_int_distribution<>(0, n - 1)(gen);
        int v = std::uniform_int_distribution<>(0, n - 1)(gen);

        // убеждаемся в корректности сгенерированных данных
        while (u == v || graph[u][v] != 0) {
            u = std::uniform_int_distribution<>(0, n - 1)(gen);
            v = std::uniform_int_distribution<>(0, n - 1)(gen);
        }

        // заполняем граф
        int weight = std::uniform_int_distribution<>(1, 10)(gen);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }

    return std::make_pair(numEdges, graph);
}
