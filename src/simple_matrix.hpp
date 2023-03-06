//
//  simple_matrix.hpp
//  filter_for_cnn_demo_feb2023
//
//  Created by Wesley Talbot on 2/8/23.
// https://www.youtube.com/watch?v=jmo_HN_-PxI&t=1124s

#ifndef simple_matrix_hpp
#define simple_matrix_hpp

#include "ofMain.h"
#include <stdio.h>

class SimpleMatrix{
    public:
    
    vector<vector<int>> create_empty_matrix(int nRows, int nCols);
    vector<vector<int>> create_random_matrix(int nRows, int nCols, int value_max);
    vector<vector<int>> substitute_index(int row, int col, int new_value, vector<vector<int>> matrix);
    int                 get_matrix_index(int row, int col, vector<vector<int>> matrix);
    
    vector<vector<int>> add_matrices(vector<vector<int>> m1,vector<vector<int>> m2);
    vector<int>         add_vectors(vector<int> v1, vector<int> v2);
    vector<vector<int>> multiply_matrices(vector<vector<int>> matrix_2,vector<vector<int>> matrix_1);
    vector<vector<int>> scalar_by_matrix(int scalar,vector<vector<int>> m);
    vector<int>         scalar_by_vector(int scalar,vector<int> m);
    
    vector<vector<int>> get_determinant(vector<vector<int>> m1,vector<vector<int>> m2);
    vector<vector<int>> get_inverse(vector<vector<int>> m1,vector<vector<int>> m2);


   
};
#endif /* simple_matrix_hpp */
