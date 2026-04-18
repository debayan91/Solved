class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        Stack<Integer> s = new Stack<>();
        int index = 0;
        for (int i = 0; i < pushed.length; i++) {
            s.push(pushed[i]);
            while (!s.isEmpty() && s.peek() == popped[index]) {
                s.pop();
                index++;
            }
        }
        if(!s.isEmpty()) return false;
        return true;
    }
}