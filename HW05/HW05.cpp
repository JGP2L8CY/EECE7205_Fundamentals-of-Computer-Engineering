#include <string>
#include <fstream>
#include <vector>
#include <utility> 
#include <stdexcept> 
#include <sstream> 
#include <iostream>
#include <limits.h> 
#include <stdio.h> 
#include <unordered_map>

void print_result(int result, int path[], int building1){
    /*Print the distance between two buildings*/
    std::cout << "Shortest Distance between the two buildings: " << result << std::endl;
}

int** read_csv(std::string filename, int number_vertices){
    /*Read distance of buildings in txt data*/
    std::ifstream inf;
    inf.open(filename);
    if(inf.fail()){
        std::cerr << "Error: Could not open input file" << std::endl;
        exit(1);
    }
    /*Create adjacency matrix, which contains number of verticies and fill with 0's*/
    int** result = 0;
    result = new int*[number_vertices];
    for(int i=0; i<number_vertices; i++){
        result[i] = new int[number_vertices];
        for(int j=0; j<number_vertices; j++) 
            result[i][j] = 0;
    }
    /*Read data, line by line*/
    int v0 = 0;
    int v1 = 0;
    int distance = 0;
    int col = 0;
    std::string line, v;
    int val;
    while(std::getline(inf, line)){
        std::stringstream ss(line);
        col = 0;
        /*Extract each integer*/
        while(std::getline(ss, v, ',')){
            val = std::stoi(v);
            if(col==0) v0 = val;
            else if(col==1) v1 = val;
            else distance = val;
            col++;
        }
        /*building_1, building_2, distance*/
        result[v0][v1] = distance;
        result[v1][v0] = distance;
    }
    inf.close();
    return result;
}

// Dijkstra Algorithm
int min_distance(int distances[], bool s[], int N){ 
    /*Get Min_distance of buildings*/
	int min = INT_MAX, min_index; 
	for (int n=0; n<N; n++) 
        /*If the point has not been marked and has min distance, change the min*/
		if (s[n]==false && distances[n]<=min) 
			min=distances[n], min_index=n; 
	return min_index; 
} 

void dijkstra(int **map, int building0, int building1, int N){ 
    /*Main Dijkstra Algorithm*/
	int distances[N];
	bool s[N];
    int path[N]; 
	for (int i=0; i<N; i++){
        /*Set the pristine value of start node*/
		distances[i] = INT_MAX;
        s[i] = false; 
        path[0] = -1;
    }
	distances[building0] = 0; 
	
	for (int i=0; i<N-1; i++) { 
        /*Calculate the shortest path from start to end*/
		int u = min_distance(distances, s, N); 
		s[u] = true; 
		for (int n=0; n<N; n++) 
			if (!s[n] && map[u][n] && distances[u]+map[u][n]<distances[n]){
				distances[n] = distances[u] + map[u][n]; 
            }
	} 
    /*Return destination*/
    int result =  distances[building1];
    print_result(result, path, building1);
} 

int main() {
    // Create data strucure to map vertices to building number.
    std::unordered_map<std::string, int> vertices;
    vertices["23G"] = 0; 
    vertices["23H"] = 1;
    vertices["28"] = 2;
    vertices["29"] = 3;
    vertices["31"] = 4;
    vertices["33"] = 5;
    vertices["34"] = 6;
    vertices["35"] = 7;
    vertices["54"] = 8;
    vertices["55"] = 9;
    vertices["57"] = 10;
    vertices["58"] = 11;
    vertices["a"] = 12;
    vertices["b"] = 13;
    vertices["c"] = 14;
    vertices["d"] = 15; 

    // Get input from user
    std::string b0 = "";
    std::string b1 = "";
    std::cout << "Enter start building: ";
    std::cin >> b0;
    std::cout << "Enter end building: ";
    std::cin >> b1;

    int number_vertices = 16;
    int **adjacency_matrix;
    adjacency_matrix = read_csv("/Users/minsungim/Desktop/neu_graph.txt", number_vertices);
    dijkstra(adjacency_matrix, vertices.at(b0), vertices.at(b1), number_vertices);
    return 0;
}