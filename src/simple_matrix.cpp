//
//  simple_matrix.cpp
//  filter_for_cnn_demo_feb2023
//
//  Created by Wesley Talbot on 2/8/23.
//

#include "simple_matrix.hpp"



vector<vector<int>> SimpleMatrix::create_empty_matrix(int nRows, int nCols){
   
    vector<vector<int>> empty_matrix;
    
    for(int i = 0; i < nRows; i++){
        vector<int> temp;
        
        for(int j = 0; j < nCols; j++){
            temp.push_back(0);
        }
        empty_matrix.push_back(temp);
    }
    
    
    return empty_matrix;
}

//--------------------------------------------------------------

vector<vector<int>> SimpleMatrix::create_random_matrix(int nRows, int nCols, int value_max){
   
    vector<vector<int>> rand_matrix;
    
    for(int i = 0; i < nRows; i++){
        vector<int> temp;
        
        for(int j = 0; j < nCols; j++){
            temp.push_back(ofRandom(value_max));
        }
        rand_matrix.push_back(temp);
    }
    
    
    return rand_matrix;
}

//--------------------------------------------------------------

vector<vector<int>> SimpleMatrix::substitute_index(int row, int col, int new_value, vector<vector<int>> matrix){
   
    matrix[row][col] = new_value;
    
    return matrix;
    
}

//--------------------------------------------------------------

int SimpleMatrix::get_matrix_index(int row, int col, vector<vector<int>> matrix){
    
    int index_value = matrix[row][col];
    
    return index_value;
}

//--------------------------------------------------------------

vector<vector<int>> SimpleMatrix::add_matrices(vector<vector<int>> m1, vector<vector<int>> m2){
   
    vector<vector<int>> matrix_sum;
  
    for(int i = 0; i < m1.size(); i++){
        vector<int> temp;
        for (int j = 0; j < m1[i].size(); j++){
            temp.push_back(m1[i][j] + m2[i][j]);
        }
        matrix_sum.push_back(temp);
    }
    
    return matrix_sum;
}

//--------------------------------------------------------------

vector<int> SimpleMatrix::add_vectors(vector<int> v1, vector<int> v2){
   
    vector<int> matrix_sum;
  
    for(int i = 0; i < v1.size(); i++){
            matrix_sum.push_back(v1[i] + v2[i]);
    }
    
    return matrix_sum;
}

//--------------------------------------------------------------

vector<vector<int>> SimpleMatrix::multiply_matrices(vector<vector<int>> m1, vector<vector<int>> m2){

    vector<vector<int>> result = create_empty_matrix(m1.size(), m1[0].size());

    vector<int> temp_1;
    vector<int> temp_2;
    vector<int> temp_result_a;
    vector<int> temp_result_b;
    vector<int> temp_result_c;

    //prime this vector with zeros
    for(int x = 0; x < m1.size(); x++){
        temp_result_b.push_back(0);
    }


    int m2Col = 0;

    for(int i = 0; i < m2[0].size(); i++){

        //Get single Row valies from M1
        for(int j = 0; j < m2.size(); j++){
            temp_1.push_back(m2[j][m2Col]);

            if(temp_1.size() == m2.size()){
                
                int m1Col = 0;

                for(int k = 0; k < m1[0].size(); k++){

                    for(int m = 0; m < m1.size(); m++){
                        temp_2.push_back(m1[m][m1Col]);

                        if(temp_2.size() == m1.size()){

                            temp_result_a = scalar_by_vector(temp_1[m1Col], temp_2);

                            temp_result_c = add_vectors(temp_result_a, temp_result_b);

                            temp_result_b = temp_result_c;

                            temp_2.clear();
                        }

                    }

                    m1Col +=1;
                }

                //Re-assemble the vectors into the original matrix format:
                for(int p = 0; p < m1.size(); p++){
                    result[p][m2Col] = temp_result_c[p];
                }
                temp_1.clear();
                temp_result_b.clear();
                for(int x = 0; x < m1.size(); x++){
                    temp_result_b.push_back(0);
                }
            }
        }
        m2Col +=1;
    }

    return result;
}

//--------------------------------------------------------------

vector<vector<int>> SimpleMatrix::scalar_by_matrix(int scalar, vector<vector<int>> m){
   
    vector<vector<int>> temp_matrix;
    temp_matrix = m;
    
    for(int i = 0; i < temp_matrix.size(); i++){
        for (int j = 0; j < temp_matrix[i].size(); j++){
            temp_matrix[i][j] = temp_matrix[i][j] * scalar;
        }
    }
    
    return temp_matrix;
}

//--------------------------------------------------------------

vector<int> SimpleMatrix::scalar_by_vector(int scalar, vector<int> m){
   
    vector<int> temp_matrix;
    temp_matrix = m;
    
    
    for (int j = 0; j < temp_matrix.size(); j++){
        temp_matrix[j] = temp_matrix[j] * scalar;
    }
    
    
    return temp_matrix;
}

//--------------------------------------------------------------

vector<vector<int>> SimpleMatrix::get_determinant(vector<vector<int>> m1, vector<vector<int>> m2){
   
    vector<vector<int>> r;
    
    return r;
}

//--------------------------------------------------------------

vector<vector<int>> SimpleMatrix::get_inverse(vector<vector<int>> m1, vector<vector<int>> m2){
   
    vector<vector<int>> r;
    
    return r;
}

//--------------------------------------------------------------


