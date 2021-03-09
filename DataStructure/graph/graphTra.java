public class graphTra{


	public void graphTraverse(Graph G) {
		int v;
		for (v=0; v<G.nodeCount(); v++)
			G.setValue(v, null); // Initialize
		for (v=0; v<G.nodeCount(); v++)
			if (G.getValue(v) != VISITED)
      			doTraversal(G, v);
	}



	public void DFS(Graph G, int v) {
		PreVisit(G, v);
		G.setValue(v, VISITED);
		int[] nList = G.neighbors(v);
		for (int i=0; i< nList.length; i++)
			if (G.getValue(nList[i]) != VISITED)
				DFS(G, nList[i]);
  		PostVisit(G, v);
	}


	
	public void BFS(Graph G, int v) {
		LQueue Q = new LQueue(G.nodeCount());
		Q.enqueue(v);
		G.setValue(v, VISITED);
		while (Q.length() > 0) { // Process each vertex on Q
			v = (Integer)Q.dequeue();
			PreVisit(G, v);
			int[] nList = G.neighbors(v);
			for (int i=0; i< nList.length; i++)
				if (G.getValue(nList[i]) != VISITED) { // Put neighbors on Q
					G.setValue(nList[i], VISITED);
					Q.enqueue(nList[i]);
      			}
    		PostVisit(G, v);
  		}
	}

}