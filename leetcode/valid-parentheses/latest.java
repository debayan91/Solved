class Solution {
    public boolean isValid(String sa) {
        //tack<Character> stack = new Stack<>();
        Deque<Character> stack = new ArrayDeque<>();
        char[] s = sa.toCharArray();
        for(int i = 0 ;i<s.length;i++){
            if(stack.isEmpty()) stack.push(s[i]);
            else{
                if(stack.peek() == '{' && s[i] == '}') stack.pop();
                else if(stack.peek() == '(' && s[i] == ')') stack.pop();
                else if(stack.peek() == '[' && s[i] == ']') stack.pop();
                else{
                    stack.push(s[i]);
                }
            }
        }
        return stack.isEmpty();
    }
}