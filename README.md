<body>
    <h1>Prova Finale - GraphRanker Project (2021)</h1>
    <h2>Overview</h2>
    <p>This project is part of the final evaluation for the "Algoritmi e Strutture Dati" course. It involves the development of a program that ranks weighted directed graphs based on specific criteria. The project requires the application of techniques learned during the course, focusing on efficiency and proper data structure usage.</p>
    <h2>Educational Objectives</h2>
    <ul>
        <li>Apply the concepts learned in the algorithms and data structures module.</li>
        <li>Develop a practical solution to a problem while paying attention to code efficiency.</li>
    </ul>
    <h2>Implementation</h2>
    <ul>
        <li><strong>Language:</strong> C (C11 standard with Variable Length Arrays allowed).</li>
        <li><strong>Restrictions:</strong> No external libraries aside from the standard C library. No multithreading.</li>
        <li><strong>Input:</strong> Data is received via stdin, and output is printed via stdout.</li>
    </ul>
    <h2>GraphRanker</h2>
    <p>The goal of the project is to manage a ranking of the top <strong>k</strong> best-directed weighted graphs.</p>
    <ul>
        <li>The program receives two parameters on the first line: 
            <ul>
                <li><strong>d:</strong> Number of nodes in the graph.</li>
                <li><strong>k:</strong> The size of the ranking list.</li>
            </ul>
        </li>
        <li>The program processes a sequence of commands:</li>
        <ul>
            <li><strong>AggiungiGrafo:</strong> Adds a graph to the ranking. It is followed by the graph's adjacency matrix, where each row corresponds to the outgoing edges of a node.</li>
            <li><strong>TopK:</strong> Outputs the indices of the top <strong>k</strong> graphs based on the shortest paths from node 0.</li>
        </ul>
    </ul>
    <h3>AggiungiGrafo Command</h3>
    <p>This command adds a new graph to the system. It is followed by the graph's adjacency matrix, printed row by row, with elements separated by commas. Nodes are labeled from 0 to <strong>d-1</strong>.</p>
    <p><strong>Example (for d = 3):</strong></p>
    <pre>AggiungiGrafo
3,7,42
0,7,2
7,4,3</pre>
    <h3>TopK Command</h3>
    <p>This command calculates the top <strong>k</strong> graphs based on the sum of the shortest paths from node 0 to all reachable nodes. If multiple graphs have the same sum, the first added graph has priority. The program outputs the indices of the top <strong>k</strong> graphs on a single line, separated by spaces.</p>
    <h3>Example Execution</h3>
    <p><strong>Input:</strong></p>
    <pre>3,2
AggiungiGrafo
0,4,3
0,2,0
2,0,0
AggiungiGrafo
0,0,2
7,0,4
0,1,0
AggiungiGrafo
3,1,8
0,0,5
0,9,0
TopK</pre>
    <p><strong>Output:</strong></p>
    <pre>0 1</pre>
    <h2>Source Code</h2>
    <p>The project is implemented in the C programming language. You can find the full source code in the file <strong>API2021_FINALE.c</strong>. The program processes graph data and implements the ranking system described above.</p>
</body>
</html>
