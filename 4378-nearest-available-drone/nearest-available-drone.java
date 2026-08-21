class Solution {
    public int nearestDrone(int[][] drones, int[] target) {
        int n = drones.length;
        int minDistance = Integer.MAX_VALUE,index = -1;
        for(int i = 0;i < n;i++) {
            int x = drones[i][0];
            int y = drones[i][1];
            int range = drones[i][2];
            int targetX = target[0];
            int targetY = target[1];

            int currDistance = Math.abs(x - targetX) + Math.abs(y - targetY);
            if(currDistance <= range && currDistance < minDistance) {
                minDistance = currDistance;
                index = i;
            }
        }
        return index;
    }
}