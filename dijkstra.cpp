#include "dijkstra.h"
#define INF DBL_MAX
std::map<std::string, double> dijkstraSSSP::dijkstra(const std::string src)
{
    // Create a vector for distances with all infinity
    // airportNode srcNode = getnodeDict()[src];
    
    std::map<std::string, double> dist;
    std::vector<std::string> nodeList;
    if (src[0] < 'A')   nodeList = (getairports()).airportList_ID();
    else    nodeList = (getairports()).airportList_IAIA();
    
    for (int i = 0; i < dist.size(); i++)
        dist[nodeList[i]] = INF;
    // Insert source with distance 0.0
    
    pq.push(std::make_pair(0.0, src));
    //pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        airportNode u = pq.top().first;
        pq.pop();
        myContainer neighbour = this->getEdges(u);
        for (auto i = neighbour.begin(); i != neighbour.end(); ++i)
        {
            // Get vertex label and weight of current adjacent of u.
            std::string v = (*i).first;
            double weight = (*i).second;

            //  If there is shorted path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    /* // print result
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
        */
    return dist;
}