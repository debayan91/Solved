class Solution {
    public List<Integer> spiralOrder(int[][] m) {
        int height = m.length; 
        int width = m[0].length;

        int total = height*width;
        List<Integer> order = new ArrayList<>();
    
        int count = 0;

        int y = 0,x = 0;

        boolean moved = false;
        while(count<total){
            moved = true;
            while(y<width && m[x][y] != -200 ){
                order.add(m[x][y]);
                m[x][y] = -200;
                count++;
                y++;
                moved = true;
            }
            y--;
            x++;
            //now we are at the leftmost point and need to go down
            while(x<height && m[x][y] != -200 ){
                order.add(m[x][y]);
                m[x][y] = -200;
                count++;
                x++;moved = true;
            }
            x--;
            y--;
            //now we end up at n.n and we need to go left
            while(y>=0 && m[x][y] != -200 ){
                order.add(m[x][y]);
                m[x][y] = -200;
                count++;
                y--;moved = true;
            }
            y++;
            x--;
            //now at the left bottom corner we need to go up
            while(x>=0 && m[x][y] != -200){
                order.add(m[x][y]);
                m[x][y] = -200;
                count++;
                x--;moved = true;
            }
            x++;
            y++;
            if(!moved) break;
        }
        return order;
    }
}