class Solution {
    public String frequencySort(String s) {

        Map<Character,Long> mp = s.chars()
                                    .mapToObj(c -> (char)c)
                                    .collect(Collectors.groupingBy(
                                        n -> n,
                                        Collectors.counting()
                                    ));
        
        return s.chars()
                .mapToObj(c -> (char)c)
                .sorted((ch1, ch2) -> {
                    long freq1 = mp.get(ch1);
                    long freq2 = mp.get(ch2);

                    if (freq1 != freq2) {
                        return Long.compare(freq2, freq1);
                    }

                    return Character.compare(ch1, ch2);
                })
                .map(String::valueOf)
                .collect(Collectors.joining());
    }
}