#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

#define MAX_VERTEX 50
#define UNDIRECTEDGRAPH 0
#define DIRECTEDGRAPH 1
#define DISPLAYGRAPH 0
#define DEPTHFIRSTTRAVERSAL 1
#define INCREASINGORDER 0
#define DECREASINGORDER 1

struct VertexType
{
    char strName[10];
    float weight;
    bool isMarked;
    VertexType *next;
    VertexType()
    {
        strcpy(strName, "");
        weight = 0;
        isMarked = false;
        next = NULL;
    }
};

struct GraphNode
{
    VertexType vertex;
    VertexType *adjVertex;
    int indegree;
    int outdegree;
    bool isMarked;
    GraphNode()
    {
        indegree = 0;
        outdegree = 0;
        isMarked = false;
        adjVertex = NULL;
    }
};

struct Graph
{
    int nGraphType;
    int nOperation;
    int nVertexNum;
    VertexType startVertex;
    int nOrder;
    GraphNode graph[MAX_VERTEX];
};
void alphabetSort(Graph &myGraph){
    for (int i = 0; i < myGraph.nVertexNum; i++) {
        for (int j = 0; j < myGraph.nVertexNum - i - 1; j++) {
            if (myGraph.graph[j].vertex.strName > myGraph.graph[j + 1].vertex.strName)
                swap(myGraph.graph[j], myGraph.graph[j + 1]);
        }
    }
}
Graph myGraph;
int readFile(Graph &myGraph, char *filename)
{
    #define MAX_CHARACTER_PER_LINE 80
	char* file_name = filename;
	FILE* f = 0;
	
	f = fopen(file_name, "r");
	if (f == NULL)	//file not found || cannot read
		return 0;
	///////////////////////////////////////////////
	char	str[MAX_CHARACTER_PER_LINE];

	fgets(str, MAX_CHARACTER_PER_LINE, f);
	sscanf(str, "%d", &myGraph.nGraphType);

    fgets(str, MAX_CHARACTER_PER_LINE, f);
    sscanf(str, "%d", &myGraph.nOperation);

    fgets(str, MAX_CHARACTER_PER_LINE, f);
    sscanf(str, "%d", &myGraph.nVertexNum);

    fgets(str, MAX_CHARACTER_PER_LINE, f);

    // int end = 0;
    // int start = 0;
    // char substring[10];
    char *token = strtok(str, " ");
	for(int i = 0; i<myGraph.nVertexNum; i++){
        // while(str[end] != ' ' && str[end] != '\0'){
        //     end++;
        // }
        // strncpy(substring, str + start, end - start);
        // substring[end - start] = '\0';
        sscanf(token, "%s", myGraph.graph[i].vertex.strName);
        token = strtok(NULL, " ");
        // start = end + 1;
        // end = start;
	}

    fgets(str, MAX_CHARACTER_PER_LINE, f);
    // for(int i = 0; i<myGraph.nVertexNum; i++){
    //     if(myGraph.graph[i].vertex.strName == str){
    //         myGraph.startVertex = myGraph.graph[i].vertex;
    //         break;
    //     }
    // }
    sscanf(str, "%s", myGraph.startVertex.strName);

    fgets(str, MAX_CHARACTER_PER_LINE, f);
    sscanf(str, "%d", &myGraph.nOrder);

    // char *s;
    // float weight;
    for(int i = 0; i < myGraph.nVertexNum; i++){
        fgets(str, MAX_CHARACTER_PER_LINE, f);
        token = strtok(str, " ");
        // int end = 0;
        // int start = 0;
        for(int j = 0; j < myGraph.nVertexNum; j++){
            float weight;
            // while(str[end] != ' ' && str[end] != '\0'){
            //     end++;
            // }
            // strncpy(s, str + start, end - start);
            sscanf(token, "%f", &weight);
            if(weight != 0){
                VertexType *Slot = new VertexType();
                strcpy(Slot->strName, myGraph.graph[j].vertex.strName);
                Slot->weight = weight;
                if(myGraph.graph[i].adjVertex == NULL)
                    myGraph.graph[i].adjVertex = Slot;
                else{
                    VertexType *temp = myGraph.graph[i].adjVertex;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = Slot;
                }
            }
            token = strtok(NULL, " ");
            // start = end + 1;
            // end = start;
        }
    }
    
	///////////////////////////////////////////////
	fclose(f);

    return 1;
}

void DisplayGraph(Graph &myGraph)
{
    for(int i = 0; i < myGraph.nVertexNum; i++){
        cout<<myGraph.graph[i].vertex.strName<<":";
        VertexType *temp = myGraph.graph[i].adjVertex;
        while(temp != NULL){
            cout<<" "<<temp->strName;
            temp = temp->next;
        }
        cout<<endl;
    }
}

string depthFirstTraversal(Graph &myGraph, VertexType startVertex)
{
    if(myGraph.nOrder == 0){
        queue<GraphNode> base;
        for(int i = 0; i < myGraph.nVertexNum; i++)
            base.push(myGraph.graph[i]);
    }
    else{
        stack<GraphNode> base;
        for(int i = 0; i < myGraph.nVertexNum; i++)
            base.push(myGraph.graph[i]);
    }
    string result = "";
    return result;
}

int main()
{
    for (int i = 0; i < MAX_VERTEX; i++)
        strcpy(myGraph.graph[i].vertex.strName, "-1");
    char	filename[80] = "input.txt";
    readFile(myGraph, filename);
    switch (myGraph.nOperation)
    {
    case DISPLAYGRAPH:
        cout << "Display Graph" << endl;
        DisplayGraph(myGraph);
        cout << "-----------------------------" << endl;
        break;
    case DEPTHFIRSTTRAVERSAL:
        cout << "Depth First Traversal" << endl;
        cout << depthFirstTraversal(myGraph, myGraph.startVertex) << endl;
        cout << "-----------------------------" << endl;
        break;
    }
    return 0;
}
