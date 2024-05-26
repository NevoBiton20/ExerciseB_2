// Id: 214173957
// Email: nevobiton0@gmail.com
#include "Graph.hpp"

namespace ariel
{
    void Graph::loadGraph(vector<vector<int>> vec)
    {
        // Get dimensions
        size_t Rows = vec.size();
        size_t Cols = vec[0].size();
        if(Rows!=Cols)
        {
            cout << "Invalid graph: The graph is not a square matrix.\n";
            return; // not a square matrix
        }

        this->AMat = new int*[Rows];
        for(size_t i = 0; i < Rows; i++)
        {
            this->AMat[i] = new int[Cols]; 
        }

        for(size_t i = 0; i < Rows; i++)
        {
            for(size_t j = 0; j < Cols; j++)
            {
                this->AMat[i][j] = vec[i][j];
            }
        }
        this->vertices = Rows;
    }

    void Graph::printGraph()
    {
        if(this->AMat==NULL)
        {
            cout << "Graph was not initialized yet\n";
            return;
        }

        int edges = 0;
        for(size_t i = 0 ;i < vertices; i++)
        {
            for(size_t j = i+1; j < vertices ; j++)
            {
                if(AMat[i][j])
                {
                    edges++;
                }
            }
        }

        cout << "Graph with "<< vertices <<" vertices and "<< edges <<" edges.\n";
    }

    int** Graph::getMat()
    {
        return this->AMat;
    }

    size_t Graph::getDimension()
    {
        return this->vertices;
    }

    Graph operator+(const Graph& mat, int x)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        vector<vector<int>> vec;
        size_t size  = mat.vertices;
        vec.resize(size);

        for (size_t i = 0; i < mat.vertices; ++i) {

            vec[i].resize(size);

            for (size_t j = 0; j < mat.vertices; ++j) {

                vec[i][j] = mat.AMat[i][j] + x;

            }
        }

        Graph result;
        result.loadGraph(vec);
        return result;
    }

    Graph operator+(const Graph &first,const Graph &second )
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }

        if(first.vertices != second.vertices)
        {
            cout << "Matrix aren't the same size\n";
            exit(EXIT_FAILURE);
        }

        vector<vector<int>> vec;
        size_t size = first.vertices;
        vec.resize(size);

        for (size_t i = 0; i < size; ++i) {

            vec[i].resize(size);

            for (size_t j = 0; j < size; ++j) {

                vec[i][j] = first.AMat[i][j] + second.AMat[i][j];

            }
        }
        
        Graph result;
        result.loadGraph(vec);
        return result;
    }

    Graph operator+=(Graph mat, int x)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        int size = mat.vertices;
        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                mat.AMat[i][j] += x;
            }
        }
        return mat;
    }

    Graph operator-(const Graph &mat, int x)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        vector<vector<int>> vec;
        vec.resize(mat.vertices);

        for (size_t i = 0; i < mat.vertices; ++i) {

            vec[i].resize(mat.vertices);

            for (size_t j = 0; j < mat.vertices; ++j) {

                vec[i][j] = mat.AMat[i][j] - x;
            }
        }

        Graph result;
        result.loadGraph(vec);
        return result;
    }

    Graph operator-(const Graph &first,const Graph &second)
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }

        if(first.vertices != second.vertices)
        {
            cout << "Matrix aren't the same size\n";
            exit(EXIT_FAILURE);
        }

        vector<vector<int>> vec;
        vec.resize(first.vertices);

        for (size_t i = 0; i < first.vertices; ++i) {

            vec[i].resize(first.vertices);

            for (size_t j = 0; j < first.vertices; ++j) {

                vec[i][j] = first.AMat[i][j] - second.AMat[i][j];

            }
        }
        
        Graph result;
        result.loadGraph(vec);
        return result;
    }

    Graph operator-=(Graph &mat, int x)
    {
        int size = mat.vertices;
        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                mat.AMat[i][j] -= x;
            }
        }
        return mat;
    }

    bool operator==(const Graph &first,const Graph &second)
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }
        if(first.vertices != second.vertices)
        {
            return false;
        }

        int size = first.vertices;
        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                if(first.AMat[i][j] != second.AMat[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Graph &first,const Graph &second)
    {
        return !(first == second);
    }

    bool operator<(const Graph &first,const Graph &second)
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }

        if(first == second)
        {
            return false;
        }

        int size = first.vertices>second.vertices ? second.vertices : first.vertices;

        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                if(first.AMat[i][j]>0 && first.AMat[i][j] != second.AMat[i][j])
                {
                    if(first.edges < second.edges)
                    {
                        return true;
                    }
                    else if(first.edges == second.edges)
                    {
                        if(first.vertices < second.vertices)
                        {
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool operator>(const Graph &first,const Graph &second)
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }

        if(first == second)
        {
            return false;
        }

        int size = first.vertices>second.vertices ? second.vertices : first.vertices;

        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                if(second.AMat[i][j]>0 && second.AMat[i][j] != first.AMat[i][j])
                {
                    if(second.edges < first.edges)
                    {
                        return true;
                    }
                    else if(first.edges == second.edges)
                    {
                        if(second.vertices < first.vertices)
                        {
                            return true;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool operator<=(const Graph &first,const Graph &second)
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }
        if(first < second || first == second)
        {
            return true;
        }
        return false;
    }

    bool operator>=(const Graph &first,const Graph &second)
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }
        if(first > second || first == second)
        {
            return true;
        }
        return false;
    }

    Graph operator++(Graph& mat)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        int size = mat.vertices;
        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                if(mat.AMat[i][j]>0)
                {
                    mat.AMat[i][j]++;
                }
            }
        }
        return mat;
    }

    Graph operator--(Graph& mat)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        int size = mat.vertices;
        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                if(mat.AMat[i][j]>0)
                {
                    mat.AMat[i][j]--;
                }
            }
        }
        return mat;
    }

    Graph operator++(Graph& mat,int x)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        Graph temp = mat;
        int size = mat.vertices;
        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                if(mat.AMat[i][j]>0)
                {
                    mat.AMat[i][j]++;
                }
            }
        }
        return temp;
    }

    Graph operator--(Graph& mat, int x)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        Graph temp = mat;
        int size = mat.vertices;
        for(int i = 0; i < size; ++i) {

            for (int j = 0; j < size; ++j) 
            {
                if(mat.AMat[i][j]>0)
                {
                    mat.AMat[i][j]--;
                }
            }
        }
        return temp;
    }

    Graph operator*=(Graph &mat, int x)
    {
        if(mat.AMat == NULL)
        {
            exit(EXIT_FAILURE);
        }
        int size = mat.vertices;
        for(int i = 0; i < size; ++i) 
        {
            for (int j = 0; j < size; ++j) 
            {
                mat.AMat[i][j] *= x;
            }
        }
        return mat;
    }
    Graph operator/=(Graph &mat, int x)
    {
        return mat*=1/x;
    }
    Graph operator*(const Graph &first,const Graph &second)
    {
        if(first.AMat == NULL || second.AMat == NULL)
        {
            cout << "Matrix aren't initialized\n";
            exit(EXIT_FAILURE);
        }

        if(first.vertices != second.vertices)
        {
            cout << "The number of columns in the first matrix must be equal to the number of rows in the second matrix.\n";
            exit(EXIT_FAILURE);
        }

        
        vector<vector<int>> vec(first.vertices, vector<int>(first.vertices,0));
        for(size_t h = 0; h<first.vertices; h++)
        {
            for(size_t k = 0; k<first.vertices; k++)
            {
                for(size_t l = 0; l<first.vertices; l++)
                {
                    vec[h][k] += first.AMat[h][l] * second.AMat[l][k];
                }
            }
        }
        Graph result;
        result.loadGraph(vec);
        return result;
    }

    ostream& operator<<(ostream& os, const Graph& mat)
    {
        for(int i = 0; i< mat.vertices; i++)
        {
            os<<"[";
            for(int j = 0; j<mat.vertices; j++)
            {
                if(j==mat.vertices-1)
                {
                    os <<mat.AMat[i][j];
                }
                else{
                    os <<mat.AMat[i][j]<<", ";
                }
            }

            if(i==mat.vertices-1)
            {
                os<<"]";
            }
            else
            {
                os<<"], ";
            }
        }
        os<<"\n";
        return os;
    }
}