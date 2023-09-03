class Solution {
    class Point implements Comparable<Point> {
        int distance;  // distance from ball
        int row;
        int col;
        String directions;  // directions from ball

        Point(int distance, int row, int col, String directions) {
            this.distance = distance;
            this.row = row;
            this.col = col;
            this.directions = directions;
        }
        public int compareTo(Point other) {
            if (this.distance == other.distance) {
                return this.directions.compareTo(other.directions);     
            }
            return this.distance - other.distance;
        }
    }
    public String findShortestWay(int[][] maze, int[] ball, int[] hole) {
        boolean[][] visited = new boolean[maze.length][maze[0].length];

        PriorityQueue<Point> pq = new PriorityQueue<>();

        pq.offer(new Point(0, ball[0], ball[1], ""));

        // arrays used for exploring 4 directions from a point
        char[] dstr = {'d', 'l', 'r', 'u'};
        int[][] dirs = {{1,0},{0,-1},{0,1},{-1,0}};

        while (!pq.isEmpty()) {
            Point pt = pq.poll();
            if (pt.row == hole[0] && pt.col == hole[1]) {
                return pt.directions;
            }
            visited[pt.row][pt.col] = true;

            for (int i = 0; i < dirs.length; i++) {
                int newRow = pt.row;
                int newCol = pt.col;
                int distance = pt.distance;
                String directions = pt.directions;

                // Explore current direction until hitting a wall or the hole
                while (newRow + dirs[i][0] >= 0 &&
                       newRow + dirs[i][0] < maze.length &&
                       newCol + dirs[i][1] >= 0 &&
                       newCol + dirs[i][1] < maze[0].length &&
                       maze[newRow + dirs[i][0]][newCol + dirs[i][1]] != 1) {

                    newRow += dirs[i][0];
                    newCol += dirs[i][1];
                    distance += 1;

                    if (newRow == hole[0] && newCol == hole[1]) {
                        break;
                    }
                }
                if (!visited[newRow][newCol]) {
                    pq.offer(new Point(distance, newRow, newCol, directions + dstr[i]));
                }
            }
        }
        return "impossible";
    }
}