Project 04: Path Finding
========================

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]


Additional Questions

Markdown Table:
| N             | Elapsed Time  | Memory Usage   |
|---------------|---------------|----------------|
| 10            | 2.54 ms       | 11.4 MB        |
| 20            | 3.64 ms       | 11.2 MB        |
| 50            | 5.9 ms        | 11.1 MB        |
| 100           | 14 ms         | 11.4 MB        |
| 200           | 48.15 ms      | 11.3 MB        |
| 500           | 292 ms        | 11.43 MB       |
| 1000          | 1054 ms       | 11.5 MB        |
|---------------|---------------|----------------|

1. I represented the map as a vector or vector of Nodes, where Node is a struct
   I created that held the data of index, back edge, distance, cost, and the tile char 

2. The complexity of my implementation of dijkstras is O(logn) I used a multimap in dijkstas and once the node had been visited it was erased from the mutimap 
   and the mutimap never had to be iterated through, since I had an iterator to constantly point to the beginning and the Nodes were keyed on distance, so the 
   smallest distances always got priority over the larger ones. All neighbor nodes are added to the mutimap, so there could be multiple instances of nodes in the
   mutimap but I combatted this by before moving onto the next node I checked if the iterator pointed to a node that had yet to be visited and if so it continued 
   otherwise the node would be erased from the multimap

3. My implementation scales well, even with a 1000 by 1000 map it took sometimes a max of two seconds to run, average all tests could be performed in aproximatley one second.
   The smaller N values executed even faster, almost instantaneously. Memory usage pretty much remained constant throughout all trials. 
