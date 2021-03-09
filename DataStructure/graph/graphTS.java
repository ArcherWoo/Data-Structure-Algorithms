public class graphTS{

	// 拓扑排序主要用来解决有向图中的依赖解析（dependency resolution）问题。

	// 当且仅当一个有向图为有向无环图（directed acyclic graph，或称DAG）时，才能得到对应于该图的拓扑排序。每一个有向无环图都至少存在一种拓扑排序。

	// Depth-first solution	 
	void topsortDFS(Graph G) {
		int v;
		for (v=0; v<G.nodeCount(); v++)
			G.setValue(v, null); // Initialize
  	
  		for (v=0; v<G.nodeCount(); v++)
    		if (G.getValue(v) != VISITED)
      			tophelp(G, v);
	}

	void tophelp(Graph G, int v) {
		G.setValue(v, VISITED);
		int[] nList = G.neighbors(v);

		for (int i=0; i< nList.length; i++)
			if (G.getValue(nList[i]) != VISITED)
				tophelp(G, nList[i]);
		printout(v);
	}


	// Queue-based Solution
	void topsortBFS(Graph G) {          // Topological sort: Queue
		Queue Q = new LQueue(G.nodeCount());
  		int[] Count = new int[G.nodeCount()];
  		int[] nList;
  		int v;
  		for (v=0; v<G.nodeCount(); v++) Count[v] = 0; // Initialize
  
  		for (v=0; v<G.nodeCount(); v++) { // Process every edge
    		nList = G.neighbors(v);
    		for (int i=0; i< nList.length; i++)
      			Count[nList[i]]++;            // Add to v's prereq count
  		}

  		for (v=0; v<G.nodeCount(); v++)   // Initialize Queue
    		if (Count[v] == 0)              // V has no prerequisites
      			Q.enqueue(v);
  		
  		while (Q.length() > 0) {          // Process the vertices
    		v = (Integer)Q.dequeue();
    		printout(v);                    // PreVisit for Vertex V
    		nList = G.neighbors(v);
    	
    		for (int i=0; i< nList.length; i++) {
      			Count[nList[i]]--;            // One less prerequisite
      			if (Count[nList[i]] == 0)     // This vertex is now free
        			Q.enqueue(nList[i]);
    		}
  		}
	}

	public static void main(String[] args) {
		
	}
}