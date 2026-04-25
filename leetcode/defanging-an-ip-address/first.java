class Solution {
    public String defangIPaddr(String address) {
        List<Character> list = new ArrayList<>();
        for (int i = 0; i < address.length(); i++) {
            if (address.charAt(i) == '.') {
                list.add('[');
                list.add('.');
                list.add(']');
            } else
                list.add(address.charAt(i));
        }
        return list.stream()
                .map(String::valueOf)
                .collect(Collectors.joining());
    }
}