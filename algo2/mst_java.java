package Algo2;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * Question 3
In this programming problem you'll code up Prim's minimum spanning tree algorithm. Download the text file here. This file describes an undirected graph with integer edge costs. It has the format
[number_of_nodes] [number_of_edges]
[one_node_of_edge_1] [other_node_of_edge_1] [edge_1_cost]
[one_node_of_edge_2] [other_node_of_edge_2] [edge_2_cost]
...
For example, the third line of the file is "2 3 -8874", indicating that there is an edge connecting vertex #2 and vertex #3 that has cost -8874. You should NOT assume that edge costs are positive, nor should you assume that they are distinct.

Your task is to run Prim's minimum spanning tree algorithm on this graph. You should report the overall cost of a minimum spanning tree --- an integer, which may or may not be negative --- in the box below.

IMPLEMENTATION NOTES: This graph is small enough that the straightforward O(mn) time implementation of Prim's algorithm should work fine. OPTIONAL: For those of you seeking an additional challenge, try implementing a heap-based version. The simpler approach, which should already give you a healthy speed-up, is to maintain relevant edges in a heap (with keys = edge costs). The superior approach stores the unprocessed vertices in the heap, as described in lecture. Note this requires a heap that supports deletions, and you'll probably need to maintain some kind of mapping between vertices and their positions in the heap.
 */
public class PS1Q3 {

	static int[][] graph;
	static int numNodes;
	static int[] tree;//it has just edges tree[i] contains j if (i,j) is in tree. This array is NOT symmetric. init to -1
	/*
	 * implements slow O(mn) algo default one
	 */
	public static void primsSlow(){
		int weight = 0;
		boolean[] status = new boolean[numNodes];
		for (boolean i : status)
			i = false;
		status[0] = true;
		
		int minw = Integer.MAX_VALUE;
		int mini =0 ;
		int minj = 0;
		while(!isComplete(status)){
			for(int i =0;i<numNodes;i++){
				if (status[i]) continue;
				//find in graph an edge with (i,j) where j=true and trace minimum
				for(int j =0;j<numNodes;j++){
					if (!status[j]) continue;
					if (minw > graph[i][j]){
						minw = graph[i][j];
						mini=i;//new node
						minj=j;//old node
					}					
				}
			}
			status[mini] = true;
			tree[minj] = mini;
			weight += graph[mini][minj];
			minw = Integer.MAX_VALUE;
		}
		
		//compute cost of the tree
//		int weight = 0;
//		for (int i =0; i<numNodes;i++){
//			if (tree[i]!=-1){
//				weight+=graph[i][tree[i]];
//			}
//		}
		System.out.println("weight "+weight);
		
	}
	
	public static boolean isComplete(boolean[] status){
		for (boolean b : status){
			if (!b) return false;
		}
		return true;
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			FileInputStream f = new FileInputStream("edges.txt");
			DataInputStream d = new DataInputStream(f);
			BufferedReader b = new BufferedReader(new InputStreamReader(f));
			numNodes = Integer.parseInt(b.readLine().split(" ")[0]);
			graph = new int[numNodes][numNodes];
			for (int i =0;i<numNodes;i++)
				for(int j=0; j < numNodes; j++)
					graph[i][j] =Integer.MAX_VALUE;
			String str;
			while((str=b.readLine())!=null){
				int i = Integer.parseInt(str.split(" ")[0])-1;
				int j = Integer.parseInt(str.split(" ")[1])-1;
				graph[i][j] = Integer.parseInt(str.split(" ")[2]);
				graph[j][i] = Integer.parseInt(str.split(" ")[2]);
			}
			tree = new int[numNodes];
			for (int i : tree)
				i=-1;
			primsSlow();
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}﻿
