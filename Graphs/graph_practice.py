def dfs(graph, start):
    visited, stack = list(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.append(vertex)
            stack.extend([vert for vert in graph[vertex] if vert not in visited])
            #stack.extend(graph[vertex] - visited)
    return visited

def dfs_paths(graph, start, goal, path=None):
    if path is None:
        path = [start]
    if start == goal:
        yield path
    for next in graph[start] - set(path):
        yield from dfs_paths(graph, next, goal, path + [next])

def bfs(graph, start):
	visited, queue = list(), [start]
	while queue:
		vertex = queue.pop(0)
		if vertex not in visited:
			visited.append(vertex)
			queue.extend([vert for vert in graph[vertex] if vert not in visited])
			#queue.extend(graph[vertex] - visited)
			queue = sorted(queue)
			print(queue)
	return visited

graph = {'1': ['2'],
		'2': ['3'],
		'3': ['3']}

print(dfs(graph, '3'))
