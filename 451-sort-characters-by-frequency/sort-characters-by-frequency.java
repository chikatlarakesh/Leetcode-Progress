class Solution {
    class Pair {
        int freq;
        char ch;

        public Pair(int freq,char ch) {
            this.freq = freq;
            this.ch = ch;
        }
    }

    public String frequencySort(String s) {
        int n = s.length();
        Pair[] hash = new Pair[256];

        for(int i=0;i<256;i++) {
            hash[i] = new Pair(0,(char)(i));
        }

        for(char ch : s.toCharArray()) {
            hash[ch].freq++;
        }

        Arrays.sort(hash,(a,b) -> {
            if(a.freq != b.freq) return b.freq - a.freq;
            else return a.ch - b.ch;
        });

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<256;i++) {
            int freq = hash[i].freq;
            if(freq == 0) break;
            char ch = hash[i].ch;
            while(freq > 0) {
                sb.append(ch);
                freq--;
            }
        }
        return sb.toString();
    }
}