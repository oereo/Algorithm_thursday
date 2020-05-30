V = 4
INF = 99999

def floydWarshall(graph):
    # dist = list(map(lambda i : list(map(lambda j: j, i)), graph))
    dist = graph
    for k in range(V):
        print(k)
        print(dist)
        for i in range(V):
            for j in range(V):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
    printSolution(dist)

def printSolution(dist):
    print("shortest distances between every pair of vertices")

    for i in range(V):
        for j in range(V):
            if dist[i][j]==INF:
                print("%7s" %("INF"))
            else:
                print("%7d\t" %(dist[i][j]))
            if j == V-1:
                print("")

graph = [[0, 4, -1, 8],[INF, 0, -2, -10],[INF,INF,0,3],[INF, INF, INF, 0]]

floydWarshall(graph)