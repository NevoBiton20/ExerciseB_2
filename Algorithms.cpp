//Id: 214173957
// Email: nevobiton0@gmail.com
#include "Algorithms.hpp"

namespace ariel
{
    bool isPath(Graph g, int a , int b, int marked[])
    { // A function that checks recursively and returns true if there is a path between a and b in graph g and false otherwise.
        int ** mat = g.getMat();
        if(mat[a][b]) // Stopping condition.
        {
            return true;
        }
        marked[a]=1;
        for(size_t i=0; i<g.getDimension(); i++) // Runs through all the neighbors of a
        {
            if(!marked[i] && mat[a][i] && isPath(g,i,b,marked))
            {
                return true;
            }
        }
        return false;
    }

    bool Algorithms::isConnected(Graph g)
    {
        int marked[g.getDimension()];
        for(size_t i = 0; i < g.getDimension(); i++)
        {
            for(size_t j = 0;j < g.getDimension(); j++)
            {
                for(size_t k =0; k<g.getDimension(); k++)
                {
                    marked[k] = 0;
                }

                if(!isPath(g,i,j,marked))
                {
                    return false;
                }
            }
        }
        return true;
    }

    void relax(Graph g,int d[],int p[], int i, int j)
    {
        if(d[j] > d[i] + g.getMat()[i][j])
        {
            d[j] = d[i] + g.getMat()[i][j];
            p[j] = i;
        }
    }                   

    string Algorithms::shortestPath(Graph g, int a, int b)
    {
        int d[g.getDimension()];
        int p[g.getDimension()];
        for(size_t i=0; i<g.getDimension(); i++)
        {
            d[i] = __INT_MAX__;
            p[i] = -1;
        }

        d[a] = 0;

        for(size_t j = 0; j<g.getDimension()-1;j++)
        {
            for(size_t i = 0; i < g.getDimension(); i++)
            {
                for(size_t k = 0;k < g.getDimension(); k++)
                {
                    if(g.getMat()[i][k])
                    {
                        relax(g, d, p, i, k);
                    }
                }
            }
        }

        for(size_t i = 0; i < g.getDimension(); i++)
        {
            for(size_t k = 0;k < g.getDimension(); k++)
            {
                if(g.getMat()[i][k] && d[k] > d[i] + g.getMat()[i][k])
                {
                    return "Error: negative cycle";
                }
            }
        }

        if(d[b] == __INT_MAX__)
        {
            return "-1";
        }

        int pos = b, verticesAmount=1;
        while(pos!=a)
        {
            pos = p[pos];
            verticesAmount++;
        }
        pos = b;

        int way[verticesAmount];
        for(int i=verticesAmount-1; i >= 0; i--)
        {
            way[i] = pos;
            pos = p[pos];
        }

        string route = std::to_string(a);
        for(int j = 1; j<=verticesAmount-1; j++)
        {
            route += "->";
            route += std::to_string(way[j]);
        }
        return route;
    }

    bool dfsVisit(Graph g, int colors[], int p[], int position , int vertex, int previous)
    {
        colors[vertex] = 1;
        for(int i=0; i<g.getDimension();i++)
        {
            if(g.getMat()[vertex][i] && i!=previous && colors[i] == 1)
            {
                p[position] = vertex;
                position++;
                p[position] = i;
                return true;
            }

            if(g.getMat()[vertex][i] && colors[i] == 0)
            {
                p[position] = vertex;
                position++;
                if(dfsVisit(g,colors,p,position,i,vertex))
                {
                    return true;
                }
            }
        }
        colors[vertex] = 2;
        return false;
    }

    bool Algorithms::isContainsCycle(Graph g)
    {
        int colors[g.getDimension()];
        int p[g.getDimension()+1];
        for(int i=0; i<g.getDimension();i++)
        {
            colors[i] = 0;
        }

        for(int j=0; j<g.getDimension();j++)
        {
            for(int k=0; k<=g.getDimension();k++)
            {
                p[k] = -1;
            }
            if(dfsVisit(g, colors,p,0,j,-1))
            {
                string cycle=std::to_string(p[0]);
                for(int h = 1; h<g.getDimension()+1; h++)
                {
                    if(p[h]!=-1)
                    {
                        cycle += "->" + std::to_string(p[h]);
                    }
                }
                cout << cycle+"\n";
                return true;
            }
        }
        return false;
    }
    void color(Graph g,int vertex,int colors[],bool colorN)
    {
        colors[vertex] = colorN;
        for(int i=0;i<g.getDimension();i++)
        {
            if(g.getMat()[vertex][i] && colors[i]==-1)
            {
                color(g,i,colors,!colorN);
            }
        }
    }
    string Algorithms::isBipartite(Graph g)
    {
        int colors[g.getDimension()];
        bool check[g.getDimension()];
        for(int i=0;i<g.getDimension();i++)
        {
            colors[i]=-1;
            check[i]=false;
        }
        color(g,0,colors,true);
        string a="{",b="{";
        for(int k = 0;k<g.getDimension();k++)
        {
            for(int h =0;h<g.getDimension(); h++)
            {
                if(h!=k && g.getMat()[k][h] && colors[k] == colors[h])
                {
                    return "the graph isnt bipartite";
                }

                if(g.getMat()[k][h] && colors[k] && !colors[h])
                {
                    if(!check[k])
                    {
                        a+=" " + std::to_string(k) + " ";     
                    }
                    if(!check[h])
                    {
                        b+=" " + std::to_string(h) + " ";  
                    }
                    check[k] = true;
                    check[h] = true;
                }
            }
        }
        a+="}";
        b+="}";
        return "the graph is bipartite: A = " + a + ", B = " + b;
    }
    
    bool bellmanFord(Graph g, int vertex)
    {
        int d[g.getDimension()];
        int p[g.getDimension()];
        for(size_t i=0; i<g.getDimension(); i++)
        {
            d[i] = __INT_MAX__;
            p[i] = -1;
        }

        d[vertex] = 0;

        for(size_t j = 0; j<g.getDimension()-1;j++)
        {
            for(size_t i = 0; i < g.getDimension(); i++)
            {
                for(size_t k = 0;k < g.getDimension(); k++)
                {
                    if(g.getMat()[i][k])
                    {
                        relax(g, d, p, i, k);
                    }
                }
            }
        }

        for(size_t i = 0; i < g.getDimension(); i++)
        {
            for(size_t k = 0;k < g.getDimension(); k++)
            {
                if(g.getMat()[i][k] && d[k] > d[i] + g.getMat()[i][k])
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    string Algorithms::negativeCycle(Graph g)
    {
        for(int i=0; i<g.getDimension();i++)
        {
            if(bellmanFord(g,i))
            {
                return "Negative cycle found!";
            }
        }
        return "There are no negative cycles in the graph";
    }
}
    